// 9. Crie um aplicativo de conversão entre as temperaturas Celsius e Farenheit.
      // Primeiro o usuário deve escolher se vai entrar com a temperatura em Célsius ou Farenheit,
      // depois a conversão escolhida é realizada através de um comando SWITCH.
      // Se C é a temperatura em Célsius e F em farenheit, as fórmulas de conversão são: C= 5.(F-32)/9 F= (9.C/5) + 32

      #include <stdio.h>

void conversor(){

  printf("Vamos converter unidades de medida! Voce vai inserir celsius (C) ou Farenheit (F)?\n");

  char tipo;
  double temp;

  scanf("%c", &tipo);


  switch(tipo){
	  case 'C': case 'c':
	  printf("Beleza! Agora coloque a temperatura\n");
      scanf("%lf", &temp);
	  temp = ((9*temp)/5) + 32;
	  printf("A temperatura em Celsius eh de %f graus Far.\n", temp);
	  break;

	  case 'F': case 'f':
	  printf("Beleza! Agora coloque a temperatura\n");
      scanf("%lf", &temp);
	  temp = (5*(temp - 32))/9;
	  printf("A temperatura em Celsius eh de %f graus\n", temp);
	  break;

	  default:
	  printf("Insira uma unidade valida por favor =D\n");
  }
}

int main(){

conversor();

  return 0;
}
