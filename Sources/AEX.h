/*
 * AEX.h
 *
 *  Created on: 18/3/2019
 *      Author: aepikhin
 */

#ifndef SOURCES_AEX_H_
#define SOURCES_AEX_H_

#include "UTIL_H1.h"
#include "Events.h"
#include "JHA.h"
#include "Bit_E1.h"

/*
 * Cierra el fichero y apaga el led rojo.
 */
void CloseFP();

/*
 * Compone un mensaje y lo escribe en la tarjeta SD.
 * @param x: X del acelerómetro
 * @param y: Y del acelerómetro
 * @param z: Z del acelerómetro
 */
int LogToSDCard(int16_t x, int16_t y, int16_t z);

/*
 * Compone un mensaje y lo escribe en la tarjeta SD.
 * @param x: X del acelerómetro
 * @param y: Y del acelerómetro
 * @param z: Z del acelerómetro
 * @param luminocidad: Valor del sensor infrarojo
 */
int LogToSDCardL(int16_t x, int16_t y, int16_t z, int16_t luminocidad);

/*
 * Compone un mensaje y lo escribe en la tarjeta SD.
 * @param x: X del acelerómetro
 * @param y: Y del acelerómetro
 * @param z: Z del acelerómetro
 * @param temperatura: Valor del sensor de la temperatura
 */
int LogToSDCardT(int16_t x, int16_t y, int16_t z, int16_t temperatura);

/*
 * Compone un mensaje y lo escribe en la tarjeta SD.
 * @param x: X del acelerómetro
 * @param y: Y del acelerómetro
 * @param z: Z del acelerómetro
 * @param luminocidad: Valor del sensor infrarojo
 * @param temperatura: Valor del sensor de la temperatura
 */
int LogToSDCardLT(int16_t x, int16_t y, int16_t z, int16_t luminocidad, int16_t temperatura);

#endif /* SOURCES_AEX_H_ */
