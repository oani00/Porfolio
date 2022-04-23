// 1. Crie uma função que receba um valor e informe se ele é positivo ou não. 

#include <stdio.h>

int checapositivo(int x){

  printf("Insira um número por favor \n");
  scanf("%d", &x);  

  if (x >= 0)
    printf("x é positivo =D ");
  else if (x < 0)
    printf("x é negativo =/ ");
  
  return 0;
}

int main(){

int x;

checapositivo(x);

return 0;
}