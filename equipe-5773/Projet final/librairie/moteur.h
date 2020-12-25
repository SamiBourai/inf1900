#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>


const double RAPPORT_ANGLE = 1.44;
const uint8_t ANGLE_ZERO = 126;
// determiner angle sur 255 a partir de l'angle sur 180
int angleServo(int angle); 
// fonctoion pour faire tourner les servos
void faireTournerServoF( int angleEntre);
void faireTournerServoE(int angleEntre);

void initialiserPort(char port, uint8_t mode);
