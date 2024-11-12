#include <stdio.h>
#include "Compartimento.h"


typedef struct {
    int Identificador;
    TLista *compartimento;
    int Latitude;
    int Longitude;
    int EstaLigada;
}TSonda;

void Inicializar(TSonda* sonda, int id, TLista* compartimento, int latitude, int longitude);
int Liga(TSonda* sonda);
int Desliga(TSonda* sonda);
void Move(TSonda* sonda, int latitude, int longitude);

void setId(TSonda* sonda, int id);
TLista setCompartimento(TSonda* sonda, TLista* lista_r);
void setLatitude(TSonda* sonda, int latitude);
void setLongitude(TSonda* sonda, int longitude);

int getId(TSonda* sonda);
TLista* getCompartimento(TSonda* sonda);
int getLatitude(TSonda* sonda);
int getLongitude(TSonda* sonda);

