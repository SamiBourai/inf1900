#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>

void delaisMS (uint16_t tempsMS);
void delaisUS(uint16_t tempsUS);
