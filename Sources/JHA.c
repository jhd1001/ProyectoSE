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
#include "JHA.h"

TIMEREC hora;
uint8_t write_buf[12];


void JHA_Run(void) {
	TmDt_H1_SetTime(0,0,0,0);
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
