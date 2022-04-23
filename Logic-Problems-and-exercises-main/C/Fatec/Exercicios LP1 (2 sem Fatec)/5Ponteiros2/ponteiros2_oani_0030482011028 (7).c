//7. Crie uma função que receba como parâmetro um array e o imprima.
//Não utilize  índices para percorrer o array, apenas aritmetica de ponteiros.

#include <stdio.h>
#define TAM 10


void mostrar(int *x){

	int i = 0;
	while(*x < TAM+1)
	{
		printf("x[%d] = %d\n", i, *x);
		x++;
		i++;
    }

}

int main(int argc, char const *argv[])
{

	int v;
	int arr[TAM] = {1,2,3,4,5,6,7,8,9,10};

	mostrar(&arr[0]);

	return 0;
}

