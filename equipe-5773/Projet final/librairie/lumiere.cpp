#include"lumiere.h"



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
    _delay_ms(10);
    PORTA = EN_ROUGE;
    _delay_ms(10);
}
void lumiereOff(){
    PORTA=0x00;
}