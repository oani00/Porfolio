#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cada contato possui um nome e telefone.
typedef struct {
	char nome[100];
	int telefone;	
	int idade;
} Contato;

//Funcoes
void		criarContato (Contato *agenda, int *n, int *cap);
void		exibirContatos (Contato *agenda, int n);
void		apagarContato (Contato *agenda, int *n);
Contato 	* inicializar(int cap);
void		flush_in();

/************************
Funcao Principal
*/
int main(){
	//Ponteiro para estrutura. Vai ser o nosso vetor de
	//estruturas dinamicas com os dados da agenda.
	Contato *agenda;
	int cap=20; //capacidade do vetor.
	int n=0; //Numero de contatos (tamanho usado).
	int opc; //opcao do switch


	agenda = inicializar(cap);

	do{
		//exibe o menu de opcoes
		printf("----- Menu -----\n");
		printf("1) Cadastrar contato\n");
		printf("2) Exibir contatos\n");
		printf("3) Apagar contato\n");
		printf("4) Sair\n");
		//Le a opcao selecionada
		scanf("%d", &opc);

		switch(opc){
			case 1: criarContato 	(agenda, &n, &cap); break;
			case 2: exibirContatos	(agenda, n);		break;
			case 3: apagarContato	(agenda, &n); 		break;
		}

	//enquanto nao for saida, mostra o menu
	}while(opc != 4);

	//libera memoria
	free(agenda);

	return 0;
}



/************************
Inicializar
*/
Contato * inicializar(int cap){

	Contato *agenda

	agenda = (Contato *) malloc(sizeof(Contato) * cap);

	return agenda
}


/***************************
Funcao exige todos os contatos
*/
void exibirContatos(Contato *agenda, int n){
	//exibe totos os contatos cadastrados
	int i;

	for(i = 0; i < n; i++){
		printf("----- Contato %d -----/n", i+1);
		printf("Nome: %s\n", agenda[i].nome);
		printf("telefone: %d\n", agenda[i].telefone);
	}
}


/***************************
funcao Apaga contato
*/
void apagarContato (Contato *agenda, int *n){

	char nome[100];
	int j, i;
	flush_in();
	printf("Digite o nome a ser removido: ");
	gets(nome);

	for (i = 0; i < *n; i++){
		if (strcmp)(agenda[i].nome, nome) == 0{
			for (j = i+1; j < *n; j++){
				strcmp(agenda[i].nome, nome)==0
				agenda[j-1].telefone = agenda[j].telefone;
			}
			(*n) --;
			i = *n;
		}
	}
}


/*****************************
Limpa o buffer
*/

void flush_in()
{
	int ch;
	while((ch = fgetc(stdin)) != EOF && ch != '/n' ){}
}


/************************************************
Funcao cadastra novo contato
*/
void criarContato(Contato *agenda, int *n, int *cap){

	if (*n == *cap){
		//Capacidade esgotada devemos aumentar o
		//vetor usando "realloc"
		*cap = *cap * 20;
		agenda = (Contato*)realloc(agenda, sizeof(Contato) * (*cap));
	}

	//leitura dos dados
	printf("Digite o nome:");
	flush_in();
	gets(agenda[*n], nome);
	printf("Digite o telefone: ");
	scanf("%d", &agenda[*n].telefone);

	//Incrementa numero de registros cadastrasod.
	(*n) ++;

}



}

//Baseado na aula da professora Janaina