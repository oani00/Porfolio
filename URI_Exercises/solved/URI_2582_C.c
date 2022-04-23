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
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI/resolvidos && gcc z1267.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

int main()
{
    int n, a, b, soma;
    
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%i %i", &a, &b);
        
        soma = a + b;

        switch (soma)
        {
        case 0:
            printf("PROXYCITY\n");
            break;
        case 1:
            printf("P.Y.N.G.\n");
            break;
        case 2:
            printf("DNSUEY!\n");
            break;
        case 3:
            printf("SERVERS\n");
            break;
        case 4:
            printf("HOST!\n");
            break;
        case 5:
            printf("CRIPTONIZE\n");
            break;
        case 6:
            printf("OFFLINE DAY\n");
            break;
        case 7:
            printf("SALT\n");
            break;
        case 8:
            printf("ANSWER!\n");
            break;
        case 9:
            printf("RAR?\n");
            break;
        case 10:
            printf("WIFI ANTENNAS\n");
            break;
        default:
            printf("\n");
        }
    }
}
