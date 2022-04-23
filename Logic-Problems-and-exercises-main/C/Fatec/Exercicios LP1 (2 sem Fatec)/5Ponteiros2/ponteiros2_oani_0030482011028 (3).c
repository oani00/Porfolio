
//3. Crie um programa que contenha um array contendo 5 elementos inteiros.
//Leia esse array do teclado e imprima o endereco das posicoes contendo valores pares.

#include <stdio.h>

int main(int argc, char const *argv[])
{

	int arr[5];
	int i = 0, *p;

	for (i = 0; i<5;i++){
		printf("Digite o valor de arr[%d]\n", i);
		p = &arr[i];
		scanf("%i", p);
		if (arr[i] %2 == 0)
			printf("arr[%i] = %d e sua posicao eh %d\n", i, arr[i], p);
		else
			printf("Putz nao eh valor par...\n");
	}

	return 0;
}
