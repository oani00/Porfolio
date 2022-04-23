/*

5. Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N.

*/
#include <stdio.h>
int soma(int N);

int main(){

  int N, SOMA = 0;
  printf("Digite um numero: ");
  scanf("%d", &N);
  SOMA = soma(N);
  printf("%d", SOMA);
  return 0;
}

int soma(int N){
    
    if(N == 0){
        return 0;
    } else {
        return N += soma(N-1);
    }
}

/*
teste
1	1
2	3
3	6
4	10
5	15
6	21
7	28
8	36
9	45
10	55
11	66


*/