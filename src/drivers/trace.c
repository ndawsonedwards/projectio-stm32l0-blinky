#include "trace.h"
#include "stm32l0xx_hal.h"
#include "hal-errors.h"
#include <string.h>
#include <stdio.h>

// #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

// /**
//   * @brief  Retargets the C library printf function to the USART.
//   * @param  None
//   * @retval None
//   */
// PUTCHAR_PROTOTYPE
// {
//   /* e.g. write a character to the USART1 and Loop until the end of transmission */
//     GuardianTrace_ClaimMutex();
//     AtomosByteStream_WriteByte(_TraceStream,(uint8_t)ch);
//     GuardianTimer_ReleaseMutex();
//     return ch;
// }
static bool _initialized = false;

static UART_HandleTypeDef _uart;

Error Trace_Initialize() {

    memset(&_uart, 0, sizeof(_uart));
    _uart.Instance = USART2;
    _uart.Init.BaudRate = 115200;
    _uart.Init.WordLength = UART_WORDLENGTH_8B;
    _uart.Init.StopBits = UART_STOPBITS_1;
    _uart.Init.Parity = UART_PARITY_NONE;
    _uart.Init.Mode = UART_MODE_TX_RX;
    _uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    _uart.Init.OverSampling = UART_OVERSAMPLING_16;
    _uart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    _uart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&_uart) != HAL_OK)
    {
        return ErrorHardwareFailure;
    }

    _initialized = true;
    return ErrorNone;
}

Error Trace_Print(const char *Format,...)
{
    if ( ! _initialized )
    {
        return ErrorBadState;
    }

    va_list Arguments;
    va_start(Arguments,Format);

    char buffer[256] = {0};
    vsnprintf(buffer, sizeof(buffer), Format, Arguments);
    int size = strlen(buffer);
    if (size == 0 ) {
        return ErrorOperationCancelled;
    }
    size = (size < sizeof(buffer)) ? size : sizeof(buffer);

    HAL_StatusTypeDef result =  HAL_UART_Transmit(&_uart, (uint8_t*) buffer, size, 1000 );
    if (result != HAL_OK) {
        return HalErrors_GetError(result);
    }

    va_end(Arguments);

    return ErrorNone;
}