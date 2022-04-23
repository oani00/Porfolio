/-- Aula do dia 12-03-2021 - TURMA 02
-- Criação de Tabelas
-- Comandos DDL DATA DEFINITION LANGUAGE
--
Create table Paciente
( Codpaciente    number(4,0)    Primary  Key,
  Nompaciente    varchar2(30)   not null,
  Datanasc       date,
  Sexo           char( 1 ) check (sexo in ( 'F',  'M' )),	
  Endereco      varchar2(25) ) ;

Create table medico
(codmedico number(4,0) primary key,
 nomeMedico  varchar2(40));
 
 
Create table Consulta
(   Codconsulta   number(3,0)     Primary Key ,
    Dataconsulta  date,
    Tipocons      char(01)   check  (tipocons in ('P','C')),
    Codpaciente  number(4,0) Not Null   References Paciente,                   
    Codmedico    number(4,0) Not Null   References Medico ,
    Valconsulta  number(6,2) Not Null ) ;

-- ALTER TABLE
ALTER TABLE  Paciente ADD (cidpaciente varchar2( 15 )  ) ;

ALTER TABLE  Paciente  MODIFY (cidpaciente varchar2( 20 )   NOT   Null ) ;

ALTER TABLE  Paciente  ADD (desconto char( 01 )   check  (desconto in ('S','N' ) )) ;

ALTER TABLE  Paciente ADD ( Check  (sexo in ('F', 'M' ))) ;

Excluindo uma coluna ( para versões a partir do oracle 8i):

alter table paciente add colunalixo varchar2(30);

ALTER TABLE Paciente DROP COLUMN colunalixo;

-----------------------------------------------------------
Excluir uma tabela

drop table tabxxx;

-----------------------------------------------------------

Comandos DML - DATA Manipulation Language

insert into paciente values (2,'Jose Maria','20-03-2001','M','Rua Primavera,23', 'Sorocaba','N');

select * from paciente;
select * from medico;

-- inserir mais 5 pacientes (2 com desconto = 'S')


-- Inserir 5 médicos

insert into medico values (100,'Dr.WHO');

--- Inserir 5 consultas

insert into consulta values (123,sysdate,'P',2,100,500.50);

---