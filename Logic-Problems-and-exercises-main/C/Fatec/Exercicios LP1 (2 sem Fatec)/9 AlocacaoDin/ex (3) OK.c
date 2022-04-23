/*3) Crie uma função que receba como parâmetros dois vetores de inteiros (já ordenados):
x1 e x2 e as suas respectivas quantidades de elementos: n1 e n2.

A função deverá retornar um ponteiro para um terceiro vetor, x3, alocado dinamicamente, contendo a união de
x1 e x2 e usar o ponteiro qtd para retornar o tamanho de x3.

Sendo x1 = {1, 3, 5, 6, 7} e x2 = {1, 3, 4, 6, 8},  x3 irá conter {1, 3, 4, 5, 6, 7, 8}.

Assinatura da função:

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd); */

#include <stdio.h>
#include <stdlib.h>

int* uniao(int *x1, int *x2, int n1, int n2, int *qtd){

	int n3 = n1+n2, i, j;

	//Adicionar tudo num vetorzão temporario. Esse vetor será reorganizado (ja que nao fui competente o suficiente
	//para usar a organização incial... e desse serão jogados em x3 apenas 1 ocorrenica de cada repetição, se houver.

	int temp[n3];
	int prex3[n3]; //esse prex3 estocará os vetores que irao para o x3 após alocação

	//////vetor 1
	for (i = 0; i < n1; ++i){
		temp[i] = x1[i];
	}

	//////vetor 2
	for (i = 0; i < n2; ++i){
		temp[i+n1] = x2[i];
	}

	//reorganizando(denovo...)

	int aux;
    for (i = n3 - 1; i >= 1; i--){
		for (j = i-1; j >= 0; j--){
			if (temp[i] < temp[j])
			{
				aux = temp[j];
				temp[j] = temp[i];
				temp[i] = aux;
			}
		}
	}

    //para ver o temp[]
	//for (i = 0; i < n3; ++i){printf ("temp[%d]= %d\n", i, temp[i]);}

    int adicional = 0;

	//Percorre o vetor e se um item se repetir adiciona apenas a ultima ocorrencia dele, e para no ultimo valor.
	for (i = 0; i < n3; ++i)
	{
        for (j = i+1+ adicional; j < n3+1; ++j) //sem esse +1 o ultimo numero nunca seria adicionado (fun fact, ele joga um 0)
        {
            if(temp[i + adicional] == temp[j]){
                adicional++;
            }
        }

        prex3[i] = temp[i + adicional];

        //printf ("prex3[%d] = %d\n", i, prex3[i]);

        (*qtd)++; //aqui estamos definindo o tamanho de x3

        if(i + adicional > n3-2) {break;} //se não começa a adicionar lixo

	}

	//Após adicionar tudo em um outro vetor temporário, alocaremos a memoria para x3 para finalmente adicionar certinho
	int *x3 = (int *) malloc(*qtd * sizeof(int));
	if (!x3){
        printf ("** Erro: Memoria Insuficiente **\n");
        exit;
	}else{
        printf ("** Memoria Alocada com Sucesso **\n");
	}

    //agora finalmente vamos adicionar prex3 em x3

    for (i = 0; i < *qtd; ++i)
	{
        x3[i] = prex3[i];
	}

	//Retornando o tamanho de x3

	//printf("-----prex3:-----\n");
	//printf("{ | "); for (i = 0; i < n3; ++i) {printf("%d | ", prex3[i]);} printf(" }");

    printf("-----------------------------------\n\n");
    printf("E a x3 eh:\n\n");
	printf("{ | "); for (i = 0; i < *qtd; ++i) {printf("%d | ", x3[i]);} printf(" }");
	printf("\n\n-----------------------------------\n");

	return qtd;
}

int main()
{
	int n1, n2, i=0, aux=0;
  	//int n1=3, n2=3, i=0, aux=0; //valores iniciais

  	//dois vetores de inteiros (já ordenados):
	printf("Digite o tamanho do 1o vetor e seu primeiro valor\n");

  	scanf("%i\n", &n1);

   	//int x1[3] = {2,3,2}; //valores iniciais
    int x1[n1];

	 	printf("Digite os valores do 1o vetor:\n");

	 	for (i = 0; i < n1; ++i)
	 	{
	 		printf("Digite o %do valor\n", i + 1);
	 		scanf("%i", &x1[i]);
	 	}

    printf("\nO 1o vetor eh: { | "); for (i = 0; i < n1; ++i) {printf("%d | ", x1[i]);} printf("}\n");

		//baseado no Buuble Sort do Diego
		for (int i = n1 - 1; i >= 1; i--){
			for (int j = i-1; j >= 0; j--){
				if (x1[i] < x1[j])
				{
					aux = x1[j];
					x1[j] = x1[i];
					x1[i] = aux;
				}
			}
		}

  printf("\nOrganizado: { | "); for (i = 0; i < n1; ++i) {printf("%d | ", x1[i]);} printf("}\n");

	 printf("Digite o tamanho do 2o vetor e seu primeiro valor\n");
	 scanf("%i\n", &n2);

    //int x2[3] = {2,2,2}; //valores iniciais
    int x2[n2];

	 	printf("Digite os valores do 1o vetor:\n");

	 	for (i = 0; i < n2; ++i)
	 	{
	 		printf("Digite o %do valor\n", i + 1);
	 		scanf("%i", &x2[i]);
	 	}

  printf("\nO 2o vetor eh: { | "); for (i = 0; i < n2; ++i) {printf("%d | ", x2[i]);} printf("}\n");

	//baseado no Buuble Sort do Diego
	for (int i = n2 - 1; i >= 1; i--){
		for (int j = i-1; j >= 0; j--){
			if (x2[i] < x2[j])
			{
				aux = x2[j];
				x2[j] = x2[i];
				x2[i] = aux;
			}
		}
	}

  	printf("\nOrganizado: { | "); for (i = 0; i < n2; ++i) {printf("%d | ", x2[i]);} printf("}\n");

	printf("Agora vou unir os vetores:\n");

	int n3 = n1 +n2;
	int qtdinicial = 0;
	int *qtd = &qtdinicial;

	printf("Tamanho inicial de x3 = %d\n\n", *qtd);

	uniao(&x1[0], &x2[0], n1, n2, qtd);

	printf("\n\nTamanho final de x3 = %d\n", *qtd);

return 0;
}

//alias que orgulho desse código, demorei para faze-lo...