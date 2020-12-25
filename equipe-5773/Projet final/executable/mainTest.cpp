#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// vu qu'ils ne sont pas dans le meme dossier 
#include<string.h>
#include<bouton.h>
#include <can.h>
#include <delayMS.h>
#include<minuterie.h>
#include <moteur.h>
#include <UART.h>
#include <lcm_so1602dtr_m_fw.h>
#include <customprocs.h>
#include <sonar.h>
#include<clavier.h>
#include<stdio.h>
#include<stdlib.h>
#include<porteLED.h>
#include<affichage.h>



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEMO_DDR	DDRB // `Data Direction Register' AVR occup� par l'aff.
#define DEMO_PORT	PORTB // Port AVR occup� par l'afficheur
uint16_t lecture_16;
uint8_t lecture_8;
can sensor;



int compteurLigne=-1;
int compteurColonne=-1;	
int compteurTouches=0;

int cntProchaineAction=0;
volatile int nbSignal=0;

LCM disp(&DEMO_DDR, &DEMO_PORT);
char choixTab [1];
char n;
char tab1[2];
char tableauLu[4];
int k=0;
uint8_t save;
volatile int compteur=0,uneJournee=0;
int heure;
int minute;
char heureNum[4];
char characLu;
bool simulation=true;
bool premierTri=true;
volatile bool pause=false;
int signal;
int compteurAction=0;

struct Action{
	char heureEntre[4];
	char dispositifEntree[4];
	int heureAction;
	bool estRempli;
	bool signalAjuste;
	int nouvelIndex;

	Action(){
		signalAjuste=false;
		estRempli=false;
		heureAction=0;
	}
};

//////////////////////////////////////////////////variable option 2 en scope//////////////////



/////////////////////////////////////////////////////////////////////////////////////////////





void definitionPin(){
	//pin horloge
	DDRA = (1<<PINA7);
	DDRA = (0<<PINA1);
	DDRC = (1<<PINC0);
	
	//pin clavier
	DDRC = (1<<PINC1);
	DDRC = (1<<PINC2);
	DDRC = (1<<PINC3);
	DDRC = (1<<PINC4);
	DDRC = (1<<PINC5);
	DDRC = (0<<PINC6);

	//pin porte
	DDRA = (1<<PINA6);
	DDRA = (1<<PINA5);
	DDRA = (1<<PINA4);
	DDRA = (1<<PINA3);
	DDRA = (1<<PINA2);

	//pin servomoteur
	DDRD = (1<<PIND4);
	DDRD = (1<<PIND5);

	//pin btn
	DDRD = (0<<PIND2);

	//pin sonar
	DDRA = (0<<PINA0);
	DDRB = (1<<PINB0);
}

void effacerLCD(){
	disp.clear();
	afficherMode('4',disp);
}


void option2(char lettre[]){

    int centaine=0,dizaine=0,angle=0;

    switch (lettre[0])
    {
        case 'A':
                if (lettre[1]=='0')
                ouvrirPorteA();
            else if (lettre[1]=='1')

                fermerPorteA();

            break;
        case 'B':
            if (lettre[1]=='0')
            {
                ouvrirPorteB();
            }else if (lettre[1]=='1')
            {
                fermerPorteB();
            }
            break;
        case 'C':
            if (lettre[1]=='0')
            {
                ouvrirPorteC();
            }else if (lettre[1]=='1')
            {
                fermerPorteC();
            }
            break;
        case 'D':
            if (lettre[1]=='0')
            {
                ouvrirPorteD();
            }else if (lettre[1]=='1')
            {
                fermerPorteD();
            }

            break;
        case 'E': 
            centaine = (lettre[1]-'0')*100;
            dizaine = (lettre[2]-'0')*10;
            angle = centaine + dizaine + (lettre[3]-'0');
            faireTournerServoE(angle);
            break;
        case 'F':
            centaine = (lettre[1]-'0')*100;
            dizaine = (lettre[2]-'0')*10;
            angle = centaine + dizaine + (lettre[3]-'0');
            faireTournerServoF(angle);
            break;
        default:
            break;
    }
}
void recupererDispositif(){
    bool erreur=false;
    bool optionEstInvalide=true;
    char n;
    int compteur1=0;
    int limite= 2;
	tableauLu[3] = 'x';
	


    while (optionEstInvalide)
    {
        while (1)
        {
            n=envoyerCaractereLcd(compteurLigne,compteurColonne, disp,compteurTouches);
            if (n!='x')
            {
                if(compteur1==0 && (n == 'E' || n == 'F')) limite = 4;
				//else if ( (compteur==0)&& (n=='A'||n=='B'||n=='C'||n=='D')) limite=2;
				

                if (compteur1==0 && ((n!='A') && (n!='B') && (n!='C') && (n!='D') & (n!='E') && (n!='F'))  ) // si il entre autre chose que ce qui faut
                {

                    erreur=true;
                    break;
                }
                else if(compteur1==1 && (n - '0') > 1)
                {
					
                    erreur=true;
                    break;
                }
                else if(compteur1==2 && (n - '0') > 8 && tableauLu[1]=='1')
                {
                    erreur=true;
                    break;
                }
                else if(compteur1==3 && tableauLu[2] == '8' && n!='0')
                {
                    erreur=true;
                    break;
                }
                else
                {
                    tableauLu[compteur1]=n;
                    compteur1++;
                }

                if(compteur1==limite)
                {
                    break;
                }
            }
        }

        if (erreur)
        {
            transmissionUART('\n');
            afficherMessageErreur();
		
			afficherChaine("reentrer une action valide : ",30);
			
            compteur1=0;
            disp.clear();
            erreur=false;
        }
        else
        {
            optionEstInvalide=false;
        }
    }
    
}
void reinitiHorloge(){

	PORTA= (1<<PINA7);
	_delay_ms(1);
	PORTA= (0<<PINA7);

	
}
void ajusterVoltage(){
    lecture_16 = sensor.lecture(0x01);
    lecture_8 = lecture_16 >> 2;

    if(lecture_8!=save){
        if(lecture_8==0)
            OCR0A=255;
        else {
            OCR0A=255/((lecture_8*5/255)*60/5);
            if(OCR0A>255)
                OCR0A=255;
        }
        save=lecture_8;
    }
}
void envoyerSignalHorloge(int signal){
	reinitiHorloge();
	_delay_ms(1);

	for (int i = 0; i < signal; i++)
	{
		PORTC = (1<<PINC7);
		_delay_ms(2);
    	PORTC = (0<<PINC7); //1260
		
	}
}

void entrerHeure(){
	
	
	int k=0;

	while(1){
		if (k==4)
		{
			if ((heureNum[0]-'0')>2 || ( (heureNum[0]-'0')==2 && (heureNum[1]-'0')>4) || (heureNum[2]-'0')>5 )
	        {
				transmissionUART('\n');
				afficherMessageErreur();
			
				afficherChaine("entrer une heure valide: ", 25);
				
				effacerLCD();
				
				k=0;

	        }else
			{
				break;
			}
		}
		
		characLu=envoyerCaractereLcd(compteurLigne,compteurColonne, disp,compteurTouches);
		
		if (characLu!='x')
		{
			
			heureNum[k]=characLu;
			k++;
		}
	}
	
	heure = (heureNum[0]-'0')*10 +(heureNum[1]-'0');
	minute = (heureNum[2]-'0')*10 +(heureNum[3]-'0');
	
	
	signal = (heure*60) + minute;
	

	
}

void initTimerHorloge(){
	cli();
    TCNT0 = 0x00;
    OCR0A = 255;
	TCCR0A = (1<<WGM01);
    TCCR0B = (1<<CS02) | (1<<CS00) ;
   
    TIMSK0= (1<< OCIE0A);

	//interuption interne
    EIMSK = (1<<INT0);
	//interuption externe
    EICRA = (1<<ISC00);
    sei();
}



Action tabAction[10];




int casterHeure(char tab[4]){
	int heure1=(tab[0]-'0')*1000 + (tab[1]-'0')*100 +(tab[2]-'0')*10 +(tab[3]-'0')*1;
	return heure1;
}


void trierActions(Action tabActions[10]){
	int x;
	int y;
	int index=0;
	Action actionTemporaire;
	if(nbSignal!=0 ){
		for(size_t i = 0; i < 10; i++){
			if(tabActions[i].estRempli == true && tabActions[i].signalAjuste==false){
				tabActions[i].signalAjuste=true;
				if(tabActions[i].heureAction>nbSignal)
					tabActions[i].heureAction=tabActions[i].heureAction-nbSignal;
				else 
					tabActions[i].heureAction=1440-(nbSignal-tabActions[i].heureAction);
			}
		}
	}
	//size-2 pour i et size-1 pour j
	for (size_t i = 0; i < 9; i++)
	{
		x= tabAction[i].heureAction;
		index=i;
		for (size_t j = i+1; j < 10; j++)
		{
			if(tabActions[i].estRempli == true && tabActions[j].estRempli == true )
			{
				
				y= tabAction[j].heureAction;
				if (x > y)
				{
					x=y;
					index=j;
				}	
			}
		}
			actionTemporaire = tabAction[i];
			tabAction[i]=tabAction[index];
			tabActions[index]=actionTemporaire;
		
	}
}

void afficherActions(Action tabActions[10]){
	
	//char tabVide [56]="- Le tableau est vide, veuillez programmer une action !";
	/*if ()
	{
		afficherChaine("- Le tableau est vide, veuillez programmer une action !",56);
	}else
	{*/	char index [1];
		for(int i = 0; i < compteurAction; i++){
			if (tabActions[i].estRempli==true)
			{
				
				
				sprintf(index, "%d", (i+1));
				
				if (i<10)
				{
					transmissionUART('0');
				}

				afficherSansConst(index, 2);
				transmissionUART(' ');
				transmissionUART('-');
				transmissionUART(tabActions[i].heureEntre[0]);
				transmissionUART(tabActions[i].heureEntre[1]);
				transmissionUART(':');
				transmissionUART(tabActions[i].heureEntre[2]);
				transmissionUART(tabActions[i].heureEntre[3]);
				transmissionUART('-');
				if(tabActions[i].dispositifEntree[0] == 'A'||tabActions[i].dispositifEntree[0] == 'B'||tabActions[i].dispositifEntree[0] == 'C'||tabActions[i].dispositifEntree[0] == 'D'){
					if(tabActions[i].dispositifEntree[1] == '1'){
						afficherChaine(" fermer porte ",14);
						transmissionUART(tabActions[i].dispositifEntree[0]);
					}
					else if(tabActions[i].dispositifEntree[1] == '0'){
						afficherChaine(" ouvrir porte ",14);
						transmissionUART(tabActions[i].dispositifEntree[0]);
					}
				}
				else if(tabActions[i].dispositifEntree[0] == 'E'||tabActions[i].dispositifEntree[0]=='F'){
					afficherChaine(" orienter servomoteur ",22);
					transmissionUART(tabActions[i].dispositifEntree[0]);
					afficherChaine(" a ",3);
					transmissionUART(tabActions[i].dispositifEntree[1]);
					transmissionUART(tabActions[i].dispositifEntree[2]);
					transmissionUART(tabActions[i].dispositifEntree[3]);
					afficherChaine(" degres ",9);
				}
				transmissionUART('\n');
			}		
		}	
	//}	
			
			
			
			//NN – HH:MM – orienter servomoteur ID à X degrés
			//Exemple : 04 – 09:10 – ouvrir porte C
}


void supprimerAction(int index){

    //tabActions[index]
	
	index--;
	for(int i=index+1;i<10;i++){
		if(i!=9){
			tabAction[i-1]=tabAction[i];
		}
	}
	compteurAction--;
}


int lireActionSupprime(){
	char n='x';
	int compteurDajout=0;
	int tabSupprimer[2];

	while (1)
	{
		n=envoyerCaractereLcd(compteurLigne,compteurColonne,disp,compteurTouches);
		if (n!='x')
		{
			tabSupprimer[compteurDajout]=n-'0';
			compteurDajout++;
			n='x';
		}
		if (compteurDajout==2)
		{
			break;
		}
	}
	if (tabSupprimer[0]==0)
	{
		return tabSupprimer[1];
	}else
	{
		return (tabSupprimer[0]*10)+tabSupprimer[1];
	}
}

void fonctionVerif(){

	if(tabAction[cntProchaineAction].heureAction == uneJournee-1){
		
		option2(tabAction[cntProchaineAction].dispositifEntree);
		cntProchaineAction++;
	}
}

int main(){
	definitionPin();
	///////////////////////////////////////////variable option 1///////////////////////

	///////////////////////////////////////////variable option 2///////////////////////
	
	///////////////////////////////////////////variable option 3///////////////////////

	//////////////////////////////////////////variable option 4////////////////////////
	
	Action action;
	///////////////////////////////////////////variable option 5///////////////////////
	//int tableauActionASupprimee[2];
	Action tabActionNonSpprimee[10];
	int indexActionSupprimee;
	///////////////////////////////////////////variable option 6///////////////////////

	///////////////////////////////////////////////////////////////////////////////////
	char optionChoisie='x';
	bool entreeMenuPrincipaleEstValide=true;
	
	int voltageSonar;

	while (entreeMenuPrincipaleEstValide)
	{
		afficherMenuRS232(); 
    	afficherMode(optionChoisie,disp);

		while (1)      // cette premiere boucle recupere l'option choisie par l'utilisateur
		{
			optionChoisie = 'x';
			optionChoisie=envoyerCaractereLcd(compteurLigne,compteurColonne,disp,compteurTouches);
			if (optionChoisie!='x')
			{
				transmissionUART('\n');
				break;
			}

		}
		switch (optionChoisie)
		{
		case '1':
		// on reinitialise l'horloge
		

			reinitiHorloge();  
			entrerHeure();
			envoyerSignalHorloge(signal);	
			nbSignal=signal;
			disp<<nbSignal;
			entreeMenuPrincipaleEstValide=true;			// on demande d<entrer le temps et on ecrit cela dans le 7 segment
			break;
			
		case '2':
			recupererDispositif();  // on va chercher ce qui a ete tapper et on le met dans un tableau de char
			option2(tableauLu);  // ici on execute l'action qui a ete tappee
			//entreeMenuPrincipaleEstValide=true;
			break;
		case '3':
			trierActions(tabAction);
			afficherActions(tabAction);
			entreeMenuPrincipaleEstValide=true;
			break;
		case '4':
			
			
			entrerHeure();
			action.heureAction = signal;

			strcpy(action.heureEntre , heureNum);
			recupererDispositif();
			
			strcpy(action.dispositifEntree, tableauLu);
	
			action.estRempli=true;
			tabAction[compteurAction] = action;

			tabAction[compteurAction].heureAction=signal;
			compteurAction++;
			entreeMenuPrincipaleEstValide=true;
			break;

		case '5':
			
			indexActionSupprimee=lireActionSupprime();
			supprimerAction(indexActionSupprimee);
			entreeMenuPrincipaleEstValide=true;

			break;

		case '6':

			afficherMode(optionChoisie,disp);
			initTimerHorloge();
			simulation=true;
	
			while(simulation==true){
				activerTrigger10ms();
				
				voltageSonar=distanceObjetMetre(detecterObjet());
				
				if(voltageSonar<200){
					TCCR0B = (0<<CS02) | (0<<CS00) ;
				}
				else if(voltageSonar>200 && uneJournee<1440 && pause==false){
					TCCR0B = (1<<CS02) | (1<<CS00) ;
				}

				ajusterVoltage();
				fonctionVerif();
			}
		

			entreeMenuPrincipaleEstValide=true;
			break;
			
		case 'x':
			entreeMenuPrincipaleEstValide=true;
			break;
		default:
			afficherMessageErreur();
			afficherMenuRS232();
			entreeMenuPrincipaleEstValide=true;
			break;
		}
		
	}

}

ISR (TIMER0_COMPA_vect){
	if (compteur==30 && simulation==true)
	{
		PORTC = (1<<PINC7);
    	PORTC = (0<<PINC7);
		uneJournee++;
		if(uneJournee==1440)
			TCCR0B = (0<<CS02) | (0<<CS00) ;
    
		nbSignal++;
		compteur=0;
	}else
	{
		compteur++;
	}

}

ISR(INT0_vect)
{
	
    _delay_ms(30);

 if(PIND & 0x04 && pause==false){
	TCCR0B = (0<<CS02) | (0<<CS00) ;
   
	pause=true;
	afficherMode('4', disp);

 }
 else if(PIND & 0x04 && pause==true){
	 
	 TCCR0B = (1<<CS02) | (1<<CS00) ;
	pause =false;
	afficherMode('6', disp);
	EICRA = (1<<ISC00);
	
 }
	

    
}