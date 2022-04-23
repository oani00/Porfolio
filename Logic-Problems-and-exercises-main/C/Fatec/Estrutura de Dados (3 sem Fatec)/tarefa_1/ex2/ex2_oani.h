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

//criara funcionarios sequencialmente
struct funcionario {
	int codigo;
	char nome[31]; 
	double salario;
	} ;

typedef struct funcionario funcionario;

// typedef struct {
// 	int codigo;
// 	char nome[31]; 
// 	double salario;
// 	} funcionario;

#define TRUE	1
#define FALSE	0

#define QTDE_ITENS	5000

//criando a lista seq. no escopo global//////////////////////////////////////////////////////////////////
		//ou seja, um array de funcionarios
funcionario entradaFuncionario[QTDE_ITENS]; /*aqui fiz um jogo de palavras meio esquisito para facilitar a leitura.
											a lista entradaFuncionario tera a entradaFuncionario1, entradaFuncionario2 etc.
											que são os funcionarios em si.
+------------------------+-----------------------+--------------------+-----------------+
| entradaFuncionario[1]  | entradaFuncionario[n] | e assim por diante | ate o fim(5000) |
+------------------------+-----------------------+--------------------+-----------------+
| int codigo;            | int codigo;           |                ... |                 |
| char nome[31];         | char nome[31];        |                ... |                 |
| double salario;        | double salario;       |                ... |                 |
+------------------------+-----------------------+--------------------+-----------------+ https://ozh.github.io/ascii-tables */
/////////////////////////////////////////////////////////////////////////////////////////////////////////