-------------- FATEC Sorocaba - Banco de Dados ------------------
------------------- Oaní da Silva da Costa ----------------------

-----------------------------------------------------------------
---------------INSERTS DA TABELA PACIENTE CONSULTA---------------
-----------------------------------------------------------------

-- 1.	Crie uma visão que possua: Código do medico,código do paciente e a data da consulta acrescentada em 30 dias (retorno).

GO
create view retorno as
select paciente.codpaciente, medico.codmedico, (dataconsulta + 30) as retorno
from paciente
    inner join consulta on consulta.codpaciente = paciente.codpaciente
    inner join medico on consulta.codmedico = medico.codmedico;
GO

-- 2.	Crie uma visão que possua: nome do medico, nome do paciente e código da consulta e  dataconsulta.

GO
create view NOME --nao foi dado o nome
as
select paciente.nompaciente , medico.nomemedico , consulta.codconsulta, consulta.dataconsulta
from paciente
    inner join consulta on consulta.codpaciente = paciente.codpaciente
    inner join medico on consulta.codmedico = medico.codmedico;
GO

-- 3.	Crie uma visão que exiba o código do medico e o valor total de suas consultas

GO
create view NOME --nao foi dado o nome
as
select medico.codmedico , medico.nomemedico , (sum (consulta.valconsulta) ) as valortotal
from consulta
    inner join medico on consulta.codmedico = medico.codmedico
group by medico.codmedico, medico.nomemedico;
GO


-- 4.	Crie uma visão que exiba o código do medico, o nome do medico  e o valor médio de suas consultas
GO
create view NOME --nao foi dado o nome
as
select medico.codmedico , medico.nomemedico , ((sum (consulta.valconsulta) ) / count(*)) as valormedio
from consulta
    inner join medico on consulta.codmedico = medico.codmedico
group by medico.codmedico, medico.nomemedico;
GO
-- 5.	Listar o nome de todas as visões que tem a string “SOR’ no nome. Usar a tabela User_views

select *
from user_views
where view_name like '%PACSOR%';