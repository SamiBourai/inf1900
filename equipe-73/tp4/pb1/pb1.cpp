/*
 * Nom: td2_pb2.cpp
 * Description: Programme simple qui permet d'allumer une DEL de repondre consecutivement et de facon differente lorsque le bouton-poussoir est appuyer ou relache.
 * Auteurs: Soheib Mounib Djellab et sami bourai
 * Date: 28 janvier 2020
+--------------+--------+--------------+------------------+
| Etat present | Entree | Etat suivant | Sortie (couleur) |
+--------------+--------+--------------+------------------+
| INIT         | 0      | INIT         | Rouge            |
+--------------+--------+--------------+------------------+
| INIT         | 1      | PRESS1       | Ambre            |
+--------------+--------+--------------+------------------+
| PRESS1       | 0      | RELEASE1     | Vert             |
+--------------+--------+--------------+------------------+
| PRESS1       | 1      | PRESS1       | Ambre            |
+--------------+--------+--------------+------------------+
| RELEASE1     | 0      | RELEASE1     | Vert             |
+--------------+--------+--------------+------------------+
| RELEASE1     | 1      | PRESS2       | Rouge            |
+--------------+--------+--------------+------------------+
| PRESS2       | 0      | RELEASE2     | Eteint           |
+--------------+--------+--------------+------------------+
| PRESS2       | 1      | PRESS2       | Rouge            |
+--------------+--------+--------------+------------------+
| RELEASE2     | 0      | RELEASE2     | Eteint           |
+--------------+--------+--------------+------------------+
| RELEASE2     | 1      | PRESS3       | Vert             |
+--------------+--------+--------------+------------------+
| PRESS3       | 0      | INIT         | Rouge            |
+--------------+--------+--------------+------------------+
| PRESS3       | 1      | PRESS3       | S6               |
+--------------+--------+--------------+------------------+
 * 
 */
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>


enum State
{
    INIT,
    PRESS1,
    RELEASE1,
    PRESS2,
    RELEASE2,
    PRESS3
};

    volatile   State stat = State::INIT;
    volatile bool  buttonPressed = false;
    const uint8_t green = 0x01;
    const uint8_t red = 0x02;
    const uint8_t lightOff = 0x00;
    
  State stateMachine(State state)
{
    

    switch (state)
    {
    case INIT:
        PORTA = red;
        state = PRESS1;
        break;
    case PRESS1:
        while (PIND & 0x04)
        {
            PORTA= green;
            _delay_ms(7);
            PORTA= red;
            _delay_ms(3);
        }
        state = RELEASE1;
        break;
    case RELEASE1:
        PORTA = green;
        state = PRESS2;
        break;
    case PRESS2:
        PORTA = red;
        state = RELEASE2;
        break;
    case RELEASE2:
        PORTA = lightOff;
        state = PRESS3;   
        break;
    case PRESS3:
        PORTA = green;
        state = INIT;
        break;
    }

    return state;
}

ISR(INT0_vect)
{
    // laisser un delai avant de confirmer la réponse du

    // bouton-poussoir: environ 30 ms (anti-rebond)

    _delay_ms(30);
    
    // se souvenir ici si le bouton est pressé ou relâché

    if (PIND & 0x04)
        buttonPressed = true;
    else
        buttonPressed = false;

    // changements d'états tels que ceux de la

    // semaine précédente
    stat=stateMachine(stat);

    EIFR |= (1 << INTF0);
}

void initialisation(void)
{

    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();

    // configurer et choisir les ports pour les entrées
    // et les sorties. DDRx... Initialisez bien vos variables
    DDRA = 0xff;
    DDRC = 0xff; // PORT C est en mode sortie
    DDRD = 0x00; // PORT D est en mode entree

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes
    // active high

    EIMSK |= (1 << INT0);

    // il faut sensibiliser les interruptions externes aux
    // changements de niveau du bouton-poussoir
    // en ajustant le registre EICRA
    // active high

    EICRA |= (1 << ISC00);

    // sei permet de recevoir à nouveau des interruptions.

    sei();
}




int main()
{
 
    //bool volatile buttonPressed = false;
    initialisation();

    //On appelle la fonciton stateMachine pour que la DEL soit initialement allume en rouge.
   // stat= stateMachine(stat);
    PORTA=green;
    while (true)
    {
         //debounce
    }
    return 0;

}

