// 6. Crie uma fun��o em linguagem C que receba 3 n�meros e retorne o menor valor, use a fun��o da quest�o 4.


#include <stdio.h>

//mudei o nome para ficar mais claro

int menord3(int x, int y, int z){

  int m;

  printf("coloque um valor\n");
  scanf("%d", &x);
  printf("�timo! agora outro valor\n");
  scanf("%d", &y);
  printf("Show! agora o ultimo valor\n");
  scanf("%d", &z);

  m = questao4(x,y);

  if (m > z){
    printf("O menor valor � %d!", z);}
  else if (m < z){
    printf("O menor valor � %d!", m);}
  else{
    printf("Os dois menores valores sao iguais 0.0");}

  return 0;
}

int questao4(int x, int y){

  int m;
//
//  printf("coloque o primeiro valor\n");
//  scanf("%d", &x);
//  printf("�timo! agora o segundo valor\n");
//  scanf("%d", &y);

  //tirei os printfs
  //e mudei a logica
  if (x > y)
    m = y;
  else if (x < y)
    m = x;
  else
    m = x;

  return m;
}

int main(){

  int x,y, z;

  menord3(x,y, z);

  return 0;
}
