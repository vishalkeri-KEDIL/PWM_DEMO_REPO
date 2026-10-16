#ifndef PT100_CONVERT_H
#define PT100_CONVERT_H

#include <stdint.h>

float ADS1220_ADC_To_Resistance(int32_t adc_code);
float PT100_Resistance_To_Temperature(float resistance);

#endif


float ADS1220_Calculate_VREF(void);
float ADS1220_ADC_To_Voltage(int32_t adc_code);
float step_size (void);
float ADS1220_Voltage_To_Resistance(float voltage);
