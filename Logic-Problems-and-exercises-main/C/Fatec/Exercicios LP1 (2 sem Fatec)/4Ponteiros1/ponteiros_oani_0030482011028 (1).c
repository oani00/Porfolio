/*
1.Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char.
	Associe as variaveis aos ponteiros (use &).
   Modifique os valores de cada variavel usando os ponteiros.
   Imprima os valores das variáveis antes e após a modificação.
*/

#include <stdio.h>

int main (){

	int i = 1, *pi;
	float f = 0.1, *pf;
	char c = 'a', *pc;

	pi = &i;
	pf = &f;
	pc = &c;

	printf("\nO valor de i eh %i", i);
	printf("\nO valor de f eh %f", f);
	printf("\nO valor de c eh %c", c);


	*pi = 2;
	*pf = 20;
	*pc = 'd';


	printf("\n\n======Agora sao:======\n");

	printf("\nO valor de i eh %i", i);
	printf("\nO valor de f eh %f", f);
	printf("\nO valor de c eh %c", c);


	return 0;
}
