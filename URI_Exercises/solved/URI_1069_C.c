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


*/

//Resposta do site https://www.life2coding.com/uri-online-judge-solution-1068-parenthesis-balance-i-intermediate-problem/
//Esse exercicio é analogo. Uma pilha de
/*

<
<
<
< >     = 1 diamante            Nem precisa fazer uma pilha de verdade 

mas nao pode deixar >>><<< fazer 3 diamantes. 

alias: https://www.life2coding.com/uri-online-judge-solution-1069-diamonds-and-sand-intermediate-problem/
*/

int main(){
    
	int n, j, esq, dir;
    char linha[1001];
    
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
		scanf("%s",&linha);
		dir = 0;
		j = 0;
		esq = 0;
		dir = 0;

		while(1){
			if(linha[j] == '\0') break;
			if(linha[j] == '<') esq++;
			if(linha[j] == '>'){
				if(esq > 0){
					dir++;
					esq--; //Cara olha que legal. < blz, << blz, > fica <> mas se entrar > fica >>, mas olha que sacada
							//a quantidade de >> indica quantos diamantes foram formados!
				}
			}
			j++;
		}
		printf("%d\n", dir);
    }
      
    return 0;
}