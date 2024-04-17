/*! \file lis3mdl_specs.h
    \brief LIS3MDL magnetic sensor specification constants.
*/
#ifndef I2C_TYPES_H
#define I2C_TYPES_H

// Full-scale config
#define CONFIG_4_GAUSS  0U
#define CONFIG_8_GAUSS  1U
#define CONFIG_12_GAUSS 2U
#define CONFIG_16_GAUSS 3U

// Data rates
#define DATA_RATE_0_625 0U
#define DATA_RATE_1_25  1U
#define DATA_RATE_2_5   2U
#define DATA_RATE_5     3U
#define DATA_RATE_10    4U
#define DATA_RATE_20    5U
#define DATA_RATE_40    6U
#define DATA_RATE_80    7U
#define DATA_RATE_1000  8U
#define DATA_RATE_560   9U
#define DATA_RATE_300   10U
#define DATA_RATE_155   11U

// Operative modes
#define OM_LP  0U
#define OM_MP  1U
#define OM_HP  2U
#define OM_UHP 3U

// Axis types
#define AXIS_X 0U
#define AXIS_Y 1U
#define AXIS_Z 2U

#endif