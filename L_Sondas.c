#include <stdio.h>
#include <stdlib.h>
#include "L_Sondas.h"

void FLVazia_s(Lista_s *lista_sonda){

    lista_sonda->pPrimeiro_s = (Apontador_s)malloc(sizeof(Celula_s));
    lista_sonda->pUltimo_s = lista_sonda->pPrimeiro_s;
    lista_sonda->pPrimeiro_s->pProx = NULL;
} 

int LEHVazia_s(Lista_s* lista_sonda){
    return(lista_sonda->pPrimeiro_s == lista_sonda->pUltimo_s);
}

int LInsere_s(Lista_s* lista_sonda, TSonda* sonda ){
    lista_sonda->pUltimo_s->pProx = (Celula_s*)malloc(sizeof(Celula_s));
    lista_sonda->pUltimo_s = lista_sonda->pUltimo_s->pProx;
    lista_sonda->pUltimo_s->item = *sonda;
    lista_sonda->pUltimo_s->pProx = NULL;
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

void LImprime_s(Lista_s* lista_sonda){
    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    printf("1");
    while (pAux!=NULL){
        printf("21");
        printf("Identificador sonda:%d\n",pAux->item.Identificador);
        printf("status:%d\n",pAux->item.EstaLigada);
        printf("localizacao:(%f,%f)\n",pAux->item.Latitude,pAux->item.Longitude);
        printf("capacidade:%f\n",pAux->item.capacidade);
        pAux = pAux->pProx;

    }
}

float MediaSondas(Lista_s* lista_sonda){
    float media = 0.0;
    int qnt = 0;

    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        media += pAux->item.peso;
        qnt++;
        pAux = pAux->pProx;
    }

    media = media/qnt;
    return media;
}

void PosicaoInicial(Lista_s* lista_sonda){
    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        pAux->item.Latitude = 0.0;
        pAux->item.Longitude = 0.0;
        pAux = pAux->pProx;
    }

}