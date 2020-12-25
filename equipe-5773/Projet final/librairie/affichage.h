


#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

#include "lcm_so1602dtr_m_fw.h"
#include "lcm_so1602dtr_m.h"
#include "customprocs.h"

#include"UART.h"

const char ENTRER[35]={'E','n','t','r','e','r'};
const char option1[35]= {'1','-','D','e','f','i','n','i','r',' ','l',' ','h','e','u','r','e',' ','d','e',' ','d','e','p','a','r','t'}; 
const char OPTION_2_MESSAGE[35]= {'2','-','D','e','f','n','i','r',' ','l',' ','e','t','a','t',' ','d',' ','u','n',' ','d','i','s','p','o','s','i','t','i','f'};
const char option3[35]= {'3','-','A','f','f','i','c','h','e','r',' ','l','e','s',' ','a','c','t','i','o','n','s',' ','p','r','o','g','r','a','m','m','e','e','s'};
const char option4[35]= {'4','-','P','r','o','g','r','a','m','m','e','r',' ','u','n','e',' ','a','c','t','i','o','n'}; 
const char option5[35]= {'5','-','S','u','p','p','r','i','m','e','r',' ','u','n','e',' ','a','c','t','i','o','n',' ','p','r','o','g','r','a','m','m','e','e'}; 
const char option6[35]= {'6','-','D','e','m','a','r','r','e','r',' ','l','a',' ','s','i','m','u','l','a','t','i','o','n'};
const char choix[35]= {'-','C','h','o','i','s','i','s','s','e','z',' ','u','n','e',' ','o','p','t','i','o','n',':'};
const char MESSAGE_HEURE[35]={'-','E','n','t','r','e','z',' ','u','n','e',' ','h','e','u','r','e',':'};
const char tabErreur[35]={'E','n','t','r','e','r','i','n','v','a','l','i','d','e','!'}; 
//const char MESSAGE_DISPOSITIF [50] = {ENTREE}
//Entrez l’identifiant d’un dispositif suivi de sa valeur de configuration. 

void afficherMode(char mode,LCM& disp);
void affichageDeuxiemeLigneLCd(char tableau[16], LCM& disp);
void afficherMessageErreur();
void afficherMenuRS232();
void afficherOption1();
void afficherOption5();
void attendreAffichage(void);