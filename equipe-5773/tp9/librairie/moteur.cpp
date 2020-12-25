#include "moteur.h"


void ajustementPWM(uint8_t rapportPWM){
    // mise à un des sorties OC1A et OC1B sur comparaison
    // réussie en mode PWM 8 bits, phase correcte
    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6
    // page 177 de la description technique du ATmega324PA)

    TCNT1 = 0x000;
    OCR1A = rapportPWM;//((rapportPWM)/100)*254;
    OCR1B = rapportPWM;//((rapportPWM)/100)*254;

    // division d'horloge par 8 - implique une frequence de PWM fixe
    TCCR1A = (1<<WGM10) | (1<<COM1A1) | (1<<COM1B1);
    TCCR1B = (1<<CS11);
    //TIMSK = (1<< TOIE1);
    TCCR1C = 0;


}

void tourner(uint8_t d4, uint8_t d5){
    TCNT1 = 0x000;
    
    OCR1A = d4; //25% sera generer pin d4

    OCR1B = d5; //25% sera generer pin d5

    // division d'horloge par 8 - implique une frequence de PWM fixe
    TCCR1A = (1<<WGM10) | (1<<COM1A1) | (1<<COM1B1);
    TCCR1B = (1<<CS11);
    //TIMSK = (1<< TOIE1);
    TCCR1C = 0;
}



void initialiserPort(char port, uint8_t mode) 
{
	switch (port) 
	{
		case 'A':
        case 'a':
			DDRA = mode;
			break;	
		case 'B':
        case 'b':
			DDRB = mode;
			break;
		case 'C':
        case 'c':
			DDRC = mode;
			break;
		case 'D':
        case 'd':
			DDRD = mode;
			break;	
	}  
}

void signalPWM(uint8_t rapportPWM, uint16_t tempsMS,char port, uint8_t mode){
    initialiserPort(port,mode);
    ajustementPWM(rapportPWM);
    delaisMS(tempsMS);
}

