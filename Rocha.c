#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rocha.h"
#include "L_Minerais.h"

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude, char* categoria){
    setidentificador(rocha, identificador);
    SetCategoria(rocha, categoria);
    setlatitude(rocha,latitude);
    setlongitude(rocha,longitude);
    setpeso(rocha, peso);

    return *rocha;
}
void classifica_categoria(L_entrada* lista_e,Trocha* rocha_m) {
    if (lista_e->item_e[1].nome == NULL || strcmp(lista_e->item_e[1].nome, "") == 0) { 
        
        if (strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0) {
            strcpy(rocha_m->categoria, "Ferrom");
        }
        else if (strcmp(lista_e->item_e[0].nome, "Solarium") == 0) {
            strcpy(rocha_m->categoria, "Solaris");
        }  
        else {
            strcpy(rocha_m->categoria, "Sem Categoria");
        }
    } else { 
        if ((strcmp(lista_e->item_e[0].nome, "Aquavitae") == 0 && strcmp(lista_e->item_e[1].nome, "Terranita") == 0) || (strcmp(lista_e->item_e[1].nome, "Aquavitae") == 0 && strcmp(lista_e->item_e[0].nome, "Terranita") == 0)) {
            strcpy(rocha_m->categoria, "Aquaterra");
        } 
        else if ((strcmp(lista_e->item_e[0].nome, "Aquavitae") == 0 && strcmp(lista_e->item_e[1].nome, "Ferrolita") == 0) ||(strcmp(lista_e->item_e[1].nome, "Aquavitae") == 0 && strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0)) {
            strcpy(rocha_m->categoria, "Aquaferro");
        }
        else if ((strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0 && strcmp(lista_e->item_e[1].nome, "Solarium") == 0) || (strcmp(lista_e->item_e[1].nome, "Ferrolita") == 0 && strcmp(lista_e->item_e[0].nome, "Solarium") == 0)) {
            strcpy(rocha_m->categoria, "Terrasol");
        }
        else if ((strcmp(lista_e->item_e[0].nome, "Calaris") == 0 && strcmp(lista_e->item_e[1].nome, "Terranita") == 0) || (strcmp(lista_e->item_e[1].nome, "Calaris") == 0 && strcmp(lista_e->item_e[0].nome, "Terranita") == 0)) {
            strcpy(rocha_m->categoria, "Terrolis");
        } 
         else if ((strcmp(lista_e->item_e[0].nome, "Aquavitae") == 0 && strcmp(lista_e->item_e[1].nome, "Calaris") == 0) || (strcmp(lista_e->item_e[1].nome, "Aquavitae") == 0 && strcmp(lista_e->item_e[0].nome, "Calaris") == 0)) {
            strcpy(rocha_m->categoria, "Calquer");
        } 
        else if ((strcmp(lista_e->item_e[0].nome, "Solarium") == 0 && strcmp(lista_e->item_e[1].nome, "Ferrolita") == 0) || (strcmp(lista_e->item_e[1].nome, "Solarium") == 0 && strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0)) {
            strcpy(rocha_m->categoria, "Solarisfer");
        }
        else if ((strcmp(lista_e->item_e[0].nome, "Terranita") == 0 && strcmp(lista_e->item_e[1].nome, "Ferrolita") == 0) || (strcmp(lista_e->item_e[1].nome, "Terranita") == 0 && strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0)) {
            strcpy(rocha_m->categoria, "Terralis");
        }
        else {
            strcpy(rocha_m->categoria, "Sem Categoria");
        }
    }
    printf("%s",rocha_m->categoria);
}



void setidentificador(Trocha *rocha, int identificador){
    rocha->identificador=identificador;
}

void setpeso(Trocha *rocha, float peso){
    rocha->peso=peso;
}
void setlatitude(Trocha *rocha, float latitude){
    rocha->latitude = latitude;
    printf("%f",latitude);
    
}
void setlongitude(Trocha *rocha, double longitude){
    rocha->longitude = longitude;
}
void SetCategoria(Trocha*rocha, char* categoria){
    strcpy(rocha->categoria, categoria);
}

int getidentificador(Trocha* rocha){
    return(rocha->identificador);
}
float getpeso(Trocha* rocha){
    return(rocha->peso);
}
char* getcategoria(Trocha* rocha){
    
}
float getlatitude(Trocha* rocha){
    return(rocha->latitude);
}
float getlongitude(Trocha* rocha){
    return(rocha->longitude);
}
