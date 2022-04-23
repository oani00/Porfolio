// ┌───┐
// │┌─┐│
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

//███████╗ █████╗ ████████╗███████╗ ██████╗
//██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔════╝
//█████╗  ███████║   ██║   █████╗  ██║
//██╔══╝  ██╔══██║   ██║   ██╔══╝  ██║
//██║     ██║  ██║   ██║   ███████╗╚██████╗ Sorocaba
//╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚══════╝ ╚═════╝ José Crespo Gonzales


struct regLista
{
	int pk; //"chave estrangeira", mas esta PK...
	char nome[TAMCIDADE];
	float populacao;
	float area;
	float pib;
};
typedef struct regLista cidade;

struct reg2
{
	int maxlista;
	int pk; //"chave primaria"
	float idh;
};
typedef struct reg2 indice;

void adjust(indice arr[], int i)
void heapify_function(indice arr[]) //Parecida com a original fornecida
void ImprimeArvore(cidade arr[], indice ind[], int maxcidades)