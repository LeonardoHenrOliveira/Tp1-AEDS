#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    lista_sonda->pUltimo_s->pProx = (Apontador_s)malloc(sizeof(Celula_s));
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
    while (pAux!=NULL){
        TLista *lista_c;
        lista_c = pAux->item.compartimento;
        
        printf("\n");
        printf("Identificador sonda:%d\n ",pAux->item.Identificador);
        printf("status:%d\n ",pAux->item.EstaLigada);
        printf("localizacao:(%.2f,%.2f)\n ",pAux->item.Latitude,pAux->item.Longitude);
        printf("capacidade:%.2f\n ",pAux->item.capacidade);
        printf("\n");
        if(pAux->item.compartimento->pPrimeiro){
            printf("\nCompartimento vazio!!!");
        }else{
            printf("==============================\n");
            printf("%s\n", pAux->item.compartimento->pPrimeiro->pProx->rocha.categoria);
            printf("%d\n", pAux->item.compartimento->pPrimeiro->pProx->rocha.identificador);
            printf("%.2f\n", pAux->item.compartimento->pPrimeiro->pProx->rocha.peso);
            printf("%.2f\n", pAux->item.compartimento->pPrimeiro->pProx->rocha.latitude);
            printf("%.2f\n",  pAux->item.compartimento->pPrimeiro->pProx->rocha.longitude);
        }
        pAux = pAux->pProx;
    }
    
}



TSonda* Calculo_sonda_prox(Lista_s *lista_sonda, Trocha *rocha) {
    TSonda *sondaProx = NULL;
    float m_distancia = 10000000000000; 
    float distancia=0;
    float longt = rocha->longitude; 
    float lat = rocha->latitude;

    Celula_s* usando= lista_sonda->pPrimeiro_s->pProx;

    while (usando!= NULL){
        TSonda *sonda_s = &usando->item;
        distancia = sqrt(pow(lat - sonda_s->Latitude, 2) + pow(longt - sonda_s->Longitude, 2));
        if (distancia<m_distancia){
            m_distancia=distancia;
            sondaProx=sonda_s;
        }
        usando=usando->pProx;
    }
    printf("\n++++ Coleta realizada com sucesso! ++++\n");
    printf("Sonda: %d\n", sondaProx->Identificador);
    printf("Rocha coletada: %s, Peso: %f\n", rocha->categoria, rocha->peso);
    printf("Nova posição da sonda: (%f, %f)\n", sondaProx->Latitude, sondaProx->Longitude);

    return sondaProx;
}


int ContemCategoria(TSonda *sonda, const char *categoria, float pesoMinimo) {
    if (sonda->compartimento == NULL) {
        return 0;
    }

    Tcelula *pAux = sonda->compartimento->pPrimeiro;
    while (pAux != NULL) {
        if (strcmp(pAux->rocha.categoria, categoria) == 0 && pAux->rocha.peso > pesoMinimo) {
            return 1;
        }
        pAux = pAux->pProx;
    }

    return 0;
}

void operacaoI(Lista_s* lista_sonda){

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