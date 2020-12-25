#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>

const uint8_t SORTIE= 0x00;
const uint8_t ENTREE= 0xff;
const uint8_t EN_VERT=0x01;
const uint8_t EN_ROUGE=0x02;
const uint8_t ETEINTE=0x00;
const uint8_t TEMPS_COULEUR_AMBREE=50;

void lumiereVerte();
void lumiereRouge();
void lumiereAmbree();
void lumiereOff();