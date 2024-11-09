#include <stdio.h>
#include <stdlib.h>
#include <L_Rochas.h>
#include <Rochas.h>

void FLVazia(TLista *pLista){
    pLista->pPrimeiro = (Apontador) malloc(sizeof(Tcelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}
int LEHVazia(TLista* pLista){
    return(pLista->pPrimeiro == pLista->pUltimo);
}
int LInsere(TLista* pLista, Trocha* pRocha ){
    pLista->pUltimo->pProx = (Apontador) malloc(sizeof(Tcelula));
    PLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->;
}
int LRetita(TLista* pLista, Trocha* pRocha){

}
void LImprime(TLista* pLista){

}
