-- Aula do dia 28-05 Turma 1
--
1- Vis�o 1
===========

Vis�es s�o ut�is para
Reuso -
Simplificar achamada a selects complexos
Prote��o 

drop view pacsor;

create or replace view pacsor
as select * from paciente 
where cidpaciente = 'Sorocaba'
with check option;

select * from pacsor;

select * from pacsor
where sexo = 'F';

select count(*) from pacsor;

select * from paciente;


== � poss�vel Inserts em vis�es?

insert into pacsor
values (78,'Roberta souza',sysdate,'F','rua','Sorocaba','S');

select * from paciente;

insert into pacsor values (61,'Maria',sysdate,'F','rua x','itu','S');

== � poss�vel Update em vis�es??

update pacsor
 set nompaciente = 'kkkkkk'
where codpaciente = 2;

select * from paciente

update pacsor
set nompaciente = 'DDDD'
where codpaciente = 3;

==� poss�vel Delete em vis�es?

delete pacsor
where codpaciente = 77;


delete pacsor
where codpaciente = 3;


2 Vis�o 2
===========

create or replace view pacsor_res
as select codpaciente,nompaciente,datanasc as data_nascimento, sexo
from pacsor;

select * from pacsor_res;

=== Ainda funciona o insert em pacsor_res??

insert into pacsor_res(codpaciente,nompaciente,data_nascimento,sexo)
values (49,'Ana',sysdate,'F');

update pacsor_res
 set nompaciente = 'KKKKK'
where codpaciente = 78;

update pacsor_res
 set nompaciente = 'KKKKK'
where codpaciente = 3;

select * from paciente;

select * from pacsor_res;

delete pacsor_res
where sexo = 'F';

3 vis�o 3   => n�o � atualiz�vel pq tem jun��o
==========

create or replace view consulta_pac
as select p.codpaciente, p.nompaciente, c.codconsulta
from paciente p, consulta c
where c.codpaciente = p.codpaciente;

� a mesma coisa que:

create or replace view consulta_pac
as select p.codpaciente, p.nompaciente, c.codconsulta
from paciente p inner join consulta c
on c.codpaciente = p.codpaciente;

select * from consulta_pac;

select * from consulta;

-- N�o funciona update, nem delete e nem insert pq a vis�o � resultante 
-- da jun��o de tabelas
update consulta_pac
set nompaciente = 'ser�?'
where codpaciente = 2;

4 vis�o 4   => n�o � atualiz�vel porque tem campos calculados ou derivados
==========

create or replace view salario_liq
as select codmedico, (valconsulta * 0.75)as valorliq , 'medico bom'  as avaliacao
from consulta;

select * from salario_liq;

select valorliq from salario_liq

select codmedico, (valconsulta * 0.75) 
from consulta;


select 'joao' as nome, '8.0' as nota from dual;

5 vis�o 5          =>  n�o � atualiz�vel
============

create or replace view totalmed
as select codmedico, count(*) as totalconsultas
from consulta
group by codmedico;


select codmedico, totalconsultas from totalmed;

select count(*) from totalmed;


ATEN��O:

uma vis�o � atualiz�vel ( permite insert, update e delete) se:

n�o tiver jun��o
n�o tiver group by, having, fun��es (sum, count, max, etc..)
n�o tiver campos calculados

== consultas as vis�es criadas

select * from user_views

1.	Crie uma vis�o que possua: 

C�digo do medico,c�digo do paciente e a data da consulta acrescentada em 30 dias (retorno).


create or replace view View_retornoMedico
as
select codmedico,codpaciente, (dataconsulta + 30) as DataRetorno
from consulta;

create  or replace view View_01
as select codmedico, paciente.codpaciente , (dataconsulta + 30) as Data_Retorno,
add_months(dataconsulta, + 1) as Dataproximo_mes
from paciente inner join consulta
on paciente.codpaciente = consulta.codpaciente;

select * from view_01


select * from user_views;
