/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : WAIT_E1.c
**     Project     : Proyecto
**     Processor   : MK64FN1M0VLQ12
**     Component   : Wait
**     Version     : Component 01.082, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-18, 06:53, # CodeGen: 26
**     Abstract    :
**          Implements busy waiting routines.
**     Settings    :
**          Component name                                 : WAIT_E1
**          SDK                                            : MCUC_H1
**          Use Cycle Counter                              : Disabled
**          Manual Clock Values                            : Disabled
**          Delay100usFunction                             : Delay100US
**          RTOS                                           : Disabled
**          Watchdog                                       : Disabled
**     Contents    :
**         Wait10Cycles   - void WAIT_E1_Wait10Cycles(void);
**         Wait100Cycles  - void WAIT_E1_Wait100Cycles(void);
**         WaitCycles     - void WAIT_E1_WaitCycles(uint16_t cycles);
**         WaitLongCycles - void WAIT_E1_WaitLongCycles(uint32_t cycles);
**         Waitms         - void WAIT_E1_Waitms(uint16_t ms);
**         Waitus         - void WAIT_E1_Waitus(uint16_t us);
**         Waitns         - void WAIT_E1_Waitns(uint16_t ns);
**         WaitOSms       - void WAIT_E1_WaitOSms(void);
**         Init           - void WAIT_E1_Init(void);
**         DeInit         - void WAIT_E1_DeInit(void);
**
**     * Copyright (c) 2013-2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file WAIT_E1.c
** @version 01.00
** @brief
**          Implements busy waiting routines.
*/         
/*!
**  @addtogroup WAIT_E1_module WAIT_E1 module documentation
**  @{
*/         

/* MODULE WAIT_E1. */

#include "WAIT_E1.h"


/*
** ===================================================================
**     Method      :  WAIT_E1_Wait10Cycles (component Wait)
**     Description :
**         Wait for 10 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__attribute__((naked, no_instrument_function)) void WAIT_E1_Wait10Cycles(void)
{
  /* This function will wait 10 CPU cycles (including call overhead). */
  /*lint -save -e522 function lacks side effect. */
  /* NOTE: Cortex-M0 and M4 have 1 cycle for a NOP */
  /* Compiler is GNUC */
  __asm (
   /* bl Wai10Cycles() to here: [4] */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
   "bx lr \n\t" /* [3] */
  );
  /*lint -restore */
}

/*
** ===================================================================
**     Method      :  WAIT_E1_Wait100Cycles (component Wait)
**     Description :
**         Wait for 100 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__attribute__((naked, no_instrument_function)) void WAIT_E1_Wait100Cycles(void)
{
  /* This function will spend 100 CPU cycles (including call overhead). */
  /*lint -save -e522 function lacks side effect. */
  __asm (
   /* bl to here:               [4] */
   "push {r0}   \n\t"        /* [2] */
   "movs r0, #0 \n\t"        /* [1] */
   "loop:       \n\t"
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "add r0,#1   \n\t"        /* [1] */
   "cmp r0,#9   \n\t"        /* [1] */
   "bls loop    \n\t"        /* [3] taken, [1] not taken */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "pop {r0}    \n\t"        /* [2] */
   "bx lr       \n\t"        /* [3] */
  );
  /*lint -restore */
}

/*
** ===================================================================
**     Method      :  WAIT_E1_WaitCycles (component Wait)
**     Description :
**         Wait for a specified number of CPU cycles (16bit data type).
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/
void WAIT_E1_WaitCycles(uint16_t cycles)
{
  /*lint -save -e522 function lacks side effect. */
#if WAIT_E1_CONFIG_USE_CYCLE_COUNTER
  uint32_t counter = cycles;

  counter += KIN1_GetCycleCounter();
  while(KIN1_GetCycleCounter()<counter) {
    /* wait */
  }
#else
  while(cycles > 100) {
    WAIT_E1_Wait100Cycles();
    cycles -= 100;
  }
  while(cycles > 10) {
    WAIT_E1_Wait10Cycles();
    cycles -= 10;
  }
#endif
  /*lint -restore */
}

/*
** ===================================================================
**     Method      :  WAIT_E1_WaitLongCycles (component Wait)
**     Description :
**         Wait for a specified number of CPU cycles (32bit data type).
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/
void WAIT_E1_WaitLongCycles(uint32_t cycles)
{
#if WAIT_E1_CONFIG_USE_CYCLE_COUNTER
  uint32_t counter = cycles;

  counter += KIN1_GetCycleCounter();
  while(KIN1_GetCycleCounter()<counter) {
    /* wait */
  }
#else
  /*lint -save -e522 function lacks side effect. */
  while(cycles>60000) {
    WAIT_E1_WaitCycles(60000);
    cycles -= 60000;
  }
  WAIT_E1_WaitCycles((uint16_t)cycles);
  /*lint -restore */
#endif
}

/*
** ===================================================================
**     Method      :  WAIT_E1_Waitms (component Wait)
**     Description :
**         Wait for a specified time in milliseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ms              - How many milliseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/
void WAIT_E1_Waitms(uint16_t ms)
{
  /*lint -save -e522 function lacks side effect. */
  uint32_t msCycles; /* cycles for 1 ms */

  /* static clock/speed configuration */
  msCycles = WAIT_E1_NofCyclesMs(1, WAIT_E1_INSTR_CLOCK_HZ);
  while(ms>0) {
    WAIT_E1_WaitLongCycles(msCycles);
    ms--;
  }
  /*lint -restore */
}
/*
** ===================================================================
**     Method      :  WAIT_E1_Waitus (component Wait)
**     Description :
**         Wait for a specified time in microseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - How many microseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/
/* implemented as macro version. See header file. */
/*
** ===================================================================
**     Method      :  WAIT_E1_Waitns (component Wait)
**     Description :
**         Wait for a specified time in nano seconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ns              - How many ns the function has to wait
**     Returns     : Nothing
** ===================================================================
*/
/* implemented as macro version. See header file. */
/*
** ===================================================================
**     Method      :  WAIT_E1_WaitOSms (component Wait)
**     Description :
**         If an RTOS is enabled, this routine will use a non-blocking
**         wait method. Otherwise it will do a busy/blocking wait.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void WAIT_E1_WaitOSms(void)
{
  Method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  WAIT_E1_Init (component Wait)
**     Description :
**         Driver initialization routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void WAIT_E1_Init(void)
{
#if WAIT_E1_CONFIG_USE_CYCLE_COUNTER
  /* init cycle counter */
  KIN1_InitCycleCounter();
  KIN1_ResetCycleCounter();
  KIN1_EnableCycleCounter();
#endif
}

/*
** ===================================================================
**     Method      :  WAIT_E1_DeInit (component Wait)
**     Description :
**         Driver de-initialization routine
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void WAIT_E1_DeInit(void)
{
#if WAIT_E1_CONFIG_USE_CYCLE_COUNTER
  /* disable hardware cycle counter */
  KIN1_DisableCycleCounter();
#endif
}

/* END WAIT_E1. */

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