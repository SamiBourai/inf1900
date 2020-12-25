#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>

volatile uint8_t minuterieExpiree;
volatile uint8_t boutonPoussoir; 
const int fcpuONprescaler=7812;
const uint8_t ouputPort = 0xff;
const uint8_t inputPort = 0x00;
uint8_t green=0x01;
uint8_t red=0x02;
uint8_t off=0x00;

void validationColor(){
    if(minuterieExpiree==1){
       PORTA=red;
        EIMSK &= (0<<INT0);
    }
    if(boutonPoussoir==1){
       PORTA=green;
    }
}

ISR (TIMER1_COMPA_vect){
    minuterieExpiree=1;
    cli ();
    validationColor();
}

ISR(INT0_vect){
    boutonPoussoir=1;
   cli ();
    validationColor();
    _delay_ms(10); //debounce
}


void minuterie(uint16_t duree){
minuterieExpiree = 0;

// mode CTC du timer 1 avec horloge divisée par 1024
// interruption après la durée spécifiée
TCNT1 = 0x000;
OCR1A = fcpuONprescaler*duree;
TCCR1A = 0;
TCCR1B = (1<<CS12) | (1<<CS10) | (1<<WGM12);
TCCR1C = 0;
TIMSK1= (1<< OCIE1A);
}

void initialisation (void){
   
    EIMSK |= (1<<INT0);
    EICRA |= (1<<ISC00);
       
    sei(); 
}



int main()
{
    DDRA = ouputPort; // PORT C est en mode sortie
    DDRD = inputPort; // PORT D est en mode entre
    bool first = true;
    
 while (true)
    {
        // 10s d'attente
        if (first==true){
            first = false;
        for(int i=0;i<100;i++)
               _delay_ms(100);
        // 1/10 s
        for(int i=0;i<3;i++){
           _delay_ms(35);
           if(PORTC==off)
          PORTA=red;
           else PORTA =off;
        }

       PORTA=off;

        initialisation();
        minuterie(1);

        //cli();
        }

    }
    return 0;

}