
#include "delayMS.h"


void delaisMS (uint16_t tempsMS) 
{
    for (uint16_t i = 0; i < tempsMS; i++) 
    {
        _delay_ms (1);
    }
}
