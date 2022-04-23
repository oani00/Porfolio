/*

7.       A multiplicação de dois números inteiros pode ser feita através de MULTs sucessivas. 
Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a multiplicação de dois inteiros.

*/
#include <stdio.h>
int Multip_Rec(int n1, int n2);

int main(){

  int N, N2, MULT = 0;
  printf("Digite um numero:  ");
  scanf("%d", &N);
  printf("Vezes quanto? ");
  scanf("%d", &N2);
  MULT = Multip_Rec(N,N2);
  printf("%d\n", MULT);
  return 0;
}

int Multip_Rec(int n1, int n2){
    
    if(n2 == 0){
        return 0;
    } else {
        return n1 += Multip_Rec(n1, n2-1);
    }
}