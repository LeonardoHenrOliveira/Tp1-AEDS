#include <stdio.h>
#include <stdlib.h>
#include "Compartimento.h"


typedef struct {
    int Identificador;
    TLista *compartimento;
    float capacidade;
    float Latitude;
    float Longitude;
    int EstaLigada;
}TSonda;

TSonda Inicializar_sonda(TSonda* sonda, int id, TLista* compartimento, float latitude, float longitude, float capacidade);
int Liga(TSonda* sonda);
int Desliga(TSonda* sonda);
void Move(TSonda* sonda, float latitude, float longitude);

void setId(TSonda* sonda, int id);
TLista setCompartimento(TSonda* sonda, TLista* lista_r);
void setLatitude(TSonda* sonda, float latitude);
void setLongitude(TSonda* sonda, float longitude);
void setCapacidade(TSonda* sonda, float capacidade);

int getId(TSonda* sonda);
TLista* getCompartimento(TSonda* sonda);
int getLatitude(TSonda* sonda);
int getLongitude(TSonda* sonda);

