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

https://www.urionlinejudge.com.br/judge/pt/problems/view/1167

pseudo

while 1
    
    -pode ou fazer uma struct criança
    -ou fazer uma matriz
    -ou fazer dois arrays
    
    scanf n
        if n == 0
        break

    for 0 até n
        popular o que for
    
    deve ter varios jeitos, mas vou fazer assim:
    
    numero = criançaI.numero
    crianças = vetorcrianças.length //ai conte isso do jeito que quiser, quando estiver populando, strlengh, sei la.
    
    
    x = 0 //a criança inicial // ou, a criança v[0]

    while crianças > 1

        k = 0 //deve ter um jeito mais inteligente de andar o "seletor" da criança, mas como sou sou mto esperto vou fazer um K mesmo.
        criançasAandar = crianças%numero //em ourro problema vi que o resto da divisão funciona como um reloginho.
        
        for j até criançasAandar
            if vetor[j] == 0
                k--;
            k++
        
        vetor[x-k] = 0 //"seta" a criança como 0, ai pula ela daqui em diante nesse if ai em cima.
        vencedor = vetor[x-k] //coloca essa criança como atual vencedora, para que tenha uma antes do while parar.
        numero = criança(i-criançasAandar).numero
        crianças--

    isso deveria ir rodando as crianças e tirando elas. Nao fiz a logica do horario e antio horario pq é "só" inverter o for
        de ir crescendo para diminuindo e um grande if e else la em cima para cado o criança.numero atual seja impar ou par.


solução: http://muitomaiscodigoss.blogspot.com/2018/04/uri-problema-1167-acampamento-de-ferias.html

*/

#include <stdio.h>

struct child_t { //outro que opta por struct... é melhor?
char name[30];
int value;
int prev, next; //eita é tipo uma lista ligada sqn??
};

int main()
{
    while (1) {
        int N, i, j;
        struct child_t child[100];

        scanf("%d", &N);
        if (!N) // ta né... nao entendi mas blz
            break;

        for (i = 0; i < N; ++i) {
            scanf("%s%d", child[i].name, &child[i].value); //populando

            child[i].prev = ((i - 1) % N  + N) % N; //blz entendi 0
            child[i].next = (i + 1) % N;
        }

        i = 0;
        
        while (N > 1) {
            int value = child[i].value;

            if (value % 2) { //olha que malandragem! Ja calcula ao popular a proxima e antes dela... hummmm dahora.
                for (j = 0; j < value; ++j) //e aqui só escolhe para qual vai... interessante é menos iterações do que o 
                i = child[i].next; // meu jeito faria realmente...
            } else {
                for (j = 0; j < value; ++j)
                i = child[i].prev;
            }

            child[child[i].prev].next = child[i].next; //cara é tipo uma lista ligada sqn mesmo...
            child[child[i].next].prev = child[i].prev; 

            --N;
        }
        
        i = child[i].next;

        printf("Vencedor(a): %s\n", child[i].name); //que dahora ele vai pulando de criança em criança sem zerar nem tirar nada. Dahora
    }

    //Poderia ter feito mesmo uma lista ligada e ir retirando nodes (ou só refazendo os ponteiros sem dar free mesmo).
    //é esse é um jeito que eu acho que não passaria no tempo mas essa solução foi suprema, não sou tao inteligente assim.

    return 0;
}

