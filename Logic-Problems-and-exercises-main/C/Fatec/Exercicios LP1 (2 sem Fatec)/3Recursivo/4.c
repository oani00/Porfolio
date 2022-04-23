/*
4.       
O máximo divisor comum dos inteiros x e y é o maior inteiro que é divisível por x e y. 
-Escreva uma função recursiva mdc em C, que retorna o máximo divisor comum de x e y. 
O mdc de x e y é definido como segue: 
  se y é igual a 0, então mdc(x,y) é x; 
  caso contrário, mdc(x,y) é mdc (y, x%y), 
  onde % é o operador resto.

  http://www.matematicadidatica.com.br/CalculadoraMMCMDC.aspx

*/

int mdc(int x, int y);

int main(){

  int x, y, MDC;
   x = 16;
   y = 24;

  MDC = mdc(x,y);
  printf("%d", MDC);
  return 0;
}

int mdc(int x, int y){
    if(y == 0){
        return x;
    } else {
        return mdc(y, x%y);
    }
}