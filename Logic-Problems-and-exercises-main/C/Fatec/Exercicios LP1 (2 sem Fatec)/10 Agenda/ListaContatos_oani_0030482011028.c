/* Criar uma agenda de contatados com o seguinte menu:

1. Cadastrar Contatos
2. Pesquisar contato pelo email
3. Pesquisar contato pelo nome
4. Alterar dados de um contato.
5. Excluir um Contato pelo código
6. Sair


A quantidade de contatos é indeterminada.
Usar alocação dinâmica e realocação.
Um contato deve ter as seguintes informações:

Codigo
Nome
Telefone
Endereço
Email */

//(Muito) Baseado na aula da professora Janaina
//tambem baseado no do Luiz Miguel
	//https://github.com/LuizJarduli/LP1/blob/main/Projeto%20Final/Projeto.c

/*

-Acrescentar dados no
	- exibir ou tirar o exibir
	-apagar contato
	-criar contato

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
	char nome[100];
	int telefone;
	char endereco[100];
	char email[100];
	char nada[100]; // a ultima entrada esta bugando n faço ideia do por que
} Contato;

	// 1. Cadastrar Contatos
void		criarContato 	(Contato *agenda, int *n, int *cap);
void		exibirContatos 	(Contato *agenda, int n);

	// 5. Excluir um Contato pelo código
int			apagarContato 	(Contato *agenda, int *n);
Contato 	* inicializar 	(int cap);
void		flush_in(); //aparentemente quebrado
	// 2. Pesquisar contato pelo email //baseado no exibir
void		pesquisarEmail 	(Contato *agenda, int *n);
	// 3. Pesquisar contato pelo nome //baseado no exibir
void		pesquisarNome 	(Contato *agenda, int *n);
	// 4. Alterar dados de um contato. //baseado no criar
void		alterarContato 	(Contato *agenda, int *n, int *cap);
	// 6. Sair (implementado no do While)

int main(){
	//Ponteiro para estrutura. Vai ser o nosso vetor de
	//estruturas dinamicas com os dados da agenda.
	Contato *agenda;
	int cap = 20; //capacidade do vetor.
	int n = 0; //Numero de contatos (tamanho usado).
	int opc; //opcao do switch

	agenda = inicializar(cap);

	do{
		//exibe o menu de opcoes
		printf("----- Menu -----\n");					//OK
		printf("1) Cadastrar contato\n");				//OK
		printf("2) Exibir contatos\n");					//OK
		printf("3) Apagar contato\n");					//OK
		printf("4) Alterar dados de um contato\n");		//-----------------
		printf("5) Pesquisar contato pelo email\n");	//-----------------
		printf("6) Pesquisar contato pelo nome\n");		//-----------------
		printf("7) Sair\n");							//OK

		scanf("%d", &opc);

		switch(opc){
			case 1: criarContato 	(agenda, &n, &cap); break;
			case 2: exibirContatos	(agenda, n);		break;
			case 3: apagarContato	(agenda, &n); 		break;
			case 4: alterarContato 	(agenda, &n, &cap); break;
			case 5: pesquisarEmail 	(agenda, &n); 		break;
			case 6: pesquisarNome 	(agenda, &n); 		break;
		}

	//enquanto nao for saida, mostra o menu
	}while(opc != 7);

	//libera memoria
	free(agenda);

	return 0;
}

//Inicializar
Contato * inicializar(int cap){

	Contato *agenda;
	agenda = (Contato *) malloc(sizeof(Contato) * cap);
	return agenda;
}

void exibirContatos(Contato *agenda, int n){
	//exibe totos os contatos cadastrados
	int i;

	for(i = 0; i < n; i++){
		printf("----- Contato %d -----\n", i+1);
		printf("Codigo: %d\n", 		agenda[i].codigo);
		printf("Nome: %s\n", 		agenda[i].nome);
		printf("telefone: %d\n", 	agenda[i].telefone);
		printf("Endereco: %s\n", 	agenda[i].endereco);
		printf("email: %s\n", 		agenda[i].email);
	}
}

int apagarContato (Contato *agenda, int *n){

	//printf("nnnnnnnn = %d", *n);

	if(*n < 2){
	printf("Apagada unica entrada"); //estava dando erro antes so com uma
	(*n) --;
	return 0;
	}

	//char codigo[100];
	int codigo;
	int j, i;
	//getchar();
	printf("Digite o codigo a ser removido: ");
	//gets(codigo);
	scanf("%d", &codigo);
	
	for (i = 0; i < *n; i++){

		if (agenda[i].codigo == codigo){
			for (j = i+1; j < *n; j++){
				strcpy(agenda[j-1].codigo, agenda[j].codigo);
				agenda[j-1].telefone = agenda[j].telefone;
			}

			(*n) --;
			i = *n;
			return 0;
		}
	}
}

//Limpa o buffer
//aparentemente ta bugado mas faço 0 ideia do por que...
//substitui pelo getchar().

void flush_in()
{
	int ch;
	while((ch = fgetc(stdin)) != EOF && ch != '/n' ){}
}

void criarContato(Contato *agenda, int *n, int *cap){

	//Capacidade esgotada devemos aumentar o vetor usando "realloc"
	if (*n == *cap){
		*cap = *cap * 20;
		agenda = (Contato*)realloc(agenda, sizeof(Contato) * (*cap));
	}

	//leitura dos dados
	printf("Digite o codigo: ");
	scanf("%d", &agenda[*n].codigo);
	printf("Digite o nome: ");
	getchar();
	gets(agenda[*n].nome);
	printf("Digite o telefone: ");
	scanf("%d", &agenda[*n].telefone);
	printf("Digite o endereco: ");
	getchar();
	gets(agenda[*n].endereco);
	printf("Digite o email (exemplo@provedor.com(.br)): "); 
	getchar(); 					
	gets(agenda[*n].email); 	//por alguma razão se coloco apenas um número ele nao registra... vai saber
								//aparentemente ele pega caracteres-1.................... aiai C sendo C
	
	// printf("Confirme o final "); 
	// getchar(); 					
	// gets(agenda[*n].nada); 	

	//Incrementa numero de registros cadastrados.
	(*n) ++;
}

	//2. Pesquisar contato pelo email //baseado no apagar contato
void		pesquisarEmail (Contato *agenda, int *n){
	
	char email[100];
	int j, i;
	getchar();
	printf("Digite o email de interesse: ");
	gets(email);

	for (i = 0; i < *n; i++){
		if (strcmp(agenda[i].email, email) == 0){
			printf("----- Contato %d -----/n", i+1);
			printf("Codigo: %d\n", 		agenda[i].codigo);
			printf("Nome: %s\n", 		agenda[i].nome);
			printf("telefone: %d\n", 	agenda[i].telefone);
			printf("Endereco: %s\n", 	agenda[i].endereco);
			printf("email: %s\n", 		agenda[i].email);
		}else{
			printf("Voce nao cadastrou esse email ainda.");
		}
	}
}

	// 3. Pesquisar contato pelo nome //baseado no busca por nome
void		pesquisarNome (Contato *agenda, int *n){

	char nome[100];
	int j, i;
	getchar();
	printf("Digite o nome de interesse: ");
	gets(nome);

	for (i = 0; i < *n; i++){
		if (strcmp(agenda[i].nome, nome) == 0){
			printf("----- Contato %d -----/n", i+1);
			printf("Codigo: %d\n", 		agenda[i].codigo);
			printf("Nome: %s\n", 		agenda[i].nome);
			printf("telefone: %d\n", 	agenda[i].telefone);
			printf("Endereco: %s\n", 	agenda[i].endereco);
			printf("nome: %s\n", 		agenda[i].nome);
		}else{
			printf("Voce nao cadastrou esse nome ainda.");
		}
	}
}

	// 4. Alterar dados de um contato. //baseado no apagar e criar
void		alterarContato (Contato *agenda, int *n, int *cap){

	//Bom, alqui altera tudo né................
	//printf("A seguir digite o código que quer mudar:");
	
	//apagarContato	(agenda, &n); //////////////////
		if(*n < 2){
		printf("Vamos mudar a unica entrada"); //estava dando erro antes so com uma
		(*n) --;
		}else{
			//char codigo[100];
			int codigo;
			int j, i;
			//getchar();
			printf("Digite o codigo a ser removido: ");
			//gets(codigo);
			scanf("%d", &codigo);
			
			for (i = 0; i < *n; i++){

				if (agenda[i].codigo == codigo){
					for (j = i+1; j < *n; j++){
						strcpy(agenda[j-1].codigo, agenda[j].codigo);
						agenda[j-1].telefone = agenda[j].telefone;
					}

					(*n) --;
					i = *n;
				}
			}
		}

	//criarContato 	(agenda, &n, &cap);

		//Capacidade esgotada devemos aumentar o vetor usando "realloc"
		if (*n == *cap){
			*cap = *cap * 20;
			agenda = (Contato*)realloc(agenda, sizeof(Contato) * (*cap));
		}

		//leitura dos dados
		printf("Digite o codigo: ");
		scanf("%d", &agenda[*n].codigo);
		printf("Digite o nome: ");
		getchar();
		gets(agenda[*n].nome);
		printf("Digite o telefone: ");
		scanf("%d", &agenda[*n].telefone);
		printf("Digite o endereco: ");
		getchar();
		gets(agenda[*n].endereco);
		printf("Digite o email (exemplo@provedor.com(.br)): "); 
		getchar(); 					
		gets(agenda[*n].email); 	//por alguma razão se coloco apenas um número ele nao registra... vai saber
									//aparentemente ele pega caracteres-1.................... aiai C sendo C
		
		// printf("Confirme o final "); 
		// getchar(); 					
		// gets(agenda[*n].nada); 	

		//Incrementa numero de registros cadastrados.
		(*n) ++;
}