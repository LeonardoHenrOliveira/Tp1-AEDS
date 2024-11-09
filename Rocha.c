#include <stdio.h>
#include <Rocha.h>

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude){

    SetIdentificador(rocha, identificador);
    SetLocalização(rocha, latitude, longitude);
    SetPeso(rocha, peso);
}

void SetIdentificador(Trocha *rocha, int identificador){
    rocha->identificador=identificador;
}

void SetPeso(Trocha *rocha, float peso){
    rocha->peso=peso;
}
void SetCategoria(Trocha *rocha, int identificador){

}
void SetLocalização(Trocha *rocha, float latitude, float longitude){
    rocha->latitude=latitude;
    rocha->longitude=longitude;
}
int getIdentificador(Trocha* rocha){
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
