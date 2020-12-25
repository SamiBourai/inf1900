#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>


void partirMinuterieCTC ( uint16_t dureeMS, volatile uint8_t& comparaisonOCR1MS);