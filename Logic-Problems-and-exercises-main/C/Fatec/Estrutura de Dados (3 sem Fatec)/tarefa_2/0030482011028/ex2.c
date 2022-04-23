// ┌───┐
// │┌─┐│
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

//███████╗ █████╗ ████████╗███████╗ ██████╗ 
//██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔════╝ 
//█████╗  ███████║   ██║   █████╗  ██║      
//██╔══╝  ██╔══██║   ██║   ██╔══╝  ██║      
//██║     ██║  ██║   ██║   ███████╗╚██████╗ Sorocaba
//╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚══════╝ ╚═════╝ José Crespo Gonzales

// cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1 &&  gcc ex1_oani.c -o ex1.exe -lm -Wall && ./ex1.exe

/*
Segundo as páginas 187 e 188 da Introdução a Estruturas de Dados, de Waldemar Celes e outros, 
“Para descrever árvores binárias, podemos usar a seguinte notação textual: a árvore vazia é 
representada por < >, e árvores não-vazias, por <raiz sae sad>. Com essa notação, a árvore da 
Figura 13.4 é representada por:

<a<b< ><d< >< >>><c<e< >< >><f< >< >>>>

Pela definição, uma subárvore de uma árvore binária é sempre especificada como sendo a sae ou 
a sad de uma árvore maior, e qualquer das duas subárvores pode ser vazia. Assim, as duas 
subárvores da Figura 13.5 são distintas.
Isso também pode ser visto pelas representações textuais das duas árvores que, em pre-order, 
são, respectivamente: <a<b< >< >>< >> e <a< ><b< >< >>>.”

Faça um programa que recebe uma sequência de inteiros e monta a árvore binária ordenada 
correspondente. Em seguida exibir a descrição da árvore na notação textual indicada 
anteriormente, porém em sentido infixo
<sae raiz sad>

*/

/////////////////////
//arquivo pArvore.c//
/////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct regNo{	struct regNo *esq;
				int valor;
				struct regNo *dir;
			};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void ImprimeArvore(TNo *, int);
int ContaNos(TNo *);
int SomaNos(TNo *);
int ContaPares(TNo *);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
	int numero;
	
	while (1)
	{	printf("\nInforme o valor (ou um numero neg. para sair):\n"); 
		scanf("%d", &numero);
		
		if (numero < 0) break;
		
		aux = (TNo *) malloc(sizeof(TNo));
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;
		
		/* Fazendo o encadeamento do novo noh */
		pai = AchaPai(raiz, numero);
		if (pai == NULL)
			raiz = aux;
		else
			if (numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
	}
	
	printf("\n\nA arvore possui %d elementos:\n", ContaNos(raiz));
	ImprimeArvore(raiz, 0);
	
	return 0;
}

TNo *AchaPai(TNo *r, int n)
{	if (r == NULL)
		return NULL;
	else
		if (n <= r->valor)
		/* n é descendente do lado esquerdo de r */
			if (r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
		/* n é descendente do lado direito de r */
			if (r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}

int ContaNos(TNo *r)
{	if (r == NULL)
		return 0;
	else
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

void ImprimeArvore(TNo *r, int n)
{	int c;
	
	if (r != NULL){
		
		printf("<");
		ImprimeArvore(r->esq, n + 1);
		printf("%d", r->valor);
		ImprimeArvore(r->dir, n + 1);
		printf(">");
	}else{
		printf("<");
		printf(" ");
		printf(">");
	}


}
