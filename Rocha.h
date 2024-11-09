#ifndef ROCHA_H
#define ROCHA_H
#include <stdio.h>
#include "L_Minerais.h"

typedef int tiporocha;
typedef struct {
    char identificador[100];
    float peso;
    tiporocha rocha;
    int latitude;
    int longitude;
    
}Trocha;

#endif