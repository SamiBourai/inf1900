#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "delayMS.h"




void ajustementPWM(double rapportPWM);
void initialiserPort(char port, uint8_t mode);
void signalPWM(double rapportPWM, uint16_t tempsMS,char port, uint8_t mode);
