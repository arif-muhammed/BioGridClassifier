#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
    canli super;
    char harf;
    int sayi;
    void(*sil)(struct BOCEK*); 

} ;

typedef struct BOCEK *bocek;
char* bocekGorunum();
bocek bocekOlustur(int deger, char sembol);
void bocekSil(bocek this); 

#endif