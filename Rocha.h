#ifndef ROCHA_H
#define ROCHA_H
#include <stdio.h>
#include "L_Minerais.h"

typedef int tiporocha;
typedef struct {
    int identificador;
    float peso;
    char categoria[100];

    tiporocha rocha;
    float latitude;
    float longitude;
    
}Trocha;

void setIdentificador(Trocha *rocha, int identificador);
void setpeso(Trocha *rocha, float peso);
void setcategoria(Trocha *rocha, int identificador);
void setlocalização(Trocha *rocha, float latitude, float longitude);

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude);

int getIdentificador(Trocha* rocha);
float getpeso(Trocha* rocha);
char* getcategoria(Trocha* rocha);
float getlatitude(Trocha* rocha);
float getlongitude(Trocha* rocha);

#endif