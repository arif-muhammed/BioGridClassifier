#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE {
    bocek super;
    void(*sil)(struct PIRE*); 
};
typedef struct PIRE *pire;
char* pireGorunum();
pire pireOlustur(int deger, char sembol);
void pireSil(pire p); 

#endif
