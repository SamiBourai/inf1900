#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#define F_CPU 8000000
#include <util/delay.h>
#include<bouton.h>
#include <can.h>
#include <delayMS.h>
#include<minuterie.h>
#include <moteur.h>
#include <UART.h>
#include <lumiere.h>
 
const uint8_t SORTTIE_PORT=0xff;

const int DELAISMULTI=25;

const uint8_t OFFPWM=0x00;
const uint8_t ONPWM=0x96;

//couleur del
const uint8_t MAX_VERT= 0x7f;
const uint8_t MIN_VERT=0x00;
const uint8_t VERT = 0x01;
const uint8_t ROUGE = 0x02;
const uint8_t ETEINT =0x00;
const uint8_t COULEUR_DEL= 200;

const uint16_t DEUX_SECONDE=2000,UNE_SECONDE=1000;


const uint8_t DBT =0x01; // debut
const uint8_t ATT =0x02; //attendre
const uint8_t DAL =0x44; // allumer del bicolore
const uint8_t DET =0x45; // eteindre del bicolore
const uint8_t MON =0x18; //allumer la matrice de del
const uint8_t MOF =0x19; // eteindre la matrice de del
const uint8_t MAR =0x60; // arreter le moteur
const uint8_t MAR2 =0x61;// arreter le moteur
const uint8_t MAV =0x62; // avancer
const uint8_t MRE =0x63; // reculer
const uint8_t TRD =0x64; // tourner a droite
const uint8_t TRG =0x65; // tourner a gauche
const uint8_t DBC =0xC0; // debuter boucle
const uint8_t FBC =0xC1; // fin de boucle
const uint8_t FIN =0xFF; // fin

// representation directionnelle de la matrice 3x3;
const uint8_t NORD=0x15, SUD=0x45, EST=0x23, OUEST=0x26, CENTRE=0x25;

// affichage de l'instruction mnomonique correspondante; 
char CASE1[3] ={'D','B','T'};
char CASE2[3] ={'A','T','T'};
char CASE3[3] ={'D','A','L'};
char CASE4[3] ={'D','E','T'};
char CASE5[3] ={'M','O','N'};
char CASE6[3] ={'M','O','F'};
char CASE7[3] ={'M','A','R'};
char CASE8[3] ={'M','A','R'};
char CASE9[3] ={'M','A','V'};
char CASE10[3] ={'M','R','E'};
char CASE11[3] ={'T','R','D'};
char CASE12[3] ={'T','R','G'};
char CASE13[3] ={'D','B','C'};
char CASE14[3] ={'F','B','C'};
char CASE15[3] ={'F','I','N'};

// variable necessaire a la boucle de relecture
uint8_t *adresse_;
uint8_t *adresseDBC;
uint8_t nBoucles = 0x00;
bool boucleTerminee=false;
bool premierTour=true;
uint8_t instructRep_,opeRep_;


//////////////////////////////////////////////////////////
unsigned char USART_Receive( void )  // p176
{

    while ( !(UCSR0A & (1<<RXC0)) ){}
    return UDR0;
}

uint8_t lire(){ 

    uint8_t donnee = eeprom_read_byte(adresse_);

    //sauvgarde de l'adresse de l'octet du début de boucle
    if(donnee==DBC && premierTour==true)
        adresseDBC =adresse_;
    return donnee;
}



void ecrire_Eeprom(){
   
    uint8_t premier_Octect = USART_Receive();
    uint8_t deuxieme_Octect = USART_Receive();

    eeprom_write_byte(adresse_,premier_Octect);
    adresse_++;
    eeprom_write_byte(adresse_,deuxieme_Octect);
    adresse_++;
    
    uint16_t taille = (premier_Octect<<8) | deuxieme_Octect;
    
    for (uint16_t i = 2; i < taille; i++){ // etant donne le decallage apres le 0 et 1

        uint8_t donnee = USART_Receive();
        
        eeprom_write_byte(adresse_,donnee); // faut declarer "adresse" ds le main
        adresse_++;
    }
}

void debut(){

    lumiereRouge();
    delaisMS(UNE_SECONDE);

    lumiereVerte();
    delaisMS(UNE_SECONDE);
    
}

void attendre(uint16_t tempsEnMs){
    tempsEnMs*= DELAISMULTI;
    delaisMS(tempsEnMs);
}

/*
*Méthode 
*param: instruction, manoeuvre a effectuer
*param: operande, variable lié à l'instruction (temps, rapport pwm)
*
*/
void allumerLed(uint8_t operande){ // sauf port B car il prend les interruptions externe B2
   
    if (operande<=MAX_VERT && operande>=MIN_VERT){
        PORTA=VERT;
        _delay_ms(UNE_SECONDE);
    }
    else{
        PORTA=ROUGE;
        _delay_ms(UNE_SECONDE);
    }
}

void eteindreLed(){
    PORTA=ETEINT;
}

void allumerMatriceLed(uint8_t instruction){
    
    PORTC=instruction;
  
}

void eteindreMatriceLed(){
    PORTC=ETEINT;
}

void arretMoteur(){
    ajustementPWM(OFFPWM);
    PORTB=CENTRE;
}

void avancer(uint8_t operande){

    ajustementPWM(operande);
    PORTD |= (1<<PIND3) | (1<<PIND6);
    PORTB=NORD;

}

void tournerDroite(){
    tourner(ONPWM,OFFPWM);
    PORTB=EST;
}

void tournerGauche(){
    tourner(OFFPWM,ONPWM);
    PORTB=OUEST;
}

void reculer(uint8_t operande){
    ajustementPWM(operande);
  
    PORTD = (0<<PIND3) | (0<<PIND6);
    PORTB=SUD;
}

/*
*méthode qui prend en parametre 3 caractere representant l'instruction a afficher sur le moniteur
*param: tabInstruction, tableau de 3 char qui représente l'instruction 
*/
void uartAffichage(char tabInstruction [3]){
    initialisationUART();

    for (int i = 0; i < 3; i++){
        transmissionUART(tabInstruction[i]);
    }

    transmissionUART('\n');
}

/*
*Méthode qui détermine la manoeuvre du robot 
*param: instruction, manoeuvre a effectuer
*param: operande, variable lié à l'instruction (temps, rapport pwm)
*
*/
void instructionsFaire(uint8_t instruction, uint8_t operande){

    switch (instruction){

            case DBT:
                allumerMatriceLed(DBT);
                allumerLed(operande);
                eteindreLed();
                uartAffichage(CASE1);  
                break;
        
            case ATT:  
                attendre(operande); // 80*25 =1000 =2sec
                uartAffichage(CASE2);
                break;

            case DAL:
                allumerMatriceLed(DAL);
                allumerLed(operande);
                uartAffichage(CASE3);
                break;

            case DET:
                allumerMatriceLed(DET);
                eteindreLed();
                uartAffichage(CASE4);
                break;

            case MON:
                allumerMatriceLed(operande);
                uartAffichage(CASE5);
                break;

            case MOF:
                eteindreMatriceLed();
                uartAffichage(CASE6);
                break;

            case MAV:
                allumerMatriceLed(MAV);
                avancer(operande);
                uartAffichage(CASE7);
                break; 

            case MAR2:
                allumerMatriceLed(MAR2);
                arretMoteur();
                uartAffichage(CASE8);
                break;

            case TRD:
                allumerMatriceLed(TRD);
                tournerDroite();
                uartAffichage(CASE9);
                break;

            case TRG:
                allumerMatriceLed(TRG);
                tournerGauche();
                uartAffichage(CASE10);
                break;

            case MAR :
                allumerMatriceLed(MAR);
                arretMoteur();
                uartAffichage(CASE11);
                break;
            case MRE:
                allumerMatriceLed(MRE);
                reculer(operande);
                uartAffichage(CASE12);
                break;

            case DBC:
                allumerMatriceLed(DBC);
                
                if(premierTour== true)
                  nBoucles=operande;
                
                uartAffichage(CASE13);
                break;
            
            case FBC:
                allumerMatriceLed(FBC); 
               
                if(premierTour== true){ 
                    premierTour=false;
                  
                    for(uint8_t i=nBoucles;i>0;i=i-0x01){
                        adresse_ = adresseDBC;

                        while(instruction!=FBC){
                            instructRep_ = lire();
                            adresse_++;
                            opeRep_ = lire();
                            adresse_++;
                            instructionsFaire(instructRep_, opeRep_);
                        }
                    }
                    boucleTerminee=true;
                }
                uartAffichage(CASE14);
                break;

            case FIN:
                if(boucleTerminee==true){
                    allumerMatriceLed(FIN);
                    allumerLed(operande);
                    arretMoteur();
                    uartAffichage(CASE15);
                }
              
                break;
        }
    }
   
int main(){
    
    initialiserPort('A',SORTTIE_PORT);
    initialiserPort('B',SORTTIE_PORT);
    initialiserPort('C',SORTTIE_PORT);
    initialiserPort('D',SORTTIE_PORT);

    ////////////////////////////////////////// transmission avant la réception/////////////////////
    char tableau[10]= {'E','q','u','i','p','e','5','7','7','3'};
    int len = sizeof(tableau)/sizeof(tableau[0]);
    initialisationUART(); 
    for (int i = 0; i < len; i++){
        transmissionUART(tableau[i]);
    }
    ecrire_Eeprom();
    
    ////////////////////////////////////////////// cette premiere boucle while trouve le debut //////////
    uint8_t instruction,operande;
    
    while(true){

        instruction = lire(); 
        adresse_++;   
        operande= lire();       
        adresse_++;  
         
        if(instruction == DBT){
            instructionsFaire(instruction,operande);
     
            break;
            
        }

    }
    //////////////////// une fois le debut trouver on commence a faire les instructions qu'il faut///////
    while(true){
        
        instruction = lire(); 

        if(instruction==DBC)
            adresseDBC=adresse_;

        adresse_++;              
        operande = lire();
        adresse_++;  

        instructionsFaire(instruction,operande);
        
        if(instruction == FIN)
            break;
            
        
    }

    return 0;
}