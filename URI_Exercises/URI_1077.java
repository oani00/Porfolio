/* 
 ▄▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄    ▄ ▄▄▄ 
█       █      █  █  █ █   █
█   ▄   █  ▄   █   █▄█ █   █
█  █ █  █ █▄█  █       █   █
█  █▄█  █      █  ▄    █   █
█       █  ▄   █ █ █   █   █
█▄▄▄▄▄▄▄█▄█ █▄▄█▄█  █▄▄█▄▄▄█


clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 2590.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe

https://www.urionlinejudge.com.br/judge/pt/problems/view/1077

Pseudo: 

Acho que é assim:

(2*4/a^b)/(2*c) Pilha:  Final:
(24/a^b)/(2*c) Pilha:*  Final:
(/a^b)/(2*c) Pilha:  Final: 24*
(ab)/(2*c) Pilha:/^  Final: 24*
/(2*c) Pilha:  Final: 24*ab^/
(2c) Pilha:/*  Final: 24*ab^/
Pilha:  Final: 24*ab^/2c* /

repte esse laço|empila o que nao for numero e desempilha antes de um /
               |ai empilha o / e o que nao for numero
               |ai solta


Blz agora vamos comparar com o pseudo só que correto: https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression

Begin
   initially push some special character say # into the stack
   for each character ch from infix expression, do
      if ch is alphanumeric character, then
         add ch to postfix expression
      else if ch = opening parenthesis (, then
         push ( into stack
      else if ch = ^, then            //exponential operator of higher precedence //Pelo que vi das duas soluções abaixo elas colocam 3 niveis de precedencia, mas parece que não precisa.
         push ^ into the stack
      else if ch = closing parenthesis ), then
         while stack is not empty and stack top ≠ (,              | Não sabia dessa parte...              
            do pop and add item from stack to postfix expression  |                          
         done                                                     |      
                                                                  
         pop ( also from the stack                                          
      else
         while stack is not empty AND precedence of ch <= precedence of stack top element, do
            pop and add into postfix expression
         done

         push the newly coming character.
   done

   while the stack contains some remaining characters, do
      pop and add to the postfix expression
   done
   return postfix
End



Solucao que gostei mais: https://github.com/ridneto/Uri-Online-Judge/blob/master/Estrutura/URI_1077%20-%20(5620147)%20-%20Accepted.c

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 600 //nao era para ser 1001? Enfim URIsses, as vezes passando ta bom... Odeio isso até o osso...
#define VAZIA -1

typedef struct{char vetor[MAX]; int topo;}Pilha; //achei meio desnecessario fazer uma struct que tem a propria pilha (um array)
                                                 //dentro... eu faria um array direto mas blz. mas a graça é fazer do seu jeito acho.

void push(Pilha *, char);
void pop(Pilha *);
void zera(Pilha *);

int GrauOpr(char);
int EhOpr(char);
char opr[7] = {'+','-','*','/','^','(',')'}; //cara fazer um array de op e um array de precedencia foi interessante 
int grau[7] = { 1 , 1 , 2 , 2 , 3 , 0 , 4};  //hummmm pelo jeito usou a precedendia para decidir algo sobre empilhar. Considerando
                                             // que essa é a porcaria do C melhor comparar com um int do que com um char. Inteligente.
                                             // Fun fact que acabei de pensar. Poderia comparar com o numero ascii do char... Ai C, como te odeio.
int main(){	
	int i, n;
	char expr[MAX];
	Pilha p;
	
	scanf("%d", &n);

	while(n--){
		zera(&p);
		scanf("%s", expr);
		for(i=0; expr[i] != '\0'; i++){
			if(!EhOpr(expr[i]))
				printf("%c", expr[i]);
			else
				if(p.topo == VAZIA)
					push(&p, expr[i]);
				else
					if(expr[i] == ')'){
						while(p.vetor[p.topo] != '('){
							printf("%c", p.vetor[p.topo]);
							pop(&p);
						}
						pop(&p);
					}else{						
						while(GrauOpr(p.vetor[p.topo]) >= GrauOpr(expr[i])){
							if(expr[i] == '(')
								break;
							printf("%c", p.vetor[p.topo]);
							pop(&p);
							if(p.topo == VAZIA)
								break;
						}
						push(&p, expr[i]);
					}
		}					
		while(p.topo != VAZIA){			
			printf("%c", p.vetor[p.topo]);
			pop(&p);
		}		
		printf("\n");
	}
	
	return 0;
}

int GrauOpr(char c){
	int i;
	for(i=0;;i++)
		if(opr[i] == c)
			return grau[i];
}

int EhOpr(char c){
	int i;
	for(i=0;i<7;i++)
		if(opr[i] == c)
			return 1;
	return 0;	
}

void zera(Pilha *p){
	p->topo = VAZIA;
}

void push(Pilha *p, char operador){
	p->vetor[++p->topo] = operador;
}

void pop(Pilha *p){
	p->topo--;
}





/*
Essa solução eu gostei um pouco menos por não usar pilha e ser mais chatinha de interpretar, mas sla, coloquei para comparar.


//http://muitomaiscodigoss.blogspot.com/2018/08/uri-problema-1077-infixa-para-posfixa.html


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_SIZE 1024

int prec(char operator);

void paraPosfixa(const char *exp, char *out);

int main (void) {
    int N;

    char infixa[EXP_MAX_SIZE], posfixa[EXP_MAX_SIZE];

    scanf("%d\n", &N);

    while (N-- > 0) {

        fgets(infixa, EXP_MAX_SIZE, stdin); //interessante como da p fazera mesma coisa de mil jeitos... olha essa main
        paraPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);

    }

    return EXIT_SUCCESS;

}




void paraPosfixa(const char *exp, char *out) {

    char p[EXP_MAX_SIZE];
    int i, o = 0, t = -1;
    char c;

    for (i = 0; exp[i] != '\n' && exp[i] != '\0'; i++) {

        c = exp[i];
        if (c == ' ') continue;

        if (c == '(') {
            p[++t] = c;
        }

        else if (c == ')') {

            while (t > -1 && p[t] != '(') {
                out[o++] = p[t--];
            }

            t--;
        }

        else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {

            out[o++] = c;

        }

        else {

            while (t > -1 && p[t] != '(' && prec(p[t]) >= prec(c)) {

            out[o++] = p[t--];

            }

            p[++t] = c;
        }

    }

    while (t > -1) out[o++] = p[t--];
    out[o++] = '\0';

}




int prec(char operator) {

switch (operator) {

case '^':

return 3;

case '*':

return 2;

case '/':

return 2;

case '+':

return 1;

case '-':

return 1;

default:

return 0;

}

}

*/