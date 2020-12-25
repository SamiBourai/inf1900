#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



bool boutonEstAppuye(uint8_t boutonValeur);
void initialisation();
void rebond();

