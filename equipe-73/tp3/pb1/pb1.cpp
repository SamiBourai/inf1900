/*
 * Nom: td2_pb1.cpp
 * Description: 
 * Auteurs: Soheib Mounib Djellab et Sami bourai
 * Date: 28 janvier 2020
*/

#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>

const uint8_t OUTPUT_PORT = 0xff;
const uint8_t INPUT_PORT = 0x00;
const uint8_t D2 = 0x04;
const uint8_t D3 = 0x08;

const uint8_t GREEN = 0x01;
const uint8_t RED = 0x02;
const uint8_t LIGHT_OFF = 0x00;

const int PERIOD = 10;    
int a=10;


void colorFade (uint8_t color){

     for(int i=0;i<300;i++){ // 300 tours de 10ms ce qui equivaux a 3s
                PORTA=color;

                for(int y=0;y<a;y++) // ratio de la del allumé
                _delay_ms(1);

                PORTA=LIGHT_OFF;

                for(int x=0;x<(PERIOD-a);x++) // ratio de la del éteinte
                _delay_ms(1);

                if(i%30==0)
                a--;
            }
}

int main()
{
    DDRA = OUTPUT_PORT; // PORT A est en mode sortie
    DDRB = OUTPUT_PORT; // PORT B est en mode sortie
    DDRC = OUTPUT_PORT; // PORT C est en mode sortie
    DDRD = INPUT_PORT; // PORT D est en mode entree

    while (true){
        a=10;

        if (PIND & D3){
            while(PIND & D3)
                {}
            colorFade(RED);
        }

        if (PIND & D2){
            while(PIND & D2)
                {}
            colorFade(GREEN);
        }
        
        
    }

    return 0;
}
