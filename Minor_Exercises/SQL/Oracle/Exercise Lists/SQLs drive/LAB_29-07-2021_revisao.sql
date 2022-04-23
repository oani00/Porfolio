--Aula do dia 29-07-2021

-- Revisão

Comando distinct

select * from paciente

select distinct (cidpaciente) from paciente;

-- Elaboração da Lista de Revisão

-- criando as tabelas

create table Livro 
(CodigoLivro 		number(5) primary key,
 Titulo			varchar2(30),
 Editora		varchar2(20),
 Cidade		varchar2(30), 
 DataEdicao		date, 
 Versao		number(3),
 CodAssunto		number(5),
 Preco		            number(5,2),
 DataCadastro	date,
 lancamento     	Char(1) );
--

create table Assunto
(CodAssunto		 number(5) primary key,
 descricao  		varchar2(40),
 descontopromocao	 char(1));
--
create table Autor
(CodAutor 		number(5) primary key, 
 Nomeautor	 	varchar2(20),
 datanascimento 	date,
 CidadeNasc  		varchar2(20),
 sexo 			char(1) );

--
create table AutorLivro
( codigoLivro  number(5) not NULL,
  codAutor 	  number(5) not NULL);
  
---------
1-	Analise o modelo e escreva um comando para adicionar a chave primária na 
tabela AutorLivro e as chaves estrangeiras, considerando que a tabela já está 
com sua estrutura criada. Usar Alter Table e dar nome às constraints.

alter table TABELA add constraint PK_Tabela_Coluna primary key (col1,col2);

alter table TABELA add constraint FK_Tabela_Coluna foreign key (col1) references OUTRATABELA;

-- definindo a PK para a tabela AUTORLIVRO

ALTER TABLE AUTORLIVRO ADD CONSTRAINT PK_AUTORLIVRO_CODLIAUTOR PRIMARY KEY(CODIGOLIVRO,CODAUTOR);

--definindo as FKs para a tabela AUTORLIVRO

ALTER TABLE AUTORLIVRO ADD CONSTRAINT FK_AUTORLIVRO_CODIGOLIVRO FOREIGN KEY (CODIGOLIVRO) REFERENCES LIVRO;

ALTER TABLE AUTORLIVRO ADD CONSTRAINT FK_AUTORLIVRO_CODAUTOR FOREIGN KEY (CODAUTOR) REFERENCES AUTOR;

-- definindo a FK para a tabela de LIVRO

ALTER TABLE LIVRO ADD CONSTRAINT FK_LIVRO_CODASSUNTO FOREIGN KEY (CODASSUNTO) REFERENCES ASSUNTO;

select  from tb_cliente;

-- montar o DER  ok

2-	Escreva os comandos necessários para incluir 2 linhas em cada tabela listada acima. A inclusão  dos registros de dados devem obedecer a uma ordem? Porque?

insert into....


3-	Adicionar uma nova coluna de nome Nacionalidade na tabela Autor. 

alter table autor add nacionalidade varchar2(20);

4-	Alterar a coluna Titulo da tabela Livros de 30 para 40 posições.

alter table LIVRO modify TITULO  varchar2(40);

5-	 Incluir uma restrição de domínio para a coluna descontopromocao da tabela assunto de forma a aceitar apenas ‘S’ ou  ‘N’.

