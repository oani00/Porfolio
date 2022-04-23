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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI/resolvidos/1028.c && gcc ex2_oani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

int main()
{
	int i, n, x, y, resto;
	
	scanf("%i", &n);
		
	for(i > 0; i < n; i++){
		
		scanf("%d %d", &x, &y);

		while(y != 0){

			resto = x % y;
			x = y;
			y = resto;
		}

		printf("%d\n", x);
	}
}