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


float percorrer(TLista comp, char* cat){
    Tcelula *pAux = comp.pPrimeiro->pProx;

    while (pAux != NULL) {
        if (strcmp(pAux->rocha.categoria,cat) == 0){
            return pAux->rocha.peso;
        }
        pAux = pAux->pProx;
    }
    return 0;
};


TSonda* Calculo_sonda_prox(Lista_s *lista_sonda, Trocha *rocha) {
    TSonda *sondaProx = NULL;
    float m_distancia = 10000000000000; 
    float distancia = 0;
    float longt = rocha->longitude; 
    float lat = rocha->latitude;

    Celula_s* usando= lista_sonda->pPrimeiro_s->pProx;

    while (usando!= NULL){
        TSonda *sonda_s = &usando->item;

        if((sonda_s->capacidade < rocha->peso) ){
            usando = usando->pProx;
            continue;
        }
    
        distancia = sqrt(pow(lat - sonda_s->Latitude, 2) + pow(longt - sonda_s->Longitude, 2));

        if (distancia < m_distancia ){
            m_distancia = distancia;
            sondaProx = sonda_s;

        }else if(ContemCategoria(sonda_s, rocha->categoria, percorrer(sonda_s->compartimento, rocha->categoria))){
            sondaProx = sonda_s;
            break;
        }

        sonda_s->capacidade -= rocha->peso;
        sonda_s->peso += rocha->peso;
        usando=usando->pProx;
    }

    Move(sondaProx,rocha->latitude,rocha->longitude);
    printf("\n");
    printf("\n++++ Coleta realizada com sucesso! ++++\n");
    printf("Sonda: %d\n", sondaProx->Identificador);
    printf("Rocha coletada: %s, Peso: %.2f\n", rocha->categoria, rocha->peso);
    printf("Nova posicao da sonda: (%.2f, %.2f)\n", sondaProx->Latitude, sondaProx->Longitude);
    printf("\n");
    
    return sondaProx;
}


int ContemCategoria(TSonda *sonda, const char *categoria, float pesoMinimo) {
    Tcelula *pAux = sonda->compartimento.pPrimeiro->pProx;
    while (pAux != NULL) {
        if (strcmp(pAux->rocha.categoria, categoria) == 0 && pAux->rocha.peso < pesoMinimo) {
            return 1;
        }
        pAux = pAux->pProx;
    }

    return 0;
}





float MediaSondas(Lista_s* lista_sonda){
    float media = 0.0;
    int qnt = 0;

    Apontador_s pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        setPesoSonda(&pAux->item, &pAux->item.compartimento);
        media += pAux->item.peso;
        qnt++;
        pAux = pAux->pProx;
    }

    media = media/qnt;
    return media;
}

void retiraRochas(TSonda* sonda, TLista* temp_lista, float media){
    Apontador pAux;
    pAux = sonda->compartimento.pPrimeiro->pProx;
    while (pAux!=NULL){
        if(sonda->peso > media){
            sonda->peso -= pAux->rocha.peso;
            Trocha* rocha_temp = &pAux->rocha;
            LInsere(temp_lista, rocha_temp);
            LRetira(&sonda->compartimento, rocha_temp);
        }
        pAux = pAux->pProx;
    }
}

void voltarRocha(TSonda* sonda, TLista* temp_lista, float media){
    Apontador pAux;
    pAux = temp_lista->pPrimeiro->pProx;

    while (pAux!=NULL){
        if((sonda->peso < media && sonda->capacidade > pAux->rocha.peso)){
            sonda->peso += pAux->rocha.peso;
            LInsere(&sonda->compartimento, &pAux->rocha);
            LRetira(temp_lista, &pAux->rocha);
            printf("\nDentro17\n");
        }
        pAux = pAux->pProx;
    }
}

void OperacaoE(Lista_s* lista_sonda){
    float media;
    Celula_s* pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;

    TLista lista_temp;
    FLVazia(&lista_temp);
    media = MediaSondas(lista_sonda);

    printf("fora\n");
    while (pAux!=NULL){
        Move(&pAux->item, 0, 0);
        retiraRochas(&pAux->item, &lista_temp, media);
        pAux = pAux->pProx;
    }

    printf("fora22\n");

    if(!(LEHVazia(&lista_temp))){
        pAux = lista_sonda->pPrimeiro_s->pProx;
        while (pAux!=NULL){
            voltarRocha(&pAux->item, &lista_temp, media);
            pAux = pAux->pProx;
        }
    }

    pAux = lista_sonda->pPrimeiro_s->pProx;
    if(!(LEHVazia(&lista_temp))){

        while(!(LEHVazia(&lista_temp))){
            pAux = lista_sonda->pPrimeiro_s->pProx;

            while(pAux != NULL){
                printf("\nDENTRO DO SOBRA\n");
                if(pAux->item.peso < media ){
                    if(LEHVazia(&pAux->item.compartimento) && pAux->item.peso < media){
                        pAux->item.peso += lista_temp.pPrimeiro->pProx->rocha.peso;
                        LInsere(&pAux->item.compartimento, &lista_temp.pPrimeiro->pProx->rocha);
                        LRetira(&lista_temp, &lista_temp.pPrimeiro->pProx->rocha);
                    }

                }
                pAux = pAux->pProx;
            }
        }
        
    }

    printf("\n\nMEDIA: %.2f\n\n", media);

}


void Operacao_i(Lista_s *lista_sonda){
    Celula_s* pAux;
    pAux = lista_sonda->pPrimeiro_s->pProx;
    while (pAux!=NULL){
        TSonda* sonda_2 = &pAux->item;
        printf("\n======================================\n");
        printf("\nID: %d\n", sonda_2->Identificador);
        printf("Localizacao:(%.2f,%.2f)\n",sonda_2->Latitude,sonda_2->Longitude);
        printf("\n");
                
        if(LEHVazia(&sonda_2->compartimento)){
            printf("Compartimento vazio!\n");
        }
        else{
            LImprime(&sonda_2->compartimento);
        }
            pAux = pAux->pProx;
        }
    printf("\n======================================\n");
}