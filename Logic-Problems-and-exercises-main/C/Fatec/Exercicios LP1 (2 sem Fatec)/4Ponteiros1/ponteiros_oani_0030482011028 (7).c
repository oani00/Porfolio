
/*
7. Crie um programa que contenha uma função que permita passar por parâmetro dois  números inteiros A e B. 
    A função deverá calcular a soma entre estes dois números e armazenar o resultado na variável A. 
    Esta funcção não deverá possuir retorno, mas deverá modificar o valor do primeiro parâmetro.
*/


#include <stdio.h>


void soma(int *ptA, int *ptB){

    *ptA = *ptA + *ptB;

}


int main(){

	int A, B;
	int *ptA, *ptB;

    printf("Me de um A\n");
	scanf("%i",&A);
	printf("Me de um B\n");
	scanf("%i",&B);
	printf("======= SOMANDO =======\n");

	soma(&A, &B);
	
	printf("Agora o conteudo de A eh: %i", A);
	printf("\nAgora o conteudo de B eh: %i", B);

	printf("\n Alias, o o conteudo de A eh a soma: %i", A);



return 0;
}
