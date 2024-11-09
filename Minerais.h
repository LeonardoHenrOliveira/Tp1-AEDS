#ifndef MINERAIS_H
#define MINERAIS_H


#include <stdio.h>
#define tamanhomaxnome 100
#define tamanhomaxcor 100
typedef struct Minerais
{
    char Nome[tamanhomaxnome];
    float Dureza;
    float Reatividade;
    char Cor[tamanhomaxcor];
}Minerais;

Minerais InicializarMineral(Minerais* minerais, char* nome, float dureza, float reatividade, char* cor);

void setNome(Minerais* minerais, char* nome);
void setDureza(Minerais* minerais, float dureza);
void setReatividade(Minerais* minerais, float reatividade);
void setCor(Minerais* minerais, char* cor);

char* getNome(Minerais* minerais);
int getDureza(Minerais* minerais);
int getReatividade(Minerais* minerais);
char* getCor(Minerais* minerais);

#endif