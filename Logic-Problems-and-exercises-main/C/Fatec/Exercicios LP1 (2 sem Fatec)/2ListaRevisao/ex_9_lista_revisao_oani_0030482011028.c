// 9.
//OK Leia 10 números inteiros e armazene em um vetor A.

//OK Crie dois novos vetores A1 e A2.

//OK Copie os valores ímpares de A para A1, e os valores pares de A para A2.
	//OK Note que cada um dos vetores A1 e A2 tem no máximo 10 elementos, mas nem todos os elementos são utilizados.

// No final escreva os elementos utilizados de A1 e A2.


#include <stdio.h>

void armazenar(){


	//int A[10] = {1,2,3,4,5,6,7,8,9,10};
	int A[10];

	int i;
	//inserindo A
	for (i=0; i < 10;i++){
		printf("Insira o numero: ");
		scanf("%d", &A[i]);
    }

	int j=0, k=0, imp = 0, par = 0;

	//gerando A1 e A2
	for (i=0; i < 10;i++){
		if (A[i]%2 == 0){ //se for par
            par++;}
		else{
            imp++;}
  	}

  	int A1[imp], A2[par];

	//preenchendo A1 e A2
  	for (i=0; i < 10;i++){
		if (A[i]%2 == 0){ //se for par
            A2[j] = A[i];
        	j++;}
		else{
            A1[k] = A[i];
        	k++;}
  	}

  	//printando os valores
  	
  	printf("Elementos de A1:\n");
  	for (i=0; i < imp;i++){
		printf("%d\n", A1[i]);
  	}

  	printf("\n");

  	printf("Elementos de A2:\n");
  	for (i=0; i < par;i++){
		printf("%d\n", A2[i]);
  	}
}

int main(){

armazenar();

return 0;}