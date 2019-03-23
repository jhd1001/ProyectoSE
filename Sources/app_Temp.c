/*
 * app_Temp.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */


#include "AD1.h"
#include "app_Selector.h"
#include "app_Temp.h"

static unsigned char	rub_CallTimes = 0u;
extern int factor;
extern uint16_t Temperatura;

uint16_t rauw_ADCRaw;


bool app_TempTask(void)
{
	if(rub_CallTimes > raub_TempExecTime[factor])
	{
		rub_CallTimes = 0u;
		rub_Jump |= TRUE;

		// mide la temperatura
		AD1_MeasureChan(TRUE,0);
		(void)AD1_GetChanValue16(0, &rauw_ADCRaw);
		Temperatura = rauw_ADCRaw / 200u;
		return TRUE;
	}
	else
	{
		rub_CallTimes++;
		return FALSE;
	}

}
