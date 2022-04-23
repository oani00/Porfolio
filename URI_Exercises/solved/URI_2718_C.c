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

//https://www.urionlinejudge.com.br/judge/pt/problems/view/2718

//solucao https://github.com/malbolgee/URI/blob/master/2718.c

/* 
Pseudo:

-while(1)
   -cond parada
   -converter decimal p binario
      -vai dividindo por 2 e pgando o resto.
      -Junto ir populando o vetor

      -declarar maiorgrupo = 0
      -declarar grupoatual = 0
      -para i=1 ate final
         grupoatual ++
         -se v[i] != 1
            se grupoatual >= maiorgrupo
               maiorgrupo = grupoatual
            senao
               grupoatual = 0
    
   printa maiorgrupo
*/


#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef long long unsigned llu; //tem que comportar os 50 bits

char valueToChar(llu a);
llu decimalToBase(llu x, llu base);

int main(int argc, char **argv)
{

	llu light, n;
	scanf("%llu", &n);

	while (n--)
	{

		scanf("%llu", &light);
		printf("%llu\n", decimalToBase(light, 2LLU)); //alem de fazer foi organizado.

	}

	return 0;

}

llu decimalToBase(llu x, llu base) 
{

	llu count, ans = 0;

	count = 0;
	while (x > 0)
	{

		if (valueToChar(x % base) == '1') //é a logica que pensei mesmo, so que o cara foi tao vicio que nem populou nada ja 
			count++;                       //foi convertendo e checando.
		else                             //
			count = 0;                    //
                                       // nesse bloco todo do while
		if (count > ans)                 //
			ans = count;                  //
                                       //
		x /= base;                       //

	}

	return ans;

}

char valueToChar(llu a) //pelo que entendi ele converteu o numero em char para na comparação comparar com 1 com ochar e nao 1
{                       //como numero? Agora o porque nao faço ideia...

	if (a >= 0 && a <= 9)
		return (char)(a + '0');
	else
		return (char)(a - 10 + 'a');

}