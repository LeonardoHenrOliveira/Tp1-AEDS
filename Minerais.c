#include <stdio.h>
#include <string.h>
#include "Minerais.h"

Minerais InicializarMineral(Minerais* minerais, char* nome, float dureza, float reatividade, char* cor){
    
    setNome(minerais, nome);
    setDureza(minerais, dureza);
    setReatividade(minerais, reatividade);
    setCor(minerais, cor);

    return *minerais;
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


char* getNome(Minerais* minerais){
    return(minerais->Nome);
}

int getDureza(Minerais* minerais){
    return(minerais->Dureza);
}

int getReatividade(Minerais* minerais){
    return(minerais->Reatividade);
}

char* getCor(Minerais* minerais){
    return(minerais->Cor);
}

