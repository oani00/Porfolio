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
Baseado no programa pListaNum_Cont2
	Programa carrega uma lista linear de inteiros por CONTIGUIDADE,
	a imprime e depois pesquisa um valor e o exclui, caso ele exista na lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1/ex2 && gcc ex2_oani.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

/*
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/tarefa_1/ex2 && gcc ex2_oani_cli.c -c -Wall -lm && gcc ex2_oani_impl.c -c -Wall -lm && gcc ex2_oani_cli.o ex2_oani_impl.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

//criara funcionarios sequencialmente
struct funcionario {
	int codigo;
	char nome[31]; 
	double salario;
	} ;

typedef struct funcionario funcionario;

// typedef struct {
// 	int codigo;
// 	char nome[31]; 
// 	double salario;
// 	} funcionario;

#define TRUE	1
#define FALSE	0

#define QTDE_ITENS	5000

//criando a lista seq. no escopo global//////////////////////////////////////////////////////////////////
		//ou seja, um array de funcionarios
funcionario entradaFuncionario[QTDE_ITENS]; /*aqui fiz um jogo de palavras meio esquisito para facilitar a leitura.
											a lista entradaFuncionario tera a entradaFuncionario1, entradaFuncionario2 etc.
											que são os funcionarios em si.
+------------------------+-----------------------+--------------------+-----------------+
| entradaFuncionario[1]  | entradaFuncionario[n] | e assim por diante | ate o fim(5000) |
+------------------------+-----------------------+--------------------+-----------------+
| int codigo;            | int codigo;           |                ... |                 |
| char nome[31];         | char nome[31];        |                ... |                 |
| double salario;        | double salario;       |                ... |                 |
+------------------------+-----------------------+--------------------+-----------------+ https://ozh.github.io/ascii-tables */
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){	
	
	int final, esse, p;

	/* inicializando a variável de controle do fim da lista */
	final = -1;
	
	//////////////////////Inserindo dados na lista///////////////////////////
	while (TRUE)
	{	printf("Informe o codigo (ou < 0 para encerrar):\n");
		scanf("%i", &esse);
		
		if (esse < 0)
			{break;}
		if (final == QTDE_ITENS)
			{puts("Lista jah estah cheia");}
		else
			{entradaFuncionario[++final].codigo = esse; 	//Acrescente final +1 e coloque nele
			
			printf("Informe o nome do funcionario a registrar (max 30 caracteres):\n"); //o nao uso do &: https://stackoverflow.com/questions/16570716/warning-format-s-expects-type-char-but-argument-2-has-type-char
			scanf("%30s", entradaFuncionario[final].nome);	//agora coloque nesse final acrescentado

			printf("Informe o salario do funcionario a registrar:\n");
			scanf("%lf", &entradaFuncionario[final].salario);}
		
	}
		
	/* imprimindo os valores da lista -----------------------------------*/
	//Desculpa pela porquisse professor, mas joguei aqui mesmo...
		int w = 0;

		printf("\n\n\nNovo conteudo da lista:\n");
		
		while (w <= final){
			printf("%i\n", entradaFuncionario[w].codigo);
			printf("%s\n", entradaFuncionario[w].nome);
			printf("%.2f\n", entradaFuncionario[w].salario);
			w = w + 1;
		}
	/* imprimindo os valores da lista -----------------------------------*/
	
	////////////////////// Exclusão ///////////////////////////
	
	int codigo;
	do
	{
		
		printf("Informe o codigo a pesquisar e excluir ou < 0 para terminar:\n");
		scanf("%d", &codigo);

		p = 0;
		while (p <= final)
		{	if (entradaFuncionario[p].codigo == codigo)
				break;

			p = p + 1;
		}

		/* O looping anterior poderia ser escrito como
			p = 0;
			while (p <= final && lista[p] != numero)
			{	p = p + 1;
			}
		*/

		if (p > final)
			puts("Valor nao existe na lista");
		else
		{	while (p < final)
			{	entradaFuncionario[p].codigo = entradaFuncionario[p + 1].codigo;
				p = p + 1;
			}
			
			final = final - 1;
		}

		/* imprimindo os valores da lista -----------------------------------*/
		//Desculpa pela porquisse professor, mas joguei aqui mesmo...
		int q = 0;

		printf("\n\n\nNovo conteudo da lista:\n");
		
		while (q <= final){
			printf("%i\n", entradaFuncionario[q].codigo);
			printf("%s\n", entradaFuncionario[q].nome);
			printf("%.2f\n", entradaFuncionario[q].salario);
			q = q + 1;
		}
		/* imprimindo os valores da lista -----------------------------------*/

	} while (codigo >= 0);

	return 0;
}