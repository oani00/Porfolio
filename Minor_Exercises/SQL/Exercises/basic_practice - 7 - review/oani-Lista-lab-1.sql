--OANI DA SILVA DA COSTA

-- Escreva os comandos SQL  correspondentes as ações/consultas abaixo:

--      1-  Analise o modelo e escreva um comando para adicionar a chave primária na tabela AutorLivro e as chaves estrangeiras, 
--          considerando que a tabela já está com sua estrutura criada. Usar Alter Table e dar nome às constraints.

ALTER TABLE AutorLivro ADD CONSTRAINT PK_AutorLivro_Codliautor PRIMARY KEY (CODIGOLIVRO, CODAUTOR));

-------FKS para AUTORLIVRO
ALTER TABLE AutorLivro ADD CONSTRAINT FK_AutorLivro_Codigolivro FOREIGN KEY Codigolivro REFERENCES AutorLivro;
ALTER TABLE AutorLivro ADD CONSTRAINT FK_AutorLivro_Codautor FOREIGN KEY Codautor REFERENCES Autor;

-------FKS para Livro
ALTER TABLE LIVRO ADD CONSTRAINT FK_Livro_Codassunto FOREIGN KEY Codassunto REFERENCES Assunto;

--      2-  Escreva os comandos necessários para incluir 2 linhas em cada tabela listada acima. 
--          A inclusão  dos registros de dados devem obedecer a uma ordem? Porque?

----------------LIVRO----------------
INSERT INTO Livro VALUES (29846, Harry Poter, A, Sorocaba, 10-11-1991, 2,   62345, 50.6,    11-11-1984, 1 )
                       , (83729, Senhor dos A, B, Sao Paulo, 10-11-1992, 3, 62746, 60,      11-11-1985, 1 )
                       , (93426, Crepusculo, C, Boituva, 10-11-1993, 4,     99283, 70,      11-11-1986, 0 )
                       , (19384, Politica, D, Itu, 10-11-1994, 5,           89526, 80,      11-11-1987, 0 )
                       , (27461, 1001 Filmes, E, Itupeva, 10-11-1995, 6,    90200, 99.99,   11-11-1988, 1 );

----------------AUTOR----------------
INSERT INTO Autor VALUES (11111, JK Rowling,    10-11-1991, Inglaterra, f );
INSERT INTO Autor VALUES (22222, Tolkien,       10-11-1991, Inglaterra, m );
INSERT INTO Autor VALUES (33333, Anne R,        10-11-1991, USA,        f );
INSERT INTO Autor VALUES (44444, Aristoteles,   10-11-1991, Grecia,     m );
INSERT INTO Autor VALUES (55555, Editora sla,   10-11-1991, USA,        m );

----------------Assunto----------------
INSERT INTO Assunto VALUES (12345, Ficcao,      1 )
INSERT INTO Assunto VALUES (12345, Ficcao,      0 )
INSERT INTO Assunto VALUES (12345, Ficcao,      0 )
INSERT INTO Assunto VALUES (23456, Filosofia,   1 )
INSERT INTO Assunto VALUES (34567, Reportagem,  1 )

Deve respeitar as chaves estrangeiras. Se houver reference, deve haver valor para ser referenciado

--     3- Adicionar uma nova coluna de nome Nacionalidade na tabela Autor.  

ALTER TABLE Autor ADD Nacionalidade varchar2(30);

--     4- Alterar a coluna Titulo da tabela Livros de 30 para 40 posições.

ALTER TABLE Livros MODIFY Titulo varchar2(40);


-- 5-   Incluir uma restrição de domínio para a coluna descontopromocao da tabela assunto 
--      de forma a aceitar apenas ‘S’ ou  ‘N’.

ALTER TABLE Assunto
ADD  CHECK (descontopromocao in ('S','N'));

-- 6-   Alterar  o campo editora da tabela livros mudando para ‘Editora LTC’  para o livro de código 3.

/* 
Boa pratica: Fazer um select antes de deletar

SELECT editora
FROM Livro
WHERE codlivro = 3 */

UPDATE Livros
SET editora = ‘Editora LTC’
WHERE codlivro = 3;

-- 7-   Excluir os livros com codassunto igual a 10 e anoedição menor que 1980;

/* 
Boa pratica: Fazer um select antes de deletar

SELECT *
FROM Livro
WHERE codassunto = 10 AND year(dataedicao) < 1980 */

DELETE Livros
WHERE codassunto = 10 AND year(dataedicao) < 1980


-- 8-   Listar o título dos livros que possuam a palavra “Banco de Dados’ em qualquer posição do Título. 

SELECT Titulo
FROM Livros
WHERE titulo LIKE '%Banco de Dados%'

-- 9-   Listar o nome dos autores que nasceram entre 1950 e 1970 
--      ordenado pelo nome
--      e depois pela data de nascimento.

SELECT nomeAutor
FROM Autore
WHERE year(datanasc) BETWEEN 1950 AND 1970
ORDER BY nomeAutor,datanasc;

-- 10-  Listar a quantidade de livros existentes por assunto. 
--      Exibir o código do assunto e a qtde de livros.

SELECT codassunto, COUNT(codassunto) AS Quantidade
FROM livro
GROUP BY assunto;



-- 11-  Listar  o título do livro e a descrição do assunto a qual ele pertence.

SELECT l.Titulo, a.descricao
FROM LIVRO l
INNER JOIN Assunto a ON L.Codassunto = A.Codassunto;

-- 12-  Listar o código do livro, titulo, código e nome dos autores de cada livro

SELECT l.codigolivro, l.titulo, a.codautor, a.Nomeautor
      FROM LIVRO L
INNER JOIN AutorLivro a ON L.codigoLivro = a.codigoLivro
INNER JOIN Autor t ON a.codAutor = t.codAutor;

-- 13-  Listar o código dos autores que tem mais de 3 livros publicados.

SELECT a.codautor 
FROM autorlivro a
HAVING COUNT(a.codautor) > 3;