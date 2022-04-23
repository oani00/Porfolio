// 2. Crie uma função que receba um valor e diga se é nulo ou não.

#include <stdio.h>

int checanulo(int x){

  printf("Insira o valor para eu dizer se eh nulo ou nao \n");
  scanf("%d", &x);

  if (x == NULL)
    printf("Seu valor eh nulo 0.0");
  else
    printf("Seu valor eh não é nulo =D");

  return x;
}


int main(){

int x;

checanulo(x);

return 0;
}

