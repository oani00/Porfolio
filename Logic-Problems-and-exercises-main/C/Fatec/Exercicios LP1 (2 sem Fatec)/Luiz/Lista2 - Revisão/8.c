#include <stdio.h>
#define TAM 6
#define TAM2 10

int main(){

    int vetorA[TAM], vetorB[TAM2], i, j, acertos, rep;
    acertos = 0;
    rep = 0;
    for ( i = 0; i < TAM; i++){
        printf("Insira os valores sorteados na mega sena (01 - 60): ");
        scanf("%d", &vetorA[i]);

    }
    printf("\n");
    for(i = 0; i < TAM2; i++){
        printf("Insira os dez valores contidos na sua aposta (01 - 60): ");
        scanf("%d", &vetorB[i]);
    }
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM2; j++){
            if(vetorA[i] == vetorB[j] && rep == 0){
                acertos++;
                rep++;
            }
        }
        rep = 0;
    }
    switch(acertos){
    case 6:
        printf("Parabens! voce acertou a sena (6 pontos)\n");
        break;
    case 5:
        printf("Parabens! voce acertou a quina (5 pontos)\n");
        break;
    case 4:
        printf("Parabens! voce acertou a quadra (4 pontos)\n");
        break;
    default:
        printf("voce acertou %d pontos\n", acertos);
        break;

    }
}


/*Testes de caso

01
05
04
40
50
08

*/
