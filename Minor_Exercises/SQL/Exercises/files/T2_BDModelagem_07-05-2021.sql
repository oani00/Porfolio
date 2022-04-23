-- aula do dia 07-05
gabarito da lista04 - Funções de grupo

1.	Listar a maior quantidade que conste na tabela de item do pedido.

select max(qtde) from tb_item_pedido;

select * from tb_item_pedido;

2.	Listar o menor valor unitário da tabela de produtos.

select min (valor_unit) from tb_produto;

select * from tb_produto

3.	Listar a somatória dos salários fixos pago aos vendedores.

select * from tb_vendedor;

select sum(salario_fixo) as Total_salario  from tb_vendedor;

4.	Listar o número de produtos cuja unidade seja igual a "CX".

insert into TB_produto values (6,'Caneta vermelha','CX', 5.00,30);
insert into TB_produto values (7,'Caneta BIC','cx', 5.00,30);

select count(*) as total from Tb_produto
where upper(unid) = 'CX';

select * from tb_produto;

5.	Listar o número de clientes agrupados por cidade.

update tb_cliente
set cidade = 'SOROCABA'
where codcliente=32;

select * from tb_cliente order by cidade; -- não estou agrupando!!!

select cidade, count(*) from tb_cliente -- eu estou agrupando!!
group by cidade;

6.	Listar quantos pedidos cada vendedor realizou.

select codvendedor,count(*) from tb_pedido
group by codvendedor;

select * from tb_pedido order by codvendedor -- para verificar

7.	Listar o maior e o menor valor unitário para cada tipo de unidade de produto.

select unid, min(valor_unit), max(valor_unit), avg (valor_unit) from tb_produto
group by unid;

8.	Listar o número de clientes, agrupados por cidade para todas as cidades
que aparecem mais de 1 vez na tabela de clientes.

select cidade, count(*) from tb_cliente
group by cidade
having count(*) > 1;

--------------------------------------------------------
Junção de tabelas

Usando o Modelo Paciente Consulta Medico criado em aulas anteriores, escreva comandos para:


1- Exibir o código da consulta, data da consulta e o código e nome do paciente 
que fizeram consultas em 2021.

select consulta.codconsulta,consulta.dataconsulta,paciente.codpaciente,paciente.nompaciente
from consulta inner join paciente
on consulta.codpaciente = paciente.codpaciente
where to_char(dataconsulta,'yyyy') = '2021';

select C.codconsulta,C.dataconsulta,P.codpaciente,P.nompaciente
from consulta C inner join paciente P
on C.codpaciente = P.codpaciente
where to_char(C.dataconsulta,'yyyy') = '2021';

2- Exibir a data da consulta, nome do medico e nome do paciente
para todos os pacientes de sexo Masculino.

select C.dataconsulta, M.nomemedico, P.nompaciente
from consulta C inner join medico M on C.codmedico = M.codmedico
                inner join paciente P on C.codpaciente = P.codpaciente
where sexo='M';

------
junção de empregados e departamentos
exibir o nome do depto e o funcionario alocado

select nomefunc, depto.coddepto, nomedepto
from depto inner join funcionario
on depto.coddepto= funcionario.coddepto;




1- Exibir o código da consulta, data da consulta e o código e nome do paciente que fizeram consultas em 2021.

select consulta.codconsulta,consulta.dataconsulta, paciente.codpaciente,paciente.nompaciente
from consulta inner join paciente
on consulta.codpaciente  = paciente.codpaciente
where to_char(dataconsulta, 'yyyy') = '2021';


2- Exibir a data da consulta, nome do medico e nome do paciente para todos os pacientes 
de sexo Masculino.

select consulta.dataconsulta, medico.nomemedico,paciente.nompaciente                          
from paciente inner join consulta
     on paciente.codpaciente = consulta.codpaciente
     inner join medico
     on medico.codmedico = consulta.codmedico
where sexo = 'M';
