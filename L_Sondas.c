#include <stdio.h>
#include "L_Sondas.h"

void FLVazia(Lista_s *lista_sonda){
    lista_sonda->pPrimeiro = (Celula_s*)malloc(sizeof(Celula_s));
    lista_sonda->pUltimo = lista_sonda->pPrimeiro;
    lista_sonda->pPrimeiro->pProx = NULL;
} 
int LEHVazia(Lista_s* lista_sonda){
    return(lista_sonda->pPrimeiro == lista_sonda->pUltimo);
}
int LInsere(Lista_s* lista_sonda, TSonda* sonda ){
    lista_sonda->pUltimo->pProx = (Celula_s*)malloc(sizeof(Tcelula));
    lista_sonda->pUltimo = lista_sonda->pUltimo->pProx;
    lista_sonda->pUltimo->item = *sonda;
    lista_sonda->pPrimeiro->pProx = NULL;
}
int LRetira(Lista_s* lista_sonda, TSonda* sonda){
    Celula_s* pAux;
    if (LEHVazia(lista_sonda)){
        return 0;
    }
    *sonda = lista_sonda->pPrimeiro->pProx->item;
    pAux = lista_sonda -> pPrimeiro;
    lista_sonda->pPrimeiro = lista_sonda->pPrimeiro->pProx;
    free(pAux);
    return 1;
}
void LImprime(Lista_s* lista_sonda){
    Apontador pAux;
    pAux = lista_sonda->pPrimeiro->pProx;
    while (pAux!=NULL){
        printf("");
    }
}
