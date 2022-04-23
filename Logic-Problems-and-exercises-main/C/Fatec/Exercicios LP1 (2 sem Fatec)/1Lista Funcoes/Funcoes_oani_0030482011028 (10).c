//  10. Um professor, muito legal, fez 3 provas durante um semestre mas só vai levar em conta as duas notas mais altas 
	//para calcular a média. 
    //  Faça uma aplicação em C que peça o valor das 3 notas	OK
		//, mostre como seria a média com essas 3 provas, 		OK
		//a média com as 2 notas mais altas, 					OK
		//bem como sua nota mais alta e sua nota mais baixa.	

#include <stdio.h>

void mostramedia(){

  char tipo;
  double n1, n2, n3, x, y, z, med;
  
  printf("Inicialmente me diga quais são as notas:\n");
  printf("da prova 1:\n");
  scanf("%lf", &x);
  printf("da prova 2:\n");
  scanf("%lf", &y);
  printf("da prova 3:\n");
  scanf("%lf", &z);
  
  printf("Olha se fossemos levar em conta as tres notas para a média, essa seria:\n");
  med = (x + y + z)/3;
  printf(" %f \n", med);
  
  	//sort das notas============================================= 
	//basicamente o exercicio 5 com mais codigo
  
  //com certeza esse jeito não é bom mas fazer o que...
	float m, A, B;
	
  if (x > y){
    m = x;
    A = y;}
  else if (x < y){
    m = y;
    A = x;}
  else if (x == y){
    m = x;
    A = y;}

  if (m > z){
    n1 = m;
    B = z;}
  else if (m < z){
    n1 = z;
    B = m;}
  else{
    n1 = m;
    B = z;}

	//blz ate agora temos o n1, agora achar os outros (o exercicio 4 permite achar n3 e n2)
	  
	if (A > B){
    n3 = B;
	n2 = A;}
  	else if (A < B){
    n3 = A;
  	n2 = B;}
  	else{
    n3 = B;
  	n2 = A;}
	
  //sort das notas=============================================

  	printf("Agora se fossemos levar em conta as duas maiores notas para a média, essa seria:\n");
  med = (n1 + n2)/2;
  printf(" %f \n", med);
  
  printf("Alias suas notas mais alta e baixa são:\n");
  printf(" %f \n", n1);
  printf(" %f \n", n3);

}

int main(){

mostramedia();

return 0;
}