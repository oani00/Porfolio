// 7. Crie uma função em linguagem C chamado Dado() que retorna, através de sorteio, um número de 1 até 6. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//http://linguagemc.com.br/valores-aleatorios-em-c-com-a-funcao-rand/
//https://stackoverflow.com/questions/9711076/why-does-rand-always-return-the-same-value

int Dado(){

	int n;
	
	printf("Vou rolar um dado virtual aqui e te retornar um número entre 1 e 6 totalmente aleatorio! (na verdade pseudo-aleatorio)\n");
	
	srand(time(NULL));
  n = rand() % 6;
		
	printf("Seu número é: %d\n", n);

return n;
}

int main(){

	Dado();
   
  return 0;
}