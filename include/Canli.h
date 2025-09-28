#ifndef CANLI_H
#define CANLI_H


struct CANLI {
    char harf;
    int sayi;
    void(*sil)(struct CANLI*); 
    char* (*gorunum)();
};

typedef struct CANLI *canli;
canli canliOlustur(int deger, char sembol);
void canliSil(canli this); 

#endif