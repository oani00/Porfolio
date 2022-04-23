/*10 escreva uma função recursiva que gera todas as combinações da mega sena de 6 dezenas

A loteria da Mega-Sena
Muito provavelmente voce já jogou na Mega Sena, não e?
Ela funciona assim: voce deve escolher 6 dezenas (sena), de um universo de 60 números, de 1 até 60.
No sorteio, tem um globo com 60 bolas e as moças bonitas lá vão tirando bolinha por bolinha...então, obviamente, as dezenas não se repetem,
concorda?
No final, eles exibem o resultado na ordem crescente dos valores, ou seja, da dezena menor pra maior.
O 'menor' palpite é:

1 2 3 4 5 6

Já o 'maior' palpite é:

55 56 57 58 59 60

*/

#include <stdio.h>

int ChanceMegaSena(int vetor[], int i, int maxDezena1);

int main(){

    int numSena[6];
    int dezenaMax1 = 55;
    int inicio = 0;
    ChanceMegaSena(numSena,inicio,dezenaMax1);
}

int ChanceMegaSena(int vetor[], int i, int maxDezena1){
    if(maxDezena1 == 60){
        for(vetor[i] = i+1; vetor[i] <= maxDezena1; vetor[i] += 1){
            if(vetor[0] != vetor[1] && vetor[0] != vetor[2] && vetor[0] != vetor[3] && vetor[0] != vetor[4] && vetor[0] != vetor[5] &&
               vetor[1] != vetor[2] && vetor[1] != vetor[3] && vetor[1] != vetor[4] && vetor[1] != vetor[5] &&
               vetor[2] != vetor[3] && vetor[2] != vetor[4] && vetor[2] != vetor[5] &&
               vetor[3] != vetor[4] && vetor[3] != vetor[5] &&
               vetor[4] != vetor[5])
                printf("%d %d %d %d %d %d\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5]);
        }
    } else {
        for(vetor[i] = i+1; vetor[i] <= maxDezena1; vetor[i] += 1){
            ChanceMegaSena(vetor,i+1,maxDezena1+1);
        }
    }
}

/////////////////////////////////////////////////////////////////
//////////////////////////Outro jeito que resolvemos/////////////
/////////////////////////////////////////////////////////////////


/*

#include <stdio.h>

//int ChanceMegaSena(int numSena, int maxDezena1);
int ChanceMegaSena(int dezena1, int dezena2, int dezena3, int dezena4, int dezena5, int dezena6);
int main(){

  //int numSena = 1;
  //int dezenaMax1 = 55;
  
  int comb = 0;
  int dezena1, dezena2, dezena3, dezena4,
        dezena5, dezena6;

  //se declarar na funcao ficara resetando
  int soma = 0;
  //comb = ChanceMegaSena(numSena,dezenaMax1);
  
  //comb = ChanceMegaSena(0,0,0,0,0,0);
  ChanceMegaSena(1,0,0,0,0,0);
  //impriminto o n de combinacoes geradas
  printf("n de combinacoes: %d", comb);
  return 0;
}

//fonte: professor da etec kk, ele deve ter pego na net, não sei kk
//int ChanceMegaSena(int numSena, int maxDezena1){
int ChanceMegaSena(int dezena1, int dezena2, int dezena3, int dezena4, int dezena5, int dezena6){
  if(dezena1 == 55)
    return 0;
  else
    //for(dezena1=1; dezena1<=55 ; dezena1++)
    //esse for éé a funçãão que sera chamada ate dezena1 <= 55
        for(dezena2=dezena1+1; dezena2<=56 ; dezena2++)
            for(dezena3=dezena2+1; dezena3<=57 ; dezena3++)
                for(dezena4=dezena3+1; dezena4<=58 ; dezena4++)
                    for(dezena5=dezena4+1; dezena5<=59 ; dezena5++)
                        for(dezena6=dezena5+1; dezena6<=60 ; dezena6++)
                            printf("%d - %d - %d - %d - %d - %d\n", dezena1, dezena2, dezena3, dezena4, dezena5, dezena6);
                            //contador de geracoes
                            //comb++;
    //dai aqui acrescenta a dezena 1
    dezena1++;
    //a ideia éé que ela se rechame o n de vezes que o 1o for rodadaria
    
    //ChanceMegaSena(numSena, maxDezena1);
    ChanceMegaSena(dezena1, dezena2, dezena3, dezena4, dezena5, dezena6);

    return 0;
}

//Algorito em que esse ultimo foi baseado--------------------------------------------------------------------------------
/*------- Algoritmo de gerar as sequencias possiveis da mega - parte de 1 2 3 4 5 6 e vai ate o 55 56 57 58 59 60 -------

fonte: professor da etec kk, ele deve ter pego na net, não sei kk

  int dezena1, dezena2, dezena3, dezena4,
        dezena5, dezena6;

    for(dezena1=1; dezena1<=55 ; dezena1++)
        for(dezena2=dezena1+1; dezena2<=56 ; dezena2++)
            for(dezena3=dezena2+1; dezena3<=57 ; dezena3++)
                for(dezena4=dezena3+1; dezena4<=58 ; dezena4++)
                    for(dezena5=dezena4+1; dezena5<=59 ; dezena5++)
                        for(dezena6=dezena5+1; dezena6<=60 ; dezena6++)
                            printf("%d - %d - %d - %d - %d - %d\n", dezena1, dezena2, dezena3, dezena4, dezena5, dezena6);

    return 0;
*/

*/