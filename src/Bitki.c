#include "Bitki.h"
#include <stdlib.h>
#include <stdio.h>

bitki bitkiOlustur(int deger, char sembol) {
    bitki this = (bitki)malloc(sizeof(struct BITKI));
    if (!this) return NULL;
    this->super = canliOlustur(deger, sembol);
    this->sil = &bitkiSil;
    this->super->harf = sembol;
    this->super->sayi = deger;
    return this;
}

void bitkiSil(bitki this) {
    if (this != NULL) {
        if (this->super->sil) {
            this->super->sil(this->super);
        }
        free(this);
    }
}