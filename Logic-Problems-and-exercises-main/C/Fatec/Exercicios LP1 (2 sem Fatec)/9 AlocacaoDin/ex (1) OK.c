/*
1)Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos

e passe esse vetor para uma função que vai ler os elementos desse vetor.

Depois, no programa principal, o vetor preenchido deve ser impresso.

Além disso, antes de finalizar o programa, deve-se liberar a área de memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

void ler(int *ptr, int n){

int i = 0;
	for(i=0; i < n; i ++){
		printf("Digite um valor:\n");
		scanf("%i", &ptr[i]);
		printf("\nvc digitou %i \n", ptr[i]);
	}
}

int main(){
int tam, *vet, i;
printf("Digite o tamanho do vetor: ");
scanf("%i", &tam);

*vet = (int *) malloc(tam * sizeof(int));

if (!vet){
	printf ("** Erro: Memoria Insuficiente **\n");
	exit;
	}
else
	printf ("** Memoria Alocada com Sucesso **\n");

ler(vet, tam);

for(i=0; i < tam; i ++){
printf("\n%i", vet[i]);
}

free(vet);
printf("\nMemoria liberada!!!!!");

return 0;
}
