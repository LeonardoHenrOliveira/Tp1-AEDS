#include <stdio.h>


typedef struct Minerais
{
    char Nome[100];
    float Dureza;
    float Reatividade;
    char Cor[100];
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