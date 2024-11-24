#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"


int main() {
    
    int quntdsondas, quntdoperacoes, i,peso, contador=0,j=0,k,escolha;
    char entrada[255], operacao;
    const char s[2]= " ";
    char * token;
    char categoria[20];
    float longitude, latitude, lat_i, long_i, velocidade_i, combustivel_i, capacidade_i;
    

    L_Minerais lista_m;
    Minerais minerais;
    
    Lista_s lista_sonda;
    Trocha lrocha;
    TLista comp;
    L_entrada lista_e;
    


    printf("Escolha se o codigo será rodado pela entrada do terminal ou de um arquivo txt:\n(1)=arquivo\n(2)=terminal\n");
    scanf("%d",&escolha);




    if (escolha==1){
        
            FILE * arquivo;
            arquivo = fopen("arquivo.txt", "r");
            if (arquivo == NULL) {
                printf("erro ao alocar");
            }
            
            int l=0;
            int quntdsondas, quntdoperacoes;

            fscanf(arquivo, "%d", &quntdsondas); 
            fgetc(arquivo);
            FLvazia_e(&lista_e);
            FLVazia_s(&lista_sonda);
            
            float lat, lon, capacidade, velocidade, combustivel;
            TSonda Nsonda;

            for (int k = 0; k < quntdsondas; k++) {

                fscanf(arquivo, "%f %f %f %f %f", &lat, &lon, &capacidade, &velocidade, &combustivel);
                fgetc(arquivo);
                Inicializar_sonda(&Nsonda, lat, lon, capacidade);
                LInsere_s(&lista_sonda, &Nsonda);
            }

            fflush(stdout);
            fscanf(arquivo, "%d", &quntdoperacoes); 
            fgetc(arquivo);
            char operacao;

            for (int i = 0; i < quntdoperacoes; i++) {
                printf("OPERACAO %d de %d\n", i + 1, quntdoperacoes);

                // Limpeza do buffer para garantir que qualquer '\n' ou caractere residual seja consumido
                while (fgetc(arquivo) != '\n' && !feof(arquivo));  // Consume até a próxima linha

                // Lê a operação com fscanf, ignorando espaços antes
                char operacao;
                if (fscanf(arquivo, " %c", &operacao) != 1) { // O " " antes do %c ignora espaços
                    printf("Erro ao ler operação\n");
                    break; // Se não conseguir ler a operação, sai do loop
                }

                // Lê e consome a quebra de linha após a operação
                while (fgetc(arquivo) != '\n' && !feof(arquivo));  // Consume até a próxima linha

                // Processa a operação de acordo com o tipo
                if (operacao == 'R') {
                    // Leitura da rocha
                    float latitude, longitude;
                    int peso;

                    // Lê a linha com latitude, longitude e peso da rocha
                    if (fscanf(arquivo, "%f %f %d", &latitude, &longitude, &peso) != 3) {
                        printf("Erro ao ler dados da rocha (latitude, longitude, peso)\n");
                        break; // Se não conseguir ler os dados, sai do loop
                    }

                    // Limpeza do buffer após a leitura dos dados da rocha
                    while (fgetc(arquivo) != '\n' && !feof(arquivo));

                    // Agora, lê os minerais (se existirem)
                    char minerais_entrada[255];
                    if (fgets(minerais_entrada, sizeof(minerais_entrada), arquivo) == NULL) {
                        printf("Erro ao ler os minerais da rocha\n");
                        break; // Se não conseguir ler os minerais, sai do loop
                    }

                    // Remove a quebra de linha, se houver
                    minerais_entrada[strcspn(minerais_entrada, "\n")] = '\0'; 

                    printf("Minerais da rocha: %s\n", minerais_entrada);

                    // Processa os minerais da rocha
                    char *token = strtok(minerais_entrada, " ");
                    Trocha rocha;
                    TSonda *sonda;
                    Trocha rnova;

                    // Inicializa a rocha com os dados lidos (antes de processar os minerais)
                    rocha = InicializaRocha(&rnova, 1, peso, latitude, longitude);

                    while (token != NULL) {
                        if (strlen(token) > 0) {  // Verifica se o token não é vazio
                            // Inicializa o mineral e insere na lista de minerais
                            entradaminerais entradam;
                            entradaminerais m1 = InicializarMinerale(&entradam, token);
                            LInsere_e(&lista_e, m1); // Insere o mineral na lista de minerais

                            // Classifica a rocha e insere na lista de classificação
                            classifica_categoria(&lista_e, &rnova, l);
                            Lretira_e(&lista_e);

                            // Atualiza a rocha com os novos minerais
                            rocha = InicializaRocha(&rnova, 1, peso, latitude, longitude);

                            // Calcula a sonda mais próxima e insere a rocha no compartimento
                            sonda = Calculo_sonda_prox(&lista_sonda, &rocha);
                            LInsere(&sonda->compartimento, &rocha);
                        }
                        token = strtok(NULL, " ");  // Avança para o próximo mineral
                    }

                    // Imprime informações sobre a rocha inserida
                    printf("Rocha inserida na sonda\n");

                } else if (operacao == 'I') {
                    // Operação de Inserção
                    Operacao_i(&lista_sonda);
                } else if (operacao == 'E') {
                    // Operação de Exibição
                    OperacaoE(&lista_sonda);
                } else {
                    // Caso a operação não seja reconhecida
                    printf("Operação inválida no arquivo\n");
                }
            }

            fclose(arquivo);


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
                        entradaminerais entradam;
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
