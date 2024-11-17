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
    Trocha lrocha;
    entradaminerais entradam;
    TLista comp;
    L_entrada lista_e;
   

    PreencheMinerais(&lista_m, &minerais);
    printquntdsondas();
    scanf("%d",&quntdsondas);

    FLVazia_s(&lista_sonda);
    
    for (k = 0; k < quntdsondas; k++){
        TSonda Nsonda;
        printsonda(quntdsondas);
        scanf("%f %f %f %f %f",&Nsonda.Latitude, &Nsonda.Longitude,&Nsonda.capacidade,&velocidade_i,&combustivel_i);
        Inicializar_sonda(&Nsonda,Nsonda.Latitude,Nsonda.Longitude,Nsonda.capacidade);
        FLVazia(&Nsonda.compartimento);
        LInsere_s(&lista_sonda, &Nsonda);
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
            Trocha rnova;
            strcpy(rnova.categoria, " ");
            
            Trocha r1 = InicializaRocha(&rnova,1, peso, latitude, longitude);
            TSonda *sondamaisprox = Calculo_sonda_prox(&lista_sonda, &r1);
            
            classifica_categoria(&lista_e,&rnova);
            LInsere(sondamaisprox->compartimento,&r1);
            
        }
        if (operacao == 2){
            Celula_s* pAux;
            pAux = lista_sonda.pPrimeiro_s->pProx;
            while (pAux!=NULL){
                TSonda* sonda_2 = &pAux->item;
                printf("\n======================================\n");
                printf("ID: %d\n", sonda_2->Identificador);
                
                if(pAux->item.compartimento->pPrimeiro == NULL){
                    printf("Compartimento vazio!\n");
                }
                else{
                    Apontador pAux2;
                    pAux2 = pAux->item.compartimento->pPrimeiro->pProx;
                    while (pAux!=NULL){
                        printf("%s %.2f\n",pAux2->rocha.categoria , pAux2->rocha.peso);
                        pAux= pAux->pProx;
                    }
                }
        pAux = pAux->pProx;
        }
        printf("\n======================================\n");
        }
        if (operacao == 3){

        }
    }



}