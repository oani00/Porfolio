// 5. Receber 12 números e armazená-los em um vetor. Ao final, exibir quais foram os números positivos informados.

#include <stdio.h>

void armazenar(){

	int A[12], POS[12];

  printf("Insira o numero 1:");
  scanf("%d", &A[0]);
  printf("Insira o numero 2:");
  scanf("%d", &A[1]);
  printf("Insira o numero 3:");
  scanf("%d", &A[2]);
  printf("Insira o numero 4:");
  scanf("%d", &A[3]);
  printf("Insira o numero 5:");
  scanf("%d", &A[4]);
  printf("Insira o numero 6:");
  scanf("%d", &A[5]);
  printf("Insira o numero 7:");
  scanf("%d", &A[6]);
  printf("Insira o numero 8:");
  scanf("%d", &A[7]);
  printf("Insira o numero 9:");
  scanf("%d", &A[8]);
  printf("Insira o numero 10:");
  scanf("%d", &A[9]);
  printf("Insira o numero 11:");
  scanf("%d", &A[10]);
  printf("Insira o numero 12:");
  scanf("%d", &A[11]);
  
  int i;
  for (i = 0;i < 12;i++)
	  if (A[i] > 0){
		POS[i] = A[i];
		printf("%d\n ", POS[i])};

  printf("Legal! Agora vou mostrar apenas os números positivos que você me deu (x>0):\n");
}

int main(){

  armazenar();

  return 0;
}
