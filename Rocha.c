#include <stdio.h>
#include "Rocha.h"

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude){

    setidentificador(rocha, identificador);
    setlocalizacao(rocha, latitude, longitude);
    setpeso(rocha, peso);
}
char* classifica_categoria(char* mineral1, char*mineral2,char* mineral3, int j){
    if (j==4){
       return "Aquacalis";
    }if(j==2){


    }if (j==1){
        
    }
}
void setidentificador(Trocha *rocha, int identificador){
    rocha->identificador=identificador;
}

void setpeso(Trocha *rocha, float peso){
    rocha->peso=peso;
}
void setcategoria(Trocha *rocha, char* categoria){
    
}
void setlocalizacao(Trocha *rocha, float latitude, float longitude){
    rocha->latitude=latitude;
    rocha->longitude=longitude;
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
