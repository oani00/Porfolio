//3.       Crie um programa em C que receba um vetor de números reais com 100 elementos. 
//			Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.*/

#include <stdio.h>
#define TAM 100

double vetorReverso(double vetor[], int pos);

int main(){
  
  double vet[TAM];
  int tamvetor = TAM-1;
  
  for(int i =0; i < TAM; i++){
    printf("Digite um numero para o vetor(de 0 a %d)", TAM);
    scanf("%lf", &vet[i]);
  }
  vetorReverso(vet,tamvetor);
  return 0;
}

double vetorReverso(double vetor[], int pos){
  printf("\n%.2lf", vetor[pos]);
  if(pos == 0){
    return 0;
  }
  else{
    return vetorReverso(vetor, pos-1);
  }
}


/*

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