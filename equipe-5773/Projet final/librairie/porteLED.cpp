#include "porteLED.h"

#define lireDsON() (PORTA |= 0x04)
#define lireDsOFF() (PORTA &= 0xfb)

#define copierRegistreON() (PORTA |= 0x08)
#define copierRegistreOFF() (PORTA &= 0xf7)

#define boutonDsON() (PORTA |= 0x10)
#define boutonDsOFF() (PORTA &= 0xef)

#define boutonMrON() (PORTA |= 0x20)
#define boutonMrOFF() (PORTA &= 0xdf)

void lireDs() // SH_CP
{
    lireDsON();
    _delay_ms(125);
    lireDsOFF();
    _delay_ms(125);
}

void copierRegistre() //ST_CP
{
 copierRegistreON();
    _delay_ms(125);
 copierRegistreOFF();
    _delay_ms(125);
}

void etteindreLED() // MR
{
    boutonMrOFF();
    boutonMrON();
 copierRegistreON();
 copierRegistreOFF();
}

void ignorerPorte()
{
    boutonDsOFF();
    for(int i = 0; i < 8; i++)
    {
        lireDsON();
        lireDsOFF();
    }
}

void ouvrirPorteA()
{
    boutonMrON();
    for(int i = 0; i < 8; i++)
    {
     etteindreLED();
        boutonDsON();
        for(int j = 8-i; j > 1; j--)
        {
            lireDsON();
            lireDsOFF();
        }
     copierRegistre();
    }
}

void ouvrirPorteB()
{
    boutonMrON();
    for(int i = 0; i < 8; i++)
    {
     etteindreLED();
        boutonDsON();
        for(int j = 8-i; j > 1; j--)
        {
            lireDsON();
            lireDsOFF();
        }
        ignorerPorte();
     copierRegistre();
    }
}

void ouvrirPorteC()
{
    boutonMrON();
    for(int i = 0; i < 8; i++)
    {
     etteindreLED();
        boutonDsON();
        for(int j = 8-i; j > 1; j--)
        {
            lireDsON();
            lireDsOFF();
        }
        ignorerPorte();
        ignorerPorte();
     copierRegistre();
    }
}

void ouvrirPorteD()
{
    boutonMrON();
    for(int i = 0; i < 8; i++)
    {
     etteindreLED();
        boutonDsON();
        for(int j = 8-i; j > 1; j--)
        {
            lireDsON();
            lireDsOFF();
        }
        ignorerPorte();
        ignorerPorte();
        ignorerPorte();
     copierRegistre();
    }
}

void fermerPorteA()
{
    boutonMrON();
    for(int j= 0; j < 8; j++)
    {
     etteindreLED();
        boutonDsON();
        for(int k = 0; k < 1+j; k++)
        {
            lireDsON();
            lireDsOFF();           
        }
     copierRegistre();
    }
}


void fermerPorteB()
{
    boutonMrON();
    for(int j= 0; j < 8; j++)
    {
     etteindreLED();
        boutonDsON();
        for(int k = 0; k < 1+j; k++)
        {
            lireDsON();
            lireDsOFF();           
        }
        ignorerPorte();
     copierRegistre();
    }
}

void fermerPorteC()
{
    boutonMrON();
    for(int j= 0; j < 8; j++)
    {
     etteindreLED();
        boutonDsON();
        for(int k = 0; k < 1+j; k++)
        {
            lireDsON();
            lireDsOFF();           
        }
        ignorerPorte();
        ignorerPorte();
     copierRegistre();
    }
}

void fermerPorteD()

{
    boutonMrON();
    for(int j= 0; j < 8; j++)
    {
     etteindreLED();
        boutonDsON();
        for(int k = 0; k < 1+j; k++)
        {
            lireDsON();
            lireDsOFF();           
        }
        ignorerPorte();
        ignorerPorte();
        ignorerPorte();
     copierRegistre();
    }
}


