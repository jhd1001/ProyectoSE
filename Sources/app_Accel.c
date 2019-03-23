/*
 * app_Accel.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */
#include "FX1.h"
#include "app_Accel.h"
#include "app_Selector.h"

static unsigned char	rub_CallTimes = 0u;
extern uint16_t x, y, z;
extern int factor;

bool app_AccelTask(void)
{
	//Revisa si ha pasado el timpo para ejecutarse
	if(rub_CallTimes > raub_AccelExecTime[factor])
	{
		rub_CallTimes = 0u;
		rub_Jump |= TRUE;

		x = FX1_MeasureGetRawX();
		y = FX1_MeasureGetRawY();
		z = FX1_MeasureGetRawZ();
		return TRUE;

	}
	else
	{
		rub_CallTimes++;
		return FALSE;
	}
}
