/*
7. Crie um programa que contenha uma função que permita passar
por parâmetro dois  números inteiros A e B.
    A função deverá calcular a soma entre estes dois números e
    armazenar o resultado na variável A.
    Esta funcção não deverá possuir retorno, mas deverá
    modificar o valor do primeiro parâmetro.
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


