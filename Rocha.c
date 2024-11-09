#include <stdio.h>
#include <Rocha.h>

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

