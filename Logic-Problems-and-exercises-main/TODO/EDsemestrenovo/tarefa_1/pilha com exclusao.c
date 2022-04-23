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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1 && gcc ex4_oani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

// O programa apresentado a seguir implementa uma pilha básica de números inteiros em linguagem C. 
//Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão. 

struct regLista{ 
	int valor;
	struct regLista *prox;};

typedef struct regLista TLista;

struct descrPilha{ 
	TLista *topo;
	int qtde;};

typedef struct descrPilha DPilha;

int main(){

	int numero;
	DPilha descritor;
	TLista *aux;
	
	descritor.topo = NULL;
	descritor.qtde = 0;
		
	while(1){
		printf("Informe o numero (ou um valor neg para continuar):\n");
		scanf("%d", &numero);

		if( numero < 0 ) break;

		aux = (TLista *) malloc(sizeof( TLista ));
		aux->valor = numero;
		aux->prox = descritor.topo;

		descritor.topo = aux;
		descritor.qtde++;
	}
	
	printf("\n\nDigite 1 para excluir (pop) ou outra coisa para encerrar:\n");
	scanf("%d", &numero);
	
	if(numero == 1)	{
		 if(descritor.topo != NULL)	{
			aux = descritor.topo;
			descritor.topo = descritor.topo->prox;
			descritor.qtde--;

			printf("\n\nExcluindo o valor %d da pilha\n", aux->valor);
			free(aux);
		}
		else
		printf("\n\nA lista estah vazia\n");
	}
	
	return 0;
}

