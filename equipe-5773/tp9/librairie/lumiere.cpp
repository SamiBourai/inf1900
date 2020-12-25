#include"lumiere.h"
#include"moteur.h"
#include"delayMS.h"

void lumiereVerte(){
    //initialiserPort('A', SORTIE );
    PORTA = EN_VERT;
}
void lumiereRouge(){
   // initialiserPort('A', SORTIE );
    PORTA = EN_ROUGE;
    
}
void lumiereAmbree(){
    //initialiserPort('A', SORTIE );
    PORTA = EN_VERT;
    delaisUS(TEMPS_COULEUR_AMBREE);
    PORTA = EN_ROUGE;
    delaisUS(TEMPS_COULEUR_AMBREE);
}
void lumiereOff(){
    PORTA=0x00;
}