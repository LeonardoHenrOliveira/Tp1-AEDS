#include <stdio.h>
#include "Sonda.h"

void Inicializar(TSonda* sonda, int id, TLista* compartimento, int latitude, int longitude){
    Liga(sonda);
    setIdentificador(sonda, id);
    setCompartimento(sonda, compartimento);
    setLatitude(sonda, latitude);
    setLongitude(sonda, longitude);
}

int Liga(TSonda* sonda){
    sonda->EstaLigada = 1;
};

int Desliga(TSonda* sonda){
    sonda->EstaLigada = 0;
}

void Move(TSonda* sonda, int latitude, int longitude){
    setLatitude(sonda, latitude);
    setLongitude(sonda, longitude);
}

void setId(TSonda* sonda, int id){
    sonda->Identificador = id;
}

void setCompartimento(TSonda* sonda, TLista* lista_r){
    sonda->compartimento = lista_r;
}

void setLatitude(TSonda* sonda, int latitude){
    sonda->Latitude = latitude;
}

void setLongitude(TSonda* sonda, int longitude){
    sonda->Longitude = longitude;
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



