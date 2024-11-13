#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

typedef struct  Celula_s* Apontador_s;
typedef struct Celula_s{
    TSonda item;
    struct Celula_s* pProx;
}Celula_s;


typedef struct {
    Apontador_s pPrimeiro;
    Apontador_s pUltimo;
}Lista_s;

void FLVazia_s(Lista_s* pLista);
int LEHVazia_s(Lista_s* pLista);
int LInsere_s(Lista_s* pLista, TSonda* sonda );
int LRetita_s(Lista_s* pLista, TSonda* sonda);
