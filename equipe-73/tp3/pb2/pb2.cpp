/*
 * Nom: pb2.cpp
 * Description: 
 * Auteurs: Soheib Mounib Djellab et Sami bourai
 * Date: 28 janvier 2020
*/

#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>

const uint8_t ouputPort = 0xff;
const uint8_t inputPort = 0x00;
//const uint8_t PWM=0x0E;

uint8_t on=0x02;
uint8_t off=0x00;
uint8_t back=0x01;
int a=0;
int periode=12;
bool valid=false;

void PWM (int &dutyCycle , int &period, int iterA, int iterB){

            for(int x=0;x<iterA;x++){
                for(int y=0; y<iterB;y++){
                    if(valid==true)
                        PORTB=back;
                        else
                    PORTB=on;

                 for(int y=0;y<dutyCycle;y++)
                _delay_ms(1);

                PORTB=off;

                for(int x=0;x<(period-dutyCycle);x++)
                _delay_ms(1);
            
                }
            }
        
      }


int main()
{
    DDRA = ouputPort; // PORT A est en mode sortie
    DDRB = ouputPort; // PORT B est en mode sortie
    DDRC = ouputPort; // PORT C est en mode sortie
    DDRD = inputPort; // PORT D est en mode entree

    while (true){

        for(int i=0;i<5;i++){
         PWM(a,periode,10,16);
          a+=3;
      }

      if(a==12)
    PORTC=off;
       
       a=0;
       periode=25;

            valid=true;
         for(int i=0;i<5;i++){
            PWM(a,periode,8,10);
          a+=5;
      }

      if(a==25)
      PORTC=off;
       
    return 0;
}
}
