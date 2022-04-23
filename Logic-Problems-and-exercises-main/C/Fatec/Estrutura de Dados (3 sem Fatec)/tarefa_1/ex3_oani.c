// ┌───┐
// │┌─┐│      /
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1 && gcc ex3_oani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//criara entradas encadeadas
struct entrada {
	double codigo; 
	struct entrada *prox;};

typedef struct entrada TNo;

typedef struct {
	TNo *inicio, *final; 
	int qtde;} TDescr;

void InicializaLista(TDescr *);
void ImprimeLista(TDescr, char *);

int main(void){
	
	double numero;
	
	TDescr lista;
	TDescr listaB;
	TDescr listaSoma;
	TNo *aux;

	/* ------------------------ lista ------------------------  */
	InicializaLista(&lista);
	
	while (1){	
		printf("----listaA----\n");
		printf("Informe o codigo do entrada a registrar (ou < 0 para encerrar(imprimir a lista)):\n");
		scanf("%lf", &numero);
		printf("\e[1;1H\e[2J"); //essa bizarrice é para limpar a tela... https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c

		if (numero < 0)
			break;
		
		/* criando uma variável struct entrada dinamicamente */
		aux = (struct entrada *) malloc(sizeof(struct entrada));

		/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo = numero;
		aux->prox = NULL;
		
		/* fazendo o encadeamento do novo nó na lista */
		if (lista.inicio == NULL) 
			lista.inicio = aux;
		else
			lista.final->prox = aux;

		lista.qtde = lista.qtde + 1;
		
		lista.final = aux;
		
	}
	
	/* ------------------------ listaB ------------------------  */
	InicializaLista(&listaB);
	
	while (1){	
		printf("----listaB----\n");
		printf("Informe o codigo do entrada a registrar (ou < 0 para encerrar(imprimir a lista)):\n");
		scanf("%lf", &numero);
		printf("\e[1;1H\e[2J");

		if (numero < 0)
			break;
		
		/* criando uma variável struct entrada dinamicamente */
		aux = (struct entrada *) malloc(sizeof(struct entrada));

		/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo = numero;
		aux->prox = NULL;
		
		// printf("Informe o nome do entrada a registrar (max 30 caracteres):\n");
		// scanf("%s", aux->nome);

		// printf("Informe o salario do entrada a registrar:\n");
		// scanf("%lf", &aux->salario);
	
		/* fazendo o encadeamento do novo nó na lista */
		if (listaB.inicio == NULL) 
			listaB.inicio = aux;
		else
			listaB.final->prox = aux; //substitui o ant por listaB->final

		listaB.qtde = listaB.qtde + 1;
		
		listaB.final = aux;
		
	}

	/* ------------------------ listaSoma ------------------------  */
	InicializaLista(&listaSoma);
	
	double valor1, valor2;	
	TNo *auxmaior, *auxmenor;
	if (lista.qtde >= listaB.qtde){auxmaior = lista.inicio; auxmenor = listaB.inicio;}else{auxmaior = listaB.inicio; auxmenor = lista.inicio;}

	while (auxmaior != NULL){	

		//puts("aaaaaaaaaaaa");
		valor1 = auxmaior->codigo;

		//printf("valor1: %lf\n", valor1);
		auxmaior = auxmaior->prox;
				
		if (auxmenor != NULL)
		{
			valor2 = auxmenor->codigo;
			auxmenor = auxmenor->prox;
		}else
			{valor2 = 0;}
		
		numero = valor1 + valor2;

		//printf("Codigo: %lf\n", aux->codigo);

		/*	+------------+-------------+------+
			| listamaior | listamenor  | SOMA |
			+------------+-------------+------+
			|          1 | 1           | 1+1  |
			|          2 | 2           | 2+2  |
			|          3 | NULL        | 3+0  |
			|          4 | NULL        | 4+0  |
			+------------+-------------+------+ */
		
		/* criando uma variável struct entrada dinamicamente */
		aux = (struct entrada *) malloc(sizeof(struct entrada));

		/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo = numero;
		aux->prox = NULL;
	
		/* fazendo o encadeamento do novo nó na lista */
		if (listaSoma.inicio == NULL) 
			listaSoma.inicio = aux;
		else
			listaSoma.final->prox = aux; 

		listaSoma.qtde = listaSoma.qtde + 1;
		
		listaSoma.final = aux;

	}
	
	
	/////////////////////Impressao////////////////////////

	if (lista.inicio == NULL)
		puts("Lista esta vazia");
	else
		ImprimeLista(lista, "Conteudo da listaA:");

	if (lista.inicio == NULL)
		puts("Lista esta vazia");
	else
		ImprimeLista(listaB, "Conteudo da listaB:");

	if (lista.inicio == NULL)
		puts("Lista esta vazia");
	else
		ImprimeLista(listaSoma, "Conteudo da listaSoma:");
		
	return 0;
}

void InicializaLista(TDescr *lista){ //a lista inicialmente é lista depois é listaB
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}

void ImprimeLista(TDescr lista, char *cabec){	
	
	TNo *aux;
	
	printf("\n\n\n%s\n", cabec);

	aux = lista.inicio;
	
	while (aux != NULL)	{	
		/*colocando para impirmir o codigo, nome*/
		printf("Codigo: %lf\n", aux->codigo);
					
		aux = aux->prox;
	}
	printf("A lista possui %d entradas\n", lista.qtde);
	
}
