#include <stdio.h>

// Tópico aula - ponteiros para ponteiros

int main(){

    int   valor = 10, x; //int - 4 bytes
    int  *ptr1; //ponteiro
    int **ptr2; //ponteiro para ponteiro

    ptr1 = &valor;
    ptr2 = &ptr1;

    printf("Conteudo de valor = %d\n", valor);
    printf("Endereco de valor = %d\n\n", &valor);

    printf("Conteudo do endereco de ptr1 = %d\n", *ptr1);
    printf("Endereco que ptr1 armazena = %d\n", ptr1);
    printf("Endereco de ptr1 = %d\n\n", &ptr1);

    printf("Conteudo do endereco de ptr2 = %d\n", **ptr2);
    printf("Endereco que ptr2 armazena = %d\n", ptr2);
    printf("Endereco de ptr2 = %d\n", &ptr2);

    return 0;
}