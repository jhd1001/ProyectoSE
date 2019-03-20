/*
 * AEX.c
 *
 *  Created on: 18/3/2019
 *      Author: aepikhin
 */

#include <AEX.h>

FIL fp;

void CloseFP()
{
	(void)FAT_E1_close(&fp); // cierra el fichero
	Bit_E1_PutVal(0); // apaga la luz roja
}

int LogToSDCard(int16_t x, int16_t y, int16_t z)
{
	uint8_t write_buf[80];
	UINT bw;
	if (FAT_E1_open(&fp, "./log.txt", FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) return -1; // abre el fichero
	if (FAT_E1_lseek(&fp, f_size(&fp)) != FR_OK || fp.fptr != f_size(&fp)) return -1; // se coloca al final del fichero
	strcpy(write_buf, getHora()); // obtiene la hora

	// compone el mensaje
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tX:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), x);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tY:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), y);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tZ:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), z);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\r\n");

	Bit_E1_PutVal(1); // enciende la luz roja
	if (FAT_E1_write(&fp, write_buf, UTIL_H1_strlen((char*)write_buf), &bw)!=FR_OK) // escribe en la tarjeta
	{
		CloseFP();
		return -1;
	}
	CloseFP();
	return 0;
}

int LogToSDCardL(int16_t x, int16_t y, int16_t z, int16_t luminocidad)
{
	uint8_t write_buf[80];
	UINT bw;
	if (FAT_E1_open(&fp, "./log.txt", FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) return -1; // abre el fichero
	if (FAT_E1_lseek(&fp, f_size(&fp)) != FR_OK || fp.fptr != f_size(&fp)) return -1; // se coloca al final del fichero
	strcpy(write_buf, getHora()); // obtiene la hora

	// compone el mensaje
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tX:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), x);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tY:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), y);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tZ:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), z);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tLuminosidad:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), luminocidad);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\r\n");

	Bit_E1_PutVal(1); // enciende la luz roja
	if (FAT_E1_write(&fp, write_buf, UTIL_H1_strlen((char*)write_buf), &bw)!=FR_OK) // escribe en la tarjeta
	{
		CloseFP();
		return -1;
	}
	CloseFP();
	return 0;
}

int LogToSDCardT(int16_t x, int16_t y, int16_t z, int16_t temperatura)
{
	uint8_t write_buf[80];
	UINT bw;
	if (FAT_E1_open(&fp, "./log.txt", FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) return -1; // abre el fichero
	if (FAT_E1_lseek(&fp, f_size(&fp)) != FR_OK || fp.fptr != f_size(&fp)) return -1; // se coloca al final del fichero
	strcpy(write_buf, getHora()); // obtiene la hora

	// compone el mensaje
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tX:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), x);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tY:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), y);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tZ:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), z);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tTemperatura:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), temperatura);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"ºC\r\n");

	Bit_E1_PutVal(1); // enciende la luz roja
	if (FAT_E1_write(&fp, write_buf, UTIL_H1_strlen((char*)write_buf), &bw)!=FR_OK) // escribe en la tarjeta
	{
		CloseFP();
		return -1;
	}
	CloseFP();
	return 0;
}

int LogToSDCardLT(int16_t x, int16_t y, int16_t z, int16_t luminocidad, int16_t temperatura)
{
	uint8_t write_buf[80];
	UINT bw;
	if (FAT_E1_open(&fp, "./log.txt", FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) return -1; // abre el fichero
	if (FAT_E1_lseek(&fp, f_size(&fp)) != FR_OK || fp.fptr != f_size(&fp)) return -1; // se coloca al final del fichero
	strcpy(write_buf, getHora()); // obtiene la hora

	// compone el mensaje
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tX:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), x);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tY:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), y);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tZ:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), z);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tLuminosidad:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), luminocidad);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"\tTemperatura:");
	UTIL_H1_strcatNum16s(write_buf, sizeof(write_buf), temperatura);
	UTIL_H1_strcat(write_buf, sizeof(write_buf), (unsigned char*)"ºC\r\n");

	Bit_E1_PutVal(1); // enciende la luz roja
	if (FAT_E1_write(&fp, write_buf, UTIL_H1_strlen((char*)write_buf), &bw)!=FR_OK) // escribe en la tarjeta
	{
		CloseFP();
		return -1;
	}
	CloseFP();
	return 0;
}
