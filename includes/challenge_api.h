/*! \file challenge_api.h
    \brief Specifies the required challenge interface.
*/
#ifndef CHALLENGE_API_HEADER_H
#define CHALLENGE_API_HEADER_H

#include "i2c.h"
#include "lis3mdl_specs.h"

/**
 * Get the full-scale config of the sensor.
 * @param config OUT full-scale configuration
 * @return STATUS_OK or STATUS_ERROR
 */
status_t
get_full_scale_config(uint8_t *config);

/**
 * Get output data rate.
 * @param rate OUT current data rate
 * @return STATUS_OK or STATUS_ERROR
 */
status_t
get_output_data_rate(uint8_t *rate);

/**
 * Set output data rate.
 * @param rate IN rate to set
 * @see lis3mdl_specs.h
 * @return STATUS_OK or STATUS_ERROR
 */
status_t
set_output_data_rate(const uint8_t rate);

/**
 * Enable interrupt pin.
 * @return STATUS_OK or STATUS_ERROR
 */
status_t
enable_int_pin(void);

/**
 * Disable interrupt pin.
 * @return STATUS_OK or STATUS_ERROR
 */
status_t
disable_int_pin(void);

/**
 * Read output data for a specified axis.
 * @param axis_type IN the specified axis type (X/Y/Z)
 * @param data OUT output data for the specified axis
 * @see lis3mdl_specs.h
 * @return STATUS_OK or STATUS_ERROR
 */
status_t
read_axis_output_data(uint8_t axis_type, uint16_t *data);

#endif