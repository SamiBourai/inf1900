
#include"affichage.h"




void afficherMode(char mode,LCM& disp){
	if (mode=='6')
	{
		disp.clear();
		disp<<"Simulation : ";
		attendreAffichage();
	}
	else{
		disp<<"Configuration : ";
		attendreAffichage();
	}
}
void affichageDeuxiemeLigneLCd(char tableau[16], LCM& disp){
	
	for (size_t i = 16; i <= 32; i++)
	{
		disp.write(tableau, i); // sauter la première ligne   
		attendreAffichage();

	}
}

void afficherMessageErreur(){
	
	afficherChaine(tabErreur,35);
	transmissionUART('\n');
}
void afficherOption1(){
	transmissionUART('\n');
	afficherChaine(option1,35);
    transmissionUART('\n');
}
void afficherOption5(){
	transmissionUART('\n');
	afficherChaine(option5,35);
    transmissionUART('\n');
}
void afficherMenuRS232()
{
 
    transmissionUART('\n');
	afficherChaine(option1,35);
    transmissionUART('\n');
    afficherChaine(OPTION_2_MESSAGE,35);
    transmissionUART('\n');
    afficherChaine(option3,35);
    transmissionUART('\n');
    afficherChaine(option4,35);
    transmissionUART('\n');
    afficherChaine(option5,35);
    transmissionUART('\n');
    afficherChaine(option6,35);
    transmissionUART('\n');
	transmissionUART('\n');
	afficherChaine(choix,35);
    transmissionUART('\n');
}
void attendreAffichage(void) {
	cp_wait_ms(165);
}