#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

#include "lcm_so1602dtr_m_fw.h"
#include "lcm_so1602dtr_m.h"
#include "customprocs.h"
#include "UART.h"
const int ZERO=0;
const int UN =1;
const int DEUX=2;
const int TROIS=3;
const int QUATRE =4;
const int CINQ=5;
const int SIX=6;

const int LIGNE =4;
const int COLONNE =4;

const uint8_t REINITIALISER_PORTC3_C4 =0xe7;  // initialiser c3 et c4 a chaque fois
const uint8_t REINITIALISER_PORTC1_C2 = 0xf9; // initialiser c1 et c2 a chaque fois
const char TAB_CLAVIER [LIGNE][COLONNE] = {'0','1','2','3',
					   					   '4','5','6','7',
					    				   '8','9','A','B',
					    				   'C','D','E','F'};


const int TEMPS_5_US =5;
const int TEMPS_10_US =15;

void attendre(void);
void donnerCourantColonne(int ligneActuelle,int& compteurLigne,int& compteurColonne);
char envoyerCaractereLcd(int compteurLigne,int compteurColonne,LCM& disp, int compteurTouches);