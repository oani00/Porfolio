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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1 && gcc ex4_ooani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe

cd C:/backupsON/Dropbox/#BOITUVA/ADS/5ED/tarefa_1
	gcc ex4_ooani.c -o ./testeC.exe -lm -Wall && ./testeC.exe
*/

// O programa apresentado a seguir implementa uma pilha básica de números inteiros em linguagem C. 
//Para testá-lo, adapte-o para imprimir o conteúdo da pilha antes e após a exclusão. 

struct regLista{ 
	char simbolo;
	struct regLista *prox;};

typedef struct regLista TLista;

struct descrPilha{ 
	TLista *topo;
	int qtde;};

typedef struct descrPilha DPilha;

int main(){

	int contador = 0; //contador de ocorrencias para desempilhar um simbolo especifico (o certo era fazer uma funcao)
	int NaPilha = 0;
	char entrada[21];
	
	DPilha descritor;
	TLista *aux;
	descritor.topo = NULL;
	descritor.qtde = 0;

	puts("Me de uma formula de ateh 20 caracteres");
	scanf("%s", entrada);
	
	int i = 0;

	while(entrada[i] != '\0'){ //e tem que ser com essas aspinhas, nao as duplas........ se nao testa para ver
				
		printf("char %d = %c\n", i, entrada[i]);
		
		
		/////////////////////////////////// push ///////////////////////////////////
		
		if (entrada[i] == '(' || entrada[i] == '[' || entrada[i] == '{')
		{
			aux = (TLista *) malloc(sizeof( TLista ));
			aux->simbolo = entrada[i];
			aux->prox = descritor.topo;
			descritor.topo = aux;
			NaPilha++;
			printf("na pilha tem %d para fechar\n", NaPilha);
						
		}
		
		/////////////////////////////////// pop ///////////////////////////////////
		//Esse tem que ser "personalizado"
		if(entrada[i] == ')'){
			
			aux = descritor.topo;
			
			while (aux != NULL)	{			
				if (aux->simbolo == '(')
				{
					contador++;
					break;
				}
				
				aux = aux->prox;
			}
			
			if (contador > 0)
			{
				if(descritor.topo != NULL)	{
				aux = descritor.topo;
				descritor.topo = descritor.topo->prox;
				NaPilha--; printf("Fechei um! na pilha agora tem %d para fechar\n", NaPilha);
				free(aux);
				}
			}
			else{
				printf("\n\nExpressao invalida\n");	
				exit(0);}
		}
		
		if(entrada[i] == ']'){
			
			aux = descritor.topo;
			
			while (aux != NULL)	{			
				if (aux->simbolo == '[')
				{
					contador++;
					break;
				}
				
				aux = aux->prox;
			}
			
			if (contador > 0)
			{
				if(descritor.topo != NULL)	{
				aux = descritor.topo;
				descritor.topo = descritor.topo->prox;
				NaPilha--; printf("Fechei um! na pilha agora tem %d para fechar\n", NaPilha);
				free(aux);
				}
			}
			else{
				printf("\n\nExpressao invalida\n");	
				exit(0);}
		}

		if(entrada[i] == '}'){
			
			aux = descritor.topo;
			
			while (aux != NULL)	{			
				if (aux->simbolo == '{')
				{
					contador++;
					break;
				}
				
				aux = aux->prox;
			}
			
			if (contador > 0)
			{
				if(descritor.topo != NULL)	{
				aux = descritor.topo;
				descritor.topo = descritor.topo->prox;
				NaPilha--; printf("Fechei um! na pilha agora tem %d para fechar\n", NaPilha);
				free(aux);
				}
			}
			else{
				printf("\n\nExpressao invalida\n");	
				exit(0);}
		}

		i++;
	}

	if (NaPilha != 0)
	{
		printf("\n\nExpressao invalida\n");
	}else	
		printf("\n\nExpressao valida\n");
	
	return 0;
}
			