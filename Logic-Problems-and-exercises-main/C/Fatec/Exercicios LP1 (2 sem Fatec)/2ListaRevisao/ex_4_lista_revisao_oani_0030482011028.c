// 4. Receber 15 números e armazená-los em um vetor. Ao final, exibir o dobro de cada um dos números.

	

#include <stdio.h>

void armazenar(){

  int A[15];
  
  // Sei que o metodo é horrível, mas to com preguiça de fazer um for XD
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
  printf("Insira o numero 13:");
  scanf("%d", &A[12]);
  printf("Insira o numero 14:");
  scanf("%d", &A[13]);
  printf("Insira o numero 15:");
  scanf("%d", &A[14]);

  printf("Legal! Agora vou dobrar os numeros e mostra-los na sua ordem:\n");
  printf("%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n", 2*A[0], 2*A[1], 2*A[2], 2*A[3], 2*A[4], 2*A[5], 2*A[6], 2*A[7], 2*A[8], 2*A[9], 2*A[10], 2*A[11], 2*A[12], 2*A[13], 2*A[14]);
}

int main(){

  armazenar();

  return 0;
}
