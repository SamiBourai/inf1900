/*

 * Nom: pb1.cpp

 * Description: Implémentation d'une machine séquentielle selon l'enoncé du tp2 p1.

 * Auteurs: Soheib Mounib Djellab et Sami Bourai

 * Date: 10 septembre 2020

+--------------+----+---+--------------+------------------+

| Etat present | D2 | D3|Etat suivant  | Sortie (couleur) |

+--------------+----+---+--------------+------------------+

| READY        | 1  | 0 | READY        | ETEINT           |

+--------------+--------+--------------+------------------+

| READY        | 0  | 1 | PRESSED1     | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED1     | 0  | 1 | PRESSED1     | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED1     | 1  | 0 | PRESSED2     | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED2     | 0  | 1 | PRESSED2     | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED2     | 1  | 0 | PRESSED3     | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED3     | 0  | 1 | PRESSED3     | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED3     | 1  | 0 | READY        | ROUGE puis eteint|

+--------------+--------+--------------+------------------+

 * 

 */

#include <avr/io.h>

#include <stdint.h>

#define F_CPU 8192000

#include <util/delay.h>

const uint8_t OUTPUT_PORT = 0xff;

const uint8_t INPUT_PORT = 0x00;

const uint8_t D2 = 0x04;

const uint8_t D3 = 0x08;

const uint8_t RED = 0x02;

const uint8_t GREEN = 0x01;

const uint8_t LIGHT_OFF = 0x00;

enum State    

{

    READY,

    PRESSED1,

    PRESSED2,

    PRESSED3

};

void stateMachine(State &state)

{

  

    switch (state)

    {

// PRESSED1 est l'etat initial

    case READY:

    PORTA = GREEN;

        state = PRESSED1;

        break;

    case PRESSED1:

        state = PRESSED2;

        break;

    case PRESSED2:

        state = PRESSED3;

        break;

    case PRESSED3:

        PORTA = RED;

        //Puisque le delais maximale de la carte mere est de 262.14 ms / F_CPU en MHz, nous avons fait un for loop pour faire le delais de 1 seconde (environ 1048ms).

        for(int i = 0; i < 4; i++)

            _delay_ms(262);

        PORTA = LIGHT_OFF;

        state = READY;

        break;

    }

}

int main()

{

    DDRA = OUTPUT_PORT; // PORT A est en mode sortie

    DDRB = OUTPUT_PORT; // PORT B est en mode sortie

    DDRC = OUTPUT_PORT; // PORT C est en mode sortie

    DDRD = INPUT_PORT; // PORT D est en mode entree

    PORTA = LIGHT_OFF;

    State state =READY;

    bool btnD3= false;

    while (true)     

    {

        // bouton poussoir D3

        if (PIND & D3 && btnD3==false)

        {

            _delay_ms(10); //debounce

                                

            while (PIND & D3)    //  dans le cas ou l'utilisateur maintient le bouton enfoncé

            {}                  // ainsi que pour valider le relachement du bouton 

            

            btnD3=true;

            stateMachine(state);

        }

         // bouton poussoir D2

          if (PIND & D2 && btnD3==true) 

        {

            _delay_ms(10); //debounce

                                

            while (PIND & D2)         // //  dans le cas ou l'utilisateur maintient le bouton enfoncé

            {}                      // ainsi que pour valider le relachement du bouton 

            stateMachine(state);

            if(state == READY)

                btnD3= false;

        }

    }

    return 0;

}
