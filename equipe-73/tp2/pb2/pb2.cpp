/*

 * Nom: pb2.cpp

 * Description:

 * Auteurs: Soheib Mounib Djellab et Sami Bourai

 * Date: 10 septembre 2020

+--------------+----+---+--------------+------------------+

| Etat present | D2 | D3|Etat suivant  | Sortie (couleur) |

+--------------+----+---+--------------+------------------+

| INIT         | 1  | 0 | PRESSED      | ROUGE            |

+--------------+--------+--------------+------------------+

| PRESSED      | 1  | 0 | INIT         | ETEINT           |

+--------------+--------+--------------+------------------+

| INIT         | 0  | 1 | PRESSED      | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED      | 0  | 1 | INIT         | ETEINT           |

+--------------+--------+--------------+------------------+

| INIT         | 0  | 1 | PRESSED      | VERT             |

+--------------+--------+--------------+------------------+

| PRESSED      | 1  | 0 | PRESSED      | ROUGE            |

+--------------+--------+--------------+------------------+

| PRESSED      | 0  | 1 | PRESSED      | VERT             |

+--------------+--------+--------------+------------------+

 * 

 */

#include <avr/io.h>

#include <stdint.h>

#define F_CPU 8192000

#include <util/delay.h>

const uint8_t ouputPort = 0xff;

const uint8_t inputPort = 0x00;

    

    uint8_t red = 0x02;

     uint8_t green = 0x01;

    uint8_t lightOff = 0x00;

enum State

{

    INIT,

    PRESSED

};

void stateMachine(State &state, uint8_t color)

{

    

    switch (state)

    {

// PRESSED1 est l'etat initial

    case INIT:

        PORTA=color;

        state = PRESSED;

        break;

    case PRESSED:

        if(PORTA==color){

            PORTA=lightOff;

            state=INIT;

        }

        else

            PORTA = color;

        break;

    }

}

int main()

{

    DDRA = ouputPort; // PORT A est en mode sortie

    DDRB = ouputPort; // PORT B est en mode sortie

    DDRC = ouputPort; // PORT C est en mode sortie

    DDRD = inputPort; // PORT D est en mode entree

    PORTA = 0x00;

    State state = State::INIT;

  

    while (true)

    {

        // bouton poussoir D3

        if (PIND & 0x08 )

        {

            _delay_ms(10); //debounce

                                

            while (PIND & 0x08)

            {} 

            

            stateMachine(state, green);

        }

         // bouton poussoir D2

          if (PIND & 0x04) 

        {

            _delay_ms(10); //debounce

                                

            while (PIND & 0x04)

            {} 

            stateMachine(state, red);

                

        }

    }

    return 0;

}
