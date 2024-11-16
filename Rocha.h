#ifndef ROCHA_H
#define ROCHA_H
#include <stdio.h>
#include "L_Minerais.h"

typedef int tiporocha;
typedef struct {
    int identificador;
    float peso;
    char categoria[20];
    tiporocha rocha;
    L_entrada lista_minerais;
    float latitude;
    float longitude;
    
}Trocha;

void setidentificador(Trocha *rocha, int identificador);
void setpeso(Trocha *rocha, float peso);
void setlatitude(Trocha *rocha, float latitude);
void setlongitude(Trocha *rocha, float longitude);
void SetCategoria(Trocha*rocha,char* categoria);

char* classifica_categoria(L_entrada* lista_e,int j, L_Minerais * lista_m, Trocha * rocha_m);

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude, char* categoria);


int getidentificador(Trocha* rocha);
float getpeso(Trocha* rocha);
char* getcategoria(Trocha* rocha);
float getlatitude(Trocha* rocha);
float getlongitude(Trocha* rocha);

#endif