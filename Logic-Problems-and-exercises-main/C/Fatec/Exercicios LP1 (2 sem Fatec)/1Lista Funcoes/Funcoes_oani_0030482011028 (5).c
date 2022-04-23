// 5. Crie uma função em linguagem C que receba 3 números e retorne o maior valor.

#include <stdio.h>


int retornade3(int x, int y, int z){

  int m;

  printf("coloque um valor\n");
  scanf("%d", &x);
  printf("Ótimo! agora outro valor\n");
  scanf("%d", &y);
  printf("Show! agora o ultimo valor\n");
  scanf("%d", &z);

  if (x > y)
    m = x;
  else if (x < y)
    m = y;
  else if (x == y)
    m = x;

  if (m > z){
    printf("O MAIOR valor é %d!", m);}
  else if (m < z){
    printf("O MAIOR valor é %d!", z);}
  else{
    printf("Os dois maiores valores sao iguais 0.0");}

  return 0;
}


int main(){

  int x = 0, y = 0, z = 0;

	retornade3(x,y,z);

  return 0;
}
