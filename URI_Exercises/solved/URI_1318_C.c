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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI/resolvidos/1318.c && gcc ex2_oani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

int main()
{
	int N, M;
	int i, j, k, cont;
	
	while(scanf("%d %d", &N, &M) && N != 0 && M != 0)
	{
		int entrada[M];
		for(i = 0; i < M; i++)
			scanf("%d", &entrada[i]);
		
		for(cont = 0, i = 0; i < M; i++)
		{
			for(j = 0; j < M; j++)
			{
				if(j != i)
					if(entrada[i] != 0 || entrada[j] != 0)
						if(entrada[i] == entrada[j]){
							cont = cont + 1;
							for(k = 0; k < M; k++)
							{
								if(k != j)
								if(entrada[k] == entrada[j])
								entrada[k] = 0;
							}
							entrada[j] = 0;
						}
			}
		}
		printf("%d\n", cont);
	}
	return 0;
}
