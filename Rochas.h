#include <stdio.h>
#include <L_Minerais.h>
#include<categoriarocha.h>
#define tamanhomaxcatg 10

typedef int tiporocha;
typedef struct {
    char identificador[100];
    float peso;
    L_Minerais Minerais;
    Categoria_R categorias;
    int latitude;
    int longitude;
    
}Trocha;

