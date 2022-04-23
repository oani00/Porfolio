-- Aula do dia 12-03-2021
-- Criação de Tabelas


Create table Paciente
( Codpaciente    number(4,0)    Primary  Key,
  Nompaciente    varchar2(30)   not null,
  Datanasc       date,
  Sexo           char( 1 ) check (sexo in ( 'F',  'M' )),	
  Endereco      varchar2(25) ) ;

Create table Medico
(codmedico number(4,0) primary key,
 nomeMedico  varchar2(40));
 
 
Create table Consulta
(   Codconsulta   number(3,0)     Primary Key ,
    Dataconsulta  date,
    Tipocons      char(01)   check  (tipocons in ('P','C')),
    Codpaciente  number(4,0) Not Null   References Paciente,                   
    Codmedico    number(4,0) Not Null   References Medico ,
    Valconsulta  number(6,2) Not Null ) ;

-----
comando Alter Table

ALTER TABLE  Paciente ADD (cidpaciente varchar2( 15 )  ) ;

ALTER TABLE  Paciente  MODIFY (cidpaciente varchar2( 20 )   NOT   Null ) ;

ALTER TABLE  Paciente  ADD (desconto char( 01 ) check  (desconto in ('S','N' ) )) ;

ALTER TABLE  Paciente ADD (colunalixo varchar2( 15 )  ) ;

-- Excluir a coluna "colunalixo" da tabela paciente

ALTER TABLE  Paciente drop column colunalixo;


-- ALTER TABLE  Paciente ADD ( Check  (sexo in ('F', 'M' ))) ;


--- Inserindo dados nas tabelas

insert into Paciente values  (1,'Maria Antônia da Silva', '20/03/1998','F','Rua das Flores,40','Sorocaba','S');
insert into ....

-- inserir 5 pacientes

-- inserir 5 médicos
insert into medico values (100,'Dr. Who');


-- inserir 5 consultas




