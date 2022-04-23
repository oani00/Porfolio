//https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

//A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array 
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


#include <stdio.h>

int solution(int A[], int N){
	
  int i, j, k, result = 99;
	
  //a ideia é: jjjjjikkkkkkkkk
  //comparar i com todos os anteriores e posteriores
  //se i for diferente dos dois, result = A[i]
  //era para isso dar o unico diferente nao?
    //Luiz -> vc não declarou o tamanho de N no main, que é um parametro pra função, 
    //quando o primeiro 'for' usando o 'i' como contador compara com < n, vai dar falso 
    //pois N é nulo, não existe valor. Por isso o loop não se inicia. Vou declarar o N lá no inicio.

    for (i=0; i < N; i++){
        for (j=0; j < i; j++){
          for (k=i+1; k < N; k++){
            if (A[i] != A[j] && A[i] != A[k]){
            result = A[i];
            //printf("result = %d\n", result);}
          }
        }
      }
    }

  printf("%d", result);
  printf("\n");

  return 0;
}


int main(){


  //n sao os elementos de a[]
  int A[1000000], N ;
  //N = 7; 	
	// tamanho do vetor A, quando for testar, lembre se que sempre vai ter  n-1 pares, e que sempre N é ímpar, 
	//então, pode testar com 2 2 3 3 4, ou 3 3 1, ou 3 2 3 2 5 3 2

/* 
  teste
  
  A[0] = 9,  A[1] = 3,  A[2] = 9;
  A[3] = 3,  A[4] = 9,  A[5] = 7;
  A[6] = 9;
*/

  solution(A, N);

  return 0;
}