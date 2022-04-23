-- Aula do dia 13-03-2021  (Reposi��o)


- Inserindo dados nas tabelas

-- Inserindo 5 pacientes

insert into Paciente values  (1,'Maria Ant�nia da Silva', '20/03/1998','F','Rua das Flores,40','Sorocaba','S');
insert into Paciente values  (3,'Jos� Roberto Pereira', '20/04/2002','M','Rua Margarida,60','Itu','N');
insert into Paciente values  (4,'Ana Costa', '02/06/1998','F','Rua das Cam�lias,140','Sorocaba','S');
insert into Paciente values  (5,'Solange Pinheiro', '15/10/1994','F','Avenida Ver�o, 234','Itapetininga','N');
insert into Paciente values  (6,'Caio da Silva', '05/03/1998','M','Rua das Flores,40','Sorocaba','S');
insert into paciente values  (2,'Jose Maria','20/03/01','M','Rua Inverno, 30','Itu','N');

-- Verificando as inser��es

select * from paciente;
commit;

-- quando for necess�rio inserir dados em uma ordem diferente da ordem dos campos na tabela.
insert into Paciente (nompaciente, codpaciente,.....) values ('Maria Ant�nia da Silva', 2,...)


-- inserir 5 m�dicos
insert into medico values (100,'Dr. Who');
insert into medico values (101,'Dr. House');
insert into medico values (102,'Dr. Smith');
insert into medico values (103,'Dr. X');
insert into medico values (104,'Dr. Estranho');

-- inserir 5 consultas

insert into consulta values (300,'01-03-2021','P',3,102,500.50);
insert into consulta values (301,'05-02-2021','C',5,103,100.50);
insert into consulta values (302,'01-03-2020','P',2,102,600.00);
insert into consulta values (303,'25-04-2021','C',1,104,99.98);

-- verificando as inclus�es
select * from paciente;
select * from medico;
select * from consulta;
-------------------------------------------------------------

D.M.L

-- Consultando os dados inseridos

select * from paciente;

-- Update -- atualiza o conte�do de uma ou mais colunas da tabela

update paciente
set endereco = 'Rua Outono,40'
where codpaciente= 2;


update paciente
set endereco = 'Rua Inverno, 30',
    cidpaciente = 'Itu'
where codpaciente = 2;

-- Delete  - Exclui a linha (tupla) selecionada

delete paciente
where cidpaciente = 'Itu';

-----Exerc�cios - Lista 01 Pr�tica
Sobre o modelo Paciente-Consulta realize:

Preparar a base de dados para os testes a serem realizados da forma:

a.	Incluir um novo paciente com o c�digo = 55

insert into Paciente values  (55,'Jos� da Silva', '20/03/1999','F','Rua das Flores,40','Sorocaba','S');

b.	Incluir uma consulta de c�digo 200 com a coluna valor da consulta igual a zero.

insert into consulta values (200,'01-04-2021','P',3,102,0.0);

Escreva comandos em SQL para:

1.	Criar uma nova coluna na tabela paciente com o nome Pa�s varchar2(15);

alter table paciente add pais varchar2(15);

2.	Alterar a coluna endere�o da tabela de paciente para 28 posi��es.

alter table paciente modify endereco varchar2(28);

3.	Excluir a nova coluna criada no exerc�cio 1.

alter table paciente drop column pais;

4.	Incluir a restri��o NOT NULL na coluna endere�o.   

ALTER TABLE Paciente MODIFY(Endereco VARCHAR2(28) NOT NULL);

5.	Alterar a data de nascimento do paciente de c�digo = 1 para '01-09-1990'.

update paciente 
set Datanasc = '01-09-1990' 
where codpaciente= 1;

 select * from paciente 
 order by codpaciente;
 
6.	Alterar o campo desconto de todos os pacientes para �N�.

Update Paciente
set desconto = 'N';

7.	Sobre a tabela Paciente, alterar o campo endere�o para �Rua Melo Alves,40� 
    e cidade para �Itu� para o paciente de c�digo = 6.

    update paciente
    set endereco = 'Rua Melo Alves, 40',
        cidpaciente = 'Itu'
    where codpaciente = 6;

8.	Excluir a consulta 200, somente se o campo valor da consulta for igual a zero.

delete consulta
where codconsulta = 200 and valconsulta = 0.0;

9.	Excluir o paciente de c�digo 55.

delete paciente
where codpaciente = 55;

10.	Excluir todos os pacientes da cidade de Sorocaba de sexo feminino.
11.	Alterar o campo desconto de todos os pacientes de sexo feminino e idade superior a 60 anos para �S�.
12.	Criar um novo campo na tabela paciente para registrar o telefone celular do paciente. Este campo dever� ser varchar2(15). Inserir o n�mero de telefone dos pacientes neste novo campo.

