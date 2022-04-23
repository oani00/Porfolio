// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘


/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1861

Do que to vendo tem varios jeitos.
	
Todas as respostas vao precisar contar quantas vezes um nome aparece 
	-Da pra ordenar
	-Fazer algum for dentro de for e ficar escaneando
	-Talvez até uma arvore =P (se bem que para montar essa arvore teria que ficar escaneando e ligando os ponteiros... o que seria ficar escaneando tudo como no caso do for)
		-Sei la Arya matou 3, no node aria em os 3 em baixo vai saber.

e depois escrever
	-O asassino pode ser um
		-vetor
		-matriz
		-struct

A ordem pode vir de uma ordenacao ja que o codigo ascii é sequencial tambem.

https://github.com/malbolgee/URI/blob/master/1861.c

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Vou confessar meio que desisti de entender essa resposta. Estou com uma preguiça infinita mas não consigo ver po porque
//de usar 2 arvores, nem po que usar uma arvore sequer (sou burro mesmo.)

//Eu faria uma matriz mesmo, ordenaria e se um nome apareceu no mortos ou apaga ele ou no printf pula ele.
//Ai conta quantas vezes um nome que nao ta nos mortos apareceu e mostra asassino e numero em ordem alfabetica.

//O cara aqui eh mto genio, usou função recursiva varias vezes... Meu QI nao é tao grande p entender o porque de tudo isso.
//Enfim quando nao usar o maldito C eu tento uma resposta.(ou quando for menos folgado)

typedef struct tipoDado{ 

	char nome[20];
	unsigned qtsMortes;

} Assassinos;

struct ArvHall{

	Assassinos dado;
	struct ArvHall *esquerdo;
	struct ArvHall *direito;

};

struct ArvMortos{

	char morto[20];
	struct ArvMortos *esquerdo;
	struct ArvMortos *direito;

};

typedef struct ArvHall Hall;
typedef struct ArvMortos Mortos;

Hall* insereAssassinos(Hall *, Assassinos);
Mortos* insereMortos(Mortos *, char *);
bool busca(Mortos *mortos, char *chave);
void show(Hall *, Mortos *);

void main ()
{

	char matou[20], morreu[20];
	Hall *hall = NULL;
	Mortos *mortos = NULL;

	while (scanf(" %s %s", matou, morreu) != EOF)
	{

		Assassinos assassino = { 0 };
		strcpy(assassino.nome, matou);
		hall = insereAssassinos(hall, assassino);
		mortos = insereMortos(mortos, morreu);

	}

	printf("HALL OF MURDERERS\n");
	show(hall, mortos);

}

Hall* insereAssassinos(Hall *hall, Assassinos assassino)
{

	if (!hall)
	{

		hall = (Hall *) malloc(sizeof(Hall));
		hall->dado = assassino;
		hall->dado.qtsMortes++;
		hall->esquerdo = hall->direito = NULL;

	}
	else if (strcmp(hall->dado.nome, assassino.nome) > 0)
		hall->esquerdo = insereAssassinos(hall->esquerdo, assassino);
	else if (strcmp(hall->dado.nome, assassino.nome) < 0)
		hall->direito = insereAssassinos(hall->direito, assassino);
	else
		hall->dado.qtsMortes++;

	return hall;

}

Mortos* insereMortos(Mortos *mortos, char *morto)
{

	if (!mortos)
	{

		mortos = (Mortos *) malloc(sizeof(Mortos));
		strcpy(mortos->morto, morto);
		mortos->esquerdo = mortos->direito = NULL;

	}
	else if (strcmp(mortos->morto, morto) > 0)
		mortos->esquerdo = insereMortos(mortos->esquerdo, morto);
	else
		mortos->direito = insereMortos(mortos->direito, morto);

	return mortos;

}

void show(Hall *hall, Mortos *mortos)
{

	if (hall != NULL)
	{

		show(hall->esquerdo, mortos);
		if (!busca(mortos, hall->dado.nome))
			printf("%s %u\n", hall->dado.nome, hall->dado.qtsMortes);
		show(hall->direito, mortos);

	}

}

bool busca(Mortos *mortos, char *chave)
{

	bool direita, esquerda;

	if (!mortos)
		return false;

	if (strcmp(mortos->morto, chave) == 0)
		return true;

	if (strcmp(mortos->morto, chave) > 0)
		esquerda = busca(mortos->esquerdo, chave);
	else
		direita = busca(mortos->direito, chave);

}