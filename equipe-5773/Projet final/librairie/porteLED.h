#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>




void lireDs();

void copierRegistre();

void eteindreLED();

void ignorerPorte();

void ouvrirPorteA();

void ouvrirPorteB();

void ouvrirPorteC();

void ouvrirPorteD();

void fermerPorteA();

void fermerPorteB();

void fermerPorteC();

void fermerPorteD();