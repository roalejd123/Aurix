/**********************************************************************************************************************
 * \file GTM_TIM_Capture_Ex.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/


/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxGtm_Tim_In.h"
#include "IfxGtm_Tom_Pwm.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

#define PWM_IN          IfxGtm_TIM0_0_TIN0_P02_0_IN     /* Input port pin for the PWM signal                        */


/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
float32 g_measuredPwmDutyCycle = 0.0;                   /* Global variable for duty cycle of generated PWM signal   */
float32 g_measuredPwmFreq_Hz = 0.0;                     /* Global variable for frequency calculation of PWM signal  */
float32 g_measuredPwmPeriod = 0.0;                      /* Global variable for period calculation of PWM signal     */
IfxGtm_Tim_In g_driverTIM;                              /* TIM driver structure                                     */
boolean g_dataCoherent = FALSE;                         /* Boolean to know if the measured data is coherent         */

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* This function initializes the TIM to capture a PWM signals */
void init_TIM(void)
{
    IfxGtm_enable(&MODULE_GTM);                                         /* Enable the GTM                           */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK0);        /* Enable the CMU clock 0                   */

    IfxGtm_Tim_In_Config configTIM;

    IfxGtm_Tim_In_initConfig(&configTIM, &MODULE_GTM);                  /* Initialize default parameters            */
    configTIM.filter.inputPin = &PWM_IN;                                /* Select input port pin                    */
    configTIM.filter.inputPinMode = IfxPort_InputMode_pullDown;         /* Select input port pin mode               */
    IfxGtm_Tim_In_init(&g_driverTIM, &configTIM);                       /* Initialize the TIM                       */
}


/* This function measures the period, the frequency and the duty cycle of the PWM signal */
void measure_PWM(void)
{
    IfxGtm_Tim_In_update(&g_driverTIM);                                         /* Update the measured data         */
    g_measuredPwmPeriod = IfxGtm_Tim_In_getPeriodSecond(&g_driverTIM);          /* Get the period of the PWM signal */
    g_measuredPwmFreq_Hz = 1 / g_measuredPwmPeriod;                             /* Calculate the frequency          */
    g_measuredPwmDutyCycle = IfxGtm_Tim_In_getDutyPercent(&g_driverTIM, &g_dataCoherent); /* Get the duty cycle     */
}
