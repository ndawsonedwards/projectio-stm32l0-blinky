#ifndef _HARDWARE_PIN_H_
#define _HARDWARE_PIN_H_

#include "stm32l0xx_hal.h"
#include "errors.h"

#include "gpio-pins.h"


/**
 * @brief Returns the port and pin nubmer from the enumerated pin
 * 
 * @param pin enumerated pin
 * @param port port value of the enumerated pin
 * @param pinNumber pin value of the enumerated pin
 * @return Error
 */
Error HardwarePins_GetPinContext(GpioPin pin, GPIO_TypeDef ** port, uint16_t * pinNumber );


#endif