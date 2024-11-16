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

char* classifica_categoria(L_entrada* lista_e,int j,L_Minerais * lista_m,Trocha* rocha_m){
    int i,TemFERR = 0,TemSola = 0,TemAqua = 0,TemTerra = 0,TemCala = 0;
    
    char* categoria = (char*)malloc(20 * sizeof(char));

    printf("\n");
        /*
        if (strcmp(lista_e->item_e[0].nome,lista_m->item[2].Nome) ==0  || strcmp(lista_e->item_e[1].nome,lista_m->item[2].Nome) ==0|| strcmp(lista_e->item_e[2].nome,lista_m->item[2].Nome)==0){
           TemAqua=1; 
        }else if (strcmp(lista_e->item_e[0].nome,lista_m->item[4].Nome) ==0 || strcmp(lista_e->item_e[1].nome,lista_m->item[4].Nome) ==0|| strcmp(lista_e->item_e[2].nome,lista_m->item[4].Nome)==0){
            TemCala=1;
        }else if (strcmp(lista_e->item_e[0].nome,lista_m->item[0].Nome) ==0 || strcmp(lista_e->item_e[1].nome,lista_m->item[0].Nome) ==0||strcmp(lista_e->item_e[2].nome,lista_m->item[0].Nome) ==0){
            TemFERR=1;   
        }else if (strcmp(lista_e->item_e[0].nome,lista_m->item[1].Nome) ==0  || strcmp(lista_e->item_e[1].nome,lista_m->item[1].Nome)==0 || strcmp(lista_e->item_e[2].nome,lista_m->item[1].Nome)==0){
            TemSola=1;
        }else if (strcmp(lista_e->item_e[0].nome,lista_m->item[3].Nome)==0 || strcmp(lista_e->item_e[1].nome,lista_m->item[3].Nome)==0 || strcmp(lista_e->item_e[2].nome, lista_m->item[3].Nome)==0){
            TemTerra=1;
        }
       */
        for(i = lista_e->primeiroe; i <lista_e->ultimoe; i++){
            if(strcmp(lista_e->item_e[i].nome, "Ferrolita")==0) {
                TemFERR = 1;
            }
            else if(strcmp(lista_e->item_e[i].nome, "Solarium")==0 ) {
                TemSola = 1;
            }
            else if(strcmp(lista_e->item_e[i].nome, "Aquavitae")==0 ) {
                TemAqua = 1;
            }
            else if(strcmp(lista_e->item_e[i].nome, "Terranita")==0 ) {
                TemTerra = 1;
                }
            else if(strcmp(lista_e->item_e[i].nome, "Calaris")==0 ) {
                TemCala = 1;
            }
        }
        
        
        if (TemAqua==1 && TemCala==1 && TemFERR==1 && j==3){
            strcpy(categoria,"Aquacalis");
        }else if (TemFERR==1 && TemAqua==1 && j==2){
            strcpy(categoria,"Aquaferro");
        }
        else if(TemTerra==1 && TemCala==1 && j==2){
            strcpy(categoria,"Terrolis");
        }
        else if(TemTerra==1 && TemSola==1 && j==2){
            strcpy(categoria,"Terrasol");
        }
        else if(TemAqua==1 && TemTerra==1 && j==2 ){
            strcpy(categoria,"Aquaterra");
        }
        else if(TemCala==1 && TemAqua==1 && j==2){
            strcpy(categoria,"Calquer");
        }
        else if(TemSola==1 && TemFERR==1 && j==2){
            strcpy(categoria,"Solarisfer");
        }
        else if(TemTerra==1 && TemFERR==1 && j==2){
            strcpy(categoria,"Terralis");
        }
        else if (TemSola==1 && j==1){
            strcpy(categoria,"Solaris");
        }
        else if (TemFERR==1 & j==1){
            strcpy(categoria,"Ferrom");
        }
        else{
            printf("Os minerais escritos nao formam uma rocha conhecida,digite novamente:\n");
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
