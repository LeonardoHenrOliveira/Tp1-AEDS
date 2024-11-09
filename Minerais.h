#include <stdio.h>


typedef struct Minerais
{
    char Nome[100];
    float Dureza;
    float Reatividade;
    char Cor[100];
}Minerais;

void Inicializar(Minerais* minerais, char* nome, float dureza, float reatividade, char* cor);

void setNome(Minerais* minerais, char* nome);
void setDureza(Minerais* minerais, float dureza);
void setReatividade(Minerais* minerais, float reatividade);
void setCor(Minerais* minerais, char* cor);

int getNome(Minerais* minerais, char* nome);
int getDureza(Minerais* minerais, float dureza);
int getReatividade(Minerais* minerais, float reatividade);
int getCor(Minerais* minerais, char* cor);