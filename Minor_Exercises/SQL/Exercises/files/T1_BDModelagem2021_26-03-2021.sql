
-- Aula do dia 26-03-2021

Revis�o da aula de reposi��o do s�bado  dia 20-03-2021

-- Comando SELECT

 select * from paciente;
 
select nompaciente, endereco from paciente;

-- informando cabe�alho para as colunas

select nompaciente as NOME , endereco "Endere�o do Paciente" from paciente;

--
express�es aritm�ticas

select codconsulta, codmedico, valconsulta*0.8 as Valor_liquido
from consulta;

select codconsulta, codmedico, valconsulta*0.8 as Valor_liquido, 'Este m�dico � bom' "Observa��o"
from consulta;

-- selecionar linhas sem repeti��o

select * from paciente;

select distinct(cidpaciente) from paciente;

-- Order by

select distinct(cidpaciente)as cidade from paciente
order by cidpaciente;

select * from paciente
order by nompaciente;

-- Listar em ordem decrescente
select * from paciente
order by nompaciente desc;


-- Listar em ordem decrescente
select * from paciente
order by cidpaciente, nompaciente;


-- Filtrando a sele��o

select * from paciente
where sexo = 'F' and cidpaciente = 'Sorocaba';


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
  
  -- � equivalente a 
  
  Update paciente
 set desconto = 'S'
 where datanasc >= '01-01-2001' and datanasc <= '31-12-2001' 
  cidpaciente = 'Sorocaba';
  
   
  
  -- pesquisando strings
  
  SELECT * FROM paciente;
  
  select * from paciente
  where nompaciente like '%Silva%';
  
  update paciente
  set nompaciente = 'Ana Silva Costa'
  where codpaciente = 4;
  
  select codpaciente|| '= Nome paciente:', nompaciente from paciente
  order by codpaciente;
  
  
  Exerc�cio
  
  -- listar o codigo de cada paciente com a frase:  ' Bom dia nome do paciente';
  
  
  select codpaciente || ' Bom dia, ' || nompaciente ||'!' "Saudac�o"
  from paciente;

  
  -- Listar a data da consulta, codigo do m�dico, valor da consulta
  para todos os medicos com valconsulta > 100.00  para o paciente de c�digo 2
  ordenado pela coluna codmedico;
  
  select * from consulta
  
  select dataConsulta, codMedico, valConsulta 
  from consulta 
  where valConsulta > 100.00 and codpaciente = 2 
  order by codmedico;
  
  ----   Conceitos novos
  
  Manipula��o de datas no Oracle
  
  select sysdate from dual;
  
  select * from dual;
  
 --  data do sistema dd-mm-yyyy:hh24:mi:ss
 
 -- To_char(data,mascara)  => transforma formato date em string
 
 select to_char(sysdate,'dd-mm-yyyy:hh24:mi:ss') from dual;
 
 select to_char(sysdate,'dd:hh24:mi:ss') from dual;
 
 select * from consulta 
 where to_char(dataconsulta, 'yyyy') = '2021';
 
 select * from consulta;
 
 -- Fun��o to_date
 -- Converte string para formato DATE
 
  to_date( string_a_ser_convertida,mascara,)
 
 insert into consulta 
 values (305,to_date('27-04-2021:11:15', 'dd-mm-yyyy:hh24:mi'),'C',1,104,99.98);
 
 select codconsulta, to_char(dataconsulta,'dd-mm-yyy:hh24:mi:ss') as dataConsulta, codpaciente
 from consulta;

 select * from consulta
 
 -- Diferen�a entre datas ( devolve o numero de dias entre as 2 datas)
 
 select (sysdate - datanasc)/365.25, nompaciente from paciente
 
 
 -- fun��o add_months - soma ou subtrai meses de uma data
 
 select dataconsulta as Original, (dataconsulta + 30) as alterada
 from consulta;
 
 
 select dataconsulta as Original, add_months(dataconsulta, -1) as alterada
 from consulta;
 
 -- somar ou subtrair dias
 
 update consulta 
 set dataconsulta = dataconsulta - 12
 where codconsulta = 123;
 
 select * from consulta;
 
 -- para somar ou subtrair anos de uma data usar add_months(data, -12)
 
 --Para casa: Fazer a Lista02_pratica  dispon�vel no Teams na pasta de
 -- exercicios de aula pr�tica
 