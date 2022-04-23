// 7. Escreva um algoritmo em linguagem C que:
   
   // a) OK leia um vetor A de 12 números reais; 
   
   // b) OKconstrua e imprima um vetor B formado da seguinte maneira: 
      // OK- os elementos de índice par são os correspondentes de A divididos por 2; 
      // OK- os elementos de índice ímpar são os correspondentes de A multiplicados por 3.


#include <stdio.h>

void armazenar(){

	//double A[12] = {1,2,3,4,5,6,7,8,9,10, 11, 12};
	double B[12];
	int i;
	double A[12];

	printf("Oi! Diga os elementos do vetor por favor:\n");
	//inserindo A
	for (i=0; i < 12;i++){
		printf("Insira o numero: ");
		scanf("%lf", &A[i]);
    }

	for (i=0; i < 12;i++){
		if (i%2 == 0){ 
            B[i] = A[i] / 2;
        }
		else {
            B[i] = A[i] * 3; // continue acumulando o produto e multiplicando ele por a[i]
		}

  }
	//printando os valores
  	
  	printf("Este é o vetor B:\n");
  	for (i=0; i < 12;i++){
		printf("%.2lf\n", B[i]);
  	}
}

int main(){

armazenar();

return 0;}