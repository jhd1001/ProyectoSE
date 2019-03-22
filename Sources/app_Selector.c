/*
 * app_Selector.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */

#include "SELECT.h"
#include "AD1.h"
#include "app_Selector.h"

static uint16_t rauw_ADCRaw[2u];
uint16_t ruw_SelectorRaw;
unsigned char rub_Mode;
uint16_t Temperatura;
uint16_t Luminosidad;
unsigned char rub_Jump = FALSE;

unsigned char raub_AccelExecTime[N_MODES] =
{
		0,
		1,
		3
};

unsigned char raub_TempExecTime[N_MODES] =
{
		4,
		9,
		19
};

unsigned char raub_LumExecTime[N_MODES] =
{
		1,
		3,
		7
};

void app_SelectorTask(void)
{
	rub_Jump = FALSE;

	SELECT_Measure(TRUE);
	SELECT_GetValue16(&ruw_SelectorRaw);
	if(ruw_SelectorRaw < 30000)
	{
		rub_Mode = 0u;
	}
	else if(ruw_SelectorRaw > 60000)
	{
		rub_Mode = 2u;
	}
	else
	{
		rub_Mode = 1u;
	}

	AD1_Measure(TRUE);
	(void)AD1_GetValue16(rauw_ADCRaw);
	Temperatura = rauw_ADCRaw[0u] / 200u;
	Luminosidad = rauw_ADCRaw[1u] / 655u;
}
