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

//https://github.com/thiagohprestes/codigosUri/blob/master/Ad-Hoc/uri_1267-Biblioteca%20Pascal.c

int main(){
  int alunos, jantares, matriz, i, j, participou;

	while(scanf("%d %d", &alunos, &jantares) && alunos+jantares){
		int evento[jantares][alunos];

		for(i= 0; i < jantares; i++)
			for(j = 0; j < alunos; j++)
				scanf("%d", &evento[i][j]);

		for(i = participou = 0; i < alunos; i++){
			for(j = 0; j < jantares; j++)
				participou += evento[j][i];
			
			if(participou == jantares)
				break;

			participou = 0;
		}

		participou ? puts("yes") : puts("no");
	}

  return 0; 
}