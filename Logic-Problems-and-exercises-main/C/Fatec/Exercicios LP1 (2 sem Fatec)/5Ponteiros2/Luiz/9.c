/*
    9.Escreva um programa que declare um array de inteiros e um
    ponteiro para inteiros. Associe o ponteiro ao array.  Agora,
    some mais um (+1) a cada posicao do array usando o ponteiro (use *)
*/
#include <stdio.h>
#define TAM 5

int main(){

    int vetor[TAM] = {1,2,3,4,5}, *ptr;
    ptr = vetor;
    for(int i = 0; i < TAM; i++){
        printf("posicao %d do vetor, contendo valor de %d\n", i, vetor[i]);
    }
    for(int i = 0; i < TAM; i++){
        *(ptr+i) += 1;
        printf("\nposicao %d do vetor, contendo valor de %d", i, vetor[i]);
    }
    return 0;
}
