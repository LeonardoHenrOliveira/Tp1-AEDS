#ifndef L_MINERAIS_H
#define L_MINERAIS_H

#include <stdio.h>
#include "Minerais.h"
#define MAXTAM 5
#define INICIO 0


typedef struct {
    Minerais item[MAXTAM];
    int primeiro;
    int ultimo;
}L_Minerais;



void FLvazia_m(L_Minerais* lista_m);
int LEhVazia_m(L_Minerais* lista_m);
int LInsere_m(L_Minerais* lista_m, Minerais x);
int Lretira_m(L_Minerais* lista_m, int p, Minerais *px);
void LImprime_m(L_Minerais* lista_m);


void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral);



#endif