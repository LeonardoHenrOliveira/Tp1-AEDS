#ifndef L_ROCHAS_H
#define L_ROCHAS_H
#include <stdio.h>
#include "Rocha.h"

typedef struct celula{
    Trocha rocha;
    struct celula* pProx;
}Tcelula;
typedef struct Celula* Apontador;
typedef struct {
    Apontador pPrimeiro;
    Apontador pUltimo;   
    struct celula* pProx;
}TLista;


void FLVazia(TLista* pLista, Tcelula* pcelula);
int LEHVazia(TLista* pLista);
int LInsere(TLista* pLista, Trocha* pRocha );
int LRetita(TLista* pLista, Trocha* pRocha);
void LImprime(TLista* pLista);

#endif