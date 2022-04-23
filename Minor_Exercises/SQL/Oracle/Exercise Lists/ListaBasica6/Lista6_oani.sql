----------- FATEC Sorocaba - Banco de Dados ---------------
---------------- Oaní da Silva da Costa -------------------

Create table Paciente
( Codpaciente    number(4,0)    Primary  Key,
  Nompaciente    varchar2(30)   not null,
  Datanasc       date,
  Sexo           char( 1 ) check (sexo in ( 'F',  'M' )),	
  Endereco      varchar2(25) ) ;


Create table Consulta
(   Codconsulta   number(3,0)     Primary Key ,
    Dataconsulta  date,
    Tipocons      char(01)   check  (tipocons in ('P','C')),
    Codpaciente  number(4,0) Not Null   References Paciente,                   
    Codmedico    number(4,0) Not Null   References Medico ,
    Valconsulta  number(6,2) Not Null );

Create table medico
(codmedico number(4,0) primary key,
 nomeMedico  varchar2(40));

-- 1.	Crie uma visão que possua: Código do medico,código do paciente e a data da consulta acrescentada em 30 dias (retorno).

create or replace view retorno
as 
select paciente.codpaciente, medico.codmedico, (dataconsulta + 30) as retorno
from paciente 
    inner join consulta on consulta.codpaciente = paciente.codpaciente
        inner join medico on consulta.codmedico = medico.codmedico;

-- 2.	Crie uma visão que possua: nome do medico, nome do paciente e código da consulta e  dataconsulta.

create or replace view NOME --nao foi dado o nome
as 
select paciente.nompaciente ,medico.nomemedico , consulta.codconsulta, consulta.dataconsulta
from paciente 
    inner join consulta on consulta.codpaciente = paciente.codpaciente
        inner join medico on consulta.codmedico = medico.codmedico;

-- 3.	Crie uma visão que exiba o código do medico e o valor total de suas consultas

create or replace view NOME --nao foi dado o nome
as 
select medico.codmedico , medico.nomemedico ,  (sum (consulta.valconsulta) ) as valortotal
from consulta 
    inner join medico on consulta.codmedico = medico.codmedico
group by medico.codmedico, medico.nomemedico;

-- 4.	Crie uma visão que exiba o código do medico, o nome do medico  e o valor médio de suas consultas

create or replace view NOME --nao foi dado o nome
as 
select medico.codmedico , medico.nomemedico ,  ((sum (consulta.valconsulta) ) / count(*)) as valormedio
from consulta 
    inner join medico on consulta.codmedico = medico.codmedico
group by medico.codmedico, medico.nomemedico;

-- 5.	Listar o nome de todas as visões que tem a string “SOR’ no nome. Usar a tabela User_views

select * from user_views
where view_name like '%PACSOR%';