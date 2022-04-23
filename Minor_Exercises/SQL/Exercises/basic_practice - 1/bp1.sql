-- Lista 01 – SQL 
-- Sobre o modelo Paciente-Consulta realize:

               
--   1. Criar uma nova coluna na tabela paciente com o nome País varchar2(15);

ALTER TABLE table_name
ADD column_name datatype;

ALTER TABLE paciente
ADD pais varchar(15);


--   2. Alterar a coluna endereço da tabela de paciente para 28 posições.

ALTER TABLE table_name 
ALTER COLUMN column_name new_data_type(size);

--   3. Excluir a nova coluna criada no exercício 1.

ALTER TABLE Customers
DROP COLUMN ContactName;

ALTER TABLE paciente
DROP COLUMN pais;

--   4. Incluir a restrição NOT NULL na coluna endereço.

The following SQL adds a constraint named "PK_Person" that is a PRIMARY KEY constraint on multiple columns
(ID and LastName):

ALTER TABLE Persons
ADD CONSTRAINT PK_Person PRIMARY KEY (ID,LastName);


--   5. Alterar a data de nascimento do paciente de código = 1 para ´01-09-1990´.

UPDATE Customers
SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
WHERE CustomerID = 1;

UPDATE paciente
SET datanasc = '1990-09-01'
WHERE codpaciente = 1;

--   6. Alterar o campo desconto de todos os pacientes para ´N´.

um update sem where


--   7. Sobre a tabela Paciente, alterar o campo endereço para ‘Rua Melo Alves,40’ e cidade para ‘Itu” 
--      para o paciente de código = 2.

analogo 5


--   8. Excluir a consulta 200, somente se o campo valor da consulta for igual a zero.
--   9. Excluir o paciente de código 55.

DELETE FROM table_name WHERE condition;

DELETE FROM paciente WHERE codpaciente = 1;

--   10. Excluir todos os pacientes da cidade de Sorocaba de sexo feminino.

analog 9 mas com WHERE e AND

--   11. Alterar o campo desconto de todos os pacientes de sexo feminino e idade superior a 60 anos para ‘S’.
--   12. Criar um novo campo na tabela paciente para registrar o telefone celular do paciente. Este campo deverá ser varchar2(15). 
--      Inserir o número de telefone dos pacientes neste novo campo.
