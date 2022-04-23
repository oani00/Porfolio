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

clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc URI_1367_C.c -o ~/testeC.exe -lm -Wextra && ~/testeC.exe

-----------------------------------------------------------------------------

Então, nós temos que admitir: precisamos da sua ajuda. 
Esse ano as coisas não estao correndo tão tranquilamente quanto queríamos, e nós não conseguimos finalizar 
o sistema do software da competição a tempo. Uma parte vital está faltando, e como você sabe, nós precisamos
desse sistema funcionando até essa tarde, para a verdadeira competição. A parte que está faltando é a que 
computa a pontuação dos times, dada a lista de submissões desse time.

Por favor, por favor, alguém nos ajude!

Entrada

A entrada contém vários casos de teste. A primeira linha de caso de teste contém um único inteiro N indicando 
o número de submissões do caso de teste (1 ≤ N ≤ 300). 
Cada uma das N linhas seguintes descrevem uma 
submissão; 
cada uma dessas linhas contém um identificador de problema (uma única letra entre 'A' e 'Z'),
seguida por um inteiro T representando o tempo em minutos (0 ≤ T ≤ 300), seguido por um julgamento 
(a palavra "correct", correto, ou a palavra "incorrect", incorreto).

A entrada está em ordem crescente de tempo, e haverá no máximo um julgamento "correct" para cada problema. 
O final da entrada é indicado por N = 0. A entrada deve ser lida da entrada padrão.

Saída

Para cada caso de teste a entrada do seu programa deve imprimir uma linha contendo dois inteiros S e P, 
separados por um espaço, onde 

S é o número de problemas distintos com o julgamento "correct" e 

P é o tempo no qual cada problema distinto foi julgado pela primeira vez como "correct", 
	somado a 20 para cada julgamento "incorrect" recebido nesse problema (desde que no final o problema tenha sido julgado como "correct"). 

A saída deve ser escrita na saída padrão.


Exemplo de Entrada 	

3						0 0
A 120 incorrect			3 431
A 130 incorrect
A 200 incorrect
5
A 100 correct
B 110 incorrect
B 111 correct
C 200 correct
D 300 incorrect
0

---------------------------------------------------------------------------------------*/

//http://muitomaiscodigoss.blogspot.com/2018/04/uri-problema-1367-ajude-solucao.html


#include <stdio.h>
#include <string.h>

int main()
{
    int N, time;
    char id, verdict[10], buffer[100];
    int i, j, incorrectCounts[26], correctTimes[26], correctCount, finalTime;

    while (1) {
        scanf("%d", &N);
        getchar();
        if (!N)
            break;

        memset(correctTimes, 0, sizeof(correctTimes));
        memset(incorrectCounts, 0, sizeof(incorrectCounts));
        correctCount = 0;
        finalTime = 0;

        for (i = 0; i < N; ++i) {
            fgets(buffer, 100, stdin);
            sscanf(buffer, "%c%d%s", &id, &time, verdict);

            j = id - 'A';
            if (verdict[0] == 'c') {
                ++correctCount;
                finalTime += time;
                correctTimes[j] = time;
            } else
                ++incorrectCounts[j];
        }

        for (j = 0; j < 26; ++j) {
            if (correctTimes[j] > 0)
                finalTime += incorrectCounts[j] * 20;
        }

        printf("%d %d\n", correctCount, finalTime);
    }

    return 0;
}

/*--------------------------------- Solucao antiga dando seg. fault ---------------------


typedef struct s
{
	char identificador;
	int T;
	char julgamento[10];
} submissao;

int main(){

	int N, S, P;

	while (scanf("%i", &N))
	{
		
		if (N == 0)
		{
			break;
		}
				
		submissao conjunto[N];
		char identificadorescorrect[N];
				
		for (int i = 0; i < N; i++)
		{
			// printf("i = %i", i);
			scanf("%c %i %s", &conjunto[i].identificador, &conjunto[i].T, conjunto[i].julgamento);
		}
		
		for (int i = 0; i < N; i++){
			if (strcmp(conjunto[i].julgamento, "correct") == 0 )
			{
				for (int j = 0; j < i; j++)
				{
					if (conjunto[i].identificador == identificadorescorrect[j])
					{
						break;
					}
					else
					{
						S++;
						P = P + conjunto[i].T;
						identificadorescorrect[i] = conjunto[i].identificador;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) //se essa fosse uma linguagem de gente usaria um "foreach correct"
		{
			for (int j = 0; j < N; i++)
			{
				if (identificadorescorrect[i] == conjunto[j].identificador)
				{
					if (strcmp(conjunto[j].julgamento, "incorrect") == 0)
					{
						P = P+20;
					}
				}
			}
		}

		printf("%i %i\n", S, P);
	}
	
	return 0;
}*/