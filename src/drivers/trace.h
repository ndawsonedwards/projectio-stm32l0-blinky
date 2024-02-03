#ifndef _TRACE_H_
#define _TRACE_H_

#include "include.h"

/**
 * @brief Initialize the trace module for first time use
 * 
 * @return Error 
 */
Error Trace_Initialize();

/**
 * @brief Sends message to the trace
 * 
 * @param Format Formatted message
 * @param ...  args
 * @return Error 
 */
Error Trace_Print(const char *Format,...);

/**
 * @brief Sends message appended with newline to the trace
 * 
 * @param Format Formatted message
 * @param ...  args
 * @return Error 
 */
Error Trace_PrintLine(const char *Format,...);


#endif //_TRACE_H_