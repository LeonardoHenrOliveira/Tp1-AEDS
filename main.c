#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L_Minerais.h"
#include "Menu.h"

int main() {
    int quntdsondas, quntdoperacoes, i,operacao,peso, contador=0;
    char entrada[200], mineral[3];
    const char s[2]= " ";
    char*token;
    float latitude, longitude;
    L_Minerais lista_m;
    Minerais minerais;

    PreencheMinerais(&lista_m, &minerais);
    printquntdsondas();
    scanf("%d",&quntdsondas);
    printquntdoperacoes();
    scanf("%d",&quntdoperacoes);
    for (i=0; i<quntdoperacoes; i++){
        printmenu();
        scanf("%d",&operacao);
        if (operacao==1){
            printRochanova();
            getchar();
            fgets(entrada, 200, stdin);
            token = strtok(entrada,s);
            latitude=atof(token);
            token = strtok(NULL,s);
            longitude= atof(token);
            token = strtok(NULL, s);
            peso=atoi(token);
            while( token != NULL ) {
                token = strtok(NULL, s);
                
            }
            
        }
        if (operacao==2){
            
        }
        if (operacao==3){

        }
    }



}