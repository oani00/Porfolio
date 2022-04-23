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

int main()
{
    int T, R, G, B, P;
    char operacao[10];

    scanf("%i", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%s", operacao);
        // printf("%s", operacao);
        scanf("%i %i %i ", &R, &G, &B);
        // printf("%i %i %i ", R, G, B);
        
        if (strcmp(operacao, "eye") == 0)
        {
            // puts("entrou eye");
            P = 0.3*R + 0.59*G + 0.11*B;
        }else if (strcmp(operacao, "mean") == 0)
        {
            // puts("entrou m");
            P = (R+G+B)/3;
        }else if (strcmp(operacao, "max") == 0)
        {
            // puts("entrou max");
            if (R>=G && R>=B)
            {
                P = R;
            }else if (G >= R && G >= B)
            {
                P = G;
            }else if (B >= R && B >= G)
            {
                P = B;
            }
            
        }else if (strcmp(operacao, "min") == 0)
        {
            // puts("entrou min");
            if (R<=G && R<=B)
            {
                P = R;
            }else if (G <= R && G <= B)
            {
                P = G;
            }else if (B <= R && B <= G)
            {
                P = B;
            }
        }
        printf("Caso #%i: %i\n", i+1, P);
    }
}