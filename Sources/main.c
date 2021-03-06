/* ###################################################################
**     Filename    : main.c
**     Project     : Proyecto
**     Processor   : MK64FN1M0VLQ12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-14, 10:29, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "TmDt_H1.h"
#include "TimeDateLdd1.h"
#include "TU_H1.h"
#include "UTIL_H1.h"
#include "MCUC_H1.h"
#include "ExtIntLdd1.h"
#include "TI_H1.h"
#include "TimerIntLdd1.h"
#include "RealTimeLdd1.h"
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
#include "TU_E1.h"
#include "GI2C1.h"
#include "WAIT1.h"
#include "CI2C1.h"
#include "TU1.h"
#include "TU_E1.h"
#include "Tick.h"
#include "TimerIntLdd3.h"
#include "FX1.h"
#include "AD1.h"
#include "AdcLdd3.h"
#include "Bit_E1.h"
#include "BitIoLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdio.h"
#include "JHA.h"
#include "AEX.h"
#include "app_Accel.h"
#include "app_Lum.h"
#include "app_Selector.h"
#include "app_Temp.h"

unsigned char ISR_FLAG;
uint16_t x, y, z;
uint16_t Luminosidad;
uint16_t Temperatura;

static FAT_E1_FATFS fileSystemObject;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* SD card detection: PTE6 with pull-down! */

  PORT_PDD_SetPinPullSelect(PORTE_BASE_PTR, 6, PORT_PDD_PULL_DOWN);
  PORT_PDD_SetPinPullEnable(PORTE_BASE_PTR, 6, PORT_PDD_PULL_ENABLE);
  if (FAT_E1_Init()!=ERR_OK) return -1; /* initialize FAT driver */
  if (FAT_E1_mount(&fileSystemObject, (const TCHAR*)"0", 1) != FR_OK) return -1; /* mount file system */

  JHA_Run(); // inicializa valores de potenciometro
  FX1_Enable(); // inicializa el acelerometro

  for(;;) {

		if (ISR_FLAG) {
			ISR_FLAG = FALSE;

			if (app_AccelTask()) { // se ha medido el acelerómetro
				bool tempOK = app_TempTask(); // se mide la temperatura
				bool lumOK = app_LumTask(); // se mide la luminosidad
				if (tempOK && lumOK)
					LogToSDCardLT(x*100/0xFFFF, y*100/0xFFFF, z*100/0xFFFF, Luminosidad, Temperatura);
				else if (tempOK)
					LogToSDCardT(x*100/0xFFFF, y*100/0xFFFF, z*100/0xFFFF, Temperatura);
				else if (lumOK)
					LogToSDCardL(x*100/0xFFFF, y*100/0xFFFF, z*100/0xFFFF, Luminosidad);
				else
					LogToSDCard(x*100/0xFFFF, y*100/0xFFFF, z*100/0xFFFF);
			}
		}
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
