#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ┌───┐
// │┌─┐│
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 1430.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//baseado em https://github.com/matheusaraujo/uri/blob/master/201904/1430/1430.c


int main(void)
{	
	char entrada[201];
	int i = 0;
	int compsOK = 0, valcomp = 0;
	
	while (scanf("%s", entrada) && entrada[0] != '*')
	{
		/*
					*	=			multiplicado
			W	1	1	1			1000000
			H	1	2	0.5			500000
			Q	1	4	0.25		250000
			E	1	8	0.125		125000
			S	1	16	0.0625		62500
			T	1	32	0.03125		31250
			X	1	64	0.015625	15625
		*/

		for (i = 1, valcomp = compsOK = 0; entrada[i] != '\0'; i++)
        {
        	if (entrada[i] == 'W')
			{
				valcomp += 1000000;
			}else if (entrada[i] == 'H')
			{
				valcomp += 500000;
			}else if (entrada[i] == 'Q')
			{
				valcomp += 250000;
			}else if (entrada[i] == 'E')
			{
				valcomp += 125000;
			}else if (entrada[i] == 'S')
			{
				valcomp += 62500;
			}else if (entrada[i] == 'T')
			{
				valcomp += 31250;
			}else if (entrada[i] == 'X')
			{
				valcomp += 15625;
			}

			if (entrada[i] == '/')
			{
				if (valcomp == 1000000)
				{
					compsOK++;
					valcomp = 0;
				}else
					valcomp = 0;
			}
        }
		printf("%i\n", compsOK);
	}
	return 0;
}