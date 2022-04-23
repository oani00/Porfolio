//4. Faça um programa que leia tres valores inteiros e chame uma função que receba estes 3  valores de entrada e retorne eles ordenados,
	//ou seja, o menor valor na primeira variável,  ́
	//o segundo menor valor na variável do meio,
	//e o maior valor na  ́última variável.

//A função deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes.
//Exibir os valores ordenados na tela.

#include <stdio.h>

int ordenar(int *px, int *py, int *pz){

	//checando se sao iguais
	int resultado, aux;

	if (*px == *py && *py == *pz)
		resultado = 1;
	else
		resultado = 0;

	//ordenando
	//Esse post ajudou: https://stackoverflow.com/questions/4367745/simpler-way-of-sorting-three-numbers

	if (*px > *pz){
		aux = *px;
		*px = *pz;
		*pz = aux;
	}
	if (*px > *py){
		aux = *px;
		*px = *py;
		*py = aux;
	}
	if (*py > *pz){
		aux = *py;
		*py = *pz;
		*pz = aux;
	}

	return resultado;
}

int main(int argc, char const *argv[])
{

	int x, y, z, res, *px, *py, *pz;
	printf("Informe x, y, z nessa ordem:\n");
	scanf("%i", &x);
	scanf("%i", &y);
	scanf("%i", &z);

	px = &x;
	py = &y;
	pz = &z;

	res = ordenar(px, py, pz);

	printf("Agora vou te apresentar em ordem crescente mas mudando os valores das variaveis:\n");
	printf("\nO novo x = %d", x);
	printf("\nO novo y = %d", y);
	printf("\nO novo z = %d", z);

	printf("\nAlias, agora retornarei o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. E o valor é:");
	printf("\nO novo x = %d", res);

	return 0;
}
