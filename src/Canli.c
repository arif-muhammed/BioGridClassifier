#include "Canli.h"
#include <stdlib.h>
#include <stdio.h>

canli canliOlustur(int deger, char sembol) {
    canli this = (canli)malloc(sizeof(struct CANLI));
    if (!this) return NULL;
    this->harf = sembol;
    this->sayi = deger;
    this->sil = &canliSil;  
    return this;
}

void canliSil(canli this) {
    if (this != NULL) {
        free(this);
    }
}
