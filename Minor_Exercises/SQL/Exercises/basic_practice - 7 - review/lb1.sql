-- criando as tabelas

create table Livro
(
    CodigoLivro int primary key,
    Titulo varchar(30),
    Editora varchar(20),
    Cidade varchar(30),
    DataEdicao date,
    Versao number(3),
    CodAssunto int,
    Preco number(5,2),
    DataCadastro date,
    lancamento Char(1)
);


create table Assunto
(
    CodAssunto int primary key,
    descricao varchar(40),
    descontopromocao char(1)
);

create table Autor
(
    CodAutor int primary key,
    Nomeautor varchar(20),
    datanascimento date,
    CidadeNasc varchar(20),
    sexo char(1)
);


create table AutorLivro
(
    codigoLivro int not NULL,
    codAutor int not NULL
);

-- 1-	Analise o modelo e escreva um comando para adicionar a chave primaria na 
-- tabela AutorLivro e as chaves estrangeiras, considerando que a tabela j_ est_ 
-- com sua estrutura criada. Usar Alter Table e dar nome _s constraints.

alter table TABELA add constraint PK_Tabela_Coluna primary key (col1,col2);

alter table TABELA add constraint FK_Tabela_Coluna foreign key (col1) references OUTRATABELA;

-- definindo a PK para a tabela AUTORLIVRO

ALTER TABLE AUTORLIVRO ADD CONSTRAINT PK_AUTORLIVRO_CODLIAUTOR PRIMARY KEY(CODIGOLIVRO,CODAUTOR);

--definindo as FKs para a tabela AUTORLIVRO

ALTER TABLE AUTORLIVRO ADD CONSTRAINT FK_AUTORLIVRO_CODIGOLIVRO FOREIGN KEY (CODIGOLIVRO) REFERENCES LIVRO;

ALTER TABLE AUTORLIVRO ADD CONSTRAINT FK_AUTORLIVRO_CODAUTOR FOREIGN KEY (CODAUTOR) REFERENCES AUTOR;

-- definindo a FK para a tabela de LIVRO

ALTER TABLE LIVRO ADD CONSTRAINT FK_LIVRO_CODASSUNTO FOREIGN KEY (CODASSUNTO) REFERENCES ASSUNTO;


-- 2-	Escreva os comandos necess_rios para incluir 2 linhas em cada tabela listada acima. 
--A inclus_o  dos registros de dados devem obedecer a uma ordem? Porque?



-- 3-	Adicionar uma nova coluna de nome Nacionalidade na tabela Autor.

alter table autor add nacionalidade varchar(20);

-- 4-	Alterar a coluna Titulo da tabela Livros de 30 para 40 posi__es.

alter table LIVRO alter COLUMN TITULO  varchar(40);

-- 5-	 Incluir uma restri__o de dom_nio para a coluna descontopromocao da tabela assunto de forma a aceitar apenas _S_ ou  _N_.

ALTER TABLE assunto ADD  check  (descontoPromocao in ('S','N' ) );


-- 6-	Alterar  o campo editora da tabela livros mudando para _Editora LTC_  para o livro de c_digo 3.

UPDATE livros 
SET editora = "Editora LTC" 
WHERE codlivro = 3;

-- 7-	Excluir os livros com codassunto igual a 10 e anoedi__o menor que 1980;

DELETE livros 
WHERE codassunto = 10 and TO_CHAR(dataedicao, 'YYYY') < '1980';

-- 8-	Listar o t_tulo dos livros que possuam a palavra _Banco de Dados_ em qualquer posi__o do T_tulo.

SELECT titulo
FROM livros
WHERE titulo LIKE '%banco de dados%';

-- 9-	Listar o nome dos autores que nasceram entre 1950 e 1970 ordenado pelo nome e depois pela data de nascimento.

SELECT nomeautor
FROM autor
WHERE datanascimento BETWEEN '01/01/1950' and '31/12/1970'
ORDER BY nomeautor,datanascimento
;

-- 10-	Listar a quantidade de livros existentes por assunto. Exibir o c_digo do assunto e a quantidade de livros.

SELECT l.codassunto, count(l.Codassunto) AS quantidade
FROM livro l
GROUP BY l.codassunto;

-- alterar a consulta acima para listar a descri__o do assunto

select livro.codassunto, assunto.descricao, count(*)
from assunto
    inner join livro on livro.codassunto = assunto.codassunto
group by livro.codassunto, assunto.descricao
;

-- 11-	Listar  o t_tulo do livro e a descri__o do assunto a qual ele pertence.

SELECT l.titulo, a.descricao
FROM livro l INNER JOIN assunto a
    ON l.CodAssunto = a.CodAssunto;


-- ou utilizando outra sintaxe

SELECT l.titulo, a.descricao
FROM livro l, assunto a
where l.CodAssunto = a.CodAssunto
;


-- 12-	Listar o c_digo do livro, titulo, c_digo e nome dos autores de cada livro

SELECT l.codigolivro, l.titulo, a.codautor, a.nomeautor
FROM livro l INNER JOIN autorlivro al
    ON  l.codigolivro = al.codigolivro
    inner join autor a
    on al.codautor = a.codautor
order by l.codigolivro;


-- 13-	Listar o c_digo dos autores que tem mais de 2 livros publicados.

SELECT a.codautor
FROM autorlivro a
GROUP BY a.codautor
HAVING COUNT(a.codautor) > 3;