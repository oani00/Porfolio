
/*
2. Escreva um programa que contenha duas variáveis inteiras.
   Compare seus endereços e exiba o maior endereço.
*/

#include <stdio.h>

int main(){

	int a, b;
	int *ptA, *ptB;

    ptA = &a;
    ptB = &b;

	if (ptA > ptB)
		printf("O maior endereco eh A: %i", ptA);
	else
		printf("O maior endereco eh B: %i", ptB);


return 0;
}
