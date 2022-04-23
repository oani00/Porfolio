//8. Implemente uma função que calcule a  área da superfície e o volume de uma esfera de raio R.
//Essa função deve obedecer ao protótipo:
//void calc_esfera(float R, float *area, float *volume)

#include <stdio.h>
#define TAM 10

void esfera(float R, float *area, float *volume){
    *area = 4 * 3.14 * R*R;
    *volume = (4 * 3.14 * R*R*R)/3;
	printf("Area da esfera eh: %.2f\n", *area);
    printf("O volume da esfera eh : %.2f\n", *volume);
}

int main(int argc, char const *argv[])
{
	float R, area = 0, volume = 0;
	printf("Me diga o R da esfera:\n");

	esfera(scanf("%lf", &R), &area, &volume);

	return 0;
}
