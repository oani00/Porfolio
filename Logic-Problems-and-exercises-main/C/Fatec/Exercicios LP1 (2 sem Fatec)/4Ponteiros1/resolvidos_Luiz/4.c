/*
4. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas  2 variaveis e troque o seu conteúdo.
    Esta função é chamada passando duas  variaveis A e B, por exemplo e, após a execução da função, A conterá o valor de B e B  terá  valor de A.
*/
#include <stdio.h>

void TrocaValor(int *a, int *b);

int main(){

    int A, B;

    printf("digite o valor de A: ");
    scanf("%d", &A);

    printf("digite o valor de B: ");
    scanf("%d", &B);

    printf("\nValor de A => %d", A);
    printf("\nValor de B => %d", B);
    TrocaValor(&A, &B);
    printf("\n\nValor de A => %d", A);
    printf("\nValor de B => %d", B);

    return 0;
}

void TrocaValor(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;
}
