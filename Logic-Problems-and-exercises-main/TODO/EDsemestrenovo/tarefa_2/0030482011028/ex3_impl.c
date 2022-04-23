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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE	1
#define FALSE	0
#define TAMCIDADE 31

//==================================FUNCOES==================================
	
	void InicializaLista(TDescr *lista)
	{	lista->inicio = NULL;
		lista->final = NULL;
		
	}

//===========================================================================

	int IncluiItem(TDescr *lista, char c[], float po, float a, float pi, float i)
	{	TNo *aux; //cria um ponteiro de nome aux

		/* criando uma variável struct regLista dinamicamente */
		aux = (struct regLista *) malloc(sizeof(struct regLista)); //aloca o aux

		if (aux == NULL)
			return FALSE;
		
		/* preenchendo os campos da variável criada dinamicamente */
		//aux->cidade = c;
		strcpy(aux->cidade, c);
		aux->populacao = po;
		aux->area = a;
		aux->pib = pi;
		aux->idh = i;
		aux->prox = NULL;
		
		/* fazendo o encadeamento do novo nó na lista */
		if (lista->inicio == NULL){
			aux->ante = NULL;
			lista->inicio = aux;}
		else{     
			lista->final->prox = aux; 
			aux->ante = lista->final;  
		}

		lista->final = aux; 

		return TRUE;
	}

//===========================================================================

	void ImprimeLista(TDescr *lista){ 
	TNo *aux;

		if (lista->inicio == NULL) 
			puts("Lista esta vazia");     
		else{ 
			printf("\nCidades cadastradas em ordem\n");

			aux = lista->inicio;

			while (aux != NULL){
				printf("Cidade: %s Populacao: %f Area %f PIB: %f IDH: %f\n",
					aux->cidade, aux->populacao, aux->area, aux->pib, aux->idh); //sim essa função peguei do Carlos mesmo. Eu ia fazer duas, uma em cada ordem. Mas, para variar, ele foi mais elegante.
				aux = aux->prox;
				
			}
	
			printf("\nCidades cadastradas em ordem contrária\n"); 

			aux = lista->final;

			while (aux != NULL){
				printf("Cidade: %s Populacao: %f Area %f PIB: %f IDH: %f\n",
					aux->cidade, aux->populacao, aux->area, aux->pib, aux->idh);
				aux = aux->ante; 
			}    
		}     
	}

//===========================================================================

	int ExcluiItem(TDescr *lista, float v){	
		
		TNo *aux, *ant;

		/* Procurando na lista o valor de IDH informado*/
		aux = lista->inicio;
		ant = NULL;
		while (aux != NULL)
		{	
			if (aux->idh >= v){break;} 	//Vai atualizando até para nessa checagem
										//Aqui que esta o exercicio, mudar == para >=
			ant = aux;
			aux = aux->prox;
		}

		if (aux == NULL) //Se nao achar para aqui e retorna FALSE (mensagem de valor nao encontrado)
			return FALSE;
		else
		{	if (ant == NULL)
				lista->inicio = aux->prox;
			else
				ant->prox = aux->prox;

			if (aux == lista->final)
				lista->final = ant;

			
			
			
			free(aux);


						
		}

		printf("Tirou o idh: %f \n", aux->idh);
		//ExcluiItem(&lista, v);
		return TRUE;
	}

//==================================FUNCOES==================================