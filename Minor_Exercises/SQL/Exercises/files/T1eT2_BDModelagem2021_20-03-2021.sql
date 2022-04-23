--- Aula do dia 20-03-2021

-- Comando SELECT

select nompaciente, endereco from paciente;

-- informando cabeçalho para as colunas

select nompaciente  NOME , endereco "Endereço do Paciente" from paciente;

--
expressões aritméticas

select codconsulta, codmedico, valconsulta*0.8 Valor_liquido
from consulta;

select codconsulta, codmedico, valconsulta*0.8 Valor_liquido, 'Este médico é bom' Observacao
from consulta;

-- selecionar linhas sem repetição

select distinct(cidpaciente) from paciente;

-- Order by

select distinct(cidpaciente)as cidade from paciente
order by cidade;

-- Between

Update paciente
 set desconto = 'S'
 where datanasc >= '01-01-2001' and datanasc <= '31-12-2001' and
  cidpaciente = 'Sorocaba';
  
  usando between

Update paciente
 set desconto = 'S'
 where datanasc between  '01-01-2001' and '31-12-2001' and
  cidpaciente = 'Sorocaba';
  
  -- pesquisando strings
  
  SELECT * FROM paciente;
  
  select * from paciente
  where nompaciente like '%Silva%';
  
  update paciente
  set nompaciente = 'Ana Silva Costa'
  where codpaciente = 4;
  
  select codpaciente|| '= ', nompaciente from paciente
  order by codpaciente;
  
  Exercício
  
  -- listar o codigo de cada paciente com a frase:  ' Bom dia nomedo paciente'
  
  select codpaciente, ' Bom dia, ' || nompaciente || '!' from paciente
  order by codpaciente;
  
  -- Listar a data da consulta, codigo do médico, valor da consulta
  para todos os medicos com valconsulta > 100.00  para o paciente de código 2
  ordenado pela coluna codmedico;
  
  select * from consulta
  
  select dataconsulta,codmedico,valconsulta
  from consulta
  where valconsulta > 100 and codpaciente = 2
  order by codmedico, valconsulta;
  
  select * from consulta
  order by codmedico,codpaciente
  