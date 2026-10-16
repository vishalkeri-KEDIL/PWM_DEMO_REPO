
#include "ads1220.h"


void ADS1220_CS_Low(void)
{

    HAL_GPIO_WritePin(ADS1220_CS_GPIO_Port,ADS1220_CS_Pin,GPIO_PIN_RESET);

}



void ADS1220_CS_High(void)
{

    HAL_GPIO_WritePin(ADS1220_CS_GPIO_Port,ADS1220_CS_Pin,GPIO_PIN_SET);

}



void ADS1220_StartConversion(void)
{

    uint8_t command = ADS1220_CMD_START;

    ADS1220_CS_Low();

    HAL_SPI_Transmit(&hspi3 , &command , 1 , 100);

    ADS1220_CS_High();

}





int32_t ADS1220_ReadADC(void)
{
    uint8_t command = ADS1220_CMD_RDATA; // 10

    uint8_t rx[3];

    int32_t adc_value;

    ADS1220_CS_Low();

    HAL_SPI_Transmit(&hspi3 , &command , 1 , 100);

    HAL_SPI_Receive(&hspi3 , rx , 3 , 100 );

    ADS1220_CS_High();


   //adc sent 32 bit digital value but in spi configration i selected 8bit values fist i will store in array

    adc_value = ((int32_t)rx[0] << 16) |((int32_t)rx[1] << 8)  |(int32_t)rx[2];

    return adc_value;

}



void ADS1220_WriteRegister(uint8_t reg, uint8_t data)
{


    uint8_t command;

    command = 0x40 | ((reg) << 2);

    ADS1220_CS_Low();

    HAL_SPI_Transmit(&hspi3, &command, 1, 100);

    HAL_SPI_Transmit(&hspi3, &data, 1, 100);

    ADS1220_CS_High();


}



void ADS1220_Init(void)
{


      //pin AIN1-AIN0  GAIN 16  PGA ENABLE


    ADS1220_WriteRegister( 0x00 , 0x68 );


     //20SPS     NORMAL MOOD   CONTINOUS-CONVARTION  TS-(disable)  burn(disable);


    ADS1220_WriteRegister( 0x01 , 0x04 );


    // vref(external REFPO/REFN0)   50AND60 rejection   PWS (0)  IDS-101 (0.5mA)


    ADS1220_WriteRegister( 0x02 , 0x55 );


   // IDAC1-PIN-(AIN2) IDAC2-PIN-(AIN3)  DRDYM(0)Dedicated-drdy   reserved


    ADS1220_WriteRegister( 0x03 , 0x70 );


}
