// 4. Crie uma função em linguagem C que receba 2 números e retorne o menor valor. 

#include <stdio.h>

int retornamenorvalor(int x, int y){

  printf("coloque o primeiro valor\n");
  scanf("%d", &x);  
  printf("Ótimo! agora o segundo valor\n");
  scanf("%d", &y);  
  
  if (x > y)
    printf("o menor valor é %d", y);
  else if (x < y)
    printf("o menor valor é %d", x);
  else
    printf("os valores sao iguais 0.0");
  
  return 0;
}

int main(){

  int x,y;
  
  retornamenorvalor(x,y);
   
  return 0;
}
