/*
6. Elaborar um programa que leia dois valores inteiros (A e B).
Em seguida faça uma função que retorne a soma do dobro dos dois numeros lidos.

	A função deverá armazenar o dobro  de A na propria variável A
	e o dobro de B na própria variável B.
*/


#include <stdio.h>


int soma(int *ptA, int *ptB){

    int soma;

	*ptA *= 2;
	*ptB *= 2;
	soma = *ptA + *ptB;

	return soma;
}


int main(){

	int A, B, S;
	int *ptA, *ptB;

    printf("Me de um A\n");
	scanf("%i",&A);
	printf("Me de um B\n");
	scanf("%i",&B);
	printf("======= SOMANDO =======\n");

	S = soma(&A, &B);

	printf("Agora o conteudo de A eh: %i", A);
	printf("\nAgora o conteudo de B eh: %i", B);

	printf("\nE a soma eh: %i", S);


return 0;
}
