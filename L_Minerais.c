#include <stdio.h>
#include "L_Minerais.h"

void FLvaziae(L_entrada* lista_e){
    lista_e->primeiroe = INICIO;
    lista_e->ultimoe = lista_e->primeiroe;
}
int LInseree(L_entrada* lista_e, char* y){
    if(lista_e->ultimoe == MAXTAM)
        return 0;
    lista_e->iteme[lista_e->ultimoe++] = y;
    return 1;
};


void FLvazia(L_Minerais* lista_m){
    lista_m->primeiro = INICIO;
    lista_m->ultimo = lista_m->primeiro;
};

int LEhVazia(L_Minerais* lista_m){
    return(lista_m->primeiro == lista_m->ultimo);
};

int LInsere(L_Minerais* lista_m, Minerais x){
    if(lista_m->ultimo == MAXTAM)
        return 0;
    lista_m->item[lista_m->ultimo++] = x;
    return 1;
};

int Lretira(L_Minerais* lista_m, int p, Minerais *px){
    int cont;
    

    if(LEhVazia(lista_m) || p >= lista_m->ultimo || p < 0)
        return 0;
    
    *px = lista_m->item[p];
    for(cont = p+1; cont <= lista_m->ultimo; cont++){
        lista_m->item[cont - 1] = lista_m->item[cont];
    }
    return 1;
};

void LImprime(L_Minerais* lista_m){
    int i;
    for (i = lista_m->primeiro; i < lista_m->ultimo; i++){
        printf("\n%s\n", lista_m->item[i].Nome);
        printf("%.2f\n", lista_m->item[i].Dureza);
        printf("%.2f\n", lista_m->item[i].Reatividade);
        printf("%s\n", lista_m->item[i].Cor);
    }
};

void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral){
    FLvazia(lista_m);

    Minerais Ferrolita = InicializarMineral(mineral, "Ferrolita", 0.5, 0.7, "Cinza");
    Minerais Solariun = InicializarMineral(mineral, "Aquamarina", 0.9, 0.2, "Amarelo");
    Minerais Aquavitae = InicializarMineral(mineral, "Aquavitae", 0.5, 0.8, "Azul");
    Minerais Terranita = InicializarMineral(mineral, "Terranita", 0.5, 0.8, "Marrom");
    Minerais Calaris = InicializarMineral(mineral, "Calaris", 0.6, 0.5, "Vermelho");
    LInsere(lista_m, Ferrolita);
    LInsere(lista_m, Solariun);
    LInsere(lista_m, Aquavitae);
    LInsere(lista_m, Terranita);
    LInsere(lista_m, Calaris);
}