

#include"bouton.h"


const uint16_t DELAIS10_MS = 10;

bool boutonEstAppuye(uint8_t boutonValeur)
{
    
    if (PIND & boutonValeur)
    {
        _delay_ms(DELAIS10_MS);
        if (PIND & boutonValeur)
            return true;
    }
    return false;
}

void initialisation()
{

    // cli est une routine qui bloque toutes les interruptions.
    cli();

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes
    EIMSK |= (1 << INT0);

    // il faut sensibiliser les interruptions externes aux
    // changements de niveau du bouton-poussoir
    // en ajustant le registre EICRA
    EICRA |= 1 << ISC00;


    // sei permet de recevoir à nouveau des interruptions.
    sei();
}

void rebond(){
    _delay_ms(DELAIS10_MS);
}
