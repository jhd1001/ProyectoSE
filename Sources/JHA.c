/*
 * JHA.c
 *
 *  Created on: 15/3/2019
 *      Author: jhuidobro
 */

#include "TmDt_H1.h"
#include "TimeDateLdd1.h"
#include "TU1.h"
#include "UTIL_H1.h"
#include "Events.h"
#include "JHA.h"

TIMEREC hora; // hora del sistema
uint8_t write_buf[12]; // mensaje de la hora del sistema
double factor = 1.0; // factor aplicable a toma de medidas

double getFactor(void) {
	return factor;
}

/*
 *  Calcula el factor que hay que aplicar a la periodicidad de las medidas.
 *  Valores posibles:
 *  - 0.5 si 0 o < 32767 cuando va creciendo
 *  - 1.0 si <32767 cuando va decreciendo, si 32767 o si >32767 cuando va creciendo
 *  - 2.0 si 65535 o si >32767 cuando va decreciendo
 */
void JHA_Factoriza(void) {
	word valores;
	AD_H1_GetValue16(&valores);
	if (valores==0) factor = 0.5;
	else if (valores==32767) factor = 1.0;
	else if (valores==65535) factor = 2.0;
	else if (valores < 32767 && factor == 2.0) factor = 1.0;
	else if (valores > 32767 && factor == 0.5) factor = 1.0;
	else factor = factor;
}

void JHA_Run(void) {
	TmDt_H1_SetTime(0,0,0,0);
	factor = 1.0;
}

char * getHora(void) {
	if (TmDt_H1_GetTime(&hora)!=ERR_OK) {
		//Err();
	}
	write_buf[0] = '\0';
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Hour);
	UTIL_H1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Min);
	UTIL_H1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Sec);
	UTIL_H1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Sec100);
	return write_buf;
}
