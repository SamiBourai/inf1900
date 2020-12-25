#include "moteur.h"



int angleServo(int angle)
{
	
	return ANGLE_ZERO + (angle/RAPPORT_ANGLE);
}
void faireTournerServoF( int angleEntre)
{
	DDRD |= (1<<PD5);	//pin 5 en output
	
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	
	int angle = angleServo(angleEntre);    
	OCR1A = angle;
	
}
void faireTournerServoE(int angleEntre)
{
	DDRD |= (1<<PD4);	//pin 5 en output
	
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	
	int angle = angleServo(angleEntre);  // determiner angle sur 255
	OCR1B = angle;
	
}

void initialiserPort(char port, uint8_t mode) 
{
	switch (port) 
	{
		case 'A':
        case 'a':
			DDRA = mode;
			break;	
		case 'B':
        case 'b':
			DDRB = mode;
			break;
		case 'C':
        case 'c':
			DDRC = mode;
			break;
		case 'D':
        case 'd':
			DDRD = mode;
			break;	
	}  
}


