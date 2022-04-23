// https://codeshare.io/5zmzq7

//    https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

// A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array 
//can be paired with another element that has the same value, except for one element that is left unpaired.

// For example, in array A such that:
//   A[0] = 9  A[1] = 3  A[2] = 9
//   A[3] = 3  A[4] = 9  A[5] = 7
//   A[6] = 9

//         the elements at indexes 0 and 2 have value 9,
//         the elements at indexes 1 and 3 have value 3,
//         the elements at indexes 4 and 6 have value 9,
//         the element at index 5 has value 7 and is unpaired.

// Write a function:

//     int solution(int A[], int N);

// that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

// For example, given array A such that:
//   A[0] = 9  A[1] = 3  A[2] = 9
//   A[3] = 3  A[4] = 9  A[5] = 7
//   A[6] = 9

// the function should return 7, as explained in the example above.

// Write an efficient algorithm for the following assumptions:
//         N is an odd integer within the range [1..1,000,000];							
//         each element of array A is an integer within the range [1..1,000,000,000];	
//         all but one of the values in A occur an even number of times.


//////////////////////////////////////////

// [13:19, 20/09/2020] Luiz Miguel FATEC: Agr to on
// [13:20, 20/09/2020] Luiz Miguel FATEC: Blz
// [13:20, 20/09/2020] Luiz Miguel FATEC: Vou ver
// [13:23, 20/09/2020] Luiz Miguel FATEC: assim, ele compara os valores a nivel binario e devolve a diferença
// [13:23, 20/09/2020] Luiz Miguel FATEC: ou seja
// [13:24, 20/09/2020] Luiz Miguel FATEC: a ^= b vai sempre retornar 0 caso sejam iguais
// [13:24, 20/09/2020] Luiz Miguel FATEC: ou seja
// [13:24, 20/09/2020] Luiz Miguel FATEC: o que não tiver par
// [13:24, 20/09/2020] Luiz Miguel FATEC: será retornado
// [13:25, 20/09/2020] Luiz Miguel FATEC: https://www.urionlinejudge.com.br/judge/pt/problems/view/1435
// [13:25, 20/09/2020] Luiz Miguel FATEC: esse foi uma hora e pouco pra resolver
// [13:25, 20/09/2020] Luiz Miguel FATEC: asduhaudhas
// [13:37, 20/09/2020] Luiz Miguel FATEC: fiz uns comentarios lá mano
// [13:39, 20/09/2020] Luiz Miguel FATEC: se ta quase lá mano
// [13:40, 20/09/2020] Luiz Miguel FATEC: asudhaushd, o primeiro caso de teste que usei foi
// [13:40, 20/09/2020] Luiz Miguel FATEC: o segundo já falhou
// [13:40, 20/09/2020] Luiz Miguel FATEC: mas o codigo ta funfando, comentei as mudanças
// [13:42, 20/09/2020] Luiz Miguel FATEC: quando quiser fazer uma chamada pra eu explicar isso, eu ajudo
// [13:43, 20/09/2020] Luiz Miguel FATEC: eu consegui resolver uma vez com 70 % no codility seguindo sua logica de ir comparada i com o vetor todo
// [13:43, 20/09/2020] Luiz Miguel FATEC: mas nos casos de teste mais longos onde N = 999.999
// [13:43, 20/09/2020] Luiz Miguel FATEC: ele falha no teste de tempo
// [13:43, 20/09/2020] Luiz Miguel FATEC: dai só com esse XOR eu consegui 100%
// [13:43, 20/09/2020] Luiz Miguel FATEC: pq ele simplifica o codigo pra krl
// [13:44, 20/09/2020] Luiz Miguel FATEC: com um loop
// [13:44, 20/09/2020] Luiz Miguel FATEC: somente 1
// [13:44, 20/09/2020] Luiz Miguel FATEC: vc termina isso
// [13:44, 20/09/2020] Luiz Miguel FATEC: minha função tem 4 linha


//////////////////////////////////////////





#include <stdio.h>

int solution(int A[], int N){
	
  int i, j, k, result = 99;
  printf("aaaaaaaaaaaaaaaaaa\n");
	
  //a ideia é: jjjjjikkkkkkkkk
  //comparar i com todos os anteriores e posteriores
  //se i for diferente dos dois, result = A[i]
  //era para isso dar o unico diferente nao?
    //Luiz -> vc não declarou o tamanho de N no main, que é um parametro pra função, 
    //quando o primeiro 'for' usando o 'i' como contador compara com < n, vai dar falso 
    //pois N é nulo, não existe valor. Por isso o loop não se inicia. Vou declarar o N lá no inicio.

    for (i=0; i < N; i++){
      printf("loooooop\n");
        for (j=0; j < i; j++){
          for (k=i+1; k < N; k++){
            if (A[i] != A[j] && A[i] != A[k]){
            result = A[i];
            //printf("result = %d\n", result);}
          }
        }
      }
    }

  printf("Rodou--------------------\n");
  printf("%d", result);
  printf("\n");
  printf("Rodou--------------------\n");

  return 0;

}


int main(){


  //////////////////parte fornecida pelo codi.//////////////////

  //n sao os elementos de a[]
  int A[1000000], N ;
  N = 7; 	// tamanho do vetor A, quando for testar, lembre se que sempre vai ter  n-1 pares, e que sempre N é ímpar, 
  				//então, pode testar com 2 2 3 3 4, ou 3 3 1, ou 3 2 3 2 5 3 2

  //teste
  A[0] = 9,  A[1] = 3,  A[2] = 9;
  A[3] = 3,  A[4] = 9,  A[5] = 7;
  A[6] = 9;

  //////////////////parte fornecida pelo codi.//////////////////

  solution(A, N);

  return 0;
}