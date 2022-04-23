// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

//███████╗ █████╗ ████████╗███████╗ ██████╗ 
//██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔════╝ 
//█████╗  ███████║   ██║   █████╗  ██║      
//██╔══╝  ██╔══██║   ██║   ██╔══╝  ██║      
//██║     ██║  ██║   ██║   ███████╗╚██████╗ Sorocaba
//╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚══════╝ ╚═════╝ José Crespo Gonzales


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc URI_1068_C.c -o ~/testeC.exe -lm -Wextra && ~/testeC.exe

Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. Por exemplo:

a+(b*c)-2-a        está correto
(a+b*(2-c)-2+a)*2  está correto

enquanto

(a*b-(2+c)         está incorreto
2*(3-a))           está incorreto
)3+b*(2-c)(        está incorreto

Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.
Entrada

Como entrada, haverá N expressões (1 <= N <= 10000), cada uma delas com até 1000 caracteres.
Saída

O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras correct ou incorrect de acordo com as regras acima fornecidas.
Exemplo de Entrada 	Exemplo de Saída

a+(b*c)-2-a 
(a+b*(2-c)-2+a)*2 
(a*b-(2+c) 
2*(3-a))  
)3+b*(2-c)( 
	
correct
correct
incorrect
incorrect
incorrect
*/

//Resposta do site https://www.life2coding.com/uri-online-judge-solution-1068-parenthesis-balance-i-intermediate-problem/

//Cara olha que fantastico o jeito deles. Não tem que fazer uma stack e ir empilhando e desemplilhando, só tem que fazer
//duas "stacks" e comparar os tamanhos! E o legal é que nem tem qeu fazer as stacks, A MATEMATICA JA FAZ ISSO!!!
//é so acrescentar o esquerda e direita. Genial.

int main(){
    
	char linha[1001];
    int i,esq, dir;
    
	while(scanf("%s",&linha) != EOF){
       esq = 0;
       dir = 0;
       
		for(i = 0; linha[i] != '\0'; i++){
			if(linha[i] == '(') esq++;
			else if (linha[i] == ')'){
				
				dir++;

				if(esq > 0){
					esq--;
					dir--;
				}
			}
		}
       
	   if(esq == 0 && dir == 0) printf("correct\n");
       else printf("incorrect\n");
    }
    return 0;
}


/*
//stack do site https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm

	int MAXSIZE = 10005;       
	char stack[10005];     
	int top = -1;            

	int isempty() {

		if(top == -1)
			return 1;
		else
			return 0;
	}
	
	int isfull() {

	if(top == MAXSIZE)
		return 1;
	else
		return 0;
	}

	int peek() {
	return stack[top];
	}

	int pop() {
		int data;
			
		if(!isempty()) {
			data = stack[top];
			top = top - 1;   
			return data;
		} 
		else {
			//printf("Could not retrieve data, Stack is empty.\n");
			return 0;			
		}
	}

	int push(char data) {

		if(!isfull()) {
			top = top + 1;   
			stack[top] = data;
		} else {
			printf("Could not insert data, Stack is full.\n");
		}
	}


int main(){
	
	char entrada[1005];
	int saida;
	
	while (scanf("%s",entrada) != EOF)
	{

		int i = 0;
		
		while (entrada[i] != '\0'){

			if (entrada[i] == '(' )
			{
				push('(');
			}
			
			if(entrada[i] == ')')
			{
				if (pop() == 0)
				{
					saida = 1;
					break;
				}
				
			}
			
			i++;
		}

		if (isempty() == 1)
		{
			if (saida != 1)
			{
				printf("correct\n");
			}else{
				printf("incorrect\n");
			}
			
		}else	
			printf("incorrect\n");

	}
	
	return 0;
}
*/