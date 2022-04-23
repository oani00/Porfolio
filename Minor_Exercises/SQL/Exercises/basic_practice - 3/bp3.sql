------------------------------------ Comandos DDL: ------------------------------------

-- 1.	Criar as tabelas do modelo lógico Cliente-Pedido indicado acima.
-- 2.	Criar os relacionamentos necessários (chaves primárias e chaves estrangeiras) 

----TABELA TB_CLIENTE

Create table TB_CLIENTE
(
  CodCliente number(5,0) Primary  Key,
  NomeCliente varchar(40) not null,
  Endereco varchar(30),
  Cidade varchar(20),
  Cep varchar(10),
  UF char(10)
);

----TABELA TB_VENDEDOR 

Create table TB_VENDEDOR
(
  CodVendedor number(5) Primary  Key,
  NomeVendedor varchar(30) ,
  FaixaComissao number(4,2)  ,
  SalarioFixo number(7,2)
  ,
);


----TABELA TB_PEDIDO 

Create table TB_PEDIDO
(
  NumPedido number(5) Primary  Key,
  PrazoEntrega date,
  CodCliente number(5) FOREIGN KEY REFERENCES TB_CLIENTE(CodCliente) ,
  CodVendedor number(5) FOREIGN KEY REFERENCES TB_VENDEDOR(CodVendedor),
);

----TABELA TB_PRODUTO 

Create table TB_PRODUTO
(
  CodProduto number(5) Primary  Key,
  Descricao varchar(20) ,
  Unidade char(2) ,
  ValorUnitario number( 6,2)
  ,
);

----TABELA TB_ITEMPEDIDO 

Create table TB_ITEMPEDIDO
(
  NumPedido number(5) PRIMARY KEY,
  CodProduto number(5) PRIMARY KEY (CodProduto),
  Quantidade number(3),
);

-- 3.	Adicionar na tabela Vendedor o campo DataNascimento do tipo Date 

ALTER TABLE  TB_VENDEDOR ADD
DataNascimento Date ;

-- 4.	Adicionar na tabela Cliente o campo Região do tipo varchar(20) 

ALTER TABLE  TB_CLIENTE ADD
Cliente varchar
(20) ;

-- 5.	Alterar o campo NomeCliente da tabela Cliente para varchar(50) 

ALTER TABLE  TB_CLIENTE ALTER COLUMN NomeCliente varchar(50) ;

-- 6.	Excluir a coluna Região da tabela Cliente 

ALTER TABLE TB_CLIENTE ADD
Regiao varchar
(20) ;
--Não havia a coluna região
ALTER TABLE TB_CLIENTE DROP COLUMN Regiao;

------------------------------------ Comandos DML: ------------------------------------

-- 1.	Inserir pelo menos 5 linhas de dados para cada tabela. 
-- Obs:  
-- na coluna Cidade da tabela de Cliente, incluir pelo menos 3 com cidade = ‘Sorocaba’.  
-- Na coluna Unidade da tabela de produto informar ‘KG’ ou ‘LT’ ou ‘CX’. 
-- A faixa de Comissão da tabela vendedor deve ser entre 1.0% e 7.0%. 

insert into TB_CLIENTE
values
  (1, 'AAA', 'Rua A', 'Alpha', 100000, 'SPA');
insert into TB_CLIENTE
values
  (2, 'BBB', 'Rua B', 'Beta', 200000, 'SPB');
insert into TB_CLIENTE
values
  (3, 'CCC', 'Rua A', 'Gamma', 000003, 'SPC');
insert into TB_CLIENTE
values
  (4, 'Silva DDD', 'Rua C', 'Alpha', 001000, 'SPD');
insert into TB_CLIENTE
values
  (5, 'EEE Silva', 'Rua D', 'Alpha', 000100, 'SPE');

insert into TB_CLIENTE
values
  (1, 'AAAA', 30, 4000);
insert into TB_CLIENTE
values
  (2, 'BBBB', 30, 5000);
insert into TB_CLIENTE
values
  (3, 'CCCC', 30, 6000);
insert into TB_CLIENTE
values
  (4, 'DDDD', 30, 7000);
insert into TB_CLIENTE
values
  (5, 'EEEE', 30, 8000);

insert into TB_PEDIDO
values
  (1, 1-1-2050, 1, 1);
insert into TB_PEDIDO
values
  (2, 1-1-2051, 2, 2);
insert into TB_PEDIDO
values
  (3, 1-1-2052, 3, 3);
insert into TB_PEDIDO
values
  (4, 1-1-2053, 4, 4);
insert into TB_PEDIDO
values
  (5, 1-1-2054, 5, 5);

insert into TB_PRODUTO
values
  (1, 'oi', 'KG', 200);
insert into TB_PRODUTO
values
  (1, 'eu', 'CX', 300);
insert into TB_PRODUTO
values
  (1, 'sou', 'TO', 400);
insert into TB_PRODUTO
values
  (1, 'o', 'GR', 500);
insert into TB_PRODUTO
values
  (1, 'Goku', 'KG', 600);

insert into TB_ITEMPEDIDO
values
  (1, 1, 50);
insert into TB_ITEMPEDIDO
values
  (2, 2, 60);
insert into TB_ITEMPEDIDO
values
  (3, 3, 70);
insert into TB_ITEMPEDIDO
values
  (4, 4, 80);
insert into TB_ITEMPEDIDO
values
  (5, 5, 90);

-- 2.	Alterar o CEP de todos os clientes da cidade de Sorocaba para ‘18035-400’. 

update paciente set Cep = '18035-400'
where Cidade = 'Sorocaba';

-- 3.	Alterar o prazo de entrega de todos os pedidos do cliente de código 20 para mais 10 dias. 

update consulta set PrazoEntrega = PrazoEntrega + 20 where codcliente = 20;

-- 4.	Alterar o preço unitário para mais 10% para todos os produtos com unidade = ‘KG’.  

update consulta
set ValorUnitario = ValorUnitario*1.1
where Unidade = 'KG';

-- 5.	Excluir todos os produtos com unidade = ‘LT’ e valor unitário superior a 50,00. 

Delete CodProduto
where Unidade = 'LT' AND salario > 50.00;

-- 6.	Listar o nome de todos os vendedores. Alterar o cabeçalho da coluna para Nome. 

select NomeVendedor as 'Nome'
from TB_VENDEDOR;

-- 7.	Listar a descrição do produto, Valor unitário original 
--e o Valor Unitário aumentado em 10% para todos os produtos. 

select Descricao , ValorUnitario, ValorUnitario*1.1 as 'valor unitario + 10%'
from TB_VENDEDOR;

-- 8.	Listar o nome dos clientes que moram em Sorocaba e cujo último nome seja "Silva".

select *
from TB_CLIENTE
where NomeCliente like '%Silva';

-- 9.	Listar o código do produto e a descrição para os produtos cuja unidade seja igual a "KG" ou ‘CX’. 

select CodProduto, Descricao
from TB_PRODUTO
where unidade = 'KG' or 'CX';

-- 10.	Listar o pedido e o prazo de entrega para os pedidos feitos entre 01/03/2021 a 31/03/2021. 
--        Não havia a coluna data do pedido
select NumPedido , PrazoEntrega
from TB_PEDIDO
where DataPedido between '01-03-2021' and '31-03-2021';

-- 11.	Listar o pedido e o prazo de entrega para os pedidos com data de entrega no ano de 2021. 

select NumPedido , PrazoEntrega
from TB_PEDIDO
where PrazoEntrega between '01-01-2021' and '31-12-2021';

-- 12.	Listar os dados dos produtos cujo valor unitário seja maior que $100,00 e menor que $200,00. 

select *
from TB_PRODUTO
where ValorUnitario between 100.00 and 200.00;
