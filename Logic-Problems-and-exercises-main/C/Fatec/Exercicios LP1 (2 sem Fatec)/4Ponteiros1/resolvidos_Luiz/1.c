/*
1.Escreva um programa que declare um inteiro, um real e um char,
    e ponteiros para inteiro, real, e char. Associe as variaveis
    aos ponteiros (use &).
   Modifique os valores de cada variavel usando os ponteiros.
   Imprima os valores das variáveis antes e após a modificação.
*/
#include <stdio.h>

int main(){

    int inteiro, *ptrInt;
    float Real, *ptrReal;
    char Char, *ptrChar;

    inteiro = 10;
    Real = 10.5;
    Char = 'D';

    ptrInt = &inteiro;
    ptrReal = &Real;
    ptrChar = &Char;

    printf("Valor do ponteiro inteiro: %d\nValor do ponteiro Real: %.1f\nValor do ponteiro Char: %c\n", *ptrInt, *ptrReal, *ptrChar);

    *ptrInt = 11;
    *ptrReal = 11.5;
    *ptrChar = 'E';

    printf("\nApos modificar\n\n");

    printf("Valor do ponteiro inteiro: %d\nValor do ponteiro Real: %.1f\nValor do ponteiro Char: %c\n", *ptrInt, *ptrReal, *ptrChar);
    return 0;
}
