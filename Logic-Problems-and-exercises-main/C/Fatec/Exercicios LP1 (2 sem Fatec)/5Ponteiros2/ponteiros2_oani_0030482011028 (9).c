//9. Escreva um programa que declare
	//um array de inteiros
	//e um ponteiro para inteiros.
		//Associe o ponteiro ao array.
		//Agora, some mais um (+1) a cada posicao do array usando o ponteiro (use *).

#include <stdio.h>
#define TAM 5

int main(int argc, char const *argv[])
{

	int arr[TAM] = {1,1,1,1,1}, *pt, i = 0;

	pt = &arr[0];

	while (i < TAM){
		*pt += 1;
		printf("arr[%d] = %d\n", i, *pt);
		i++;
		pt++;
	}

	return 0;
}
