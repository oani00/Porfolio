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

/* 1) Adapte o programa que implementa a árvore binária ordenada de inteiros apresentada na
apostila, para que ele imprima na tela o conteúdo de cada nó e, após isso, também exiba:

• Maior valor contido na árvore.
• Menor valor contido na árvore.
• Quantidade de folhas da árvore.
• A altura da árvore.
• Pesquisa na árvore de um valor informado pelo usuário.

Obs: Criar uma função para realizar cada um dos processamentos solicitados acima.*/

/////////////////////
//arquivo pArvore.c//
/////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regNo{
struct regNo *esq;
int valor;
struct regNo *dir;};
typedef struct regNo TNo;

int quantidadeFolhas = 0;
int *PquantidadeFolhas;

TNo *AchaPai(TNo *r, int n){	
	if (r == NULL)
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
	
	if (r != NULL)
	{	for (c = 0; c < n; c++) 
			// printf("    ");
			printf("───"); //https://theasciicode.com.ar/extended-ascii-code/box-drawings-single-horizontal-line-character-ascii-code-196.html
			
		
		printf("%d\n", r->valor);

		ImprimeArvore(r->esq, n + 1);
		ImprimeArvore(r->dir, n + 1);
	}
}

// • Quantidade de folhas da árvore.
//para variar, desisti https://stackoverflow.com/questions/41132740/number-of-leaves-in-binary-search-tree-in-c

int qtdfolhas(TNo *r)
{
	int nb=0;
	if(r->dir==NULL && r->esq ==NULL){
		nb=nb+1;
	}else {
		if(r->esq!=NULL)
			nb += qtdfolhas(r->esq);
		if(r->dir!=NULL)
			nb += qtdfolhas(r->dir);
	}
	return nb;
}


// • A altura da árvore.
//Desisti. https://www.journaldev.com/34979/height-of-a-binary-tree-in-c-plus-plus
//Sou pessimo de recursao... Enfim sou muito burro.

int altura(TNo *r) {
    // Get the height of the tree
    if (!r)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = altura(r->esq);
        int right_height = altura(r->dir);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

// • Pesquisa na árvore de um valor informado pelo usuário.
void pesquisa(TNo *r, int n){
		
	if (r != NULL){
		if (r->valor == n)
		{
			printf("%d\n", r->valor);
			
		}else
		{
			printf("Nao achei seu numero..."); //sou burro eu sei (fica repetindo)
		}
				
		pesquisa(r->esq, n);
		pesquisa(r->dir, n);
	}
}

// • Menor valor contido na árvore.
void MostraMenor(TNo *r){

	if (r != NULL)
	{	
		if (r->esq == NULL)
		{
			printf("%d\n", r->valor);	
		}

		MostraMenor(r->esq);
	}
}

// • Maior valor contido na árvore.
void MostraMaior(TNo *r){

	if (r != NULL)
	{	
		if (r->dir == NULL)
		{
			printf("%d\n", r->valor);	
		}

		MostraMaior(r->dir);
	}
}



int main(void){	
	
	PquantidadeFolhas = &quantidadeFolhas;
	
	TNo *raiz = NULL, *aux, *pai;
	int numero;
		
	while (1)
	{	printf("\nInforme o valor (ou um numero negativo para terminar):\n"); 
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

// • Maior valor contido na árvore.
	printf("\n\nO maior valor da arvore é \n"); MostraMaior(raiz); printf("\n");
// • Menor valor contido na árvore.
	printf("\n\nO menor valor da arvore é \n"); MostraMenor(raiz); printf("\n");
// • Quantidade de folhas da árvore.
	printf("\n\nA arvore possui %d folhas:\n", qtdfolhas(raiz));
// • A altura da árvore.
	printf("\n\nA altura da arvore é %d\n", altura(raiz));
// • Pesquisa na árvore de um valor informado pelo usuário./////////

	printf("\n\nSe quiser pesquisar um valor, digite <s> \n");
	char escolha;
	scanf("%c", &escolha);
	scanf("%c", &escolha);
	
	if (escolha == 's')
	{
		int numero;
		puts("Digite um numero a pesquisar");
		scanf("%i", &numero);
		pesquisa(raiz, numero);
		
	}else
	{
		puts("Ok nao procurarei nada.");
	}
	
////////////////////////////////////////////////////////////////////
	
	puts("Eis a arvore:");
	ImprimeArvore(raiz, 0);

	return 0;
}