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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI/resolvidos && gcc z1267.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

typedef struct 
{
	char carne[51];
	int validade;
}lote;

int main()
{
    
	int n, i, j, k;
	
	while (scanf("%i", &n) != EOF)
	{
		
		lote churras[n];
		lote aux;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%s %i", churras[i].carne, &churras[i].validade);
		}

		for (int i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n - j - 1; k++)
				{
					//ordenando os volumes e ids igualmente
					if (churras[k].validade > churras[k + 1].validade) /* For decreasing order use '<' instead of '>' */
					{
						aux				= churras[k];
						churras[k] 		= churras[k + 1];
						churras[k + 1] 	= aux;
					}
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			if (i != 0 && i != n)
				printf(" ");

			printf("%s", churras[i].carne);

		}
		printf("\n");
	}
	
	return 0;
}