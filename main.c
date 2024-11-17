#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"


int main() {
    
    int quntdsondas, quntdoperacoes, i,operacao,peso, contador=0,j=0,k;
    char entrada[255];
    const char s[2]= " ";
    char*token;
    char categoria[20];
    float longitude, latitude, lat_i, long_i, velocidade_i, combustivel_i, capacidade_i;
    

    L_Minerais lista_m;
    Minerais minerais;
    Lista_s lista_sonda;
    TSonda sonda;
    Trocha lrocha;
    entradaminerais entradam;
    TLista comp;
    L_entrada lista_e;
   

    PreencheMinerais(&lista_m, &minerais);
    printquntdsondas();
    scanf("%d",&quntdsondas);

    FLVazia_s(&lista_sonda);
    
    for (k = 0; k < quntdsondas; k++){
        printsonda(quntdsondas);
        scanf("%f %f %f %f %f",&lat_i, &long_i,&capacidade_i,&velocidade_i,&combustivel_i);
        TSonda sondaN = Inicializar_sonda(&sonda,lat_i,long_i,capacidade_i);
        LInsere_s(&lista_sonda, &sonda);
    }
    
    
    printquntdoperacoes();
    scanf("%d",&quntdoperacoes);
    FLvazia_e(&lista_e);

    for (i = 0; i < quntdoperacoes; i++){
        printmenu();
        scanf("%d",&operacao);
        if (operacao == 1){
            j = 0;
            printRochanova();
            getchar();
            fgets(entrada, 255, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';

            token = strtok(entrada,s);
            longitude = atof(token);
            token = strtok(NULL,s);
            latitude = atof(token);
            token = strtok(NULL, s);
            peso = atoi(token);
            
            while( token!= NULL ) {
                token = strtok(NULL,s);
                if (token!=NULL){
                    entradaminerais m1 = InicializarMinerale(&entradam,token);
                    LInsere_e(&lista_e, m1);
                    j++;
                }       
            }
            classifica_categoria(&lista_e,&lrocha);
            
            printf("%f",longitude);
            Trocha r1 = InicializaRocha(&lrocha, 1, peso, latitude, longitude, categoria);
            TSonda *sondamaisprox = Calculo_sonda_prox(&lista_sonda, &r1);
            Lretira_e(&lista_e);
            
        }
        if (operacao == 2){
            operacaoI(&lista_sonda);           
        }
        if (operacao == 3){

        }
    }



}