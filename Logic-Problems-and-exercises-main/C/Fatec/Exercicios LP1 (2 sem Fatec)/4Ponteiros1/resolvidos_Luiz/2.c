/*
2. Escreva um programa que contenha duas vari�veis inteiras.
   Compare seus endere�os e exiba o maior endere�o.
*/
#include <stdio.h>

int main(){

    int a,b, *ptra, *ptrb;

    a = 10;
    b = 15;

    ptra = &a;
    ptrb = &b;

    printf("endereco de A: %ld\n", ptra);
    printf("endereco de B: %ld\n", ptrb);
    if(ptra > ptrb) printf("\nvalor do maior endereco: %ld\n", *ptra);
    else printf("\nvalor do maior Endereco: %ld\n", *ptrb);

    return 0;
}
