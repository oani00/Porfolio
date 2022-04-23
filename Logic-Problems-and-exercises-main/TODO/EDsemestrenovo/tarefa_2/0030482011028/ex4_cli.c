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

#define MAX_ELEMS 5005
#define TAMCIDADE 31

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