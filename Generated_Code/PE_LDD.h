/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PE_LDD.h
**     Project     : Proyecto
**     Processor   : MK64FN1M0VLQ12
**     Version     : Component 01.046, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-18, 06:53, # CodeGen: 26
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
** @file PE_LDD.h                                                  
** @version 01.00
*/         
/*!
**  @addtogroup PE_LDD_module PE_LDD module documentation
**  @{
*/         
#ifndef __PE_LDD_H
#define __PE_LDD_H

/* MODULE PE_LDD. */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "TmDt_H1.h"
#include "TimeDateLdd1.h"
#include "TU_H1.h"
#include "UTIL_H1.h"
#include "MCUC_H1.h"
#include "AD_H1.h"
#include "AdcLdd1.h"
#include "TI_H1.h"
#include "TimerIntLdd1.h"
#include "TU_H2.h"
#include "EInt_H1.h"
#include "ExtIntLdd1.h"
#include "FC16_H1.h"
#include "RealTimeLdd1.h"
#include "TU_H3.h"
#include "AS_H1.h"
#include "ASerialLdd1.h"
#include "FAT_E1.h"
#include "SD_E1.h"
#include "SS1.h"
#include "CD1.h"
#include "WAIT_E1.h"
#include "TMOUT_E1.h"
#include "CS_E1.h"
#include "SM_E1.h"


/*
** ===================================================================
** Function prototypes
** ===================================================================
*/

/*
** ===================================================================
**     Method      :  Cpu_PE_FillMemory (component MK64FN1M0LQ12)
*/
/*!
**     @brief
**         Fills a memory area block by a specified value.
**     @param
**       SourceAddressPtr - Source address pointer.
**     @param
**       c - A value used to fill a memory block.
**     @param
**       len - Length of a memory block to fill.
*/
/* ===================================================================*/
void PE_FillMemory(register void* SourceAddressPtr, register uint8_t c, register uint32_t len);

/*
** ===================================================================
**     Method      :  Cpu_PE_PeripheralUsed (component MK64FN1M0LQ12)
*/
/*!
**     @brief
**         Returns information whether a peripheral is allocated by PEx 
**         or not.
**     @param
**       PrphBaseAddress - Base address of a peripheral.
**     @return
**       TRUE if a peripheral is used by PEx or FALSE if it isn't used.
*/
/* ===================================================================*/
bool PE_PeripheralUsed(uint32_t PrphBaseAddress);

/*
** ===================================================================
**     Method      :  Cpu_LDD_SetClockConfiguration (component MK64FN1M0LQ12)
*/
/*!
**     @brief
**         Changes the clock configuration of all LDD components in a 
**         project.
**     @param
**       ClockConfiguration - New CPU clock configuration changed by CPU SetClockConfiguration method.
*/
/* ===================================================================*/
void LDD_SetClockConfiguration(LDD_TClockConfiguration ClockConfiguration);

/* END PE_LDD. */


#endif

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
