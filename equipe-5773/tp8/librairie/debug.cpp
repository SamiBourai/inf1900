#include "debug.h"
#include "UART.h"


void printf( char mots[])
{
    initialisationUART();
    uint8_t i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            
            transmissionUART(mots[j]);
        }
    }
    
}

