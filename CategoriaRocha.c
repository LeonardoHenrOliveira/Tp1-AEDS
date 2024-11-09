#include <stdio.h>
#include <string.h>
#include "CategoriaRocha.h"

Categoria_R InicializarMineral(Categoria_R* categoria, char* nomeC){

    setNome(categoria, nomeC);

    return *categoria;
}

void setNome(Categoria_R* categoria, char* nomeC){
    strcpy(categoria->Nome, nomeC);
};

char* getNome(Categoria_R* categoria){
    return(categoria->Nome);
}