/*
 * app_Accel.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */
#include "FX1.h"
#include "AS1.h"
#include "app_Accel.h"
#include "app_Selector.h"
#include "UART.h"

// se inicializa en el eje W (previo al eje X)
char eje = 'W';
static unsigned char	rub_CallTimes = 0u;
static uint16_t x, y, z;

void app_AccelTask(void)
{
	//Revisa si ha pasado el timpo para ejecutarse
	if(rub_CallTimes >= rub_Mode)
	{
		rub_CallTimes = 0u;
		rub_Jump |= TRUE;

		x = FX1_MeasureGetRawX();
		y = FX1_MeasureGetRawY();
		z = FX1_MeasureGetRawZ();
		UART_Write_Numero_Int('X', x*100/0xFFFF, FALSE);
		UART_Write_Numero_Int('Y', y*100/0xFFFF, FALSE);
		UART_Write_Numero_Int('Z', z*100/0xFFFF, TRUE);

	}
	else
	{
		rub_CallTimes++;
	}
}
