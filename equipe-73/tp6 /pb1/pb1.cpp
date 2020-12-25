/*
* Nom: pb2.cpp
* Auteurs : Mounib Djellab (1909732) et sami bourai (2041659)
* Description: Tout d'abord cette classe permet d'implementer un robot qui réagis à l'intansité de la lumière.
               Cela ce fait par un senseur que l'on place dans un circuit qui permet de transformer un signal lumineux
               en donnée binaire. Suite à cela, on compare cette donnée binaire avec une échelle que nous avons nous 
               même établie, et dépendament de l'intensité de la lumière, une led s'allumera sois en vert, 
               en rouge ou en orange(ambree).
* Entrée: DDRA (PORT A)
* Sortie: DDRB (PORT B)
*/

#define F_CPU 8000000
#include "can.h"
#include <avr/io.h>
#include <util/delay.h>

//variable constante utilisé pour définir les ports d'entrées et sorties
const uint8_t ouputPort = 0xff;
const uint8_t inputPort = 0x00;

//variable utilisé pour définir les changements d'états de la led
const int highLight = 230, lowLight = 160;

// senseur
can sensor;

// variable servant à manipuler la coloration de la led et à lire l'intansité de la lumière
const uint8_t green = 0x01;
const uint8_t red = 0x02;
const uint8_t on = 0x00;

// variable utilisé pour les delays de la couleur ambre et la bascule des données de l'intensité lumineuse
const int greenAmbree=8, redAmbree=15, bitShift=2;

// variable utilisé pour la lecture de l'intancité lumineuse
uint16_t brightness_16 ;
uint8_t brightness_8;

//méthode implémenté dans l'optique de l'affichage visuel de la lumière de coloration ambrée.
void Ambree(){

    PORTB = green;
    _delay_ms(greenAmbree);
    PORTB = red;
    _delay_ms(redAmbree);
}

int main()
{
    DDRA = inputPort; // PORT D est en mode entrée
    DDRB = ouputPort; // PORT B est en mode sortie

    while (true)
    {
         //conversion de la lumière en données numeriques et prise en compte des bits appropriés
        brightness_16 = sensor.lecture(on);
        brightness_8 = brightness_16 >> bitShift;

        if (brightness_8 < lowLight)
            PORTB = green;
        else if (brightness_8 >= highLight)
            PORTB = red;
        else
            Ambree();
    }
    return 0;
}