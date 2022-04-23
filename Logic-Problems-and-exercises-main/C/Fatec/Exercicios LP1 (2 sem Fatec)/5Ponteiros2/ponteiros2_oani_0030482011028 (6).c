//6. Crie uma função que receba dois parâmetros:
	//um array
	//e um valor do mesmo tipo do array.
//A função deverá preencher os elementos de array com esse valor.
//Não utilize  índices para percorrer o array, apenas aritmetica de ponteiros.

//https://www.dummies.com/programming/c/how-to-substitute-pointers-for-array-notation-in-c-programming/

#include <stdio.h>
#define TAM 10


void encher(int *x, int *v){

	int soma = 0, i= 0;
	while(*x < TAM)
	{
		x[0] = *v;
		printf("arr[%d] = %d\n", i, *x);
		x++;
		i++;
    }
}

int main(int argc, char const *argv[])
{

	int v;
	int arr[TAM] = {1,1,1,1,1,1,1,1,1,1};

	printf("Vou encher um array com um valor que você fornecer:\n");
	scanf("%d", &v);

	encher(&arr[0], &v);

	return 0;
}
