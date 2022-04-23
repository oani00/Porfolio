/*

Joãozinho está aprendendo a somar frações na escola e quer sua ajuda para escrever um programa que dadas duas frações 
imprima a soma delas em sua forma irredutível. Assim ele vai poder conferir as respostas dos exercícios que está fazendo.

A forma irredutível de uma fração é quando o divisor (número de baixo) é o menor possível. Por exemplo, 10⁄3 é uma fração 
irredutível, pois 10 e 3 não têm nenhum divisor em comum. Mas 10⁄6 não é, pois ela pode ser simplificada para 5⁄3, 
dividindo-se 10 e 6 por 2.

Dados quatro inteiros a, b, c, d, escreva um programa que calcule a⁄b + c⁄d na sua forma irredutível.
Entrada

A única linha da entrada contém quatro inteiros a, b, c, d, (1 ≤ a, b, c, d ≤ 100) respectivamente dividendo e divisor 
da primeira fração e dividendo e divisor da segunda fração.
Saída

Seu programa deve imprimir uma única linha contendo dois inteiros, dividendo e divisor da fração irredutível formada 
pela soma das duas frações dadas.
Exemplos de Entrada 	Exemplos de Saída

2 3 7 3         3 1

7 5 3 2         29 10

//duvidas de cosinnhas
https://github.com/malbolgee/URI

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Algoritmo de Euclides iterativo https://www.blogcyberini.com/2018/03/algoritmo-para-calcular-o-mmc.html
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{								
	
	//a + c = x 
	//-   -   -
	//b   d   y

	int a, b, c, d, x, y;

	scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	scanf("%i", &d);

	x = a*d + c*b;
	y = b*d;

	//printf("x= %i \n", x);
  //printf("y= %i \n", y);

  int min = mdc(x,y);

  //printf("mmc= %i \n", min);
  
  x = x/min;
	y = y/min;

	printf("%i %i\n", x, y);

	return 0;
}