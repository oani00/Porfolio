// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 2590.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1880

//solucao https://nayeemuniverse.wordpress.com/2015/10/17/solution-to-1180-from-uri-in-c/

Pseudo:

   scanf (n)
      for até n
         scanf numero
         for i de 2 ate 16
            while (n > 0)
               dividir numero por i
               resto divisao por i
               colocar em um v[i]
            for i até 0 i--
               if v[i] == 10 
                  print A
               else v[i] == 11
                  print B
               ...
               else
                  print v[i]


*/
int main()
{
   int a[1000],i,k=0,n;
   scanf("%d",&n);
   for(i=0 ; i<n ; i++)
   {
      scanf("%d",&a[i]);
   }

   int min=a[k];
for(i=0 ; i<n ; i++)
{
if(a[i]<min)
{
min=a[i];
k=i;
}
}
printf("Menor valor: %d\nPosicao: %d\n",a[k],k);

return 0;

}
