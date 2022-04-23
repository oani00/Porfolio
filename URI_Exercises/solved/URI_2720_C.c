#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// ┌───┐
// │┌─┐│
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘


//https://www.urionlinejudge.com.br/judge/pt/problems/view/2720

//https://github.com/malbolgee/URI/blob/master/2720.c

//Ajuda de https://github.com/carloswagner1

#define TAM 100000

//também dá para fazer uma matriz ou duas tabelas, mas baseado em outros problemas é melhor struct mesmo.
typedef struct presente{unsigned _id; unsigned _volume;}presente;

int compara(presente *, presente *);
int compara2(unsigned *, unsigned *);

presente presentes[TAM] = { 0 };
unsigned ids[TAM];

int main ()
{
	unsigned i;
	unsigned short t;
	unsigned short x, y, z;
	unsigned noel, bruno;

	scanf("%hu", &t);

	while (t--)
	{
		scanf("%u %u", &noel, &bruno);

		for (i = 0; i < noel; ++i)
		{

			scanf("%u %hu %hu %hu", &presentes[i]._id, &x, &y, &z);
			presentes[i]._volume = x * y * z;

		}

		//inicialmente coloquei um bubble sort mas ja tem o qsort no C entao fica assim mesmo.
		qsort(presentes, noel, sizeof(presente), compara);

		for (i = 0; i < bruno; ++i)
			ids[i] = presentes[i]._id;

		
		qsort(ids, bruno, sizeof(unsigned), compara2);

		for (i = 0; i < bruno; ++i)
		{

			if (i != 0 && i != bruno)
				printf(" ");

			printf("%u", ids[i]);

		}
		printf("\n");
	}

	return 0;
}

int compara(presente *a, presente *b)
{

	if (a->_volume == b->_volume)
	{

		if (a->_id > b->_id)
			return 1;
		else
			return -1;

	}
	else if (a->_volume > b->_volume)
		return -1;
	else
		return 1;

}

int compara2(unsigned *a, unsigned *b)
{

	if (*a > *b)
		return 1;
	else
		return -1;

}