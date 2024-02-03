#ifndef _GPIO_H_
#define _GPIO_H_

#include "include.h"
#include "gpio-pins.h"
#include "stm32l0xx_hal.h"



Error Gpio_Initialize();

Error Gpio_Write(GpioPin pin, GPIO_PinState state);

Error Gpio_Read(GpioPin pin, GPIO_PinState * state);

Error Gpio_Toggle(GpioPin pin);

#endif