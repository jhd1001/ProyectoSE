/* ###################################################################
**     Filename    : Events.h
**     Project     : Proyecto
**     Processor   : MK64FN1M0VLQ12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-14, 10:29, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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
<<<<<<< HEAD
#include "AD_H2.h"
#include "AdcLdd2.h"
#include "TI_H2.h"
#include "TimerIntLdd2.h"
#include "TU1.h"
=======
#include "Bit_E1.h"
#include "BitIoLdd1.h"
>>>>>>> bf8b829d402269c68ce878df1cf79215699ec76e

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK64FN1M0LQ12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void);


/*
** ===================================================================
**     Event       :  TI_H1_OnInterrupt (module Events)
**
**     Component   :  TI_H1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI_H1_OnInterrupt(void);

void AD_H1_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD_H1_OnEnd (module Events)
**
**     Component   :  AD_H1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD_H1_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  AD_H1_OnCalibrationEnd (module Events)
**
**     Component   :  AD_H1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt_H1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt_H1_OnInterrupt (module Events)
**
**     Component   :  EInt_H1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  AS_H1_OnError (module Events)
**
**     Component   :  AS_H1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS_H1_OnError(void);

/*
** ===================================================================
**     Event       :  AS_H1_OnRxChar (module Events)
**
**     Component   :  AS_H1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS_H1_OnRxChar(void);

/*
** ===================================================================
**     Event       :  AS_H1_OnTxChar (module Events)
**
**     Component   :  AS_H1 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS_H1_OnTxChar(void);

/*
** ===================================================================
**     Event       :  AS_H1_OnFreeTxBuf (module Events)
**
**     Component   :  AS_H1 [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS_H1_OnFreeTxBuf(void);

/*
** ===================================================================
**     Event       :  AS_H1_OnFullRxBuf (module Events)
**
**     Component   :  AS_H1 [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS_H1_OnFullRxBuf(void);

/*
** ===================================================================
**     Event       :  SM_E1_OnBlockSent (module Events)
**
**     Component   :  SM_E1 [SPIMaster_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SM_E1_OnBlockSent(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  TI_H2_OnInterrupt (module Events)
**
**     Component   :  TI_H2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI_H2_OnInterrupt(void);

void AD_H2_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD_H2_OnEnd (module Events)
**
**     Component   :  AD_H2 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD_H2_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  AD_H2_OnCalibrationEnd (module Events)
**
**     Component   :  AD_H2 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
