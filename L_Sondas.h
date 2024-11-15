#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

typedef struct  Celula_s* Apontador_s;
typedef struct Celula_s{
    TSonda item;
    struct Celula_s* pProx;
}Celula_s;


typedef struct {
    Apontador_s pPrimeiro_s;
    Apontador_s pUltimo_s;
}Lista_s;

void FLVazia_s(Lista_s* lista_sonda);
int LEHVazia_s(Lista_s* lista_sonda);
int LInsere_s(Lista_s* lista_sonda, TSonda* sonda );
int LRetita_s(Lista_s* lista_sonda, TSonda* sonda);
void LImprime_s(Lista_s* lista_sonda);

float MediaSondas(Lista_s* lista_sonda);
void PosicaoInicial(Lista_s* lista_sonda);