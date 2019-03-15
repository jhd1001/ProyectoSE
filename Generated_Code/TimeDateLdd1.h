/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TimeDateLdd1.h
**     Project     : Proyecto
**     Processor   : MK64FN1M0VLQ12
**     Component   : TimeDate_LDD
**     Version     : Component 01.007, Driver 01.01, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-15, 17:36, # CodeGen: 1
**     Abstract    :
**          This component "TimeDate_LDD" implements real time and date.
**          The component requires a periodic interrupt generator: timer
**          compare or reload register or timer-overflow interrupt
**          (of free running counter). User can select precision of
**          selected timer.
**          The component supports alarm with event OnAlarm and every second
**          event OnSecond is also available.
**          This TimeDate component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : TimeDateLdd1
**          Periodic interrupt source                      : FTM0_MOD
**          Counter                                        : FTM0_CNT
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM0
**            Interrupt priority                           : medium priority
**          Resolution                                     : 25 ms
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Time                                         : 00:00:00
**            Date                                         : 2008-01-01
**            Alarm time                                   : 00:00:00
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnAlarm                                    : Disabled
**              OnSecond                                   : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked TimerUnit                             : TU1
**     Contents    :
**         Init    - LDD_TDeviceData* TimeDateLdd1_Init(LDD_TUserData *UserDataPtr);
**         SetTime - LDD_TError TimeDateLdd1_SetTime(LDD_TDeviceData *DeviceDataPtr,...
**         GetTime - LDD_TError TimeDateLdd1_GetTime(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file TimeDateLdd1.h
** @version 01.01
** @brief
**          This component "TimeDate_LDD" implements real time and date.
**          The component requires a periodic interrupt generator: timer
**          compare or reload register or timer-overflow interrupt
**          (of free running counter). User can select precision of
**          selected timer.
**          The component supports alarm with event OnAlarm and every second
**          event OnSecond is also available.
**          This TimeDate component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup TimeDateLdd1_module TimeDateLdd1 module documentation
**  @{
*/         

#ifndef __TimeDateLdd1_H
#define __TimeDateLdd1_H

/* MODULE TimeDateLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TU1.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TimeDateLdd1_PRPH_BASE_ADDRESS  0x40038000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define TimeDateLdd1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_TimeDateLdd1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define TimeDateLdd1_Init_METHOD_ENABLED /*!< Init method of the component TimeDateLdd1 is enabled (generated) */
#define TimeDateLdd1_SetTime_METHOD_ENABLED /*!< SetTime method of the component TimeDateLdd1 is enabled (generated) */
#define TimeDateLdd1_GetTime_METHOD_ENABLED /*!< GetTime method of the component TimeDateLdd1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */



/*
** ===================================================================
**     Method      :  TimeDateLdd1_Init (component TimeDate_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* TimeDateLdd1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  TimeDateLdd1_SetTime (component TimeDate_LDD)
*/
/*!
**     @brief
**         Sets new time.
**         Note: All LDD_TimeDate_TTimeRec structure members must be
**         correctly filled in.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @param
**         TimePtr         - Pointer to the time structure with
**                           new time to set.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError TimeDateLdd1_SetTime(LDD_TDeviceData *DeviceDataPtr, LDD_TimeDate_TTimeRec *TimePtr);

/*
** ===================================================================
**     Method      :  TimeDateLdd1_GetTime (component TimeDate_LDD)
*/
/*!
**     @brief
**         Returns actual time.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @param
**         TimePtr         - Pointer to the time structure to
**                           fill with current time.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TimeDateLdd1_GetTime(LDD_TDeviceData *DeviceDataPtr, LDD_TimeDate_TTimeRec *TimePtr);

/*
** ===================================================================
**     Method      :  TimeDateLdd1_TU1_OnCounterRestart (component TimeDate_LDD)
**
**     Description :
**         The method services the event of the linked component TU1 and 
**         eventually invokes event OnAlarm and OnSecond.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr);

/* END TimeDateLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TimeDateLdd1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
