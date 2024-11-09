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


#endif