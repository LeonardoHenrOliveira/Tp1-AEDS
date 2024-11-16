#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
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

void LImprime_s(Lista_s* lista_sonda, TLista* lista_c){
    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        printf("\n");
        printf("Identificador sonda:%d\n ",pAux->item.Identificador);
        printf("status:%d\n ",pAux->item.EstaLigada);
        printf("localizacao:(%.2f,%.2f)\n ",pAux->item.Latitude,pAux->item.Longitude);
        printf("capacidade:%.2f\n ",pAux->item.capacidade);
        printf("\n");
        LImprime(lista_c);
        pAux = pAux->pProx;

    }
}

void CalculaNovaRocha(Lista_s *lista_sonda, Trocha* rocha){

    TSonda* sondaProx = NULL;
    float longt = rocha->latitude;
    float lat = rocha->latitude;

    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){

        float cap_disponivel = pAux->item.capacidade - pAux->item.peso;
        TSonda sonda = pAux->item;

        if(cap_disponivel < rocha->peso){
        continue;
        }

        LogicaEuclides(lista_sonda, &sonda, longt, lat, sondaProx);

        pAux = pAux->pProx;
    }   
    sondaProx->compartimento->pUltimo->rocha = *rocha;
}


int LogicaEuclides(Lista_s *lista_sonda, TSonda* sonda, float longitude, float latitude, TSonda* sonda_prox){
    float dist_anterior, dist_atual;

    if(sonda_prox == NULL){
        sonda_prox = sonda;
        return 0;
    }

    dist_anterior = sqrt(pow(latitude - sonda_prox->Latitude, 2) + pow(longitude - sonda_prox->Longitude, 2));
    dist_atual = sqrt(pow(latitude - sonda->Latitude, 2) + pow(longitude - sonda->Longitude, 2));

    if(dist_anterior > dist_atual){
        sonda_prox = sonda;
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

void RedistribuirSondas(Lista_s* lista_Sonda){
    Apontador_s pAux;
    pAux = lista_Sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        
        pAux = pAux->pProx;
    }
}

void OperacaoE(Lista_s* lista_sonda){
}