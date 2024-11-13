#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

TSonda Inicializar_sonda(TSonda* sonda, int id, TLista* compartimento, float latitude, float longitude,float capacidade){
    Liga(sonda);
    setId(sonda, id);
    setCompartimento(sonda, compartimento);
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

void setId(TSonda* sonda, int id){
    sonda->Identificador = id;
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



