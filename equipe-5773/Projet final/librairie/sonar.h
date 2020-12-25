

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"


const uint16_t TEMPS_ECHO_PULSE_US = 100;
const uint16_t TEMPS_OBJET_INTROUVABLE_US= 36000;
int detecterObjet();
int arrondirNombre();
void activerTrigger10ms();
int distanceObjetMetre(double distanceMetre);