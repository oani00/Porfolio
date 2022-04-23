#include <stdio.h>
#define TAM 10

int main(){

    int vetor[TAM], i;
    for (i = 0; i < TAM; i++){
        printf("Insira um valor: ");
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < TAM; i++){
        printf(" VETOR[%d] = %d\n", i, vetor[i]);
    }
}
