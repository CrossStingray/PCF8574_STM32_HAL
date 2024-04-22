/*
 * PCF8574.h
 *
 *  Created on: Feb 29, 2024
 *      Author: spiran
 */

#ifndef INC_PCF8574_H_
#define INC_PCF8574_H_

#include "main.h"

#define PCF8574_BASE_ADDRESS 	0x40
#define PCF8574_TIMEOUT			HAL_MAX_DELAY
#define PCF8574_WRITE			0x00
#define PCF8574_READ			0x01

typedef enum PCF8574_GPIO{
	PCF8574_GPIO_EX0 = 0,		// A2 = L ; A1 = L ; A0 = L
	PCF8574_GPIO_EX1,			// A2 = L ; A1 = L ; A0 = H
	PCF8574_GPIO_EX2,			// A2 = L ; A1 = H ; A0 = L
	PCF8574_GPIO_EX3,			// A2 = L ; A1 = H ; A0 = H
	PCF8574_GPIO_EX4,			// A2 = H ; A1 = L ; A0 = L
	PCF8574_GPIO_EX5,			// A2 = H ; A1 = L ; A0 = H
	PCF8574_GPIO_EX6,			// A2 = H ; A1 = H ; A0 = L
	PCF8574_GPIO_EX7,			// A2 = H ; A1 = H ; A0 = H
}PCF8574_GPIO;

uint8_t PCF8574_Read(I2C_HandleTypeDef *hi2c, PCF8574_GPIO GPIO_EX);
void PCF8574_Write(I2C_HandleTypeDef *hi2c, PCF8574_GPIO GPIO_EX, uint8_t Tx);

#endif /* INC_PCF8574_H_ */
