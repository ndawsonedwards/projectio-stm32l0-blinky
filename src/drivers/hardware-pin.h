#ifndef _GPIO_PIN_H_
#define _GPIO_PIN_H_

#include "stm32l0xx_hal.h"
#include "errors.h"


typedef enum {

    GpioPin_Led

}GpioPin;


/**
 * @brief Returns the port and pin nubmer from the enumerated pin
 * 
 * @param pin enumerated pin
 * @param port port value of the enumerated pin
 * @param pinNumber pin value of the enumerated pin
 * @return Error
 */
Error GpioPin_GetPinContext(GpioPin pin, GPIO_TypeDef ** port, uint16_t * pinNumber );


#endif