/*
3. Escreva um programa que contenha duas vari�veis inteiras.
    Leia essas vari�veis do teclado.
    Em seguida, compare seus endere�os e exiba o conteudo do maior endere�o.
*/

#include <stdio.h>

int main(){

    int a, b, *ptra, *ptrb;

    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    ptra = &a;
    ptrb = &b;

    printf("endereco de A: %ld\n", ptra);
    printf("endereco de B: %ld\n", ptrb);
    if(ptra > ptrb) printf("\nvalor do maior endereco: %ld\n", *ptra);
    else printf("\nvalor do maior Endereco: %ld\n", *ptrb);

    return 0;
}
