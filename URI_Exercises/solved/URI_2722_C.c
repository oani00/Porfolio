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

//https://www.urionlinejudge.com.br/judge/pt/problems/view/2722

/*
Pseudo

-while(scanf("N") != EOF)
   
   for i até 3
      -popular v1[105]
         -fazer alguma czisse de colocar '\0' no final da entrada
      -popular v2[105]
         -fazer alguma czisse de colocar '\0' no final da entrada

      i = 0;
      while(v1[i] == '\0) (aqui tem que fazer o maldito stringcpr)
         printf("v1[i]v1[i+1]");
         printf("v2[i]v2[i+1]");
         i = i + 2

         //Apenas um fato curioso: a primeira linha do nome misturado sempre terá um número par de caracteres
            //sendo assim essa logica sempre deveria chegar em um '\0'

      -printf("\n")




*/

//solução: https://github.com/malbolgee/URI/blob/master/2722.c

#include <stdio.h>
#include <string.h>

void main ()
{

	char nome[100], sobrenome[100], nomecmpl[300];
	unsigned short casos, i, j, k;
	unsigned contador, aux;

	scanf("%hu", &casos); //nao tinha percebido que era um lote de casos só por execucao do programa...

	while (casos--)
	{

		scanf(" %[^\n] %[^\n]", nome, sobrenome); //descobri que isso é "leia até \n"... czisses.

		contador = 0;
		i = 0;
		k = 0;
		j = 0;

		aux = strlen(sobrenome); //bem melhor que os negocios com /0 que fiz... descobri esse strlen hoje...

		// Um laço que continua até que o tamanho da (talvez) menor string acabe; //nota original 
		// Uma vez que a string do 'nome' sempre é iterada primeiro que a 'sobrenome'; //nota original 
		// A string 'sobrenome' vai acabar antes que a 'nome'; //nota original 
		while (aux--)
		{

			while (nome[i])
			{	
				// A string 'nomecmpl' recebe as letras em 'nome' até que 'contador' seja 2 //nota original 
				// 'contador' sendo == 2 significa que passei duas letras da string fonte para a string destino; //nota original 
				// O laço para e o laço da string 'sobrenome' itera da mesma forma; //nota original 
				nomecmpl[k++] = nome[i++];
				contador++;

				if (contador == 2)
					break;
			}

			contador = 0;
			while (sobrenome[j])
			{

				nomecmpl[k++] = sobrenome[j++];
				contador++;

				if (contador == 2)
					break;


			}

			contador = 0;
		}

      //interessante essa solução é o que tinha pensado mas de um jeito bem diferente. Jamais na vida iria pensar nesses contadores
      //e todos esses whiles. Não sei por que o pessoal não gosta muito de for nas soluções... 

      //outra coisa foi ter primeiro jogado em um terceiro vetor para depois escrever... Talvez tenha Czisses que não entendo ai.

		nomecmpl[k] = '\0';
		printf("%s\n", nomecmpl);
	}
}

