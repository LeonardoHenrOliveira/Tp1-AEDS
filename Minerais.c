#include <stdio.h>
#include <string.h>
#include <Minerais.h>

void Inicializar(Minerais* minerais, char* nome, float dureza, float reatividade, char* cor){
    setNome(minerais, nome);
    setDureza(minerais, dureza);
    setReatividade(minerais, reatividade);
    setCor(minerais, cor);
}

void setNome(Minerais* minerais, char* nome){
    strcpy(minerais->Nome, nome);
};

void setDureza(Minerais* minerais, float dureza){
    minerais->Dureza = dureza;
};

void setReatividade(Minerais* minerais, float reatividade){
    minerais->Reatividade = reatividade;
};

void setCor(Minerais* minerais, char* cor){
    strcpy(minerais->Cor, cor);
};


int getNome(Minerais* minerais, char* nome){
    return(minerais->Nome);
}

int getDureza(Minerais* minerais, float dureza){
    return(minerais->Dureza);
}

int getReatividade(Minerais* minerais, float reatividade){
    return(minerais->Reatividade);
}

int getCor(Minerais* minerais, char* cor){
    return(minerais->Cor);
}

