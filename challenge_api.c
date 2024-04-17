/*! \file challenge_api.c
    \brief Challenge interface implementation.
*/
#include "challenge_api.h"
#include "lis3mdl_register_map.h"

status_t
get_full_scale_config(uint8_t *config)
{
    uint8_t read_buffer;

    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, CTRL_REG2_ADDR, 1, &read_buffer))
    {
        return STATUS_ERROR;
    }

    *config = (read_buffer >> 5) & 0x3;

    return STATUS_OK;
}

status_t
get_output_data_rate(uint8_t *rate)
{
    uint8_t read_buffer;

    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, CTRL_REG1_ADDR, 1, &read_buffer))
    {
        return STATUS_ERROR;
    }

    // Need to check if it's in FAST_ODR
    const uint8_t is_fast_odr = (read_buffer & 0x2) != 0;
    
    if (!is_fast_odr)
    {
        *rate = (read_buffer >> 2) & 0x7;
    }
    else
    {
        const uint8_t op_mode = (read_buffer >> 5) & 0x3;
        *rate = op_mode + 8;
    }

    return STATUS_OK;
}

status_t
set_output_data_rate(const uint8_t rate)
{
    if (rate > DATA_RATE_155)
    {
        return STATUS_ERROR;
    }

    uint8_t read_write_buffer;

    // Read current config first
    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, CTRL_REG1_ADDR, 1, &read_write_buffer))
    {
        return STATUS_ERROR;
    }

    const uint8_t set_fast_odr = (rate > DATA_RATE_80);
    if (set_fast_odr)
    {
        const uint8_t op_mode = rate - 8;
        read_write_buffer |= (op_mode << 5) & 0x2;
    }
    else
    {
        read_write_buffer |= rate << 2;
    }

    return i2c_write(I2C_BUS_ADDR, CTRL_REG1_ADDR, 1, &read_write_buffer);
}

status_t
enable_int_pin(void)
{
    uint8_t read_write_buffer;

    // Read current config first
    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, INT_CFG_ADDR, 1, &read_write_buffer))
    {
        return STATUS_ERROR;
    }

    read_write_buffer |= 0x1;
    if (STATUS_OK != i2c_write(I2C_BUS_ADDR, INT_CFG_ADDR, 1, &read_write_buffer))
    {
        return STATUS_ERROR;
    }

    return STATUS_OK;
}

status_t
disable_int_pin(void)
{
    uint8_t read_write_buffer;

    // Read current config first
    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, INT_CFG_ADDR, 1, &read_write_buffer))
    {
        return STATUS_ERROR;
    }

    read_write_buffer &= 0xFE;
    if (STATUS_OK != i2c_write(I2C_BUS_ADDR, INT_CFG_ADDR, 1, &read_write_buffer))
    {
        return STATUS_ERROR;
    }

    return STATUS_OK;
}

status_t
read_axis_output_data(uint8_t axis_type, uint16_t *data)
{
    uint8_t read_buffer[2];
    const uint8_t axis_low_reg = OUT_X_L_ADDR + 2*axis_type;
    const uint8_t axis_high_reg = OUT_X_H_ADDR + 2*axis_type;
    uint8_t axis_low_value;
    uint8_t axis_high_value;

    // Read high and low registers and pack into 16-bits
    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, axis_low_reg, 1, &axis_low_value))
    {
        return STATUS_ERROR;
    }
    if (STATUS_OK != i2c_read(I2C_BUS_ADDR, axis_high_reg, 1, &axis_high_value))
    {
        return STATUS_ERROR;
    }

    *data = axis_low_value | (axis_high_value << 8);

    return STATUS_OK;
}