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

int LogToSDCard(int16_t x, int16_t y, int16_t z);
int LogToSDCardL(int16_t x, int16_t y, int16_t z, int16_t luminocidad);
int LogToSDCardT(int16_t x, int16_t y, int16_t z, int16_t temperatura);
int LogToSDCardLT(int16_t x, int16_t y, int16_t z, int16_t luminocidad, int16_t temperatura);

#endif /* SOURCES_AEX_H_ */
