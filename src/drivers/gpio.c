#include "gpio.h"
#include "hardware-pin.h"
#include "hal-errors.h"


Error Gpio_Initialize() {

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();


    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = LD3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LD3_GPIO_Port, &GPIO_InitStruct);

    return ErrorNone;
}



Error Gpio_Write(GpioPin pin, GPIO_PinState state) {

    GPIO_TypeDef *port;
    uint16_t pinNumber;

    Error error = HardwarePins_GetPinContext(pin, &port, &pinNumber);
    if (error != ErrorNone ){
        return error;
    }

    HAL_GPIO_WritePin(port,pin,state);

    return ErrorNone;
}

Error Gpio_Read(GpioPin pin, GPIO_PinState * state) {

    if (ILLEGAL_POINTER(state)) {
        return ErrorIllegalPointer;
    }

    GPIO_TypeDef *port;
    uint16_t pinNumber;
    Error error = HardwarePins_GetPinContext(pin, &port, &pinNumber);
    if (error != ErrorNone ){
        return error;
    }

    *state = HAL_GPIO_ReadPin(port, pinNumber);
    return ErrorNone;

}

Error Gpio_Toggle(GpioPin pin) {

    GPIO_TypeDef *port;
    uint16_t pinNumber;
    Error error = HardwarePins_GetPinContext(pin, &port, &pinNumber);
    if (error != ErrorNone ){
        return error;
    }

    HAL_GPIO_TogglePin(port, pinNumber);
    return ErrorNone;
}

