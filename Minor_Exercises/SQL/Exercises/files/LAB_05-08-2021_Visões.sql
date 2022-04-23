-- revisão Visões em SQL
--
select * from user_tables;
select * from user_constraints order by table_name;

select * from user_views;

select view_name from user_views;

create or replace view pacsor
as select * from paciente 
where cidpaciente = 'Sorocaba'
with check option;

select * from pacsor;

select * from paciente;

insert into pacsor
values (77,'Roberto souza',sysdate,'M','rua','Sorocaba','S');

insert into pacsor values (61,'Maria',sysdate,'F','rua x','itu','S');

update pacsor
 set nompaciente = 'Carlos Souza'
where codpaciente = 10;

2 Visão 2
===========

create or replace view pacsor_res
as select codpaciente,nompaciente,datanasc as data_nascimento, sexo
from pacsor;


insert into pacsor_res(codpaciente,nompaciente,data_nascimento,sexo)
values (49,'Ana',sysdate,'F');

update pacsor_res
 set nompaciente = 'KKKKK'
where codpaciente = 7;

select * from paciente;

update pacsor_res
 set cidpaciente = 'KKKKK'
where codpaciente = 7;

delete pacsor_res
where sexo = 'F';

3 visão 3   => não é atualizável pq tem junção
==========

create or replace view consulta_pac
as select p.codpaciente, p.nompaciente, c.codconsulta
from paciente p, consulta c
where c.codpaciente = p.codpaciente;

4 visão 4   => não é atualizável porque tem campos calculados ou derivados
==========

create or replace view salario_liq
as select codmedico, (valconsulta * 0.75) as valorliq, 'medico bom'  as avaliacao
from consulta;

select * from salario_liq;

select valorliq from salario_liq

select codmedico, (valconsulta * 0.75) 
from consulta;

----- Lista de fixação

1.	Crie uma visão que possua: Código do medico,código do paciente e a 
data da consulta acrescentada em 30 dias (retorno).

create or replace view v_ex1
as
select codmedico,codpaciente, (dataconsulta + 30) as dataretorno
from consulta;

select * from v_ex1;

select * from consulta;

2.	Crie uma visão que possua: nome do medico,código da consulta e  dataconsulta.


3.	Crie uma visão que exiba o código do medico e o valor total de suas consultas

4.	Crie uma visão que exiba o código do medico, o nome do medico  e o valor médio de suas consultas

5.	Listar o nome de todas as visões que tem a string “SOR’ no nome.

user_views



