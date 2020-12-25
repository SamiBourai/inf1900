
#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/eeprom.h>




void initialisationUART ();

void transmissionUART( uint8_t uneDonnee);

void afficherChaine(const char tab [150], int taille);

// unsigned char USART_Receive( void );


// void ecrire_Eeprom();

// uint8_t lire();

void afficherSansConst(char tab[150],int taille);