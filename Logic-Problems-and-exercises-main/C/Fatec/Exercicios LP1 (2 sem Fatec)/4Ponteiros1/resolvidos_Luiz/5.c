/*
5. Fa�a um programa que leia dois valores inteiros e
chame uma fun��o que receba estes  2 valores de entrada e
retorne o maior valor na primeira vari�vel e o menor valor na
segunda vari�vel.
    Escreva os conte�dos das 2 vari�veis na tela.
*/
#include <stdio.h>

void TrocaValorPorMaior(int *a, int *b);

int main(){

    int A, B;

    printf("digite o valor de A: ");
    scanf("%d", &A);

    printf("digite o valor de B: ");
    scanf("%d", &B);

    printf("\nValor de A => %d", A);
    printf("\nValor de B => %d", B);
    TrocaValorPorMaior(&A, &B);
    printf("\n\nValor de A => %d", A);
    printf("\nValor de B => %d", B);

    return 0;
}

void TrocaValorPorMaior(int *a, int *b){

    int aux = *a;
    if(*a > *b){
        *a = aux;
    } else {
        *a = *b;
        *b = aux;
    }

}
