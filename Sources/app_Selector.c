/*
 * app_Selector.c
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */

#include "AD1.h"
#include "app_Selector.h"

//uint16_t ruw_SelectorRaw;
//unsigned char rub_Mode;
//uint16_t Temperatura;
//uint16_t Luminosidad;
unsigned char rub_Jump = FALSE;
extern int factor;

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

/*
 *  Calcula el factor o índice que hay que aplicar a la periodicidad de las medidas.
 *  Valores posibles:
 *  - 0 si 0 o < 32767 cuando va creciendo
 *  - 1 si <32767 cuando va decreciendo, si 32767 o si >32767 cuando va creciendo
 *  - 2 si 65535 o si >32767 cuando va decreciendo
 */
void app_SelectorTask(void) {
	rub_Jump = FALSE;
	word valores;
	AD1_GetChanValue16(2, &valores);
	if (valores==0) factor = 0;
	else if (valores==32767) factor = 1;
	else if (valores==65535) factor = 2;
	else if (valores < 32767 && factor == 2) factor = 1;
	else if (valores > 32767 && factor == 0) factor = 1;
	else factor = factor;
}

