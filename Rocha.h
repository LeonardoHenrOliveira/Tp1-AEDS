#include <stdio.h>
#include "L_Minerais.h"
#include "categoriarocha.h"


typedef int tiporocha;
typedef struct {
    char identificador[100];
    float peso;
    
    Categoria_R categorias;
    int latitude;
    int longitude;
    
}Trocha;

