#include <stdio.h>
#include "L_Minerais.h"

void FLvazia(L_Minerais* lista_m){
    lista_m->primeiro = INICIO;
    lista_m->ultimo = lista_m->primeiro;
};

int LEhVazia(L_Minerais* lista_m){
    return(lista_m->primeiro == lista_m->ultimo);
};

int LInsere(L_Minerais* lista_m, Mineral x){
    if(lista_m->ultimo == MAXTAM)
        return 0;
    lista_m->item[lista_m->ultimo++] = x;
    return 1;
};

int Lretira(L_Minerais* lista_m, int p, Mineral *px){
    int cont;
    
    if(LEhVazia(lista_m) || p >= lista_m->ultimo || p < 0)
        return 0;
    
    for(cont = p+1; cont <= lista_m->ultimo; cont++){
        lista_m->item[cont - 1] = lista_m->item[cont];
    }
    return 1;
};

void LImprime(L_Minerais* lista_m){
    int i;
    for (i = lista_m->primeiro; i < lista_m->ultimo; i++){
        printf("%d\n", lista_m->item[i].Mine);
    }
};


