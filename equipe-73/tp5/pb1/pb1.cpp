#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "memoire_24.h"
#include <string.h>
#include <avr/eeprom.h>
#define BLKSIZE 16
#define DATA 0x10

const uint8_t ouputPort = 0xff;
const uint8_t inputPort = 0x00;
uint8_t green = 0x01;
uint8_t red = 0x02;
volatile uint16_t eepromaddress;
volatile bool written=false;

//string array index initial 0
volatile uint8_t i;
//message to be written to EEPROM
uint8_t EEMEM poly[] ="*P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";
//uint8_t off = 0x00;

ISR(EE_READY_vect){
/*check if not end of string and address
didn't reach end of EEPROM*/
    if ((poly[i])&&(eepromaddress<=E2END)){
    //loads address and increments for next load
    EEAR=eepromaddress++;
    //loads current byte and increments index for next load
    EEDR=poly[i++];
    //master write enable
    EECR|=(1<<EEMPE);
    //strobe eeprom write
    EECR|=(1<<EEPE);
    }else
        {
    //disable eeprom ready interrupt
    EECR &= ~(1<<EERIE);
    }
written=true;
}

void initialisation(void)
{  
     cli();
     DDRC = ouputPort; // PORT C est en mode sortie
     DDRD = inputPort; // PORT D est en mode entre

    //Enable eeprom ready interrupt
    EECR |= (1<<EERIE);
    //enable global interrupts
     sei();
}

int main(){
   initialisation();

    while(true){
        if(written==true){
            volatile uint8_t EEByte;
            EEByte = eeprom_read_byte((uint8_t*)EEDR);
        }
    }
}