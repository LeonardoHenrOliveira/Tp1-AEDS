#include <stdio.h>
#include <L_Minerais.h>
#define tamanhomaxnome 100

typedef struct {
    char Nome[tamanhomaxnome];
    L_Minerais minerais;
}Categoria_R;

void FLvazia(Categoria_R* lista_c);
int LEhVazia(Categoria_R* lista_c);
int LInsere(Categoria_R* lista_c, Minerais x);
int Lretira(L_Minerais* lista_m, int p, Minerais *px);
void LImprime(L_Minerais* lista_m);

void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral);
