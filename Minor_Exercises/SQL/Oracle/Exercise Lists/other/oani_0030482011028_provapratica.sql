-- Fatec Sorocaba                            Disciplina de Banco de Dados	Avaliação de SQL	11/06/2021
-- Nome do aluno:	OANI DA SILVA DA COSTA 	0030482011028						Turma T1


-- Utilize o modelo abaixo para a elaboração das questões a seguir. 

 
-- 1-	Utilize o script a seguir para criação das tabelas em sua base de dados.

create table TipoMulta
( codtipoMulta  number(3) primary key,
  descricaoTipo Varchar2(20));

create table Veiculo
( placaVeiculo  char(7) primary key,
  modelo        varchar2(20),
  anoveiculo    date);

create table Motorista 
(CNH number(6)  primary key, 
NomeMotorista   varchar2(40), 
Sexo Char(1)    check (sexo in ('F', 'M')), 
CidadeNasc      varchar2(25), 
DataNasc        date,
Email           varchar2 (30),
Situacao        Char(1));

Create table  Multa
(NumMulta      number(6), 
 DataMulta     date,
 CNH           number(6),
 PlacaVeiculo  char(7), 
 Pontuacao     number(2),  
 codTipoMulta  number(2),
 ValorMulta    number(5,2));

-- 2-	Após criar as tabelas execute estes inserts:

INSERT INTO VEICULO VALUES ('GEE2345','HB20 HATCH','01/01/2017');
INSERT INTO VEICULO VALUES ('FTZ8809','HB20','01/01/2019');
INSERT INTO VEICULO VALUES ('GHT','GOLF','01/01/2021');

INSERT INTO TIPOMULTA VALUES (100,'GRAVE');
INSERT INTO TIPOMULTA VALUES (120,'GRAVÍSSIMA');
INSERT INTO TIPOMULTA VALUES (130,'LEVE');

-- Atenção:
-- Salve todos os comandos em um arquivo texto que deverá ser  enviado através do Teams(pode ser este da prova) respeitando o horário estipulado para término da prova. Lembre-se que o Teams finaliza a prova automaticamente.

-- 1.	Chaves e inserts							
-- a-	A tabela Multa possui 1 chave primária e 3 chaves estrangeiras, porém estas não estão no script apresentado. 
-- Crie as constraints para estas chaves usando o comando Alter table.


alter table multa modify NumMulta not null;
alter table multa modify NumMulta Primary key;

--PlacaVeiculo
alter table multa modify PlacaVeiculo not null;
ALTER TABLE multa modify PlacaVeiculo REFERENCES Veiculo;

--codTipoMulta
alter table multa modify PlacaVeiculo not null;
ALTER TABLE multa modify PlacaVeiculo REFERENCES TipoMulta;

--CNH
alter table multa modify PlacaVeiculo not null;
ALTER TABLE multa modify PlacaVeiculo REFERENCES Motorista;

----------b-	Inserir 3 linhas na tabela de Motorista 

--                            CNH, NomeMotorista, Sexo, CidadeNasc,     DataNasc,     Email, 
INSERT INTO Motorista VALUES (123456, AAAAAAA,      M,    'Sorocaba'  ,'10/11/1991', aaaa@prov.com, 'n');
INSERT INTO Motorista VALUES (123457, BBBBBBB,      F,    'Campinas'  ,'10/11/1992', bbbb@prov.com, 'n');
INSERT INTO Motorista VALUES (123458, CCCCCCC,      F,    'Sao_Paulo' ,'10/11/1993', cccc@prov.com, 'n');


----------e 3 na tabela de Multas.

alter table multa modify codtipomulta number(3);

--                        NumMulta, DataMulta , CNH    , PlacaVeiculo , Pontuacao ,   codTipoMulta , ValorMulta ;
INSERT INTO multa VALUES (111111, '1/1/1997',   123456, 'abc1234',     20,           100,            10000.50);
INSERT INTO multa VALUES (111112, '2/1/1997',   123457, 'def5678',     20,           120,            10001.50);
INSERT INTO multa VALUES (111113, '3/1/1997',   123458, 'ghi9012',     20,           130,            10002.50);


------------------- 2. Escreva os comandos para:

-- 1.	Adicionar o campo  MarcaVeiculo com 20 posições alfanuméricas na tabela de Veículos.

ALTER TABLE VEICULO ADD (MarcaVeiculo varchar2(20));

-- 2.	Alterar o campo ValorMulta da tabela de Multa para aceitar 4 inteiros e 2 decimais.

alter table multa modify ValorMulta number(6,2);

-- 3.	Eliminar o campo email da tabela de Motorista.

ALTER TABLE Motorista DROP COLUMN email;

-- 4.	Excluir as multas com ano multa menor que 2 anos atrás (usar a data do sistema,  não fixar 2021).

Delete multa
where DataMulta < SYSDATE - (365.25 * 2); --2 anos considerando o .25 de bisexto

-- 5.	Atualizar  o campo CidadeNasc da tabela de  Motorista com  CNH = ‘09876543’  para  ‘Campinas’.

update Motorista
set CidadeNasc = 'Campinas'
where CNH = '09876543';

-- 6.	Listar a CNH, o nome do motorista e data de nascimento de todos os motoristas do sexo masculino 
--    e que moram na cidade de ‘Sorocaba’.  
--    Exibir o resultado ordenado pelo nome.

select cnh,nomemotorista,datanasc from motorista 
where sexo = 'M' and cidadenasc = 'Sorocaba'
order by NomeMotorista;

-- 7.	Listar  o valor das Multas aumentado em 10% onde o campo CodTipoMulta = 100 e o campo Pontuação estiver entre 3 e 7 pontos.

select (ValorMulta * 1.1) from TB_PRODUTO;
where CodTipoMulta = 100
where Pontuacao between 3 and 7;

-- 8.	Listar a placa do veículo e a soma dos valores das multas que cada veiculo tem.      

select placaveiculo, SUM(valormulta) from multa
group by placaveiculo;

-- 9.	Exibir o número da multa, data da multa, CNH e nome do motorista para todas as multas com pontuação > 20 
--    e idade do motorista entre 18 e 25 anos.

select multa.nummulta, multa.datamulta, multa.cnh, motorista.nomemotorista
from multa inner join motorista 
  on multa.cnh=motorista.cnh
where multa.pontuacao > 20 and ((sysdate - DataNasc) / 365.25) between 18 and 25;

-- 10.	Exibir o código da multa, a data da multa, nome do motorista, e marca do veículo para cada multa ordenado pela data da multa.

select multa.nummulta, multa.datamulta, motorista.nomemotorista, VEICULO.marcaveiculo
from multa inner join motorista on motorista.cnh = multa.cnh
    inner join veiculo on veiculo.placaveiculo = multa.placaveiculo
order by datamulta;

-- 11- Criar uma visão para exibir a placa dos veiculos  que tem mais de 3 multas.

create of replace view Placas_mais_3_multas
as
  select placaVeiculo
  group by placaVeiculo
  HAVING (count(*) > 3);

-- 12-  Considere a seguinte consulta em SQL

Select nomemotorista from Motorista
  intersect
  Select nomemotorista from Motorista innerjoin Multa 
  on Motorista.cnh = Multa.cnh 
and data.pagamento is null

-- Quando esta consulta é realizada o que é recuperado?

-------------------------ESSE-----------------------------|
-- a- Nome dos motoristas que tem multas e não foram pagas|
-------------------------ESSE-----------------------------|

-- b- Nome dos motorista  que não tem multas ou tem multas que não foram pagas
-- c- Nome dos motoristas que  tem multas pagas ou não
-- d- Nome dos motoristas que não tem multas

------------------------------------------------ Boa Prova !!! -------------------------------------------
--                                         ----- OBRIGADO =D -------
--                                         ----- OBRIGADO =D -------
--                                         ----- OBRIGADO =D -------
--                                         ----- OBRIGADO =D -------
--                                         ----- OBRIGADO =D -------
--                                         ----- OBRIGADO =D -------
--                                         ----- OBRIGADO =D -------