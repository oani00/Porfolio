#include <stdio.h>
#define TAM 10
double mediavetor(int vetor[], int tamanho);
void main(void){
    double media =0;
    int vetor[TAM];
    for(int i = 0; i < TAM; i++){
        printf("Digite um numero para o vetor(total de %d numeros): ", TAM);
        scanf("%d", &vetor[i]);
    }
    int tamvetor = TAM; // ou sizeof(vetor)/sizeof(int)
    media = mediavetor(vetor, tamvetor-1);
    printf("media com funcao recursiva = %.1lf\n", media);
}

double mediavetor(int vetor[], int tamanho){
    if(tamanho < 0){
        return 0;
    } else if(tamanho == TAM-1){
        return (vetor[tamanho] + mediavetor(vetor, tamanho-1))/TAM;
    } else {
        return vetor[tamanho] + mediavetor(vetor, tamanho-1);
    }
}

/* Casos de teste

1
2
3
4
5
6
7
8
9
10

10
5
10
5
10
5
10
5
10
5

*/
