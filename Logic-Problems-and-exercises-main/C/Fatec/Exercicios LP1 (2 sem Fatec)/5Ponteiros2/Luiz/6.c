/*
    6.Crie uma fun��o que receba dois par�metros: um array e um
    valor do mesmo tipo do array. A fun��o dever� preencher os
    elementos de array com esse valor. N�o utilize  �ndices para
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
