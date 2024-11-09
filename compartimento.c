#include <stdio.h>
#include <stdlib.h>
#include "compartimento.h"
#include "Rocha.h"

void FLVazia(TLista *pLista){
    pLista->pPrimeiro = (Apontador) malloc(sizeof(Tcelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
} 
int LEHVazia(TLista* pLista){
    return(pLista->pPrimeiro == pLista->pUltimo);
}
int LInsere(TLista* pLista, Trocha* pRocha ){
    pLista->pUltimo->pProx = (Apontador) malloc(sizeof(Tcelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->rocha= *pRocha;
    pLista->pPrimeiro->pProx = NULL;
}
int LRetita(TLista* pLista, Trocha* pRocha){
    Tcelula* pAux;
    if (LEHVazia(pLista)){
        return 0;
    }
    *pRocha = pLista->pPrimeiro->pProx->rocha;
    pAux = pLista -> pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(pAux);
    return 1;
}
void LImprime(TLista* pLista){
    Apontador pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux!=NULL){
        printf("");
    }
}