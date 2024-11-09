#include <stdio.h>
#include "L_Minerais.h"
#define tamanhomaxnome 100

typedef struct {
    char Nome[tamanhomaxnome];
    
    L_Minerais minerais;
}Categoria_R;

Categoria_R InicializaCategorias(Categoria_R* categoria, char* nomeC);

void setNome(Categoria_R* categoria, char* nomeC);

char* getNome(Categoria_R* categoria);
