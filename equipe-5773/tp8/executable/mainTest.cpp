#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// vu qu'ils ne sont pas dans le meme dossier 
#include<bouton.h>
#include <can.h>
#include <delayMS.h>
#include<minuterie.h>
#include <moteur.h>
#include <UART.h>

// declaration de constantes 
const uint8_t ROUGE=0x02;
const uint8_t VERT=0x01;
const uint8_t ETEINT=0x00;
const uint8_t BOUTOND2=0x04;
const uint16_t TEMPSENMS = 1000;


int main (){
    initialiserPort('D',0x00);
    initialiserPort('A',0xFF);
    while (true)
    {
        if (boutonEstAppuye(BOUTOND2))
        {
            PORTA=VERT;
            delaisMS(TEMPSENMS);
            PORTA=ROUGE;
            delaisMS(TEMPSENMS);
        }
        PORTA= ETEINT;
    }
}