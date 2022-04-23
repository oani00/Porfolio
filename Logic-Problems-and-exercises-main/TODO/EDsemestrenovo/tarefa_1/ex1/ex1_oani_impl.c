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
	Implementação
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ex1_oani.h"

void InicializaLista(TDescr *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}

void ImprimeLista(TDescr lista, char *cabec)
{	TNo *aux;
	int soma, maior, menor;
	
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
