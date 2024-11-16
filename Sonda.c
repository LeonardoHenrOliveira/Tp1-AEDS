#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

TSonda Inicializar_sonda(TSonda* sonda, float latitude, float longitude,float capacidade){
    Liga(sonda);
    FazId(sonda);

    TLista compartimento;
    FLVazia(&compartimento);
    
    setCompartimento(sonda, &compartimento);
    setLatitude(sonda, latitude);
    setLongitude(sonda, longitude);
    setCapacidade(sonda,capacidade);
    
    return *sonda;
}

int Liga(TSonda* sonda){
    sonda->EstaLigada = 1;
};

int Desliga(TSonda* sonda){
    sonda->EstaLigada = 0;
}

void Move(TSonda* sonda, float latitude, float longitude){
    setLatitude(sonda, latitude);
    setLongitude(sonda, longitude);
}
int FazId(TSonda* sonda){
    int aleatorio;
    aleatorio= rand();
    sonda->Identificador=aleatorio;
}

TLista setCompartimento(TSonda* sonda, TLista* lista_r){
    sonda->compartimento = lista_r;
}

void setLatitude(TSonda* sonda, float latitude){
    sonda->Latitude = latitude;
}

void setLongitude(TSonda* sonda, float longitude){
    sonda->Longitude = longitude;
}
void setCapacidade(TSonda* sonda, float capacidade){
    sonda->capacidade=capacidade;
}


int getId(TSonda* sonda){
    return sonda->Identificador;
}

TLista* getCompartimento(TSonda* sonda){
    return sonda->compartimento;
}

int getLatitude(TSonda* sonda){
    return sonda->Latitude;
}

int getLongitude(TSonda* sonda){
    return sonda->Longitude;
}


float setPesoSonda(TSonda* sonda, TLista* lista_r){
    float peso_s = 0.0;

    Apontador pAux;
    pAux = lista_r->pPrimeiro->pProx;
    while (pAux!=NULL){
        peso_s += pAux->rocha.peso;
        pAux = pAux->pProx;
    }

    sonda->peso = peso_s;
}

