#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

////////////////////////////////////////////////////
//		Code by: oani00
//		Help: LUIZZZZZZZZZZZZZZ
//		https://oanispace.blogspot.com
////////////////////////////////////////////////////

//https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

//A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
//For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
//The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
//The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
 //The number 32 has binary representation 100000 and has no binary gaps.

//Write a function:

//int solution(int N);

//that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
//For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.
//Write an efficient algorithm for the following assumptions:
//N is an integer within the range [1..2,147,483,647].




////////////////////////primeiro fiz as funcoes para depois chama-las no main()
int conversor (int x)
    {
        //De alguma forma tem que pegar o input N

        //adaptado daqui: https://www.javatpoint.com/c-program-to-convert-decimal-to-binary

        //aqui eu que coloquei. Sei la, 99 parece grande
        int binario[99], i;

        for(i=0;x>0;i++)
        {
            binario[i]=N%2;
            x=x/2
        }

        //precisa retornar esse vetor
        return binario[99];
    }

int contagemdezeros(int c);
{

  //cria o array que contera a contagem
  int contagemDezeros[99],i;j;

  //inicia com o j na posicao 0 do array contagemDezeros[]
  j = 0;

    for (i=0;i<100;i++)// Luiz: i<99? se a intenção é ir incrementando o 1 até 99, coloque i<99<-------- OK
    {
        if binario[i] = 0
            contagemDezeros[j] + 1;
        else binario[i] = 1
            j + 1;

        // para
        // 11000101
        // isso vai outputar
        // 003010

    }

  	return contagemDezeros[99];

}



int solution (int N)
    {

    //o input N da solution tem que entrar nesse conversor
    int conversor (N);

    //Conta quantos 0s tem em sequencia e forma um array
    int contagemdezeros(binario[99]);

    int i;

	//=====================
  // sort do array aqui ?????????
  //=====================


  //=====================
  // testes logicos
  //=====================

	//finalmente este r deve ser o maior grupo de 0s
	return r
	}


/////////////////////////aqui vem o main principal////////////////////////////////
void main(){

    //declara N
    int N;

    //pede o valor de N
    scanf(%d, &N)

    //chama a funcao solution
    //que chamara as outras funcoes dentro dela
    int solution (int N)

    //outputa o resultado
    printf("%i", r)

    //pausando o sistema
    system("pause");

}
