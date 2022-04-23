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

/* 
cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_2 && gcc ex3.c -o ex3.exe -lm -Wall && ./ex3.exe < cidades.txt


Faça um programa que implementa uma lista linear duplamente encadeada contendo os dados de cidades informadas pelo usuário. 

* Deverão ser armazenados 
	- o nome da cidade (uma palavra de até 30 caracteres úteis), 
	- sua população (um inteiro), 
	- sua área territorial, 
	- PIB 
	- IDH 
(todos do tipo float). 

* Encerrar a entrada de dados quando o usuário informar “FIM” para o nome do município 

* e imprimir a lista 
	tanto a partir do início 
	como a partir do final. 

* Após a impressão do conteúdo original da lista, 
	o programa deverá executar um looping onde, a cada ciclo, 
		-um valor de IDH é informado 
			e todas as ocorrências de cidades na lista que possuem IDH igual ou superior a esse valor devem ser excluídas.
		-Se não for encontrado nenhum nó com valor de IDH igual ou superior ao informado, 
			emitir mensagem apropriada e não imprimir a lista. 
		Após a exclusão, 
			imprimir a lista novamente, 
				tanto a partir do início 
				como a partir do final. 
				Encerrar o programa quando o usuário informar um IDH negativo. 

* Organize o programa em arquivo cliente, de interface e de implementação

+-------------+----------+
|        Descritor       |
+-------------+----------+
| pont INICIO | pont FIM |
+-------------+----------+

| 						Estrutura:
+------+--------------+------------+-----------------+------+
| NULL | <-anterior-> | <- item -> | <- posterior -> | NULL |
+------+--------------+------------+-----------------+------+ */
/*
	Baseado no pListaNum_Enc4
		Opera sobre lista linear de inteiros por ENCADEAMENTO, 
		com exclusao de item informado pelo usuario, descritor 
		estruturado e subrotinas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE	1
#define FALSE	0
#define TAMCIDADE 31

struct regLista {
	char 	cidade[TAMCIDADE];
	float 	populacao;
	float 	area;
	float 	pib;
	float 	idh;
	struct 	regLista *prox;
	struct 	regLista *ante;
}; typedef struct regLista TNo;

typedef struct {TNo *inicio, *final;} TDescr;

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

int main(void)
{	
	char cidade[TAMCIDADE];
	float populacao;
	float area;
	float pib;
	float idh;
	TDescr lista;

	/* inicializando os descritores da lista */
	InicializaLista(&lista);
	
	puts("-----------------------------------------");
	puts("|       ---      CIDADES       ---      |");
	puts("-----------------------------------------");
	
	while (1)
	{	
		
		puts("Insira o nome da cidade (uma palavra de até 30 caracteres úteis), ");
		puts("ou digite FIM no nome do municipio para terminar");
		scanf("%s", cidade);   
		if (strcmp(cidade, "FIM") == 0){break;}
				
		puts ("População?");
		scanf("%f", &populacao);
		puts ("Área?");
		scanf("%f", &area);     
		puts ("PIB?");
		scanf("%f", &pib);      
		puts ("IDH?");
		scanf("%f", &idh);      

		if (IncluiItem(&lista, cidade, populacao, area, pib, idh) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao");
			return 3;
		}
	}
	puts("Lista atualizada do inicio e fim:");
	ImprimeLista(&lista);

	float numero;
	while (1)
	{	
		printf("\nInforme um IDH que eu excluirei tudo igual o superior a ele, ou insira um numero <0 para sair:\n");
		scanf("%f", &numero);
		if (numero < 0){break;}

		printf("\nIDH informado: %f \n", numero);
		puts("================================================================================================");

		
		while (1){
			if (ExcluiItem(&lista, numero) == FALSE)
			{
				puts("Não encontrei nenhum avalor acima desse na lista");
				puts("Lista atualizada do inicio e fim:");
				ImprimeLista(&lista);
				break;
			}
		}
		

		// if (ExcluiItem(&lista, numero) == FALSE)
		// 	puts("Não encontrei nenhum avalor acima desse na lista");
		// else{
		// 	puts("Lista atualizada do inicio e fim:");
		// 	ImprimeLista(&lista);
		// }
	}
	
	return 0;
}