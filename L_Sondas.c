#include <stdio.h>
#include <stdlib.h>
#include "L_Sondas.h"

void FLVazia_s(Lista_s *lista_sonda){
    printf("1");
    lista_sonda->pPrimeiro_s = (Apontador_s)malloc(sizeof(Celula_s));
    printf("2");
    lista_sonda->pUltimo_s = lista_sonda->pPrimeiro_s;
    printf("3");
    lista_sonda->pPrimeiro_s->pProx = NULL;
} 

int LEHVazia_s(Lista_s* lista_sonda){
    return(lista_sonda->pPrimeiro_s == lista_sonda->pUltimo_s);
}

int LInsere_s(Lista_s* lista_sonda, TSonda* sonda ){
    lista_sonda->pUltimo_s->pProx = (Celula_s*)malloc(sizeof(Celula_s));
    lista_sonda->pUltimo_s = lista_sonda->pUltimo_s->pProx;
    lista_sonda->pUltimo_s->item = *sonda;
    lista_sonda->pPrimeiro_s->pProx = NULL;
}

int LRetira_s(Lista_s* lista_sonda, TSonda* sonda){
    Celula_s* pAux;
    if (LEHVazia_s(lista_sonda)){
        return 0;
    }
    *sonda = lista_sonda->pPrimeiro_s->pProx->item;
    pAux = lista_sonda->pPrimeiro_s;
    lista_sonda->pPrimeiro_s = lista_sonda->pPrimeiro_s->pProx;
    free(pAux);
    return 1;
}
/*
void LImprime_s(Lista_s* lista_sonda){
    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        printf("");
    }
}
*/