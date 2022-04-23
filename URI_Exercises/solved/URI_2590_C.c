// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 2590.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//https://github.com/malbolgee/URI/blob/master/2590.c

typedef unsigned long long llu;

int main(void)
{	
	
	/*

	Esta solução da Time limit exceeded. Comentarei a correta abaixo:
	int casos;
	double n;
	
	scanf("%i", &casos);
	// printf("aaaaaaaaaaa");

	for (int i = 0; i < casos; ++i)
	{
		scanf("%lf", &n);
		// printf("bbbbbbbbbbb");

		//blz me achei aqui. Ele calcula o exp, ja passa no achar ultimo, e ja passa no printf.
		//https://www.tutorialgateway.org/c-program-find-last-digit-number/
		printf("%i\n", (int) (pow(7, n))%10);
	}
	
	return 0;
	*/


	llu n, m;
	char l_digit[] = { 1, 7, 9, 3 }; //olha que sacada

	scanf("%llu", &m);

	while (m--) //semelhante a um for 
		scanf("%llu", &n), printf("%hhd\n", l_digit[n % 4]); //o cara ate ja deixou em uma linha, outra coisa ein
															 //Fantastico. Os multiplos de 7 deve terminar apenas nesses 4
															 //Ai esse resto por 4 deve funcionar como um reloginho
															 //ai que quer que seja o numero a operação é 10bi de vezes mais rapida de se fazer assim
															 //Compare isso com meu codigo que ia eletar o 7 a um numero long long!!!!!!
															 //enfim sacada demais.

	//outro erro meu foi supor que o limite seria não muito grande pelo problema nao fornece-lo
	//mas ja que podemos, por que não jogar la em cima?

	return  0;
}