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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 1022.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//Algoritmo de Euclides iterativo https://www.blogcyberini.com/2018/03/algoritmo-para-calcular-o-mmc.html
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{	
	
	int n, a, b, c, d, x, y, xsimp, ysimp;
	char op, bar, bardois;

	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
	{
	
		scanf("%i %c %i %c %i %c %i", &a, &bar, &b, &op, &c, &bardois, &d);

		if (op == '+'){
			// a   c   x
			// - + - = -
			// b   d   y

			x = a*d + c*b;
			y = b*d;

			int min = mdc(x,y);

		  	xsimp = x/min;
			ysimp = y/min;

			if (xsimp < 0 || ysimp < 0){
				printf("%i/%i = -%i/%i\n", x, y, abs(xsimp), abs(ysimp));
			}else{
				printf("%i/%i = %i/%i\n", x, y, xsimp, ysimp);}
		}

		if (op == '-'){
			// a   c   x
			// - - - = -
			// b   d   y

			x = a*d - c*b;
			y = b*d;

			int min = mdc(x,y);

		  	xsimp = x/min;
			ysimp = y/min;

			if (xsimp < 0 || ysimp < 0){
				printf("%i/%i = -%i/%i\n", x, y, abs(xsimp), abs(ysimp));
			}else{
				printf("%i/%i = %i/%i\n", x, y, xsimp, ysimp);}
		}

		if (op == '*'){
			// a   c   x
			// - * - = -
			// b   d   y

			x = a*c;
			y = b*d;

			int min = mdc(x,y);

		  	xsimp = x/min;
			ysimp = y/min;

			if (xsimp < 0 || ysimp < 0){
				printf("%i/%i = -%i/%i\n", x, y, abs(xsimp), abs(ysimp));
			}else{
				printf("%i/%i = %i/%i\n", x, y, xsimp, ysimp);}
		}

		if (op == '/'){
			// a   c   x
			// - / - = -
			// b   d   y

			x = a*d; //multiplica pelo inverso
			y = b*c;

			int min = mdc(x,y);

		  	xsimp = x/min;
			ysimp = y/min;

			if (xsimp < 0 || ysimp < 0){
				printf("%i/%i = -%i/%i\n", x, y, abs(xsimp), abs(ysimp));
			}else{
				printf("%i/%i = %i/%i\n", x, y, xsimp, ysimp);}
		}
	}
	return 0;
}