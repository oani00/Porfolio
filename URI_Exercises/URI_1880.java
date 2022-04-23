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

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1880

Pseudo:

   scanf (n)
      for até n
         scanf numero
         for i de 2 ate 16
            while (n > 0)
               dividir numero por i
               resto divisao por i
               colocar em um v[i]
            for i até 0 i--
               if v[i] == 10 
                  print A
               else v[i] == 11
                  print B
               ...
               else
                  print v[i]

	Nao coloquei a logica dos espaços " "... mas tem que ter.


Solucao: https://www.life2coding.com/uri-online-judge-solution-1880-renzo-and-the-palindromic-decoration-intermediate-problem/
*/

int palindrome(int n, int b) //numero e base
{
	char ret[35];
	int tam = 0;
	int i;
	i = 0;
	
	while (n)
	{
		int resto = n % b;
		if (resto <= 9)
			ret[i++] = resto + '0'; 
		else ret[i++] = resto - 10 + 'a';
			n /= b;
		
		tam++;
	}
	
	ret[tam] = '\0';

	for (int k = 0, j = tam - 1; k < j; ++k, --j) //checa o palindromo
		if (ret[j] != ret[k]) return 0;
	
	return 1;	
}


int main()
{
	int cases;
	int flag;
	int n;

	scanf("%i", &cases);

	while (cases--){
		
		scanf("%i", &n);
		flag = 0;

		for (int i = 2; i <= 16; ++i)
		{
			if (palindrome(n, i))
			{
				if (flag) printf(" ");
				
				printf("%i", i);
				flag = 1;
			}
		}
		if (!flag) printf("-1");
		printf("\n");
    
	}

	return 0;
}


/* ------------------ O R I G I N A L ------------------ 

int palindrome(int n, int b)
{
	char ret[35];
	int tam = 0;
	int auxn = n;
	int i;
	i = 0;
	
	while (n)
	{
		int resto = n % b;
		if (resto <= 9)
			ret[i++] = resto + '0';
		else ret[i++] = resto - 10 + 'a';
			n /= b;
		
		tam++;
	}
	
	ret[tam] =  '\0';

	for (int k = 0, j = tam - 1; k < j; ++k, --j)
		if (ret[j] != ret[k]) return 0;
	
	return 1;	
}


int main()
{
	int cases;
	int flag;
	int n;

	cin >> cases;

	while (cases--)
	{
		cin >> n;
		flag = 0;
		for (int i = 2; i <= 16; ++i)
		{
			if (palindrome(n, i))
			{
				if (flag) cout << ' ' ;
				cout << i;
				flag = 1;
			}
		}
		if (!flag) cout << -1;
		cout << '\n';
	}

	return 0;
} */ 