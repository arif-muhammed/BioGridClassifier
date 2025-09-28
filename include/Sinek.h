#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {
    bocek super;
    void(*sil)(struct SINEK*); 

};
typedef struct SINEK *sinek;
char* sinekGorunum();
sinek sinekOlustur(int deger, char sembol);
void sinekSil(sinek p); 

#endif