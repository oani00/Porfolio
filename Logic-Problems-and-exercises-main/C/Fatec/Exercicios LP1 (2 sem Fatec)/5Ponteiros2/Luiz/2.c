/*
    2.Crie um programa que contenha um array de inteiros
    contendo 5 elementos. Utilizando apenas aritmetica
    de ponteiros, leia esse array do teclado e imprima
    o dobro de cada valor lido.
*/
#include <stdio.h>
#define TAM 5

int main(){

    int vetor[TAM];
    int *ptr;
    for(int i = 0; i < TAM; i++){
        printf("Digite o numero %d do array: ", i+1);
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < TAM; i++){
        ptr = &vetor[i];
        *ptr *= 2;
        printf("\nO dobro do valor na posicao %d do vetor e': %d", i+1, (*ptr));
    }
    return 0;
}
