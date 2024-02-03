#ifndef _TARGET_RESET_REASON_H_
#define _TARGET_RESET_REASON_H_

#include "include.h"

/**
 * @brief List of supported reset flags
 * 
 */
typedef enum 
{
    /**
     * @brief Reset triggered by the physical reset pin
     * 
     */
    TargetResetReasonFlag_PinReset = 0,

    /**
     * @brief Reset caused due to brown out
     * 
     */
    TargetResetReasonFlag_PowerOn,

    /**
     * @brief Reset caused by software reset
     * 
     */
    TargetResetReasonFlag_SoftwareReset,

    /**
     * @brief Reset caused by the watchdog
     * 
     */
    TargetResetReasonFlag_Watchdog,

    /**
     * @brief Reset caused by illegal entry into sleep state
     * 
     */
    TargetResetReasonFlag_IllegalSleep,

    /**
     * @brief Number of supported reset flags
     * 
     */
    TARGET_RESET_REASON_FLAG_COUNT

}TargetResetReasonFlag;

/**
 * @brief Queries the target to see if a reset flag was set
 * 
 * @param Flag Flag to query
 * @param Set Returns true if the reset flag was set
 * @return Error Indication of success or failure
 */
Error TargetResetReason_Query(TargetResetReasonFlag Flag, bool *Set);

/**
 * @brief Clears out reset reason flags
 * 
 * @return Error Indication of success or failure
 */
Error TargetResetReason_ClearFlags();


/**
 * @brief Returns the human readible name of the reset flag
 * 
 * @param Flag reset flag
 * @return const char* 
 */
static inline const char * TargetResetReason_GetName(TargetResetReasonFlag Flag)
{
    switch(Flag)
    {
        case TargetResetReasonFlag_PinReset:
            return "Pin Reset";
        case TargetResetReasonFlag_PowerOn:
            return "Power On";
        case TargetResetReasonFlag_SoftwareReset:
            return "Software Reset";
        case TargetResetReasonFlag_Watchdog:
            return "Watchdog";
        case TargetResetReasonFlag_IllegalSleep:
            return "Illegal Sleep";                                
        default:
            return "UNKNOWN";
    }
}


#endif