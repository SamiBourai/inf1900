#include"minuterie.h"


void partirMinuterieCTC ( uint16_t dureeMS, volatile uint8_t& comparaisonOCR1MS) {

    comparaisonOCR1MS = 0;

    // mode CTC du timer 1 avec horloge divisée par 1024
    // interruption après la durée spécifiée

    TCNT1 = 0;

    OCR1A = dureeMS;

    TCCR1A |= (1 << COM1A1) | (1<< COM1A0);

    TCCR1B |= (1 << CS10) | (1 << CS12) | (1 << WGM12);

    TCCR1C = 0;

    TIMSK1 |= (1 << OCIE1A);

}