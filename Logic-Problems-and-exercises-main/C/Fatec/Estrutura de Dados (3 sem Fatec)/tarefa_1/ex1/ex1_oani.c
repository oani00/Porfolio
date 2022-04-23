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

/*
	Opera sobre lista linear de inteiros por encadeamento, 
	com exclusao de item informado pelo usuario, descritor 
	estruturado e subrotinas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1/ex1 && gcc ex1_oani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

/*
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1/ex2 && gcc ex2_oani_cli.c -c -Wall -lm && gcc ex2_oani_impl.c -c -Wall -lm && gcc ex2_oani_cli.o ex2_oani_impl.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//criara funcionarios encadeados
struct funcionario {int codigo; char nome[31]; double salario; struct funcionario *prox;};

typedef struct funcionario TNo;

typedef struct {TNo *inicio, *final; int qtde; float soma;} TDescr; //descritores de soma aqui

void InicializaLista(TDescr *);
void ImprimeLista(TDescr, char *);


int main(void)
{	int numero;
	
	TDescr lista;
	TNo *aux; 

	/* inicializando os descritores da lista */
	InicializaLista(&lista);
	
	while (1)
	{	printf("Informe o codigo do funcionario a registrar (ou < 0 para encerrar(imprimir a lista)):\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		/* criando uma variável struct funcionario dinamicamente */
		aux = (struct funcionario *) malloc(sizeof(struct funcionario));

		/* preenchendo os campos da variável criada dinamicamente */
		aux->codigo = numero;
		aux->prox = NULL;
		
		printf("Informe o nome do funcionario a registrar (max 30 caracteres):\n");
		scanf("%s", aux->nome);

		printf("Informe o salario do funcionario a registrar:\n");
		scanf("%lf", &aux->salario);
	
		/* fazendo o encadeamento do novo nó na lista */
		if (lista.inicio == NULL) 
			lista.inicio = aux;
		else
			lista.final->prox = aux; //substitui o ant por lista->final

		lista.qtde = lista.qtde + 1;
		lista.soma = lista.soma + aux->salario;
		lista.final = aux;
		
	}
	
	/////////////////////Impressao////////////////////////
	/* imprimindo os codigos da lista */

	if (lista.inicio == NULL)
		puts("Lista esta vazia");
	else
		ImprimeLista(lista, "Conteudo da lista:");

	/////////////////////exclusao////////////////////////

	while (1)
	{	printf("\nInforme o codigo a excluir:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		
		/* Procurando o codigo informado na lista */
		aux = lista.inicio;
		lista.final = NULL;
		while (aux != NULL)
		{	if (aux->codigo == numero)
				break;
		
			lista.final = aux;
			aux = aux->prox;
		}
	
		if (aux == NULL)
			puts("codigo nao existe na lista");
		else
		{	if (lista.final == NULL)
				lista.inicio = aux->prox;
			else
				lista.final->prox = aux->prox;
		
			if (aux == lista.final)
				lista.final = lista.final;
		
			free(aux);
		
			lista.qtde = lista.qtde - 1;
			lista.soma = lista.soma - aux->salario;

			/* imprimindo os codigoes da lista */
			if (lista.inicio == NULL)
				puts("Lista esta vazia");
			else
				ImprimeLista(lista, "Novo conteudo da lista:");
		}
	}
	
	return 0;
}

void InicializaLista(TDescr *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}

void ImprimeLista(TDescr lista, char *cabec)
{	TNo *aux;
	int soma;
	
	printf("\n\n\n%s\n", cabec);

	aux = lista.inicio;
	/*menor = aux->salario;
	maior = aux->salario;*/ //vc não precisa destes dados
	soma = 0;

	while (aux != NULL)
		/*colocando para impirmir o codigo, nome*/
	{	printf("Codigo: %d\n", aux->codigo);
		printf("Nome: %s\n", aux->nome);
		printf("Salário %.2f\n", aux->salario);
		
		soma = soma + aux->salario;
			
		aux = aux->prox;
	}
	printf("A lista possui %d funcionarios\n", lista.qtde);
	printf("E o somatorio dos salario e eh %d e a Media: %.2f\n", 
			soma, soma / (float) lista.qtde);

}
