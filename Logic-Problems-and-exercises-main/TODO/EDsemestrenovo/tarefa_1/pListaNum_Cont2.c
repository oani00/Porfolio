/* 
	Programa carrega uma lista linear de inteiros por CONTIGUIDADE,
	a imprime e depois pesquisa um valor e o exclui, caso ele exista na lista
	*** Eh a versao equivalente a do programa pLista_Enc2.c ***
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE	1
#define FALSE	0

#define QTDE_ITENS	100

void ImprimeLista(int, char *);

int lista[QTDE_ITENS];

int main(void)
{	int final, numero, p;

	/* inicializando a variável de controle do fim da lista */
	final = -1;
	
	while (TRUE)
	{	printf("Informe o numero (ou -999 para encerrar):\n");
		scanf("%d", &numero);
		
		if (numero == -999)
			break;
		
		if (final == QTDE_ITENS)
			puts("Lista jah estah cheia");
		else
			lista[++final] = numero;
	}
	
	/* imprimindo os valores da lista */
	ImprimeLista(final, "Conteudo da lista:");
	
	printf("Informe o numero a pesquisar:\n");
	scanf("%d", &numero);

	p = 0;
	while (p <= final)
	{	if (lista[p] == numero)
			break;

		p = p + 1;
	}

	/* O looping anterior poderia ser escrito como
		p = 0;
		while (p <= final && lista[p] != numero)
		{	p = p + 1;
		}
	*/

	if (p > final)
		puts("Valor nao existe na lista");
	else
	{	while (p < final)
		{	lista[p] = lista[p + 1];
			p = p + 1;
		}
		
		final = final - 1;
	}

	/* imprimindo os valores da lista */
	ImprimeLista(final, "Novo conteudo da lista:");

	return 0;
}

void ImprimeLista(int final, char *cabec){	
	int p;

	printf("\n\n\n%s\n", cabec);
	p = 0;
	while (p <= final)
	{	printf("%5d\n", lista[p]);
		p = p + 1;
	}
}
