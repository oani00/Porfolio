// 8. Use a função da questão passada e lance o dado 1 milhão de vezes. Conte quantas vezes cada número saiu.
      // A probabilidade deu certo? Ou seja, a porcentagem dos números foi parecida?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Dado(){

	int n;

	//esse printf demora muito
	//printf("Vou rolar um dado virtual aqui e te retornar um número entre 1 e 6 totalmente aleatorio! (na verdade pseudo-aleatorio)\n");

	n = rand() % 7;

    //hidem
	//printf("Seu número é: %d\n", n);

return n;
}

int main(){

	int i,d,num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
	float numTot = 0, visao;

	srand(time(NULL));

	for (i = 0;i < 1000000;i ++){

	    d = Dado();

	    //contando cada ocorrencia
	    if (d == 1)
            num1 ++;
        if (d == 2)
            num2 ++;
        if (d == 3)
            num3 ++;
        if (d == 4)
            num4 ++;
        if (d == 5)
            num5 ++;
        if (d == 6)
            num6 ++;
	}

	//somando tudo para porcentagem
	numTot = num1 + num2 + num3 + num4 + num5 + num6;

	printf("Olha joguei esse negocio 1M vezes! Olha quanto saiu de cada numero:\n 1 - %d\n 2 - %d\n 3 - %d\n 4 - %d\n 5 - %d\n 6 - %d\n", num1, num2, num3, num4, num5, num6);
    printf("\nDeu muito numero! E a proporcao de cada um eh esta: \n 1 - %.6f %%%\n 2 - %.6f %%%\n 3 - %.6f %%%\n 4 - %.6f %%%\n 5 - %.6f %%%\n 6 - %.6f %%%\n", num1/numTot, num2/numTot, num3/numTot, num4/numTot, num5/numTot, num6/numTot);

  return 0;
}
