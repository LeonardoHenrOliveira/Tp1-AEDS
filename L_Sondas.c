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



void CalculaNovaRocha(Lista_s *lista_sonda, Trocha *rocha) {
    TSonda *sondaProx = NULL; // Armazena a sonda mais próxima que pode coletar a rocha

    float longt = rocha->longitude; 
    float lat = rocha->latitude;
    printf("\nuu\n");

    // Percorre a lista de sondas
    Apontador_s pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux != NULL) {
        TSonda *sonda = &pAux->item;
        float cap_disponivel = sonda->capacidade - sonda->peso;

        // Verifica se a sonda pode coletar a rocha
        if (cap_disponivel >= rocha->peso || ContemCategoria(sonda, rocha->categoria, rocha->peso)) {
            LogicaEuclides(lista_sonda, sonda, longt, lat, &sondaProx);
            printf("\nTETETET: %s", sondaProx->compartimento->pUltimo->rocha.categoria);

        }

        pAux = pAux->pProx;
    }

    if (sondaProx == NULL) {
        printf("Nenhuma sonda adequada foi encontrada para coletar a rocha.\n");
        return;
    }

    // Move a sonda selecionada para a posição da rocha
    sondaProx->Latitude = rocha->latitude;
    sondaProx->Longitude = rocha->longitude;

    // Insere a rocha no compartimento da sonda
    if (sondaProx->compartimento == NULL) {
        sondaProx->compartimento->pPrimeiro->pProx = (Apontador)malloc(sizeof(Tcelula));
        sondaProx->compartimento->pPrimeiro = NULL;
        sondaProx->compartimento->pUltimo = NULL;
    }


    Tcelula *novaCelula = (Tcelula *)malloc(sizeof(Tcelula));
    novaCelula->rocha = *rocha;
    novaCelula->pProx = NULL;

    if (sondaProx->compartimento->pPrimeiro == NULL) {
        sondaProx->compartimento->pPrimeiro = novaCelula;
        sondaProx->compartimento->pUltimo = novaCelula;
    } else {
        sondaProx->compartimento->pUltimo->pProx = novaCelula;
        sondaProx->compartimento->pUltimo = novaCelula;
    }

    // Atualiza o peso da sonda
    sondaProx->peso += rocha->peso;

    // Exibe informações da coleta
    printf("\n++++ Coleta realizada com sucesso! ++++\n");
    printf("Sonda: %d\n", sondaProx->Identificador);
    printf("Rocha coletada: %s, Peso: %f\n", rocha->categoria, rocha->peso);
    printf("Nova posição da sonda: (%f, %f)\n", sondaProx->Latitude, sondaProx->Longitude);
}

int LogicaEuclides(Lista_s *lista_sonda, TSonda *sonda, float longitude, float latitude, TSonda **sonda_prox) {
    float dist_anterior, dist_atual;
    

    if (*sonda_prox == NULL) {
        *sonda_prox = sonda; 
        printf("TTTTTTTTTTTTTTTTTTT");
        return 0;
    }
    dist_anterior = sqrt(pow(latitude - (*sonda_prox)->Latitude, 2) + pow(longitude - (*sonda_prox)->Longitude, 2));
    dist_atual = sqrt(pow(latitude - sonda->Latitude, 2) + pow(longitude - sonda->Longitude, 2));
    if (dist_atual < dist_anterior) { 
        *sonda_prox = sonda; 
    }
    return 1;
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
    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        printf("\nid: %d", pAux->item.Identificador);
        printf("\nLONGITUDE: %.2f", pAux->item.Longitude);
        printf("\nLATITUDE%.2f", pAux->item.Latitude);
        if(pAux->item.compartimento->pPrimeiro->pProx != NULL){
            printf("==============================\n");  
            printf("\nCategoria: %s", pAux->item.compartimento->pUltimo->rocha.categoria);
            printf("\nPESO: %.2f", pAux->item.compartimento->pUltimo->rocha.peso);
            printf("\n==============================");

        }
        else if (pAux->item.compartimento->pPrimeiro->pProx== NULL){
            printf("\nCompartimento vazio!!\n\n");
        }
        pAux = pAux->pProx;
    }

}

/*
void CalculaNovaRocha(Lista_s *lista_sonda, Trocha *rocha) {

    TSonda *sondaProx= NULL;
    float longt = rocha->longitude; 
    float lat = rocha->latitude;

    Apontador_s pAux=lista_sonda->pPrimeiro_s->pProx;
    while (pAux != NULL) {
        float cap_disponivel = (pAux->item.capacidade) - (pAux->item.peso);
        TSonda *sonda = &pAux->item;

        if (cap_disponivel < rocha->peso) {
            pAux = pAux->pProx; 
            continue;
        }
        LogicaEuclides(lista_sonda, sonda, longt, lat, &sondaProx);

        pAux = pAux->pProx;

    }
    if (sondaProx!= NULL){
        LInsere(&sondaProx->compartimento->pPrimeiro, &rocha);
    }
    if (sondaProx != NULL) {
        printf("\n+++++++++++++++++++++++++++\n");
        printf("\n%s", sondaProx->compartimento->pUltimo->rocha.categoria);
        printf("\n%f", sondaProx->compartimento->pUltimo->rocha.latitude);
        printf("\n%f", sondaProx->compartimento->pUltimo->rocha.longitude);
        printf("\n%f\n", sondaProx->compartimento->pUltimo->rocha.peso);
    } else {
        printf("Nenhuma sonda selecionada.\n");
    }

}

int LogicaEuclides(Lista_s *lista_sonda, TSonda *sonda, float longitude, float latitude, TSonda **sonda_prox) {
    float dist_anterior, dist_atual;

    if (*sonda_prox == NULL) {
        *sonda_prox = sonda; 
        return 0;
    }

    dist_anterior = sqrt(pow(latitude - (*sonda_prox)->Latitude, 2) + pow(longitude - (*sonda_prox)->Longitude, 2));
    dist_atual = sqrt(pow(latitude - sonda->Latitude, 2) + pow(longitude - sonda->Longitude, 2));

    if (dist_atual < dist_anterior) { 
        *sonda_prox = sonda; 
    }
    printf("\n+++++++++++++++++++++++++++\n");
    printf("\n%f", (*sonda_prox)->capacidade);
    printf("\n%f", (*sonda_prox)->Latitude);
    printf("\n%f", (*sonda_prox)->Longitude);
    printf("\n%d", (*sonda_prox)->EstaLigada);
    return 1;
}

*/


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