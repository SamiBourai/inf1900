
#include "delayMS.h"

////////////////////////////pour grand temps/////////////////////
void delaisMS (uint16_t tempsMS) 
{
    for (uint16_t i = 0; i < tempsMS; i++) 
    {
        _delay_ms (1);
    }
}
////////////////////////pour petit temps////////////////////
void delaisUS(uint16_t tempsUS)
{
    for (uint16_t i = 0; i <tempsUS ; i++){
        _delay_us(1);
    }

}