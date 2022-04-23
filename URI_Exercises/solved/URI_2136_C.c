// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 2590.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe

https://www.urionlinejudge.com.br/judge/pt/problems/view/2136

Pseudo muito abstrato:

-Ler
    -ou jogar num array para separar em duas marizes YES ou NO
    -Ou jogar em uma e dependendo do YES ou NO jogar na outra
    -Ou fazer uma struct com nome e YES ou NO (0 ou 1 sei la)

Se for YES
    -Ver quantas letras é o nome e marcar aquele nome como o amigo atual
    -A cada vez que letras aumentar marcar o novo como amigo

Sortar
Imprimir

*/

//Solução: https://github.com/ridneto/Uri-Online-Judge/blob/master/Estrutura/URI_2136%20-%20(5882846)%20-%20Accepted.c



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LISTA 100000    //so dizendo que isso é arbitrario. Ta vendo por que odeio o URI as vezes?
                            //Se isso fosse 10^100000 daria time limit =P Ai começa a dar wrong answer
                            //e nao tenho saco p ficar escovando o codigo p achar essas coisas...
#define MAX_NOME 50

typedef struct{ //ó a pessoa aqui foi pelo caminho da struct.
    char nome[MAX_NOME], amigo; 
    int tam;
}TAmigo; 

TAmigo vetor[MAX_LISTA];

int compara(const void *p1, const void *p2){ //função para o qsort. Enfim tem que sortar no final...
                                             //na mao sei fazer o bubble sort (o mais simples)
                                             //ai o URI da Time limit... que se lasque o uri.

TAmigo *i = (TAmigo *)p1, *j = (TAmigo *)p2;

if(i->amigo > j->amigo)
    return -1;
else if(i->amigo < j->amigo)
    return 1;
else
    return strcmp(i->nome, j->nome);
}



int main(){	

    TAmigo winner;
    char resp[5], nome[MAX_NOME];
    int i, n=0;
    winner.tam = 0;

    while(1){
        scanf(" %s %s ", nome, resp);	
        if(strcmp(nome, "FIM") == 0)
            break;

        strcpy(vetor[n].nome, nome); //ai a opção por struct. Que alias até tem o passo adicional de jogar
                                     //em um nome[] "intermediario". Nao sei pq ja nao jogou no struct direto.
        vetor[n].tam = strlen(vetor[n].nome); //eu faria um while != '/0', mas assim deve ser melhor...
        
        if(strcmp(resp, "YES") == 0){
            vetor[n].amigo = 1;
            if(vetor[n].tam > winner.tam){
            winner.tam = vetor[n].tam;
            strcpy(winner.nome, vetor[n].nome);
            }
        }else
            vetor[n].amigo = 0;
        
        n++;
    }

    qsort(vetor, n, sizeof(TAmigo), compara); //nao sei usar qsort...

    printf("%s\n", vetor[0].nome);
    for(i=1; i<n; i++)
    if(strcmp(vetor[i].nome, vetor[i-1].nome) != 0)
    printf("%s\n", vetor[i].nome);
    printf("\nAmigo do Habay:\n");
    printf("%s\n", winner.nome);

    //no final foi a escolha por struct. Mas o que da raiva é que imagine que eu tivesse feito por vetor
    //se eu tomar um time limit eu jogo o pc da janela de raiva...

    return 0;
}

