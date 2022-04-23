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


struct regLista {
	char 	cidade[TAMCIDADE];
	float 	populacao;
	float 	area;
	float 	pib;
	float 	idh;
	struct 	regLista *prox;
	struct 	regLista *ante;
}; typedef struct regLista TNo;

typedef struct {TNo *inicio, *final;} TDescr;
	
void InicializaLista(TDescr *lista)
int IncluiItem(TDescr *lista, char c[], float po, float a, float pi, float i)
void ImprimeLista(TDescr *lista)
int ExcluiItem(TDescr *lista, float v)