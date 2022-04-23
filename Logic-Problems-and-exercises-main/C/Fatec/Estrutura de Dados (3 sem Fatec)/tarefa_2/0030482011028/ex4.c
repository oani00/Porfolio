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

cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_2 && gcc ex4.c -o ex4.exe -lm -Wall && ./ex4.exe < ex4cidades.txt

Baseado no pArv2c
e em https://www.techgeekbuzz.com/heap-sort-in-c/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ELEMS 5005
#define TAMCIDADE 31

struct regLista
{
	int pk; //"chave estrangeira", mas esta PK...
	char nome[TAMCIDADE];
	float populacao;
	float area;
	float pib;
};
typedef struct regLista cidade;

struct reg2
{
	int maxlista;
	int pk; //"chave primaria"
	float idh;
};
typedef struct reg2 indice;

/*

A ideia é:

+-----+-----------+		+-----+--------+--------------+
| pk  |    idh    |		| PK  |  nome  | atributos... |
+-----+-----------+		|-----+--------+--------------+
| 1   | 0.777     |		| 1   | seila  |          ... |
| 2   | 0.888     |		| 2   | seila2 |          ... |
| 3   | 0.444     |		| 3   | seila3 |          ... |
| ... | ...       |		| ... | ...    |          ... |
| n   | informado |		| n   | seilan |          ... |
+-----+-----------+		+-----+--------+--------------+

Reordenado

+-----+-----------+		+-----+--------+--------------+
| pk  |    idh    |		| PK  |  nome  | atributos... |
+-----+-----------+		|-----+--------+--------------+
| 3   | 0.444     |		| 1   | seila  |          ... |
| 1   | 0.777     |		| 2   | seila2 |          ... |
| 2   | 0.888     |		| 3   | seila3 |          ... |
| ... | ...       |		| ... | ...    |          ... |
| n   | informado |		| n   | seilan |          ... |
+-----+-----------+		+-----+--------+--------------+

Ai a leitura lê as cidades correspondentes ordenadas agora segundo o idh.
A PK existe para caso existam idhs repetidos

*/


void adjust(indice arr[], int i)
{
	//int j, tempIDH, tempPK, n, k = 1;
	
	int j, tempPK, n, k = 1;
	float tempIDH;
	n = arr[0].maxlista; //agora saquei o por que da posicao 0. É para passar entre os escopos.
	while (2 * i <= n && k == 1)
	{
		j = 2 * i;
		if (j + 1 <= n && arr[j + 1].idh > arr[j].idh)
			j = j + 1;

		if (arr[j].idh < arr[i].idh)
			k = 0;
		else
		{
			tempIDH = arr[i].idh;
			tempPK = arr[i].pk;
			arr[i].idh = arr[j].idh;
			arr[i].pk = arr[j].pk;
			arr[j].idh = tempIDH;
			arr[j].pk = tempPK;
			i = j;

		}
	}
}

void heapify_function(indice arr[]) //Parecida com a original fornecida
{
	int i, n;
	n = arr[0].maxlista;
	for (i = n / 2; i >= 1; i--)
		adjust(arr, i);
}

void ImprimeArvore(cidade arr[], indice ind[], int maxcidades)
{

	printf("\n\n");
	puts(" Lista: ");

	for (int j = 2; j < maxcidades; j++)
	{
		printf("%da contemplada: ", j-1);
		for (int k = 1; k < TAMCIDADE; k++)
		{
			if (ind[j].pk == arr[k].pk)
			{
				if (ind[j].idh == 0)
				{
					break; //gambiarra para nao mostrar.
				}
				
				//printf("PK %d - ", ind[j].pk);
				//printf("%d : PKcid |||", arr[k].pk);
				printf("cidade: %s - ", arr[k].nome);
				printf("idh: %f|", ind[j].idh);
				printf("area: %f| ",arr[k].area);
				printf("pib: %f| ",arr[k].pib);
				printf("populacao: %f \n",arr[k].populacao);
			}
		}
	}

	printf("\n\n");
}

int main()
{

	puts("------------------------------------------------");
	puts("|       ---      CIDADES HEAPies       ---      |");
	puts("------------------------------------------------");

	cidade arr[MAX_ELEMS];
	indice indice[MAX_ELEMS];
	int n = 1; //entendi o 1. O '0' é o n de elementos.

	char cidade[TAMCIDADE];

	while (1)
	{

		puts("Insira o nome da cidade (uma palavra de ate 30 caracteres uteis), ");
		puts("ou digite FIM no nome do municipio para terminar");
		scanf("%s", cidade);
		if (strcmp(cidade, "FIM") == 0)
		{
			break;
		}

		strcpy(arr[n].nome, cidade);
		puts("Populacao?");
		scanf("%f", &arr[n].populacao);
		puts("Area?");
		scanf("%f", &arr[n].area);
		puts("PIB?");
		scanf("%f", &arr[n].pib);
		puts("IDH?");
		scanf("%f", &indice[n].idh);

		indice[n].pk = arr[n].pk = n; //coloca uma chave primaria para cada cidade

		n++;
	}

	puts("Cidades fornecidas:");
	for (int i = 1; i < n; i++)
	{
		printf("cidade: %s - ", arr[i].nome);
		printf("idh: %f| ", indice[i].idh);
		//printf("PK %d - ", indice[i].pk);
		//printf("PKcid: %d \n", arr[i].pk);
		printf("area: %f| ",arr[i].area);
		printf("pib: %f| ",arr[i].pib);
		printf("populacao: %f \n",arr[i].populacao);
	}

	indice[0].maxlista = n; //estoca no vetor a quantidade de itens que tem
							//sim, uma "coluna" inteira da memoria alocada para estocar apenas um int. Eficiencia 0, mas vai funcionar.

	heapify_function(indice); //ou seja, vamos criar um heap ordenando o IDH mas a PK vai acompanhar para depois ler corretamente

	//Nessa parte vai fazer a substituição da tirada do primeiro pelo ultimo e depois fazer o adjust ai.
	float tempIDH;
	int tempPK;
	int last;

	while (indice[0].maxlista > 1)
	{
		last = indice[0].maxlista;

		tempIDH = indice[1].idh;
		tempPK = indice[1].pk;

		indice[1].idh = indice[last].idh;
		indice[1].pk = indice[last].pk;

		indice[last].idh = tempIDH;
		indice[last].pk = tempPK;

		indice[0].maxlista--; //aqui ele vai tirando. Hummm agora entendi.
		adjust(indice, 1);
	}

	int maxcidades;
	puts("Agora me diga por favor quantas cidades serao contempladas:\n\n");
	scanf("%d", &maxcidades);
	while (maxcidades > 50 || maxcidades < 1)
	{
		puts("Entre 1 e 50 cidades por favor.");
		scanf("%d", &maxcidades);
	}
	
	printf("Ok, vou listar %d cidades:", maxcidades);
	ImprimeArvore(arr, indice, maxcidades);
	
	return 0;
}