#include "Bocek.h"
#include <stdlib.h>
#include <stdio.h>

bocek bocekOlustur(int deger, char sembol) {
    bocek this = (bocek)malloc(sizeof(struct BOCEK));
    if (!this) return NULL;
    this->super = canliOlustur(deger, sembol);
    this->sil = &bocekSil;
    this->super->harf = sembol;
    this->super->sayi = deger;
    return this;
}

void bocekSil(bocek this) {
    if (this != NULL) {
        if (this->super->sil) {
            this->super->sil(this->super);
        }
        free(this);
    }
}