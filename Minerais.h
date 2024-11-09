#include <stdio.h>


typedef struct Minerais
{
    char nome[100];
    float dureza;
    float Reatividade;
    char cor[100];
}Minerais;

void Inicializar(Minerais* minerais);

void setNome(Minerais* minerais, char* nome);
void setDureza(Minerais* minerais, float dureza);
void setReatividade(Minerais* minerais, float reatividade);
void setCor(Minerais* minerais, char* cor);