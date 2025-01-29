/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: untitled.c
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

#include "untitled.h"
#include <math.h>
#include "rtwtypes.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* External inputs (root inport signals with default storage) */
ExtU_untitled_T untitled_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/pushSW'
   */
  if (!untitled_U.pushSW) {
    /* Outport: '<Root>/blueLed' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  Sin: '<S1>/Sine Wave'
     */
    untitled_Y.blueLed = (uint16_T)floor(sin((real_T)untitled_DW.counter * 2.0 *
      3.1415926535897931 / 300.0) * 25000.0 + 25000.0);
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/SW_OFF' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Outport: '<Root>/blueLed' incorporates:
     *  Constant: '<S1>/Zero'
     *  SignalConversion generated from: '<S2>/In1'
     */
    untitled_Y.blueLed = 0U;

    /* End of Outputs for SubSystem: '<S1>/SW_OFF' */
  }

  /* End of If: '<S1>/If' */

  /* Update for Sin: '<S1>/Sine Wave' */
  untitled_DW.counter++;
  if (untitled_DW.counter == 300) {
    untitled_DW.counter = 0;
  }

  /* End of Update for Sin: '<S1>/Sine Wave' */
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
