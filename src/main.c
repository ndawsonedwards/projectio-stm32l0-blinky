
#include "stm32l0xx_hal.h"
#include "drivers/gpio.h"
#include "drivers/trace.h"
#include "include.h"


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
static void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}


static Error App_Initialize() {

    Error error = Trace_Initialize();
    if (error != ErrorNone) {
        return error;
    }

    error = Gpio_Initialize();
    if (error != ErrorNone) {
        return error;
    }

    return ErrorNone;
}

int main() {

    Error error = App_Initialize();
    if (error != ErrorNone) {
        Error_Handler();
    }

    while(1) {

        HAL_Delay(1000);
        HAL_GPIO_TogglePin(GPIOB, 3);
    }


    return 0;
}


