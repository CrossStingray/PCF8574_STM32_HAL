/*
 * PCF8574.c
 *
 *  Created on: Feb 29, 2024
 *      Author: spiran
 */

#include "PCF8574.h"

/**
 * @brief Gets the byte in the designated PCF8574 selected.
 * @param hi2c User I2C handle pointer.
 * @param GPIO_EX Selects the GPIO Expander using the A0, A1 and A2 inputs.
 * @return Reads register stored in the I/O port, 0 to 255.
 */
uint8_t PCF8574_Read(I2C_HandleTypeDef *hi2c, PCF8574_GPIO GPIO_EX){
	uint8_t Rx;
	uint16_t DevAddress = PCF8574_BASE_ADDRESS | (GPIO_EX << 1) | PCF8574_READ;
	HAL_I2C_Master_Receive(hi2c, DevAddress, &Rx, 1, PCF8574_TIMEOUT);
	return Rx;
}

/**
 * @brief Writes to the I/O port on the designated PCF8574
 * @param hi2c User I2C handle pointer.
 * @param GPIO_EX Selects the GPIO Expander using the A0, A1 and A2 inputs.
 * @param Tx Value to set, 0 to 255.
 */
void PCF8574_Write(I2C_HandleTypeDef *hi2c, PCF8574_GPIO GPIO_EX, uint8_t Tx){
	uint16_t DevAddress = PCF8574_BASE_ADDRESS | (GPIO_EX << 1) | PCF8574_WRITE;
	HAL_I2C_Master_Transmit(hi2c, DevAddress, &Tx, 1, PCF8574_TIMEOUT);
}
