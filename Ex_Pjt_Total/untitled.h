/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jan 22 14:09:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T counter;                     /* '<S1>/Sine Wave' */
} DW_untitled_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T pushSW;                    /* '<Root>/pushSW' */
} ExtU_untitled_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T blueLed;                    /* '<Root>/blueLed' */
} ExtY_untitled_T;

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_untitled_T untitled_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_untitled_T untitled_Y;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Subsystem'
 * '<S2>'   : 'untitled/Subsystem/SW_OFF'
 * '<S3>'   : 'untitled/Subsystem/SW_ON'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
