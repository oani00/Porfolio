/*
   7. Crie uma fun��o que receba como par�metro um array e o
   imprima. N�o utilize  �ndices para percorrer o array,
   apenas aritmetica de ponteiros.
*/
#include <stdio.h>
#define TAM 10

void ImprimeArray(int *ptrVetor);

int main(){

    int vetor[TAM] = {10,20,30,40,50,60,70,80,90,100};
    ImprimeArray(vetor);
    return 0;
}

void ImprimeArray(int *ptrVetor){
    for(int i = 0; i < TAM ; i++){
        printf("Posicao %d do array, tendo valor de %d\n", i, *(ptrVetor+i));
    }
}
