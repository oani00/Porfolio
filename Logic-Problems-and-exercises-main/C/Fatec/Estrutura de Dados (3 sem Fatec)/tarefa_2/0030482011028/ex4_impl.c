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