#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "delayMS.h"




void ajustementPWM(uint8_t rapportPWM);
void initialiserPort(char port, uint8_t mode);
void signalPWM(uint8_t rapportPWM, uint16_t tempsMS,char port, uint8_t mode);
void tourner(uint8_t d4, uint8_t d5);