/*
    1.Crie um programa que contenha um array de float contendo
    10 elementos. Imprima o endereço de cada posição desse array.
*/
#include <stdio.h>
#define TAM 10

int main(){

    int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    for(int i = 0; i < TAM; i++){
        ptr = &vetor[i];
        printf("endereco da posicao %d do vetor: %d\n", i, ptr);
    }
    return 0;
}
