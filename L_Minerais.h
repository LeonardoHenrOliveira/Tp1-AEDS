#include <stdio.h>
#include "Minerais.h"
#define MAXTAM 5
#define INICIO 0

typedef struct
{
    Minerais Mine; 
}Mineral;

typedef struct 
{
    Mineral item[MAXTAM];
    int primeiro;
    int ultimo;
}L_Minerais;

void FLvazia(L_Minerais* lista_m);
int LEhVazia(L_Minerais* lista_m);
int LInsere(L_Minerais* lista_m, Mineral x);
int Lretira(L_Minerais* lista_m, int p, Mineral *px);
void LImprime(L_Minerais* lista_m);

void PreencheMinerais(L_Minerais* lista_m);
