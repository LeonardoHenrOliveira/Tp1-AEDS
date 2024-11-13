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
    char* listam[3];
    float latitude;
    float longitude;
    
}Trocha;

void setidentificador(Trocha *rocha, int identificador);
void setpeso(Trocha *rocha, float peso);
void setcategoria(Trocha *rocha, char* categoria);
void setlocalizacao(Trocha *rocha, float latitude, float longitude);

//char* classifica_categoria(char* mineral1, char*mineral2,char* mineral3, int j);

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude);

int getidentificador(Trocha* rocha);
float getpeso(Trocha* rocha);
char* getcategoria(Trocha* rocha);
float getlatitude(Trocha* rocha);
float getlongitude(Trocha* rocha);

#endif