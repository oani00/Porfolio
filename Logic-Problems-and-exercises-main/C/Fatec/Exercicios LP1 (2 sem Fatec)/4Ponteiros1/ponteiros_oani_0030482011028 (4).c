
/*
4. Faça um programa que leia 2 valores inteiros
e chame uma função que receba estas  2 variaveis e troque o seu conteúdo.
    Esta função é chamada passando duas  variaveis A e B,
	por exemplo e, após a execução da função, A conterá o valor de B e B  terá  valor de A.
*/



#include <stdio.h>


void transforma(int *ptA, int *ptB){

	int aux = *ptA;
	*ptA = *ptB;
	*ptB = aux;

}


int main(){

	int A, B;
	int *ptA, *ptB;

    printf("Me de um A\n");
	scanf("%i",&A);
	printf("Me de um B\n");
	scanf("%i",&B);
	printf("======= TROCANDO =======\n");

	transforma(&A, &B);

	printf("Agora o conteudo de A eh: %i", A);
	printf("\nAgora o conteudo de B eh: %i", B);


return 0;
}
