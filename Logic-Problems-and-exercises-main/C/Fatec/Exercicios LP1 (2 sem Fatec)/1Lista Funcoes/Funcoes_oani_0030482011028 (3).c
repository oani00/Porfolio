// 3. Crie uma função que receba três valores, 'a', 'b' e 'c', que são os coeficientes de uma equação do segundo grau e retorne o valor do delta, que é dado por 'b² - 4ac' 3. 

// Usando as 2 funções acima, crie um aplicativo que calcula as raízes de uma equação do 2o grau: ax² + bx + c=0. 
	// -Para ela existir, o coeficiente 'a' deve ser diferente de zero. 
	// -Caso o delta seja maior ou igual a zero, as raízes serão reais. 
	// -Caso o delta seja negativo imprimir "Erro"

		////Sobre raizes complexas no C
		//https://www.gnu.org/software/libc/manual/html_node/Complex-Numbers.html#:~:text=ISO%20C99%20introduces%20support%20for%20complex%20numbers%20in%20C.&text=It%20is%20a%20keyword%20if,complex%20%2C%20and%20long%20double%20complex%20.
			//teste
			//https://www.mathsisfun.com/quadratic-equation-solver.html

#include <stdio.h>
#include <math.h>

//calculo do delta
double delta(double a, double b, double c){
  
  double d;
  d = b*b - 4*a*c;

  printf("O valor do delta é %f \n", d);
  
  return d;
}

//função do ex 1, adaptada
double checapositivo(double d){

  int sinal;

  //o valor de delta sera checado aqui pela funcao anterior

  if (d >= 0){
    sinal = 0;
    printf("d é positivo =D (ou 0) \n");}
  else if (d < 0){
    sinal = 1;
    printf("d é negativo = / (as raizes serao complexas(na verdade nem vou apresenta-las para você XD ))\n\n");}
  
  return sinal;
}

//função do ex 2, adaptada
int checanulo(double a){

  int ehnulo;
  
  if (a == 0){
    ehnulo = 1;
    printf(" e o A é nulo\n");}
  else if (a != 0){
    ehnulo = 0;
    printf("e o A nao é nulo\n");}

  return ehnulo;
}

/////////////a função "principal"/////////////
void raizes(){
  
  double d, a, b, c;
  double x1r, x2r;
  int ehnulo, sinal;

//   printf("Insira os valores de a, b e c\n");
// scanf("%lf", &a);  
// scanf("%lf", &b);  
// scanf("%lf", &c);  

  //alguns valores interessantes
  // a = 1;
  // b = 2;
  // c = 3;

  //d = -8
  //x1 = -1 + 1.4142135623731i
  //x2 = -1 - 1.4142135623731i

  a = 1;
  b = -1;
  c = -12;

  //d = 49 
  //x1= -3
  //x2= 4

  printf("Então a = %f, b = %f e c = %f. Beleza vamos começar:\n\n", a, b, c);


  //delta
  d = delta(a, b, c);

  //é aqui que sera usada a funcao do ex 1 (checapositivo)
  sinal = checapositivo(d);
  
  //a funcao do ex2 (checanulo) nao é chamado na main, é aqui mesmo.
  ehnulo = checanulo(a);

  if (ehnulo == 1){
    printf("'A' nao existe, logo nao temos raizes. (na verdade não é uma equação de segundo grau ne...)\n");
    }
  else if (ehnulo == 0){
    if (sinal == 0){ //0 = positivo, 1 = negativo
      x1r = -b/(2*a) + (sqrt(d))/(2*a);
      x2r = -b/(2*a) - (sqrt(d))/(2*a);
      printf("Agora, depois de extensos calculos, eu digo que \nx1 = %f \ne \nx2 = %f" , x1r, x2r);
    }
    else if (sinal == 1){
      printf("Opa opa opa! Raizes complexas jovem, aqui não!\n");
	  printf("Erro");
    }
  }
}

//ai tudo isso é chamado na main
int main(){

//usa o delta,  o ex 2 e ex 1 para checar o a e calcula as raizes
raizes();

return 0;
}

// //Essa é a funcao antiga, so para mostrar como tinha feito ; )

// int raizes(int a,int b,int c,double d){
  
//   double x1r, xim, x2r;
//   int ehnulo, sinal;

//   //é aqui que sera usada a funcao do ex 1 (checapositivo)
//   sinal = checapositivo(d);
  
//   //a funcao do ex2 (checanulo) nao é chamado na main, é aqui mesmo.
//   ehnulo = checanulo(a);

//   if (ehnulo == 1){
//     printf("a nao existe, logo nao temos raizes\n");
//     }
//   else if (ehnulo == 0){
//     if (sinal == 0){ //0 = pos, 1 = neg
//       x1r = (-b)/2*a + sqrt(d)/2*a;
//       x2r = (-b)/2*a - sqrt(d)/2*a;
//       printf("Agora epois de extensos calculos, eu digo que \nx1 = %f \ne \nx2 = %f" , x1r, x2r);
//     }
//     else if (sinal == 1){
//       d = -d; //pois ele nao calcula a raiz de numero negativo
//       x1r = (-b)/2*a;
//       xim = sqrt(d)/2*a;
//       printf("Agora depois de extensos calculos, eu digo que \nx1 = %f + i*%f \ne \nx2 = %f - i*%f \ne que são raizes complexas!" , x1r, xim, x1r, xim);
//     }
//   }
  
// 	return 0;
// }