#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"


int main() {
    
    int quntdsondas, quntdoperacoes, i,peso, contador=0,j=0,k,escolha;
    char entrada[255], operacao;
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


    printf("Escolha se o codigo será rodado pela entrada do terminal ou de um arquivo txt:\n(1)=arquivo\n(2)=terminal\n");
    scanf("%d",&escolha);
   
    if (escolha==1){
        
            FILE * arquivo = NULL;
            arquivo = fopen("arquivo.txt", "r");
            if (arquivo == NULL) {
                perror("Erro ao abrir o arquivo");
            }
            int l=0;
            int quntdsondas, quntdoperacoes;
            fscanf(arquivo, "%d", &quntdsondas); // Ler número de sondas
            FLVazia_s(&lista_sonda);

            // Ler as informações das sondas
            for (int k = 0; k < quntdsondas; k++) {
                TSonda Nsonda;
                float lat, lon, capacidade, velocidade, combustivel;
                fscanf(arquivo, "%f %f %f %f %f", &lat, &lon, &capacidade, &velocidade, &combustivel);
                Inicializar_sonda(&Nsonda, lat, lon, capacidade);
                LInsere_s(&lista_sonda, &Nsonda);
            }

            fscanf(arquivo, "%d", &quntdoperacoes); // Ler número de operações
            char operacao;
            TLista lista_temp;
            FLVazia(&lista_temp);

            for (int i = 0; i < quntdoperacoes; i++) {
                fscanf(arquivo, " %c", &operacao);

                if (operacao == 'R') {
                    float latitude, longitude;
                    int peso;
                    char minerais_entrada[255];
                    fscanf(arquivo, "%f %f %d %[^\n]", &latitude, &longitude, &peso, minerais_entrada);

            // Processar minerais
                    L_entrada lista_e;
                    FLvazia_e(&lista_e);
                    char* token = strtok(minerais_entrada, " ");
                    while (token != NULL) {
                        entradaminerais m1 = InicializarMinerale(NULL, token);
                        LInsere_e(&lista_e, m1);
                        token = strtok(NULL, " ");
                        l++;
                    }

                    Trocha rnova;
                    classifica_categoria(&lista_e, &rnova,l );
                    Trocha rocha = InicializaRocha(&rnova, 1, peso, latitude, longitude);
                    TSonda* sonda = Calculo_sonda_prox(&lista_sonda, &rocha);
                    LInsere(&sonda->compartimento, &rocha);
                    Lretira_e(&lista_e);

                } else if (operacao == 'I') {
                    Operacao_i(&lista_sonda);
                } else if (operacao == 'E') {
                    OperacaoE(&lista_sonda);
                } else {
                    printf("Operação inválida no arquivo\n");
                }
    
    fclose(arquivo);
}







    }
    else if (escolha==2){
        PreencheMinerais(&lista_m, &minerais);
        printquntdsondas();
        scanf("%d",&quntdsondas);

        FLVazia_s(&lista_sonda);
    
        for (k = 0; k < quntdsondas; k++){
            TSonda Nsonda;
            printsonda(quntdsondas);
            scanf("%f %f %f %f %f", &Nsonda.Latitude, &Nsonda.Longitude,&Nsonda.capacidade,&velocidade_i,&combustivel_i);
            Inicializar_sonda(&Nsonda,Nsonda.Latitude,Nsonda.Longitude,Nsonda.capacidade);
            LInsere_s(&lista_sonda, &Nsonda);
        }
    
    
        printquntdoperacoes();
        scanf("%d",&quntdoperacoes);
        FLvazia_e(&lista_e);
        
        for (i = 0; i < quntdoperacoes; i++){
            printmenu();
            scanf(" %c",&operacao);
            
            if(operacao=='R'){
                j = 0;
                printRochanova();
                getchar();
                fgets(entrada, 255, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';

                token = strtok(entrada,s);
                latitude = atof(token);
                token = strtok(NULL,s);
                longitude = atof(token);
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
                classifica_categoria(&lista_e,&rnova,j);
                Lretira_e(&lista_e);
                Trocha r1 = InicializaRocha(&rnova,1, peso, latitude, longitude);
                TSonda *sondamaisprox = Calculo_sonda_prox(&lista_sonda, &rnova);
                LInsere(&sondamaisprox->compartimento,&rnova);
            
                
            }
            else if (operacao== 'I'){
                Operacao_i(&lista_sonda);
            }
            else if (operacao== 'E'){
                OperacaoE(&lista_sonda);
            }
            else{
                printf ("operacao invalido");
            }
            
        }

    }

}
