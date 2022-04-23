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

https://www.urionlinejudge.com.br/judge/pt/problems/view/1548

Pseudo: 

Eu achei que era mto facil, mas eu faria do jeito mais "burro" (mesmo assim o uri deve aceitar pq nao é tao pesado de executar)

-poupular o vetor
   -e uma cópia

-ordenar a copia

-comparar cada entrada e para quando der diferente cont++ e fazer total alunos - cont

Mas nao é tao simples, um jeito mais inteligente seria no bubble sort, ou o sort que for, ja ir comparando, algo como "quando não preciar
mudar aqui é um aluno que ja nao precisa"

Acho que tem um terceiro jeito que seria achar alguma regra tipo o 100 e 120, evidente que pelo menos 2 vao precisar trocar.
Deve ter algo matematico que ja indique o numero de trocas MINIMA, ai faz algo como maxAlunos - TrocasMinimas ou sei la.
   
Esses jeito seriam legais pq nem precisariam de um segundo vetor, mas nao sou nem inteligente nem paciente p fazer.

Solução: https://github.com/ferreiraapfernanda/fatec-uri-online-judge/blob/master/1548.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TRUE  1
#define FALSE 0

int main()
{
	int  Ncasos= 0, Malunos = 0, c, d, k, aux, qtd;
	int vAntes[1000], vDepois[1000]; //ó fez como eu tinha falado. Esse é meio que o padrao né, o resto seria mais legal mas mais dificil de fazer. 
	char trocas;

	scanf("%d", &Ncasos);

	for(c=0; c < Ncasos; c++)
	{
		qtd=0;
		scanf("%d", &Malunos);

		for(d=0; d < Malunos; d++)
		{
			scanf("%d", &vAntes[d]);
			vDepois[d] = vAntes[d];
		}

		do
		{
			trocas = FALSE;
			k = 0;
			while (k < Malunos - 1)
			{	if (vDepois[k] < vDepois[k + 1])
				{	aux = vDepois[k];
					vDepois[k] = vDepois[k + 1];
					vDepois[k + 1] = aux;

					trocas = TRUE; //interessante o jeito que escreveu a parada do bubble sort.
				}
				k++;
			}
		} while (trocas == TRUE);

		for(d=0; d < Malunos; d++)
			if (vAntes[d] == vDepois[d]) //é isso msm. Eu pensei que pesquisando uma solução usariam o psort, mas o bubble ja passou.
                                       //Uri é um saco, dependendo do problema o sort pode dar Time Lim...
				qtd++;

		printf("%d\n", qtd);
	}

	return 0;
}