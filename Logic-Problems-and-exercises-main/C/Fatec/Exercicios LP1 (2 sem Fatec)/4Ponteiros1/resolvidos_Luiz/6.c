/*
6. Elaborar um programa que leia dois valores inteiros (A e B).
 Em seguida faça uma função que retorne a soma do dobro dos dois
 numeros lidos.
    A função deverá armazenar o dobro  de A na propria variável A
    e o dobro de B na própria variável B.
*/
#include <stdio.h>
void DobraValor(int *a, int *b);

int main(){

    int A, B;

    printf("digite o valor de A: ");
    scanf("%d", &A);

    printf("digite o valor de B: ");
    scanf("%d", &B);

    printf("\nValor de A => %d", A);
    printf("\nValor de B => %d", B);
    DobraValor(&A, &B);
    printf("\n\nValor de A => %d", A);
    printf("\nValor de B => %d", B);

    return 0;
}

void DobraValor(int *a, int *b){

    *a *= 2;
    *b *= 2;

}


