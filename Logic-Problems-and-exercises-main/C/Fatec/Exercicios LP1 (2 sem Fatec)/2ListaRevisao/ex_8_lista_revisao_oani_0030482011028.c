// 8. Leia um vetor A de 6 elementos contendo o gabarito da Mega-Sena.

	// O sorteio consiste na extração de 6 números diferentes, no universo de 01 a 60.

    // A seguir, ler um vetor B de 10 elementos contendo uma aposta.

    // Escrever quantos pontos fez o apostador, e se ele fez a sena (6 acertos), a quina (5 acertos) ou a quadra (4 acertos).


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int A[6], B[10], i;

	//gerar os numeros da mega s

	//////Essa é a versao gerando ns aleatorios. Acho que não é para fazer assim né?
	// srand(time(NULL));
	// A[0] = rand() % 61;
	// A[1] = rand() % 61;
	// A[2] = rand() % 61;
	// A[3] = rand() % 61;
	// A[4] = rand() % 61;
	// A[5] = rand() % 61;

	printf("Insira o gabarito (entre 1 e 60 ein):\n");
	for(i = 0;i < 6;i++){
		scanf("%d", &A[i]);
		while ((A[i] > 60) || (A[i] <1)){
			printf("Paaaaaaaara para para para, entre 1 e 60");
			scanf("%d", &A[i]);
		}
	}

	//gerar os numeros da aposta
	//era para fazer um for, preguiça denovo...
	// B[0] = rand() % 61;
	// B[1] = rand() % 61;
	// B[2] = rand() % 61;
	// B[3] = rand() % 61;
	// B[4] = rand() % 61;
	// B[5] = rand() % 61;
	// B[6] = rand() % 61;
	// B[7] = rand() % 61;
	// B[8] = rand() % 61;
	// B[9] = rand() % 61;
  		//impressionante como é dificil ganhar nesse negócio!!!


	printf("Blz, agora insira uma aposta\n");
	for(i = 0;i < 10;i++){
		scanf("%d", &B[i]);
		while ((B[i] > 60) || (B[i] <1)){
			printf("Paaaaaaaara para para para, entre 1 e 60");
			scanf("%d", &B[i]);
		}
	}

	int a, b, acertos = 0;
	for (b=0;b < 10;b++)
	{
		for (a=0;a < 6;a++)
		{
			if (B[b] == A[a])
				acertos++;
		}
	}

	printf("Você acertou %d!", acertos);

	if (acertos == 6)
		printf("E fez uma sena!!!!!!!!");
	if (acertos == 5)
		printf("E fez uma sena!!!!!!!!");
	if (acertos == 4)
		printf("E fez uma sena!!!!!!!!");

  return 0;
}
