#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L_Minerais.h"
#include "Menu.h"

int main() {
    int quntdsondas, quntdoperacoes, i,operacao,peso,nome1[100],nome2[100],nome3[100];
    char f;
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
            scanf("%f %f %d %s %s %s",&latitude,&longitude,&peso,&nome1,&nome2,&nome3);
        }
        if (operacao==2){
            printf("%f\n",latitude);
            printf("%f\n",longitude);
            printf("%d\n",peso);
            printf("%s\n",nome1);
            printf("%s\n",nome2);
            printf("%s\n",nome3);
        }
        if (operacao==3){

        }
    }



}