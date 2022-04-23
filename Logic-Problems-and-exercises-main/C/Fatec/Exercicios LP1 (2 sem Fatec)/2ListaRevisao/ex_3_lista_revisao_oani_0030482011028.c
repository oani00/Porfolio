// 3. Receber 8 números e armazená-los em um vetor. Ao final, pedir para o usuário
	//escolher uma posição do vetor e exibir o número contido nela.

#include <stdio.h>

void armazenar(){

  int A[9];

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
  // printf("Insira o numero 9:");
  // scanf("%d", &A[8]);
  // printf("Insira o numero 10:");
  // scanf("%d", &A[9]);

  printf("Blz, agora queria que voce me disesse algum dos numeros para exibir. Fala ai:\n");
  int n;
  scanf("%d", &n);
  printf("Show! Seu numero eh:\n");
  printf("%d\n", A[n-1]);

}

int main(){

  armazenar();

  return 0;
}
