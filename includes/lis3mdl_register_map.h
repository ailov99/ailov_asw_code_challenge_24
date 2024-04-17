/*! \file lis3mdl_register_map.h
    \brief LIS3MDL magnetic sensor register addresses.
*/
#ifndef REGISTER_MAP_HEADER_H
#define REGISTER_MAP_HEADER_H

// Bus
#define I2C_BUS_ADDR 0x0 // Assume

// Control registers
#define CTRL_REG1_ADDR 0x20
#define CTRL_REG2_ADDR 0x21

// Interrupt config
#define INT_CFG_ADDR 0x30

// Axes
#define OUT_X_L_ADDR 0x28
#define OUT_X_H_ADDR 0x29
#define OUT_Y_L_ADDR 0x2A
#define OUT_Y_H_ADDR 0x2B
#define OUT_Z_L_ADDR 0x2C
#define OUT_Z_H_ADDR 0x2D

#endif