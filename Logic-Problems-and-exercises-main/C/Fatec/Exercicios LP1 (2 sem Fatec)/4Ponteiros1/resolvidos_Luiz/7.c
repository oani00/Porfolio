/*
7. Crie um programa que contenha uma fun��o que permita passar
por par�metro dois  n�meros inteiros A e B.
    A fun��o dever� calcular a soma entre estes dois n�meros e
    armazenar o resultado na vari�vel A.
    Esta func��o n�o dever� possuir retorno, mas dever�
    modificar o valor do primeiro par�metro.
*/
#include <stdio.h>
void SomaValor(int *a, int *b);

int main(){

    int A, B;

    printf("digite o valor de A: ");
    scanf("%d", &A);

    printf("digite o valor de B: ");
    scanf("%d", &B);

    printf("\nValor de A => %d", A);
    printf("\nValor de B => %d", B);
    SomaValor(&A, &B);
    printf("\n\nValor de A => %d", A);
    printf("\nValor de B => %d", B);

    return 0;
}

void SomaValor(int *a, int *b){

    *a = *a + *b;

}


