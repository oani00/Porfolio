////////////////////////////////////////////////////
//    Code by: Oaní
////    https://oanispace.blogspot.com
//		Ajuda de: Luiz Miguel
////////////////////////////////////////////////////

////////////para testar: https://repl.it/languages/c

//https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

//A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
	//For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
	//The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 
	//The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. 
	//The number 32 has binary representation 100000 and has no binary gaps.

//Write a function:

//int solution(int N);

//that, given a positive integer N, returns the length of its longest binary gap. 

//The function should return 0 if N doesn't contain a binary gap.
	//For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. 

//Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

//Write an efficient algorithm for the following assumptions:

//N is an integer within the range [1..2,147,483,647].


//usando array

int solution(int N) 
{

  //declarando o array com os valores nulos e outras variaveis
  int binario[99] = {NULL}, intervalo, intervaloAtual, maiorInt, first;
  
  //zerando as variaveis
  maiorInt = 0;
  intervaloAtual = 0;
  intervalo = 0;/
  first = 0;
  
  //converte N em um array com os valores binarios
  for(int i=0;N>0;i++)
    {
        binario[i] = N % 2; 
        N = N/2;
    }
  
  //para cada [i]
  for(int i=0; i<99; i++)
  { 
  	//se for 1 reseta o intervalo
    //e intervalo começa como 0 caso nao tenha um bin. gap.
    if(binario[i] == 1)
      {
        first = 1;
        intervaloAtual = intervalo;
        intervalo = 0;
      }
      
    //se for 0 inicia um intervalo de contagem
    else if(binario[i] == 0)
      {
        //mas para isso o anterior tem que ser 1, caso contrario nao conta como intervalo. 
      	if(first == 1)
         {
           intervalo++;
         }
      }
    
    //estoca apenas o maior intervalo
      if(intervaloAtual > maiorInt)
      {
        maiorInt = intervaloAtual;
      }
  }
  
  //finalmente, retorna o maior intervalo.
  return maiorInt;
}
