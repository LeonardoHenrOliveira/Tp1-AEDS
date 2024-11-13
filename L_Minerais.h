#ifndef L_MINERAIS_H
#define L_MINERAIS_H

#include <stdio.h>
#include "Minerais.h"
#define MAXTAM 5
#define INICIO 0
#define maxtamentrada 3

typedef struct {
    Minerais item[MAXTAM];
    int primeiro;
    int ultimo;
}L_Minerais;
typedef struct{
    entradaminerais iteme[maxtamentrada];
    int primeiroe;
    int ultimoe;
}L_entrada;

void FLvazia(L_Minerais* lista_m);
int LEhVazia(L_Minerais* lista_m);
int LInsere(L_Minerais* lista_m, Minerais x);
int Lretira(L_Minerais* lista_m, int p, Minerais *px);
void LImprime(L_Minerais* lista_m);

void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral);

void FLvaziae(L_entrada* lista_e);
int LInseree(L_entrada* lista_e, char* y);

#endif