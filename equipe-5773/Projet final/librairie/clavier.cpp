

#include "clavier.h"
#include "UART.h"


void attendre(void) {
	cp_wait_ms(1000);
}


void donnerCourantColonne(int ligneActuelle,int& compteurLigne,int& compteurColonne){
	compteurColonne=-1;
	compteurColonne=-1;
	/////////////////////////////////////////////////////////////////////////////////////
	PORTC &= REINITIALISER_PORTC3_C4; // remettre c3 et c4 a 0
	_delay_us(TEMPS_10_US);
	PORTC = PORTC | (0<<3);
	PORTC = PORTC | (0<<4); // 00 row 0   -> '0'
	_delay_us(TEMPS_10_US);
	if ( PORTC | (0<<3)&& PORTC |(0<<4)&& PINC & (1<<PINC6))
	{
		compteurColonne = ligneActuelle;
		compteurLigne=ZERO;
		return;
	}
				
	/////////////////////////////////////////////////////////////////////////////////////
	PORTC &= REINITIALISER_PORTC3_C4; // remettre c3 et c4 a 0
	_delay_us(TEMPS_10_US);
	PORTC = PORTC | (1<<3);
	PORTC = PORTC | (0<<4); // 10 row 1   -> '4'
	_delay_us(TEMPS_10_US);
	if (  PORTC | (1<<3)&& PORTC |(0<<4)&&PINC & (1<<PINC6))
	{
		compteurColonne = ligneActuelle;
		compteurLigne=UN;
		return;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	PORTC &= REINITIALISER_PORTC3_C4; // remettre c3 et c4 a 0
	_delay_us(TEMPS_10_US);
	PORTC = PORTC | (0<<3);
	PORTC = PORTC | (1<<4); // 10 row 1   -> '8'
	_delay_us(TEMPS_10_US);
	if (  PORTC | (0<<3) && PORTC |(1<<4) &&PINC & (1<<PINC6))
	{
		compteurColonne = ligneActuelle;
		compteurLigne=DEUX;
		return;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	PORTC &= REINITIALISER_PORTC3_C4; // remettre c3 et c4 a 0
	_delay_us(TEMPS_10_US);
	PORTC = PORTC | (1<<3);
	PORTC = PORTC | (1<<4); // 11 row 3   -> 'C'
	_delay_us(TEMPS_10_US);
	if ( PORTC | (1<<3)&& PORTC |(1<<4)&&PINC & (1<<PINC6))
	{		
		compteurColonne = ligneActuelle;
		compteurLigne=TROIS;
		return;
	}			
}

char envoyerCaractereLcd(int compteurLigne,int compteurColonne,LCM& disp, int compteurTouches){
	
	PORTC = PORTC | (1<<5);
	for (int i = 0; i < 4; i++)
	{	
		for (int j = 0; j < 4; j++)
		{
			PORTC &=REINITIALISER_PORTC1_C2;  // initialiser c1 et c2 a chque fois
			switch (i) // i=ligne
			{
			case ZERO:
				PORTC = PORTC | (0<<1);	
				PORTC = PORTC | (0<<2);
				donnerCourantColonne(i, compteurLigne, compteurColonne);
				break;
			case UN:
				PORTC = PORTC | (1<<1);	
				PORTC = PORTC | (0<<2);
				donnerCourantColonne(i, compteurLigne, compteurColonne);
				break;
			case DEUX:
				PORTC = PORTC | (0<<1);	
				PORTC = PORTC | (1<<2);
				donnerCourantColonne(i, compteurLigne, compteurColonne);
				break;
			case TROIS:
				PORTC = PORTC | (1<<1);	
				PORTC = PORTC | (1<<2);
				donnerCourantColonne(i, compteurLigne, compteurColonne);    
				break;
			}
			
		}
		if (compteurLigne!=-UN && compteurColonne!=-UN)
		{ 
			compteurTouches++;
			
			disp<<TAB_CLAVIER[compteurLigne][compteurColonne];
			
			attendre();	
			transmissionUART(TAB_CLAVIER[compteurLigne][compteurColonne]);
			return TAB_CLAVIER[compteurLigne][compteurColonne];
		}
		
		
	}
	return 'x';
}