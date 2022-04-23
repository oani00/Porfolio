/*
5. Faça um programa que leia dois valores inteiros 
e chame uma função que receba estes  2 valores de entrada 
e retorne 
	o maior valor na primeira variável 
	e o menor valor na  segunda variável.
    
	Escreva os conteúdos das 2 variáveis na tela.
*/





#include <stdio.h>


void transforma(int *ptA, int *ptB){

	if (*ptB>*ptA){
	int aux = *ptA;
	*ptA = *ptB;
	*ptB = aux;
	}
	
}


int main(){

	int A, B;
	int *ptA, *ptB;

    printf("Me de um A\n");
	scanf("%i",&A);
	printf("Me de um B\n");
	scanf("%i",&B);
	printf("======= ORDENANDO =======\n");

	transforma(&A, &B);

	printf("Agora o conteudo de A eh: %i", A);
	printf("\nAgora o conteudo de B eh: %i", B);


return 0;
}
