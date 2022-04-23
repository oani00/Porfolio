/*
3. Escreva um programa que contenha duas variáveis inteiras. 
    Leia essas variáveis do teclado. 
    Em seguida, compare seus endereços e exiba o conteudo do maior endereço.
*/

#include <stdio.h>

int main(){

	int a, b;
	int *ptA, *ptB;

    printf("Apesar de isso nao mecher no endreco, digite um valor para A por favor: \n");
	scanf("%i",&a);
	printf("Apesar de isso nao mecher no endreco, digite um valor para B por favor: \n");
	scanf("%i",&b);
	printf("Blz, agora o valor de a é %i e b é %i, e... \n", a, b);
	
	ptA = &a;
    ptB = &b;

	if (ptA > ptB)
		printf("O maior endereco eh A: %i", ptA);
	else
		printf("O maior endereco eh B: %i", ptB);


return 0;
}
