/*
 * app_Lum.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */


#include "AD1.h"
#include "AS1.h"
#include "app_Lum.h"
#include "app_Selector.h"
#include "UART.h"


static unsigned char	rub_CallTimes = 0u;
char LuminosidadText[] = "Luminosidad: ";

void app_LumTask(void)
{
	if(rub_CallTimes >= raub_LumExecTime[rub_Mode])
	{
		rub_CallTimes = 0u;
		rub_Jump |= TRUE;

		word env;
		AS1_SendBlock(LuminosidadText,sizeof(LuminosidadText)-1u,&env);
		SendNum(Luminosidad);
		AS1_SendChar(0x25);
		AS1_SendChar(' ');
	}
	else
	{
		rub_CallTimes++;
	}
}
