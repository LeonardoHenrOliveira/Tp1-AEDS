#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"


int main() {
    
    
    int quntdsondas, quntdoperacoes, i,operacao,peso, contador=0,j=0,k;
    char entrada[255];
    const char s[2]= " ";
    char*token, categoria[20];
    float latitude, longitude,lat_i,long_i,velocidade_i,combustivel_i,capacidade_i;

    L_Minerais lista_m;
    Minerais minerais;
    Lista_s pLista;
    TSonda sonda;
    Trocha lrocha;
    entradaminerais* entradam;
    TLista comp;
    L_entrada lista_e;
    L_entrada* listae;

    PreencheMinerais(&lista_m, &minerais);
    printquntdsondas();
    scanf("%d",&quntdsondas);

    FLVazia_s(&pLista);
    
    for (k=0;k<quntdsondas;k++){
        printsonda(quntdsondas);
        scanf("%f %f %f %f %f",&lat_i, &long_i,&capacidade_i,&velocidade_i,&combustivel_i);
        TSonda sondaN = Inicializar_sonda(&sonda,&comp,lat_i,long_i,capacidade_i);
        LInsere_s(&pLista, &sonda);
    }
    LImprime_s(&pLista);


    
    printquntdoperacoes();
    scanf("%d",&quntdoperacoes);
    FLvazia_e(&lista_e);
    for (i=0; i<quntdoperacoes; i++){
        printmenu();
        scanf("%d",&operacao);
        if (operacao==1){
            printRochanova();
            getchar();
            fgets(entrada, 255, stdin);
            token = strtok(entrada,s);
            latitude=atof(token);
            token = strtok(NULL,s);
            longitude= atof(token);
            token = strtok(NULL, s);
            peso=atoi(token);
            
            while( token!= NULL ) {
                token = strtok(NULL,s);
                if (token!=NULL){
                    entradaminerais m1 = InicializarMinerale(entradam,token);
                    LInsere_e(&lista_e, m1);
                }
            }
        }
        if (operacao==2){
           
        }
        if (operacao==3){

        }
    }



}