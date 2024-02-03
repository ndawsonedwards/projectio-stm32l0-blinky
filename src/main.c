
#include "stm32l0xx_hal.h"
#include "drivers/trace.h"
#include "drivers/rcc.h"
#include "drivers/gpio.h"
#include "include.h"
#include "hal-errors.h"


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

    HAL_StatusTypeDef status = HAL_Init();
    if (status != HAL_OK) {
        return HalErrors_GetError(status);
    }

    Error error = Rcc_Initialize();
    if (error != ErrorNone) {
        return error;
    }
    
    error = Trace_Initialize();
    if (error != ErrorNone) {
        return error;
    }

    error = Gpio_Initialize();
    if (error != ErrorNone) {
        return error;
    }

    return ErrorNone;
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void) {

    Error error = App_Initialize();
    if (error != ErrorNone) {
        Error_Handler();
    }

    const char* msg = "Yippie-ki-yay mother flipper";
    while(1) {

        HAL_Delay(1000);
        error = Gpio_Toggle(GpioPin_Led);
        if (error != ErrorNone ) {
            Trace_Print("Error Gpio no good");
        }

        Trace_Print(msg);

    }


    return 0;
}

void HardFault_Handler(void)
{
    //TODO - add debug info here
  while (1)
  {

  }
}


void SysTick_Handler(void)
{
  HAL_IncTick();
}

