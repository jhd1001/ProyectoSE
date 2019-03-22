/*
 * app_Temp.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */


#include "AD1.h"
#include "AS1.h"
#include "app_Selector.h"
#include "app_Temp.h"
#include "UART.h"

static unsigned char	rub_CallTimes = 0u;
static char TemperaturaText[] = "Temperatura: ";

void app_TempTask(void)
{
	if(rub_CallTimes > raub_TempExecTime[rub_Mode])
	{
		rub_CallTimes = 0u;
		rub_Jump |= TRUE;

		word env;
		AS1_SendBlock(TemperaturaText,sizeof(TemperaturaText)-1u,&env);
		SendNum(Temperatura);
		AS1_SendChar(0xB0);
		AS1_SendChar(' ');
	}
	else
	{
		rub_CallTimes++;
	}

}
