

#define DEBUG // à mettre en commentaire au besoin

#ifdef DEBUG

#define DEBUG_PRINT(x) printf (x) // ou par RS-232

#else

#define DEBUG_PRINT(x) do {} while (0) // code mort

#endif


void printf(char mots[]);
