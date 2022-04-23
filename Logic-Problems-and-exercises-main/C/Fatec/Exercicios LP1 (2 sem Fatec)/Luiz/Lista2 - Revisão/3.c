
#include <stdio.h>
#define TAM 8

int main(){
    int vetor[TAM], i, pos;
    for (i = 0; i < TAM; i++){
        printf("Insira um valor: ");
        scanf("%d", &vetor[i]);
    }
    printf("Insira uma posicao do vetor para exibir seu valor ( de 1 a 8): ");
    scanf("%d", &pos);
    if(pos < 1 || pos > 8){
        printf("Digitou uma posicao invalida!");
    } else{
        printf("VETOR[%d] = %d", pos, vetor[pos-1]);
    }


}
