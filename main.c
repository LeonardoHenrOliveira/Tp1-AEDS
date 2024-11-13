#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L_Minerais.h"
#include "Menu.h"
#include "Rocha.h"

int main() {
    int quntdsondas, quntdoperacoes, i,operacao,peso, contador=0,j=0;
    char entrada[255];
    const char s[2]= " ";
    char*token,mineral1[20],mineral2[20],mineral3[20], categoria[20];
    float latitude, longitude;
    L_Minerais lista_m;
    Minerais minerais;
    Trocha lrocha;
    entradaminerais* entradam;
    L_entrada* listae;

    PreencheMinerais(&lista_m, &minerais);
    FLvaziae(listae);
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
            fgets(entrada, 255, stdin);
            token = strtok(entrada,s);
            latitude=atof(token);
            token = strtok(NULL,s);
            longitude= atof(token);
            token = strtok(NULL, s);
            peso=atoi(token);
            while( token!= NULL ) {
                token = strtok(NULL,s);
                InicializarMinerale(entradam,token);
                LInseree(listae,token);
            }
            for (j=0;j<3;j++){
                printf("%s",listae->iteme[j]);
            }
        }
        if (operacao==2){
           
        }
        if (operacao==3){

        }
    }



}