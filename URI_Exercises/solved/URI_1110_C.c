// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI/resolvidos && gcc z1267.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1110

//solucao: https://github.com/ferreiraapfernanda/fatec-uri-online-judge/blob/master/1110.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*
É aqui é uma lista ligada que vai jogando o topo num vetor de int e o proximo no inicio.
Eu tinah pensado em fazer dois vetores mas uma fila ao invéz de uma pilha (Na verdade o comportamento dessa "pilha" aqui é de fila)
pois apesar do nome não ta empilhando, ta saindo de uma ponta e entrando coisas em outra.

ai poderia fazer dois vetores e uma função de sair e entrar dai

-popula
while cartas >2
	{
	-sai(n)
		-joga n no vetor d eint
	-sai(n+1) (a proxima carta)
	-entra(n+1) (la atras)
	}

ai printa

mas como não sabia se por vetor o URI aceitaria vi uma solução pronta, que deve alias ser bem mais lenta por que
se fosse um baralho de 10000000000000 cartas por lista ia ser uma eternidade p ficar movendo tudo

mas como sao 55... bom enfim.

*/


struct Cartas{
char carta;
struct Cartas *prox;
}; typedef struct Cartas TCartas;

struct descrPilha{
TCartas *topo, *final;
int qtd;
}; typedef struct descrPilha DPilha;

int main()
{
	int vDescart[55], Cqtd, c=0, k=0;
	DPilha	descritor;
	TCartas *aux;

	while (scanf("%d", &Cqtd) && Cqtd != 0)
	{
		for(c=0; c < 55; c++)
			vDescart[c] = 0;

		k = 0;

		descritor.topo = NULL;
		descritor.qtd = 0;

		for(c=Cqtd; c > 0; c--)
		{
			aux = (TCartas *) malloc(sizeof(TCartas));

			if(aux == NULL)
				break;

			aux->carta = c;
			aux->prox = descritor.topo;

			descritor.topo = aux;
			descritor.qtd++;

			if(c == Cqtd)
				descritor.final = aux;
		}

		while (descritor.qtd >= 2)
		{
			aux = descritor.topo;
			descritor.topo = aux->prox;
			vDescart[k] = aux->carta;
			free(aux);
			descritor.qtd--;
			k++;
			
			aux = descritor.topo->prox;
			descritor.final->prox = descritor.topo;
			descritor.final = descritor.topo;
			descritor.topo = aux;
		}

		printf("Discarded cards:");
		for(c=0; c < k; c++)
		{
			printf(" %d", vDescart[c]);
			if(c != k-1)
				printf(",");
		}
		printf("\nRemaining card: %d\n", descritor.final->carta);
	}

	return 0;
}