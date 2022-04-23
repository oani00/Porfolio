/*

6. Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N. 
  Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.

*/
#include <stdio.h>

int RepeteDig(int N, int K, int rep);

int main(){

  //caso teste
  // 762021192
  // 101111100
  int Num, Dig,qtdDig = 0, Total = 0;
  printf("Digite um Numero natural: ");
  scanf("%d", &Num);
  printf("NUM: %d \n", Num);
  printf("Digite um numero e veja quantas vezes ele se repete no numero digitado: ");
  scanf("%d", &Dig);
  Total = RepeteDig(Num,Dig,qtdDig);
  printf("O digito se repete %d vezes", Total);
  return 0;
}

int RepeteDig(int N, int K, int rep){
  printf("%d\n", N);
  if(N == 0){
    //printf("%d \n", N);
    return rep;
  } else {
    if(N % 10 == K){
      rep++;
    }
    return RepeteDig(N / 10, K, rep);
  }
}