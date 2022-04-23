#include <stdio.h>

int main(){
    int TAM, i, j;
    double media, produto;
    media = 0;
    produto = 1;
    j = 0;
    printf("Digite uma tamanho para o vetor: ");
    scanf("%d", &TAM);
    int vetor[TAM];
    for (i = 0; i < TAM; i++){
        printf("Insira um valor: ");
        scanf("%d", &vetor[i]);
    }
    for( i = 0; i < TAM; i++)
    {
        if(i % 2 == 0){
            media += vetor[i];
            j++;

        } else {
            produto *= vetor[i];
        }

    }
    printf("Media dos valores de todos os vetores de indice par: %.2lf",  media/j);
    printf("\nProduto dos valores de todos os vetores de indice impar: %.2lf\n",  produto);
}

/* caso de teste
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
*/


