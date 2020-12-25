
#include"sonar.h"


int detecterObjet(){

    uint16_t compteurEcho = 0;
    while (!(PINA & (1 << PA0)));
  
    while ((PINA & (1 << PA0)) != 0)
    {
        compteurEcho++;
        _delay_us(TEMPS_ECHO_PULSE_US);
        ///////si compteur est plus grand que 36000 rien n'est detecter
        if (compteurEcho > TEMPS_OBJET_INTROUVABLE_US)
            return 0;
    }
    return compteurEcho;

}


void activerTrigger10ms(){
    PORTB |= (1 << PB0);
    _delay_us(100);
    PORTB &= (~(1 << PB0));
}

int distanceObjetMetre(double distanceMetre){
    return round(distanceMetre)*100/58.0f;
}


