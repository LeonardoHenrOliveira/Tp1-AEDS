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
/**/
char* classifica_categoria(L_entrada* lista_e,int j,L_Minerais * lista_m,Trocha* rocha_m){

    
    char* categoria = (char*)malloc(20 * sizeof(char));

    printf("\n");
        if (j == 0){
            printf("Nao tem mineral\n");
            return "0";
        }
    
    if (j == 1)
    {
        {
            if (strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0)
            {
                strcpy(categoria,"Ferrom");
            }
            else if (strcmp(lista_e->item_e[0].nome, "Solarium") == 0)
            {
                strcpy(categoria,"Solaris");
            }
        }
    }
    if (j == 2)
    {
        if (strcmp(lista_e->item_e[0].nome, "Terranita") == 0 || (strcmp(lista_e->item_e[1].nome, "Terranita")) == 0)
        {
            if (strcmp(lista_e->item_e[0].nome, "Calaris") == 0 || (strcmp(lista_e->item_e[1].nome, "Calaris")) == 0){
                strcpy(categoria,"Terrolis");
                
            }
            else if (strcmp(lista_e->item_e[0].nome, "Solarium") == 0 || (strcmp(lista_e->item_e[1].nome, "Solarium")) == 0){
                strcpy(categoria,"Terrasol");
            }
            else if (strcmp(lista_e->item_e[0].nome, "Aquavitae") == 0 || (strcmp(lista_e->item_e[1].nome, "Aquavitae")) == 0){
                strcpy(categoria,"Aquaterra");
                
            }
            else if (strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0 || (strcmp(lista_e->item_e[1].nome, "Ferrolita")) == 0){
                strcpy(categoria,"Terralis");
                
            }
        }
        if (strcmp(lista_e->item_e[0].nome, "Aquavitae") == 0 || (strcmp(lista_e->item_e[1].nome, "Aquavitae") == 0)){
            if(strcmp(lista_e->item_e[0].nome, "Calaris") == 0 || (strcmp(lista_e->item_e[1].nome, "Calaris")) == 0){
                strcpy(categoria,"Calquer");
                
            }
        }
        if (strcmp(lista_e->item_e[0].nome, "Ferrolita") == 0 || (strcmp(lista_e->item_e[1].nome, "Ferrolita")) == 0){
            if (strcmp(lista_e->item_e[0].nome, "Solarium") == 0 || (strcmp(lista_e->item_e[1].nome, "Solarium")) == 0){
                strcpy(categoria,"Solarisfer");
                
            }
        }   
    }
    if (j == 3) {
        strcpy(categoria,"Aquacalis");
    }
    printf("%s",categoria);
    
    return categoria;
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
