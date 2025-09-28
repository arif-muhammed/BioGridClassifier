#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{
    canli super;
    void(*sil)(struct BITKI*); 

};
typedef struct BITKI *bitki;
char* bitkiGorunum();
bitki bitkiOlustur(int deger, char sembol);
void bitkiSil(bitki this); 
#endif
