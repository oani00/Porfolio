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

//http://muitomaiscodigoss.blogspot.com/2018/04/uri-problema-2493-jogo-do-operador.html

//No meu pensamento inicial ia fazer duas structs, uma de formula e uma de jogador e escolha, ai no final ia criar um array
//com os jogadores que erraram e ordenar, mas assim também funcionara. Nunca ia pensar em fazer uma matriz de char...

int X[50], Y[50], resultado[50], escolha[50];
char N[50][51], operador[50];

int compare(const void *a, const void *b)
{
    const int *p1 = (const int *) a;
    const int *p2 = (const int *) b;

    return strcmp(N[*p1], N[*p2]);
}

int main()
{
    int T;

    while (scanf("%d", &T) != EOF){
		int escolhaerrada[50];
        int length = 0;
        int i;

        for (i = 0; i < T; ++i)
            scanf("%d %d=%d", &X[i], &Y[i], &resultado[i]);

        for (i = 0; i < T; ++i)
            scanf("%s %d %c", &N[i], &escolha[i], &operador[i]);

        for (i = 0; i < T; ++i) {
            switch (operador[i]) {
                case '+': // tipo o samuel escolheu o 2, entao vai mecher com a posicao 1 do array de numeros (escolha - 1)
                    if (X[escolha[i] - 1] + Y[escolha[i] - 1] != resultado[escolha[i] - 1])
                        escolhaerrada[length++] = i;
                    break;
                case '-':
                    if (X[escolha[i] - 1] - Y[escolha[i] - 1] != resultado[escolha[i] - 1])
                        escolhaerrada[length++] = i;
                    break;
                case '*':
                    if (X[escolha[i] - 1] * Y[escolha[i] - 1] != resultado[escolha[i] - 1])
                        escolhaerrada[length++] = i;
                    break;
                case 'I':
                    if (X[escolha[i] - 1] + Y[escolha[i] - 1] == resultado[escolha[i] - 1] ||
                        X[escolha[i] - 1] - Y[escolha[i] - 1] == resultado[escolha[i] - 1] ||
                        X[escolha[i] - 1] * Y[escolha[i] - 1] == resultado[escolha[i] - 1])
                        escolhaerrada[length++] = i;
                    break;
            }
        }

        if (length == 0)
            printf("You Shall All Pass!\n");
        else if (length == T)
            printf("None Shall Pass!\n");
        else {
            qsort(escolhaerrada, length, sizeof(int), compare);
            for (i = 0; i < length - 1; ++i)
                printf("%s ", N[escolhaerrada[i]]); //tipo escolhaerrada[i] = 2, entao fica N[2] = aline
            printf("%s\n", N[escolhaerrada[i]]);
        }
    }

    return 0;
}