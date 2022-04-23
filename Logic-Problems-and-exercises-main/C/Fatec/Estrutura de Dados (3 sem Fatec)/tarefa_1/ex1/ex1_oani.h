// ┌───┐
// │┌─┐│      /
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

/*
	Interface
*/

struct funcionario {int codigo; char nome[31]; double salario; struct funcionario *prox;};

typedef struct funcionario TNo;

typedef struct {TNo *inicio, *final; int qtde; float soma;} TDescr; //descritores de soma aqui

void InicializaLista(TDescr *);
void ImprimeLista(TDescr, char *);