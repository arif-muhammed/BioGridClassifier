#include "Sinek.h"
#include <stdlib.h>
#include <stdio.h>

sinek sinekOlustur(int deger, char sembol) {
    sinek this = (sinek)malloc(sizeof(struct SINEK));
    if (!this) return NULL;
    this->super = bocekOlustur(deger, sembol);
    this->sil = &sinekSil;
    this->super->super->sayi=deger;
    this->super->super->harf=sembol;
    return this;
}

void sinekSil(sinek this) {
    if (this != NULL) {
        if (this->super->sil) {
            this->super->sil(this->super);
        }
        free(this);
    }
}