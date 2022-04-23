/*4)  Crie uma função que receba como parâmetros dois vetores de inteiros:

x1 e x2 e as suas respectivas quantidades de elementos: n1 e n2.

A função deverá retornar um ponteiro para um terceiro vetor, x3, alocado dinamicamente,

contendo a ///////intersecção/////// de x1 e x2 e usar o ponteiro qtd para retornar o tamanho de x3.

Sendo:
x1 = {1, 3, 5, 6, 7}
x2 = {1, 3, 4, 6, 8}
x3 irá conter {1, 3, 6}.

Assinatura da função:
int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd);*/


#include <stdio.h>
#include <stdlib.h>

int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd){

	int n3 = n1+n2, i, j;

	//Agora a coisa mudou. Ficou mais simples a logica. (ate pq eu descansei mais e tive sacadas melhores)

	int prex3[n3]; //esse prex3 estocará os vetores que irao para o x3 após alocação
	int k = 0; //isso é um contador para o prex3 começar do primerio, se não ele acompanha ou o i ou o j.

	//Para cada i ele checa todos os j, se i bater com algum ele adiciona e para, e se o i for igual ao i antigo, tambem para.
	for (i = 0; i < n1; ++i)
		{
        if(x1[i] == x1[i-1])
            break; //se não ele fica adicionando copias do x1

        for (j = 0; j < n2; ++j)
        	{

            if(x2[j] == x1[i])
            	{
                prex3[k] = x1[i];
                (*qtd)++;//aqui estamos definindo o tamanho de x3
                k++;//contador do prex3.

	            if(x2[j+1] == x2[i])
	            	break;//se não ele fica adicionando copias do x2
            	}
            }
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

    printf("-----------------------------------\n\n");
    printf("E a x3 eh:\n\n");
	printf("{ | "); for (i = 0; i < *qtd; ++i) {printf("%d | ", x3[i]);} printf(" }");
	printf("\n\n-----------------------------------\n");

	//Retornando o tamanho de x3
	return qtd;
}

int main()
{
	int n1, n2, i=0, aux=0;
  	//int n1=3, n2=3, i=0, aux=0; //valores iniciais

	printf("Digite o tamanho do 1o vetor e seu primeiro valor\n");
  	scanf("%i\n", &n1);

   	//int x1[3] = {1,1,1}; //valores iniciais
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

    //int x2[3] = {1,1,1}; //valores iniciais
    int x2[n2];

	 	printf("Digite os valores do 2o vetor:\n");

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

	printf("Agora vou mostrar a interseccao entre os vetores:\n");

	int n3 = n1 +n2;
	int qtdinicial = 0;
	int *qtd = &qtdinicial;

	printf("Tamanho inicial de x3 = %d\n\n", *qtd);

	interseccao(&x1[0], &x2[0], n1, n2, qtd);

	printf("\n\nTamanho final de x3 = %d\n", *qtd);

return 0;
}
//Esses 2 fiz sem a ajuda do Luiz Miguel!!!!!!! Que orgulho.
