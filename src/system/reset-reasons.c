#include "reset-reason.h"
#include "stm32l0xx_hal.h"
/**
 * @brief Queries the target to see if a reset flag was set
 * 
 * @param Flag Flag to query
 * @param Set Returns true if the reset flag was set
 * @return Error Indication of success or failure
 */
Error TargetResetReason_Query(TargetResetReason Flag, bool *Set)
{

    switch (Flag)
    {
        case TargetResetReasonFlag_PinReset:
			*Set = (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST) == SET);
			break;

        case TargetResetReasonFlag_PowerOn:
			*Set = (__HAL_RCC_GET_FLAG(RCC_FLAG_PORRST) == SET);
			break;

        case TargetResetReasonFlag_SoftwareReset:
			*Set = (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST) == SET);
			break;

        case TargetResetReasonFlag_Watchdog:
			*Set = (( __HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST) == SET) || (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) == SET) );
			break;

        case TargetResetReasonFlag_IllegalSleep:
			*Set = (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST) == SET);
			break;

        default:
        	return ErrorBadParameter;
    }

    return ErrorNone;
}

/**
 * @brief Returns the reset reasom
 * @note This returns on teh first detected set flag. There may be additional flags set
 * 
 * @param Reason Reason to query
 * @return Error Indication of success or failure
 */
Error TargetResetReason_Get(TargetResetReason *Reason)
{

    TargetResetReason flag;
    for (flag = 0; flag < TARGET_RESET_REASON_COUNT; flag++)
    {
        bool IsSet = false;
        Error Error = TargetResetReason_Query(flag, &IsSet);
        if (Error != ErrorNone)
        {
            continue;
        }
        
        if ( IsSet)
        {
            *Reason = flag;
            return ErrorNone;
        }
    } 

    TargetResetReason_ClearFlags();

    return ErrorNone;
}

/**
 * @brief Clears out reset reason flags
 * 
 * @return Error Indication of success or failure
 */
Error TargetResetReason_ClearFlags()
{
    __HAL_RCC_CLEAR_RESET_FLAGS();
    return ErrorNone;
}
