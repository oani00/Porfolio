/* Faça uma função recursiva que permita somar os elementos de um vetor de inteiros de 10 posições.*/

#include <stdio.h>


int somavetor(int vetor[], int posicao);
void main(void){
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};
    int tamvetor = sizeof(vet)/sizeof(int);
    printf("%d", somavetor(vet,tamvetor-1));
}

int somavetor(int vetor[], int posicao){
    if(posicao < 0)
        return 0;
    else
        return vetor[posicao] + somavetor(vetor, posicao-1);
}
