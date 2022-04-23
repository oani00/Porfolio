-- Aula do dia 28-05 Turma 1
--
1- Visão 1
===========

Visões são utéis para
Reuso -
Simplificar achamada a selects complexos
Proteção 

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


== É possível Inserts em visões?

insert into pacsor
values (78,'Roberta souza',sysdate,'F','rua','Sorocaba','S');

select * from paciente;

insert into pacsor values (61,'Maria',sysdate,'F','rua x','itu','S');

== é possível Update em visões??

update pacsor
 set nompaciente = 'kkkkkk'
where codpaciente = 2;

select * from paciente

update pacsor
set nompaciente = 'DDDD'
where codpaciente = 3;

==é possível Delete em visões?

delete pacsor
where codpaciente = 77;


delete pacsor
where codpaciente = 3;


2 Visão 2
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

3 visão 3   => não é atualizável pq tem junção
==========

create or replace view consulta_pac
as select p.codpaciente, p.nompaciente, c.codconsulta
from paciente p, consulta c
where c.codpaciente = p.codpaciente;

é a mesma coisa que:

create or replace view consulta_pac
as select p.codpaciente, p.nompaciente, c.codconsulta
from paciente p inner join consulta c
on c.codpaciente = p.codpaciente;

select * from consulta_pac;

select * from consulta;

-- Não funciona update, nem delete e nem insert pq a visão é resultante 
-- da junção de tabelas
update consulta_pac
set nompaciente = 'será?'
where codpaciente = 2;

4 visão 4   => não é atualizável porque tem campos calculados ou derivados
==========

create or replace view salario_liq
as select codmedico, (valconsulta * 0.75)as valorliq , 'medico bom'  as avaliacao
from consulta;

select * from salario_liq;

select valorliq from salario_liq

select codmedico, (valconsulta * 0.75) 
from consulta;


select 'joao' as nome, '8.0' as nota from dual;

5 visão 5          =>  não é atualizável
============

create or replace view totalmed
as select codmedico, count(*) as totalconsultas
from consulta
group by codmedico;


select codmedico, totalconsultas from totalmed;

select count(*) from totalmed;


ATENÇÃO:

uma visão é atualizável ( permite insert, update e delete) se:

não tiver junção
não tiver group by, having, funções (sum, count, max, etc..)
não tiver campos calculados

== consultas as visões criadas

select * from user_views

1.	Crie uma visão que possua: 

Código do medico,código do paciente e a data da consulta acrescentada em 30 dias (retorno).


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
