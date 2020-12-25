#include "UART.h"

void initialisationUART (void){

    UBRR0H = 0;

    UBRR0L = 0xCF;


    UCSR0A = 0;

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0); // active reception et reception



    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // 8 bits, un bit de stop,pas de parite
}

// trasmission de donnees vers le pc
void transmissionUART( uint8_t uneDonnee){

    while ( !( UCSR0A & (1 << UDRE0)) ) {

    }

    UDR0 = uneDonnee;
}

void afficherChaine(uint8_t* tab, int taille){

    for(int i = 0; i < taille; ++i)
    {
        transmissionUART(tab[i]);
    }
 
}



