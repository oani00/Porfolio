/*
    5.Elabore uma função que receba duas strings como parâmetros
    e verifique se a segunda string ocorre dentro da primeira.
    Use aritmética de ponteiros para acessar os caracteres  ́das strings.
*/
#include <stdio.h>
#define TAM 100

void VerificaOcorrencia(char *ptr1, char *ptr2);

int main(){

    char string1[TAM] = "Aula de Linguagem de Programacao", string2[TAM] = "Linguagem";
    VerificaOcorrencia(string1, string2);
    return 0;
}

void VerificaOcorrencia(char *ptr1, char *ptr2){

    int contador, Freq = 0;
    char ocorre[TAM];
    for(int i = 0; *(ptr1+i) != '\0'; i++){
        contador = 0;
        if(*(ptr1+i) == *(ptr2+contador)){
            Freq = i + 1;
            while(*(ptr1+i) == *(ptr2+contador)){
                ocorre[contador] = *(ptr1+i);
                i++;
                contador++;
            }
            if(*(ptr2+contador) == '\0'){
                printf("A segunda string ocorre na primeira, Parabens: %s\n", ocorre);
            }
            else{
                i = Freq;
                Freq = 0;
            }

        }
    }
    if(Freq == 0) printf("A segunda string nao ocorre na primeira, Desculpe\n");
}
