#include <stdio.h>
#include "compartimento.h"
#include "Sonda.h"

typedef struct Celula_s{
    TSonda item;
    struct Celula_s* pProx;
}Celula_s;

typedef struct {
    struct Celula_s* pPrimeiro;
    struct Celula_s* pUltimo;
}Lista_s;

void FLVazia(Lista_s* pLista);
int LEHVazia(Lista_s* pLista);
int LInsere(Lista_s* pLista, TSonda* pRocha );
int LRetita(Lista_s* pLista, TSonda* pRocha);
void LImprime(Lista_s* pLista);