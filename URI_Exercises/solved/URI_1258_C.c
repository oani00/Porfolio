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

//https://github.com/matheusaraujo/uri/blob/master/201906/1258/1258.c


struct se{
    char nome[100], cor[10], tipo;
} typedef pedido;

pedido conjPedidos[61]; //<- cria um conjunto de pedidos do tipo pedido (definido na struct)

//se fosse fazer o sort "na mao" ia ficar algo como
//sort conjpedidos por cor
    //ai sort cada parte dos pedidos por tamanho
        //ai cada parte dos tamanhos por nome

//ia dar alguns while dentro de while e eu fariapor bubble sort, mas: 
    //1- como é URI tem que se preocupar com o tempo
    //2- odeio uri e so quero entregar =P nao to a fim de testar essa implementação "na mao" até por que o psort ta ai para isso.

int cmp(const void *c1, const void *c2)
{
    pedido *e1 = (pedido *)c1;
    pedido *e2 = (pedido *)c2;

    if (e1->cor[0] != e2->cor[0])
        return e1->cor[0] - e2->cor[0];
    else if (e1->tipo != e2->tipo)
        return e2->tipo - e1->tipo;

    return strcmp(e1->nome, e2->nome);
}

int main(void)
{
    int n, i, k = -1;

    while (scanf("%d", &n) && n != 0)
    {
        //vai popular o array de pedidos
        for (i = 0; i < n; i++)
        {
            getchar(); //<- nao faco ideia de por que isso ta aqui
            gets(conjPedidos[i].nome); //<- esse gets nao é recomendado mas deixei ai, afinal é uri passando ta bom
            scanf("%s %c", conjPedidos[i].cor, &conjPedidos[i].tipo);
        }

        //vai sortar esse array
        qsort(conjPedidos, n, sizeof(pedido), cmp);

        if(++k)
            printf("\n");

        for (i = 0; i < n; i++)
            printf("%s %c %s\n", conjPedidos[i].cor, conjPedidos[i].tipo, conjPedidos[i].nome);
    }

    return 0;
}