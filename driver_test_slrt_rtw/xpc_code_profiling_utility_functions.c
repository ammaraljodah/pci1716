/*
 * File: xpc_code_profiling_utility_functions.c
 *
 * Code generated for instrumentation.
 *
 */

#include "xpc_code_profiling_utility_functions.h"

/* Code instrumentation offset(s) for model  */
#define taskTimeStart__offset          0
#define taskTimeEnd__offset            0

void xilUploadProfilingData(uint32_T sectionId)
{
  xpceaddEvent(sectionId);
}

/* For real-time, multitasking case this function is stubbed out. */
void xilProfilingTimerFreeze(void)
{
}

/* For real-time, multitasking case this function is stubbed out. */
void xilProfilingTimerUnFreeze(void)
{
}

void taskTimeStart(uint32_T sectionId)
{
  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreeze();
}

void taskTimeEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
}

/* Code instrumentation method(s) for model  */
void taskTimeStart_(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart__offset + sectionId);
}

void taskTimeEnd_(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd__offset + sectionId);
}
