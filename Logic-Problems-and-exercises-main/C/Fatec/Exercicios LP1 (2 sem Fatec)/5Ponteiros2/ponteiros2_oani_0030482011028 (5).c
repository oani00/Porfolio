//5. Elabore uma função que receba duas strings como parâmetros e verifique se a segunda string ocorre dentro da primeira.
//Use aritmética de ponteiros para acessar os caracteres  ́das strings.

//Com a ajuda de Luiz Miguel

#include <stdio.h>
#define TAM 10

void comparar(char *p1, char *p2){

	//ia fazer uma funcao separada mas ja coloquei aqui mesmo
	//ela conta quantos caracteres tem em str2
	int caracteres = 0;

	for (int i = 0; *(p2+i) != '\0'; ++i)
	{
		caracteres++;
	}

	int i, j, cont = 0;
	//for para andar até TAM
	//andar por cada letra
	for (int i = 0; *(p1+i) != '\0'; ++i)
	{
	    //printf("b\n"); //teste
		//dentro do for, um for para cada elemento de str2
		for (int j = 0; j < caracteres; ++j)
		{
		    //printf("caracteres = %d\n", caracteres); //teste
		    //printf("j = %d\n", j); //teste
		    //printf("c\n"); //teste
			// e ver se ela as proximas letras são iguais
			if (*(p2+j) == *(p1+i+j))
			{
				//printf("p2 = %c\n", (p2+j));
				//printf("p1 = %c\n", (p1+i+j));
				//printf("d\n"); //teste
				cont ++;
				//printf("cont = %d\n", cont); //teste

				//ou seja, se bater o numero de ocorrencias iguais com o numero de letras no 2:
				if (cont == caracteres){
                    printf("A string 2 ocorre na 1!");
					exit(0);
				}

			}
		}
	}
	if (cont != caracteres)
        printf("A string 2 NAO ocorre na 1...");
}

int main(int argc, char const *argv[])
{
	char str[TAM], str2[TAM];

	printf("Diga a primeira string:\n");
	scanf("%s", &str);

	printf("Agora diga a segunda que eu te direi se ela ocorre na primeira:\n");
	scanf("%s", &str2);

	comparar(&str, &str2);

	return 0;
}
