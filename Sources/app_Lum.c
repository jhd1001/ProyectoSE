/*
 * app_Lum.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */


#include "AD1.h"
#include "app_Lum.h"
#include "app_Selector.h"


static unsigned char	rub_CallTimes = 0u;
uint16_t rauw_ADCRaw;
extern int factor;
extern uint16_t Luminosidad;


bool app_LumTask(void)
{
	if(rub_CallTimes >= raub_LumExecTime[factor])
	{
		rub_CallTimes = 0u;
		rub_Jump |= TRUE;

		// mide la temperatura
		AD1_MeasureChan(TRUE,1);
		(void)AD1_GetChanValue16(1, &rauw_ADCRaw);
		Luminosidad = rauw_ADCRaw / 655u;
		return TRUE;
	}
	else
	{
		rub_CallTimes++;
		return FALSE;
	}
}
