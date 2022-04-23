//9.   Escreva uma função recursiva que dado um número n, 
//gere todas as possíveis combinações com as n primeiras letras do alfabeto. 
//Ex.: n = 3. Resposta: ABC, ACB, BAC, BCA, CAB, CBA.

#include <stdio.h>


// adaptação de https://gist.github.com/marcoscastro/60f8f82298212e267021

void permutaRecursivo(char vetor[], int inf, int sup)
{
	if(inf == sup)
	{
		for(int i = 0; i <= sup; i++){
            if(vetor[i] != '\0'){
                printf("%c ", vetor[i]);
            }
		}
		printf("\n");
	}
	else
	{
		for(int i = inf; i <= sup; i++)
		{

			int aux = vetor[inf];
			vetor[inf] = vetor[i];
			vetor[i] = aux;
			permutaRecursivo(vetor, inf + 1, sup);
			aux = vetor[inf];
			vetor[inf] = vetor[i];
			vetor[i] = aux;
		}
	}
}

int main()
{
	char alfa[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n, i = 0;
	printf("Digite o numero para gerar permutacoes possiveis com as letras correspondentes ao alfabeto: ");
	scanf("%d", &n);
    char alfaPermuta[n];
    for(i = 0; i < n; i++){
        if(i == n){
            alfaPermuta[i] = '\0';
        } else {
            alfaPermuta[i] = alfa[i];
            //printf("letra %c \n", alfaPermuta[i]);
        }
    }

	permutaRecursivo(alfaPermuta, 0, n-1);

	return 0;
}





