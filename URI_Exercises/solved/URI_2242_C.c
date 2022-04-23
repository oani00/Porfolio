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
*/

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1880

//solucao: https://mamun-amin.blogspot.com/2016/09/solution-of-uri-2242-huaauhahhuahau.html


/* 
Pseudo:

while(não ser condicao de termino)
   -Popular o vetor
      -Para isso ver se entrada == a,e,i,o,u, se nao ignorar
   -se vetor[final] == vetor[inicial] && vetor[final-1] == vetor[inicial+1] ...
      -S
      else
      -N

   //poderia fazer isso com um i subindo e um j descendo e um break ou algo assim
   //ou fazer esses passos e subir um count. Se count == N, S, se nao, N
*/


#include <stdio.h>

int main()
{
   int i, j=0, tamanho;
   char entrada[60], vogais[60]; //aqui populou o entrada direto e "filtrou" para o vogais. Enfim nao sei se é mais lento.

   scanf("%s", entrada);
   
   for(i=0; entrada[i]; i++)
   {
      if(entrada[i]=='a' || entrada[i]=='e' || entrada[i]=='i' || entrada[i]=='o' || entrada[i]=='u')
      {
         vogais[j] = entrada[i];
         j++;
      }
   }
   
   vogais[j] = '\0'; //ah Czisses...
   
   tamanho = strlen(vogais); //dahora nao conhecia essa strlen

   for(i=0, j=tamanho-1; i < tamanho; i++, j--)
   {
      if(vogais[i] != vogais[j])
      {
         printf("N\n");
         return 0;       //tem esse outro jeito tambem que nao tinha pensado. só finaliza se alguma vez nao bater a logica.
      }
   }
   printf("S\n");
   return 0;
}