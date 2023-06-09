/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_hal.h

  Summary:
    Header file for hardware abstraction

  Description:
    This file contains the function mapping and channel mapping to provide
    hardware abstraction layer for motor control algorithm
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef MCHAL_H    // Guards against multiple inclusion
#define MCHAL_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "definitions.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

/****************************** PWM ***********************************************************/
#define MCHAL_PWM_PH_U                  MCPWM_CH_1
#define MCHAL_PWM_PH_V                  MCPWM_CH_2
#define MCHAL_PWM_PH_W                  MCPWM_CH_3
#define MCHAL_PWM_PH_MASK               0xe
#define MCHAL_PWMStop(mask)                 MCPWM_Stop()
#define MCHAL_PWMStart(mask)                MCPWM_Start()
#define MCHAL_PWMPrimaryPeriodGet(ch)       MCPWM_PrimaryPeriodGet()
#define MCHAL_PWMDutySet(ch, duty)          MCPWM_ChannelPrimaryDutySet(ch, duty)
#define MCHAL_PWMOutputDisable(ch)          MCPWM_ChannelPinsOwnershipDisable(ch)
#define MCHAL_PWMOutputEnable(ch)           MCPWM_ChannelPinsOwnershipEnable(ch)
#define MCHAL_PWMCallbackRegister(ch, fn, context)  MCPWM_CallbackRegister(ch, fn, context)


/**************************************** ADC ***************************************************/
#define MCHAL_ADC_PH_U                                   ADCHS_CH0
#define MCHAL_ADC_PH_V                                   ADCHS_CH4
#define MCHAL_ADC_PH_W
#define MCHAL_ADC_VDC                                    ADCHS_CH10
#define MCHAL_ADC_POT                                    ADCHS_CH15

#define MCHAL_ADC_RESULT_SHIFT                           0
#define MCHAL_ADCCallbackRegister(ch, fn, context)       ADCHS_CallbackRegister(ch, fn, context)
#define MCHAL_ADCChannelConversionStart(ch)              ADCHS_ChannelConversionStart(ch)
#define MCHAL_ADCPhaseUResultGet(ch)                     ADCHS_ChannelResultGet(ch)
#define MCHAL_ADCPhaseVResultGet(ch)                     ADCHS_ChannelResultGet(ch)
#define MCHAL_ADCPotResultGet(ch)                        ADCHS_ChannelResultGet(ch)
#define MCHAL_ADCVdcResultGet(ch)                        ADCHS_ChannelResultGet(ch)
#define MCHAL_ADCChannelResultIsReady(ch)                ADCHS_ChannelResultIsReady(ch)
#define MCHAL_ADCEnable( )                              
#define MCHAL_ADCDisable( )                             




/************************************ Interrupt *********************************************/
#define MCHAL_CTRL_IRQ              (INT_SOURCE_ADC_DATA0)
#define MCHAL_FAULT_IRQ             (INT_SOURCE_PWM1)

#define MCHAL_IntDisable(irq)       EVIC_SourceDisable(irq)
#define MCHAL_IntEnable(irq)        EVIC_SourceEnable(irq)
#define MCHAL_IntClear(irq)         EVIC_SourceStatusClear(irq)


/******************************* LED and Switches *******************************************/

#define MCHAL_FAULT_LED_SET()       GPIO_RG15_Set()
#define MCHAL_FAULT_LED_CLEAR()     GPIO_RG15_Clear()
#define MCHAL_FAULT_LED_TOGGLE()    GPIO_RG15_Toggle()

#define MCHAL_DIR_LED_SET()         GPIO_RF5_Set()
#define MCHAL_DIR_LED_CLEAR()       GPIO_RF5_Clear()
#define MCHAL_DIR_LED_TOGGLE()      GPIO_RF5_Toggle()

#define MCHAL_DIR_SWITCH_GET()         GPIO_RC7_Get()

#define MCHAL_START_STOP_SWITCH_GET()  GPIO_RG1_Get()

/***************************** X2CScope **************************************************/
#define MCHAL_X2C_Update()          X2CScope_Update()

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCINF_H

/**
 End of File
*/
