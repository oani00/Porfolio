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