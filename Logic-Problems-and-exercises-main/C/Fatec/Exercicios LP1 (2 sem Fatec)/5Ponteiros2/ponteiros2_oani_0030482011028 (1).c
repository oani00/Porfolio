//1. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição desse array.

#include <stdio.h>

int main(int argc, char const *argv[])
{
	float arr[10];
	int i = 0, *p;

	for (i = 0; i<10;i++){
        p = &arr[i];
        printf("p[%d] = %d\n", i, p);
	}
	
	return 0;
}
