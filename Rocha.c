#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rocha.h"
#include "L_Minerais.h"

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, double longitude, char* categoria){
    setidentificador(rocha, identificador);
    SetCategoria(rocha, categoria);
    printf("%f",latitude);
    setlatitude(rocha,latitude);
    printf("%f",longitude);
    setlongitude(rocha,longitude);
    setpeso(rocha, peso);

    return *rocha;
}

char* classifica_categoria(L_entrada* lista_e,int j,L_Minerais * lista_m,Trocha* rocha_m){
    int i,TemFERR = 0,TemSola = 0,TemAqua = 0,TemTerra = 0,TemCala = 0;
    
    char* categoria = (char*)malloc(20 * sizeof(char));
    
    printf("\nPRIM %s  ",lista_e->item_e[0].nome);
    printf("\nseg %s  ",lista_e->item_e[1].nome);
    
    printf("%d",j);
    
    if (j==3){
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[2].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[2].Nome) || strcmp(lista_e->item_e[2].nome,lista_m->item[2].Nome)){
           TemAqua=1; 
        }
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[4].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[4].Nome) || strcmp(lista_e->item_e[2].nome,lista_m->item[4].Nome)){
            TemCala=1;
        }
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[0].Nome)||strcmp(lista_e->item_e[1].nome,lista_m->item[0].Nome)||strcmp(lista_e->item_e[2].nome,lista_m->item[0].Nome)){
            TemFERR=1;   
        }

        if (TemAqua==1 && TemCala==1 && TemFERR==1){
            strcpy(categoria,"Aquacalis");
        }else{
            printf("Os minerais escritos nao formam uma rocha conhecida,digite novamente:\n");
        }
    }
    if(j==2){
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[3].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[3].Nome)){
            TemTerra=1;
        }
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[4].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[4].Nome)){
            TemCala=1;
        }
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[1].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[1].Nome)){
            TemSola=1;
        }
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[2].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[2].Nome)){
            TemAqua=1;   
        }
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[0].Nome) || strcmp(lista_e->item_e[1].nome,lista_m->item[0].Nome)){
            TemFERR=1;   
        }

        if (TemFERR==1 && TemAqua==1 ){
            strcpy(categoria,"Aquaferro");
        }
        else if(TemTerra==1 && TemCala==1){
            strcpy(categoria,"Terrolis");
        }
        else if(TemTerra==1 && TemSola==1){
            strcpy(categoria,"Terrasol");
        }
        else if(TemAqua==1 && TemTerra==1 ){
            strcpy(categoria,"Aquaterra");
        }
        else if(TemCala==1 && TemAqua==1){
            strcpy(categoria,"Calquer");
        }
        else if(TemSola==1 && TemFERR==1){
            strcpy(categoria,"Solarisfer");
        }
        else if(TemTerra==1 && TemFERR==1){
            strcpy(categoria,"Terralis");
        }else{
            printf("Os minerais escritos nao formam uma rocha conhecida,digite novamente:\n");
        }
        
       

    }if (j==1){
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[0].Nome)){
            TemFERR=1;
        }
        
        if (strcmp(lista_e->item_e[0].nome, lista_m->item[1].Nome)){
            TemSola=1;
        }
        
        if (TemSola==1){
            strcpy(categoria,"Solaris");
        }else if (TemFERR==1){
            strcpy(categoria,"Ferrom");
        }else{
            printf("Os minerais escritos nao formam uma rocha conhecida,digite novamente:\n");
        }
    }
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
