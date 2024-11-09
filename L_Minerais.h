#include <stdio.h>
#include "Minerais.c"
#define MAXTAM 5
#define INICIO 0

typedef struct 
{
    Minerais item[MAXTAM];
    int primeiro;
    int ultimo;
}L_Minerais;

void FLvazia(L_Minerais* lista_m);
int LEhVazia(L_Minerais* lista_m);
int LInsere(L_Minerais* lista_m, Minerais x);
int Lretira(L_Minerais* lista_m, int p, Minerais *px);
void LImprime(L_Minerais* lista_m);

void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral);