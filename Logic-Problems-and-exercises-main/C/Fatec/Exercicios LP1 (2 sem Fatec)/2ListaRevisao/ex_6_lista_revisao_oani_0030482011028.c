//Com ajuda do Luiz Miguel

// 6. Fa�a um programa que
	//OK leia o tamanho de um vetor A
		//OK e, em seguida, leia os n elementos do vetor.

	//OK Considere que o valor m�ximo de elementos que o vetor A pode armazenar � 100. Por fim,

	//OK calcule e mostre a m�dia dos elementos de �ndice par -- > luiz: OBS:  repare que ele pede indices e nao os valores em si

	//OK e o produto dos elementos de �ndice �mpar.

#include <stdio.h>

void armazenar(){

	printf("Oi! Primeiro diga quantos elementos quer no vetor (n�o pode ser mais de 100 ok ):\n");
	int n;
	scanf("%d", &n);

	if (n > 100){
	printf("Ei! S� 100 elementos = P.");

	scanf("%d", &n);}
	int A[n];

	double media = 0, produto = 1, contador = 0; // declare uma variavel pra contar quantos indices pares tem, dai facilita a media

	printf("Show! Agora diga quais s�o esses elementos:\n");

	
	int i;
	//inserindo A
	for (i=0; i < n;i++){
		printf("Insira o numero: ");
		scanf("%d", &A[i]);
    }

	//use esse segundo for pra separar os impares dos pares, sem necessidade de outros vetores envolvidos;

	for (i=0; i < n;i++){
		if (i%2 == 0){ //se for par, aqui que esta a pegadinha, s�o os elementos de indice par, n�o os elementos par, ou seja, o A[0], a[2], a[4], etc.
            media = media + A[i]; // acumulando a soma dos valores dentro dos indices pares do vetor
            contador++; // contabilizando quando indices pares existem, pra facilitar a divis�o depois pra media
        }
		else{ // aqui entraria os indices impares de A, ou seja, A[1], A[3], A[5], etc;
            produto = produto * A[i]; // continue acumulando o produto e multiplicando ele por a[i]
		}

  }
	printf("Legal! Agora utilizando meu super processamento calcularei:\n");
	printf("O produto dos indices impares do vetor: %.2lf\n", produto); // exibindo produto dos valores em INDICES impares do vetor
	printf("A media dos indices Pares do vetor: %.2lf\n", media/contador); // exibindo a media dos valores em INDICES pares do vetor
}

int main(){

armazenar();

return 0;}