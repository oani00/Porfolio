/*
    6.Crie uma função que receba dois parâmetros: um array e um
    valor do mesmo tipo do array. A função deverá preencher os
    elementos de array com esse valor. Não utilize  índices para
    percorrer o array, apenas aritmetica de ponteiros.
*/
#include <stdio.h>
#define TAM 5

void PreencheArray(int *ptrVetor, int valor);

int main(){

    int vetor[TAM],
    valor = 7;

    PreencheArray(vetor, valor);

    for(int i = 0; i < sizeof(vetor)/sizeof(int); i++){
        printf("valor na Posicao %d: %d\n", i, vetor[i]);
    }
    return 0;
}

void PreencheArray(int *ptrVetor, int valor){
    for(int i = 0; i < TAM; i++){
        *(ptrVetor+i) = valor;
    }
}
