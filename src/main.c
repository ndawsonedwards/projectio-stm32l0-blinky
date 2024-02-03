
#include "stm32l0xx_hal.h"
#include "drivers/trace.h"
#include "drivers/rcc.h"
#include "drivers/gpio.h"
#include "include.h"
#include "hal-errors.h"
#include "system/reset-reason.h"


void HardFault_Handler(void)
{
    //TODO - add debug info here
    __disable_irq();

    while (1)
    {

    }
}


void SysTick_Handler(void)
{
    HAL_IncTick();
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
        HardFault_Handler();
    }

    TargetResetReason reason;
    error = TargetResetReason_Get(&reason);
    if (error != ErrorNone){
      Trace_PrintLine("Unable to retrieve Reset Reason");
    }

    Trace_PrintLine("Reset Reason: %s", TargetResetReason_GetName(reason));

    const char* msg = "Yippie-ki-yay mother flipper";
    while(1) {

        HAL_Delay(1000);
        error = Gpio_Toggle(GpioPin_Led);
        if (error != ErrorNone ) {
            Trace_PrintLine("Error Gpio no good");
        }

        Trace_PrintLine(msg);
    
    }


    return 0;
}

