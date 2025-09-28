#include "Pire.h"
#include <stdlib.h>
#include <stdio.h>

pire pireOlustur(int deger, char sembol) {
    pire this = (pire)malloc(sizeof(struct PIRE));
    if (!this) return NULL;
    this->super = bocekOlustur(deger, sembol);
    this->sil = &pireSil;
    this->super->super->sayi=deger;
    this->super->super->harf=sembol;
    return this;
}

void pireSil(pire this) {
    if (this != NULL) {
        if (this->super->sil) {
            this->super->sil(this->super);
        }
        free(this);
    }
}