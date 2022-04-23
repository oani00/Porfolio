//1.       Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 – 321.

#include <stdio.h>

int inverte(int n);

int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    inverte(numero);
}

int inverte(int n){

    if(n == 0){
        return n;
    } else {
        printf("%d", n%10);
        n = n /10;
        return inverte(n);
    }
}
