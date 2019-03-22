/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
//#include "JHA.h"
int tics_Temperatura = 0;
double factor = 1.0;

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
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

// cada 25 ms mide el potenciometro (CANAL 0)
void TI_H1_OnInterrupt(void) {
	AD_H1_MeasureChan(FALSE, 0);
}

// cada 0.5 por el factor s. se miden las entradas
void TI_H2_OnInterrupt(void) {
	// se incrementan los contadores de los tics
	tics_Temperatura++;

	// para la temperatura, se mide cada 5 * 2 / factor tics. 5*2 porque el timer está cada 0.5 s
	// y la medición base de temperatura debe ser cada 5 s.
	if (tics_Temperatura > ((5 * 2 / factor) - 1)) {
		AD_H2_MeasureChan(FALSE, 0);
		tics_Temperatura = 0;
	}
}

// Interrupción del potenciomento, medida disponible
void AD_H1_OnEnd(void) {
	JHA_Factoriza();
}

// Interrupción del sensor de temperatura (AD_H2, canal 0)
void AD_H2_OnEnd(void) {
	JHA_Temperatura();
}

// se produce una interrupción en el pulsador D12
// se pulsa o se suelta
void EInt_H1_OnInterrupt(void) {
	JHA_SetHora();
}

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
void AD_H1_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

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
void AS_H1_OnError(void)
{
  /* Write your code here ... */
}

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
void AS_H1_OnRxChar(void)
{
  /* Write your code here ... */
}

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
void AS_H1_OnTxChar(void)
{
  /* Write your code here ... */
}

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
void AS_H1_OnFreeTxBuf(void)
{
	printf("ultimo caracter transmitido\r\n");
  /* Write your code here ... */
}

void AS_H1_OnFullRxBuf(void) {
	JHA_OnFullRxBuf();
}

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
void SM_E1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

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
void AD_H2_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
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
