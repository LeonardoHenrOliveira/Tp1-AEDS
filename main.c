#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L_Minerais.c"
#include "Menu.h"

int main() {
    int quntdsondas, quntdoperacoes, i,operacao;
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
    }



}