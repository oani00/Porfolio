
//2. Crie um programa que contenha um array de inteiros contendo 5 elementos.
//Utilizando apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.


#include <stdio.h>

int main(int argc, char const *argv[])
{

	int arr[5];
	int i = 0, *p;

	for (i = 0; i < 5; i++){
		printf("Digite o valor de arr[%d]\n", i);
		p = &arr[i];
		scanf("%i", p);
		*p *= 2;
		printf("arr[%i] = %d\n", i, arr[i]);
	}

	return 0;
}
