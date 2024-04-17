/*! \file main.c
    \brief Driver for testing out the challenge interface implementation.
*/
#include "challenge_api.h"

#include <stdio.h>

int
main(void)
{
    uint8_t data;

    // Real full scale config
    printf("=== Reading full scale config ===\n");
    if (STATUS_OK != get_full_scale_config(&data))
        printf("Failed to get full scale config\n");
    else
        printf("Full scale config: %d\n", data);

    // Get and set output data rate
    printf("=== Getting and setting output data rate ===\n");
    if (STATUS_OK != get_output_data_rate(&data))
        printf("Failed to get output data rate\n");
    else
        printf("Output data rate: %d\n", data);        

    if (STATUS_OK != set_output_data_rate(DATA_RATE_560))
        printf("Failed to set output data rate\n");      
    else
        printf("Successfully set output data rate\n");

    if (STATUS_OK != set_output_data_rate(DATA_RATE_1_25))
        printf("Failed to set output data rate\n");      
    else
        printf("Successfully set output data rate\n");

    // Enable and disable int pin
    printf("=== Enabling and disabling interrupt pin ===\n");
    if (STATUS_OK != enable_int_pin())
        printf("Failed to enable int pin\n");
    else
        printf("Successfully enabled int pin\n");

    if (STATUS_OK != disable_int_pin())
        printf("Failed to disable int pin\n");
    else
        printf("Successfully disabled int pin\n");
    
    // Read axes output data
    printf("=== Reading axes output data ===\n");
    uint16_t axis_data;
    for (uint8_t i = 0; i < 3; i++)
    {
        if (STATUS_OK != read_axis_output_data(i, &axis_data))
            printf("Failed to read axis %d data\n", i);
        else
            printf("Successfully read axis %d data = %d\n", i, axis_data);
    }

    return 0;
}

