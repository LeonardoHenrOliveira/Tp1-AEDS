#include <stdio.h>
#include <string.h>
#include "Rocha.h"
#include "L_Minerais.h"

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude){

    setidentificador(rocha, identificador);
    setlocalizacao(rocha, latitude, longitude);
    setpeso(rocha, peso);
}
/*char* classifica_categoria(char* mineral1, char*mineral2,char* mineral3, int j){
    L_Minerais minerios;
    if (j==4){
        if (strcmp(mineral1,'Aquavitae')||strcmp(mineral2,'Aquavitae')||strcmp(mineral3,'Aquavitae')){
            if (strcmp(mineral1,'Calaris')||strcmp(mineral2,'Calaris')||strcmp(mineral3,'Calaris')){
                if (strcmp(mineral1,minerios.item[1])||strcmp(mineral2,'ferrolita')||strcmp(mineral3,'Ferrolita')){
                    return "Aquacalis";
                }
            }
        }

            
    }if(j==3){
        if (strcmp(mineral1,'Terranita')||strcmp(mineral2,'Terranita')){
            if (strcmp(mineral1,'Calaris')||strcmp(mineral2,'Calaris')){
                return 'Terrolis';
            }
            if (strcmp(mineral1,'Solarium')||strcmp(mineral2,'Solarium')){
                return 'Terrasol';
            }
            if (strcmp(mineral1,'Aquavitae')||strcmp(mineral2,'Aquavitae')){
                return 'Aquaterra';
            }
            if (strcmp(mineral1,'Ferranita')||strcmp(mineral2,'Ferranita')){
                return 'Terralis';
            }
        }
        if (strcmp(mineral1, 'ferrolita')|| strcmp(mineral2, 'Ferrolita')){
            if (strcmp(mineral1,'Aquavitae')||strcmp(mineral2,'Aquavitae')){
                return 'Aquaferro';
            }
            if (strcmp(mineral1,'Solarium')||strcmp(mineral2,'Solarium')){
                return 'Solarisfer';
            }
        }
        if (strcmp(mineral1,'Calaris')||strcmp(mineral2,'Calaris')){
            if (strcmp(mineral1,'Aquavitae')||strcmp(mineral2,'Aquavitae')){
                return 'Calquer';
            }
        }

    }if (j==2){
        if (strcmp(mineral1,'Ferrolita')){
            return 'Ferrom';
        }
        if (strcmp(mineral1, 'Solarium')){
            return 'Solaris';
        }
        
    }
}*/
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
