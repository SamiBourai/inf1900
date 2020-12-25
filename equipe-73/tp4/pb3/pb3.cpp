#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>

double dutyCycle=0;

const uint8_t ouputPort = 0xff;
const uint8_t inputPort = 0x00;

void ajustementPWM(double dutyCycle){
// mise à un des sorties OC1A et OC1B sur comparaison
// réussie en mode PWM 8 bits, phase correcte
// et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6
// page 177 de la description technique du ATmega324PA)

TCNT1 = 0x000;
OCR1A = ((dutyCycle)/100)*254;
OCR1B = ((dutyCycle)/100)*254;

// division d'horloge par 8 - implique une frequence de PWM fixe
TCCR1A = (1<<WGM10) | (1<<COM1A1) | (1<<COM1B1);
TCCR1B = (1<<CS11);
//TIMSK = (1<< TOIE1);
TCCR1C = 0;
}


int main(){
 DDRA = inputPort; // PORT C est en mode entree
 DDRD = ouputPort;// PORT D est en mode sortie
   
   
   while(true){
       ajustementPWM(dutyCycle);

      dutyCycle+=25;
      _delay_ms(2000);
      if(dutyCycle>125)
       dutyCycle=0;
   }
}