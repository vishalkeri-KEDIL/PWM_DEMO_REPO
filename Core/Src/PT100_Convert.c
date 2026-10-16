
#include "PT100_Convert.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>


//extern float vref ;

#define RREF        1612.0f

#define PT100_GAIN        16.0f

#define ADC_FULL_SCALE    8388608.0f  // 2^23

#define IDAC1          0.0005f

#define IDAC2          0.0005f





float ADS1220_Calculate_VREF(void)
{
    float total_current;

    float vref;

    total_current = (IDAC1 + IDAC2);

    vref = total_current * RREF;

    return vref;

}



float step_size(void)
{
    float vref = ADS1220_Calculate_VREF();

    return vref / (PT100_GAIN * ADC_FULL_SCALE);

}




float ADS1220_ADC_To_Voltage(int32_t adc_code)
{
    float stepsize,voltage=0;
    stepsize=step_size();
    voltage=adc_code*stepsize;
    return voltage;
}





float ADS1220_Voltage_To_Resistance(float voltage)
{
    float current = IDAC1 ;
    		//* 1.0e-6f;               // 0.5 mA in ampere
    return voltage / current;
}



