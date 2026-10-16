#ifndef ADS1220_H
#define ADS1220_H


#include "main.h"


/* ADS1220 uses SPI3 and PB1 as software-controlled CS */


extern SPI_HandleTypeDef hspi3;




#define ADS1220_CS_GPIO_Port   GPIOB
#define ADS1220_CS_Pin         GPIO_PIN_1





/* ADS1220 commands */
#define ADS1220_CMD_RESET      0x06

#define ADS1220_CMD_START      0x08

#define ADS1220_CMD_RDATA      0x10




void ADS1220_CS_Low(void);

void ADS1220_CS_High(void);

void ADS1220_Reset(void);
void ADS1220_StartConversion(void);

int32_t ADS1220_ReadADC(void);
void ADS1220_WriteRegister(uint8_t reg, uint8_t data);
uint8_t ADS1220_ReadRegister(uint8_t reg);
void ADS1220_Init(void);




#endif
