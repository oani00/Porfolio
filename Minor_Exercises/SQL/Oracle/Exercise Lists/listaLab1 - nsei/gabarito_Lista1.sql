--Aula do dia 29-07-2021

-- Revis�o

Comando distinct

select * from paciente

select distinct (cidpaciente) from paciente;

-- Elabora��o da Lista de Revis�o

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
1-	Analise o modelo e escreva um comando para adicionar a chave prim�ria na 
tabela AutorLivro e as chaves estrangeiras, considerando que a tabela j� est� 
com sua estrutura criada. Usar Alter Table e dar nome �s constraints.

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

2-	Escreva os comandos necess�rios para incluir 2 linhas em cada tabela listada acima. A inclus�o  dos registros de dados devem obedecer a uma ordem? Porque?

insert into....


3-	Adicionar uma nova coluna de nome Nacionalidade na tabela Autor. 

alter table autor add nacionalidade varchar2(20);

4-	Alterar a coluna Titulo da tabela Livros de 30 para 40 posi��es.

alter table LIVRO modify TITULO  varchar2(40);

5-	 Incluir uma restri��o de dom�nio para a coluna descontopromocao da tabela assunto de forma a aceitar apenas �S� ou  �N�.

ALTER TABLE assunto ADD  check  (descontoPromocao in ('S','N' ) );

select * from assunto;

6-	Alterar  o campo editora da tabela livros mudando para �Editora LTC�  para o livro de c�digo 3.

UPDATE livros 
SET editora = "Editora LTC" 
WHERE codlivro = 3;

7-	Excluir os livros com codassunto igual a 10 e anoedi��o menor que 1980;

DELETE livros 
WHERE codassunto = 10 and TO_CHAR(dataedicao, 'YYYY') < '1980';

8-	Listar o t�tulo dos livros que possuam a palavra �Banco de Dados� 
em qualquer posi��o do T�tulo.

SELECT titulo FROM livros WHERE titulo LIKE '%banco de dados%'; 

9-	Listar o nome dos autores que nasceram entre 1950 e 1970 ordenado pelo nome e depois pela data de nascimento.

SELECT nomeautor FROM autor 
WHERE datanascimento BETWEEN '01/01/1950' and '31/12/1970'
ORDER BY nomeautor,datanascimento;

10-	Listar a quantidade de livros existentes por assunto.
Exibir o c�digo do assunto e a quantidade de livros.

SELECT l.codassunto,count(l.Codassunto) AS quantidade
FROM livro l
GROUP BY l.codassunto;

select * from livro order by codassunto;

-- alterar a consulta acima para listar a descri��o do assunto

select livro.codassunto,assunto.descricao, count(*)
from assunto inner join livro
on livro.codassunto = assunto.codassunto
group by livro.codassunto, assunto.descricao;

11-	Listar  o t�tulo do livro e a descri��o do assunto a qual ele pertence.

SELECT l.titulo, a.descricao 
FROM livro l INNER JOIN assunto a 
ON l.CodAssunto = a.CodAssunto;


-- ou utilizando outra sintaxe

SELECT l.titulo, a.descricao 
FROM livro l, assunto a 
where l.CodAssunto = a.CodAssunto;


12-	Listar o c�digo do livro, titulo, c�digo e nome dos autores de cada livro

SELECT l.codigolivro, l.titulo, a.codautor, a.nomeautor 
FROM livro l INNER JOIN autorlivro al
ON  l.codigolivro = al.codigolivro
inner join autor a
on al.codautor = a.codautor order by l.codigolivro;

select * from autorlivro

insert into autorlivro values (777,111);
insert into autorlivro values (999,111);

13-	Listar o c�digo dos autores que tem mais de 2 livros publicados.

SELECT a.codautor FROM autorlivro a 
GROUP BY a.codautor 
HAVING COUNT(a.codautor) > 3;


select * from autorlivro order by codautor;




DML � insert/update/delet/select
DDL � create/alter/drop/grand

