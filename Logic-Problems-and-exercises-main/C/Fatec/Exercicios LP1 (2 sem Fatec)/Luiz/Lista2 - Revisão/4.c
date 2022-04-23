#include <stdio.h>
#define TAM 15

int main(){
    int vetor[TAM], i;
    for (i = 0; i < TAM; i++){
        printf("Insira um valor: ");
        scanf("%d", &vetor[i]);
    }
    for( i = 0; i < TAM; i++)
    {
        printf("Dobro do valor de VETOR[%d] = %d\n", i, vetor[i] * 2);
    }
}

/* caso de teste
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
11
12
13
14
15
*/
