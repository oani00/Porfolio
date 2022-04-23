// 1. Receber 10 números e armazená-los em um vetor. Ao final, exibir os números na ordem que foram recebidos.

#include <stdio.h>

void armazenar(){

  int A[10];

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

  printf("Legal! Os numeros que voce inseriu foram:\n");
  printf("%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ", A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8], A[9]);

}

int main(){

  armazenar();

  return 0;
}
