/*

8.   Faça uma função recursiva que 
	-receba um número inteiro positivo N 
	-e imprima todos os números naturais de 0 até N 
	-em ordem crescente.

*/

#include <stdio.h>

int incrementCrescente(int n, int cont);

int main(){
    int i = 0, n;
    printf("Entre com um numero positivo e veja a ordem de 0 até ele! ");
    scanf("%d", &n);
    incrementCrescente(n, i);
    return 0;
}

int incrementCrescente(int n, int cont){
  printf("\n%d", cont);
  if(cont == n){
    return cont;
  } else {
    return incrementCrescente(n, cont+1);
  }
}


