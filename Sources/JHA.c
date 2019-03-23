/*
 * JHA.c
 *
 *  Created on: 15/3/2019
 *      Author: jhuidobro
 */

#include "TmDt_H1.h"
#include "TimeDateLdd1.h"
#include "TU_H1.h"
#include "UTIL_H1.h"
#include "Events.h"
#include "JHA.h"

TIMEREC hora; // hora del sistema
uint8_t write_buf[12]; // mensaje de la hora del sistema
extern int factor; // factor aplicable a toma de medidas
char *mensaje = "introduzca la hora (hh:mm): ";
char *mensaje2 = "Reloj establecido";
char datos[5];
bool recibir;

void parseHora(char *datos, TIMEREC *hora) {
	char h[] = {datos[0],datos[1],'\0'};
	hora->Hour = atoi(h);
	char m[] = {datos[3],datos[4],'\0'};
	hora->Min = atoi(m);
	hora->Sec = 0;
	hora->Sec100 = 0;
}

/*
 * Trata la interrupción de llenado del buffer de entrada. Se produce cuando se han tecleado 5 caracteres
 * en el terminal.
 */
void JHA_OnFullRxBuf() {
	// solo tomará en cuenta el contenido del buffer si se ha activado la recepción
	// desde la función JHA_SetHora (recibir = TRUE)
	if (recibir) {
		word Recibido, env;
		// carga en datos el contenido del buffer
		AS_H1_RecvBlock((byte*)&datos, sizeof(datos), &Recibido);
		// transforma lo tecleado en la hora
		parseHora(&datos, &hora);
		// y establece la hora del sistema
		TmDt_H1_SetTime(hora.Hour, hora.Min, hora.Sec, hora.Sec100);
		// desactiva la recepción evitando que nuevas pulsaciones cambien
		// indeseadamente la hora
		recibir = FALSE;
		// y emite un mensaje de que la hora ha sido cambiada.
		while (AS_H1_SendBlock(mensaje2, strlen(mensaje2),&env)!=ERR_OK) {}
	}
}

/*
 * Función que trata el establecimiento de la hora mediante el pulsador D4
 * Cuando se presiona D4, se resetea el contador FC16_H1
 * Cuando se suelta D4, se mira el valor del contador. Si es mayor de 2000 ms,
 * se limpian los buffers de entrada y salida del puerto serie, se manda un mensaje
 * para que se introduzca la nueva hora y activa la recepción
 */
void JHA_SetHora(void) {
	word time;
	byte hour, min, sec, sec100;
	word env;

	// si se pulsa D4, se activa el contador de tiempo (2 segs)
	if (EInt_H1_GetVal()) {
		FC16_H1_Reset();
	}
	// si se suelta D4, y el tiempo transcurrido es
	// más de 2 segundos, se solicita la hora
	else {
		// se obtiene el valor del contador
		FC16_H1_GetTimeMS(&time);
		if (time>=2000) { // si han pasado más de 2000 ms
			// se limpian los buffers
			AS_H1_ClearTxBuf();
			AS_H1_ClearRxBuf();
			// se manda mensaje a la terminal
			while (AS_H1_SendBlock(mensaje, strlen(mensaje),&env)!=ERR_OK) {}
			// y se activa la recepción por interrupción
			recibir = TRUE;
		}
	}

}

void JHA_Run(void) {
	TmDt_H1_SetTime(0,0,0,0);
	factor = 1;
	recibir = FALSE;
}

char * getHora(void) {
	write_buf[0] = '\0';
	if (TmDt_H1_GetTime(&hora)!=ERR_OK) {
		return write_buf;
	}
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Hour);
	UTIL_H1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Min);
	UTIL_H1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Sec);
	UTIL_H1_chcat(write_buf, sizeof(write_buf), ':');
	UTIL_H1_strcatNum8u(write_buf, sizeof(write_buf), hora.Sec100);
	return write_buf;
}
