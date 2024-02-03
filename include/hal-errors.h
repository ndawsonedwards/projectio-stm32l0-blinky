#ifndef _HAL_ERRORS_H_
#define _HAL_ERRORS_H_

#include "include.h"
#include "stm32l0xx_hal.h"

/**
 * @brief Converts the HAL_StatusTypeDef status enumeration to Error enumeration 
 * 
 * @return Error
 */
static inline Error HalErrors_GetError(HAL_StatusTypeDef status)
{
    switch(status)
    {
        case HAL_OK:
            return ErrorNone;
        case HAL_ERROR:
            return ErrorUnknown;
        case HAL_BUSY:
            return ErrorResourceInUse;
        case HAL_TIMEOUT:
            return ErrorTimeout;                                
        default:
            return ErrorUnknown;;
    }

    return ErrorUnknown;
}

#endif
