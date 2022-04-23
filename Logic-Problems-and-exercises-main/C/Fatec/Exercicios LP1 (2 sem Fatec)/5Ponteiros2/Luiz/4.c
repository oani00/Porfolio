/*
    4.Faça um programa que leia tres valores inteiros e chame uma
    função que receba estes 3  valores de entrada e retorne eles
    ordenados, ou seja, o menor valor na primeira variável,  ́o
    segundo menor valor na variável do meio, e o maior valor na
    última variável. A função deve retornar o valor 1 se os tres
    valores forem iguais e 0 se existirem valores diferentes. Exibir
    os valores ordenados na tela.
*/
#include <stdio.h>

int RetornaOrdenado(int *a, int *b, int *c);

int main(){
    int num1, num2, num3;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);

    RetornaOrdenado(&num1, &num2, &num3);

    printf("\nNumero 1: %d",  num1);
    printf("\nNumero 2: %d",  num2);
    printf("\nNumero 3: %d",  num3);

    return 0;
}

int RetornaOrdenado(int *a, int *b, int *c){
    if(*a == *b && *a == *c){
        return printf("%d", 1);
    }
    else {
        int aux = *a, aux2 = *b;

        *a = *b < *c ? *b < *a ? *b : *a : *c < *a ? *c : *a;

        *b = *b > aux ? *b < *c ? *b : *c > aux ? *c : aux : *b > *c ? *b : *c;

        *c = *c > aux ? *c > aux2 ? *c : aux2 : aux > aux2 ? aux : aux2;

        return printf("%d", 0);
    }
}
