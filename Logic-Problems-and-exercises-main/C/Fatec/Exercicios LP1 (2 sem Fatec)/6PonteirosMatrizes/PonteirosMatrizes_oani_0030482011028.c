#include <stdio.h>
#define TAMA 3
#define TAMB 4

int main(int argc, char const *argv[])
{

	//------------Ex1------------
	int matriz[TAMA][TAMA];
	int i, j, *pa, *pb;

	for(i = 0; i<TAMA;i++){
        for(j = 0; j<TAMA;j++){
          printf("Insira o valor para a matriz[%d][%d] = \n", i, j);
          scanf("%d", &matriz[i][j]);
        }
	}

	printf("Matriz 1\n");

	pa = &matriz[0];

	for(i = 0; i < TAMA;i++){
        for(j = 0; j < TAMA;j++){
          printf("%d ", *(pa + i * TAMA + j));
        }
    printf("\n");
	}


	//------------Ex2------------

	printf("Matriz invertida eh\n");

	for(j = 0; j < TAMA; j++){
        for(i = 0; i < TAMA; i++){
          printf("%d ", *(pa + i * TAMA + j));
        }
    printf("\n");
	}

	//------------Ex3------------
	int matriza[TAMB][TAMB];
	int matrizb[TAMB][TAMB];
	//int matriza[TAMB][TAMB] = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
	//int matrizb[TAMB][TAMB] = {{2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}};

	for(i = 0; i<TAMB;i++){
        for(j = 0; j<TAMB;j++){
          printf("Insira o valor para a matriza[%d][%d] = \n", i, j);
          scanf("%d", &matriza[i][j]);
        }
	}

	for(i = 0; i<TAMB;i++){
        for(j = 0; j<TAMB;j++){
          printf("Insira o valor para a matrizb[%d][%d] = \n", i, j);
          scanf("%d", &matrizb[i][j]);
        }
	}

    printf("Agora vou somar essas matrizes:\n");

	pa = &matriza[0];
	pb = &matrizb[0];

	for(i = 0; i < TAMB;i++){
        for(j = 0; j < TAMB;j++){
          *(pb + i * TAMB + j) = *(pa + i * TAMB + j) + *(pb + i * TAMB + j);
          printf("%d ", *(pb + i * TAMA + j));
        }
    printf("\n");
	}

	return 0;
}
