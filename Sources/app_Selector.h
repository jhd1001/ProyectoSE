/*
 * app_Selector.h
 *
 *  Created on: 22/03/2019
 *      Author: Admin
 */

#ifndef SOURCES_APP_SELECTOR_H_
#define SOURCES_APP_SELECTOR_H_

#define N_MODES	3u

extern unsigned char raub_AccelExecTime[N_MODES];
extern unsigned char raub_TempExecTime[N_MODES];
extern unsigned char raub_LumExecTime[N_MODES];
extern unsigned char rub_Mode;

extern uint16_t Temperatura;
extern uint16_t Luminosidad;
extern unsigned char rub_Jump;

extern void app_SelectorTask(void);

#endif /* SOURCES_APP_SELECTOR_H_ */
