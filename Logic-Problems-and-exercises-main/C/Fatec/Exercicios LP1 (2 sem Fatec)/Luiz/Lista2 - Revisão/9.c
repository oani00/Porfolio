#include <stdio.h>
#define TAM 10

int main(){

    int vetorA[TAM], vetorA1[TAM] = {NULL}, vetorA2[TAM] = {NULL}, i, p, imp;
    p = 0;
    imp = 0;
    for ( i = 0; i < TAM; i++){
        printf("Insira um valor: ");
        scanf("%d", &vetorA[i]);

    }
    for(i = 0; i < TAM; i++){
        if(vetorA[i] % 2 == 1){
            vetorA1[imp] = vetorA[i];
            imp++;
        }
        else{
            vetorA2[p] = vetorA[i];
            p++;
        }
    }
    printf("\n");
    for(i = 0; i < TAM; i++){
        if(vetorA1[i] != NULL){
            printf("A1[%d] = %d | ", i,vetorA1[i]);
        }
        if(vetorA2[i] != NULL) {
            printf("A2[%d] = %d\n", i,vetorA2[i]);
        }

    }
}



/* Testes de caso

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
*/

