/*
    3.Crie um programa que contenha um array contendo 5
    elementos inteiros. Leia esse arraydo teclado e
    imprima o endereço das posiçoes contendo valores
    pares.
*/
#include <stdio.h>
#define TAM 5

int main(){

    int vetor[TAM];
    int *ptr;
    for(int i = 0; i < TAM; i++){
        printf("Digite o valor que sera armazenado na posicao %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\nSomente sera impresso o endereco dos indices contando valores pares\n");
    for(int i = 0; i < TAM; i++){
        ptr = &vetor[i];
        if(*ptr % 2 == 0){
            printf("endereco da posicao %d do vetor: %d\n", i, ptr);
        }
    }
    return 0;
}
