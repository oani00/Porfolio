-- Aula do dia 16-04-2021

Elaboração da lista 02 (prática)
--
Criação da tabelas

1- criar as tabelas Depto, Projeto, Funcionario e FuncProj
nesta ordem devido à dependencia de chaves primaria e estrangeira

Create table Depto
(coddepto number(4) primary key,
 Nomedepto  varchar2(20));
 
 Create table Projeto
(codProjeto number(4) primary key,
 Descricao  varchar2(20));
 
 Create table Funcionario
(codFuncionario number(4) primary key,
 nomeFunc varchar2(40),
 sexo char(1) check (sexo in ('F','f','M','m')),
 datadmissao date,
 salario number(7,2),
 coddepto number(4) references Depto);
 
 create table FuncProj
 ( codFunc number(4)references Funcionario,
   codProj number(4) references Projeto,
   tempoAlocacao number(4),
   bonuSalario number(6,2),
   primary key(codfunc,codProj));
   
 
 --- Inserts
 
 Insert into Depto values (100, 'TI');
 Insert into Depto values (200, 'RH');
 Insert into Depto values (300, 'CTB');
 Insert into Depto values (400, 'LOgistica');
 
 select * from depto;
 
 -------
 Alter table Projeto modify descricao varchar2(50);
 
 Insert into Projeto values (111, 'Aplicação WEB  para Vendas');
 Insert into Projeto values (222, 'Projeto de reestruturação RH');
 Insert into Projeto values (333, 'Aplicação WEB  para Contabilidade');
 Insert into Projeto values (444, 'Aplicativo Android para Vendedores');
  Insert into Projeto values (555, 'Suporte para Logistica');
  
  select * from projeto
 ------------------------------------------------------------
Inserindo dados para tabela de funcionario

insert into funcionario values (1,'Maria Antonia da Silva', 'F', '02-03-2021',3200.00,300);
insert into funcionario values (2,'Marcos Silva', 'M', '02-03-2020',4200.00,100);
insert into funcionario values (3,'Claudia Andrade', 'F', '12-08-2010',8000.00,100);
insert into funcionario values (4,'Pedro Pereira', 'M', '25-03-1999',6000.00,200);
insert into funcionario values (5,'Renata', 'F', '11-10-2005',3500.00,400);

select * from funcionario;
----
inserindo dados para a tabela FuncProj

delete from funcproj

insert into FuncProj values (1,111,12,300.00);
insert into FuncProj values (1,444,6,100.00);
insert into FuncProj values (2,333,8,100.00);
insert into FuncProj values (3,444,6,100.00);
insert into FuncProj values (3,333,4,100.00);
insert into FuncProj values (4,222,6,150.00);
insert into FuncProj values (5,555,16,200.00);

select * from funcproj

----------------------------------------------------------------------
2.	Escreva comandos para:

a)	Alterar a tabela TB_Funcionario adicionando a coluna telefone varchar(15); 

alter table funcionario add  telefone varchar(15)

b)	Alterar o campo Descricao da tabela projeto para varchar(40).

alter table projeto modify descricao varchar2(40);

c)	Criar o campo Cidade varchar2(30) na tabela de funcionario.

alter table funcionario add cidade varchar2(30);

d)	Excluir o campo Cidade da tabela de Funcionario.

alter table funcionario drop column cidade;

e)	Para o funcionário de código = 003 atualizar a coluna telefone para ‘(15) 3238-1188’.   

update TB_Funcionario
set telefone = '15-32291233'
where CodFunc = 3;

f)	Excluir todos os funcionários lotados no departamento de código 300.

Delete funcionario
where coddepto =300;

select * from funcionario;

select * from funcproj;

g)	Listar o nome do funcionário, data de admissão e 
código do departamento do funcionário  cujo salário estiver entre 1.000 e  5.000 reais.

select nomefunc, datadmissao, coddepto, salario
from funcionario
where salario between 1000.00 and 5000.00;

h)	Listar todas as colunas da tabela TB_FuncProj onde a coluna Bonus_salario for diferente de zero, e tempo alocação maior que 3, ordenado pela coluna TempoAlocação


i)	Listar  o nome dos funcionarios que foram admitidos no ano atual.
