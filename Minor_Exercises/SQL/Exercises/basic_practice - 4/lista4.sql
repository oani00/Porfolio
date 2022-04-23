----------- FATEC Sorocaba - Banco de Dados ---------------
---------------- Oaní da Silva da Costa -------------------
--- Script para aulas práticas Modelo Cliente-Pedido
--- Atualização: Fevereiro-2021

--
create table TB_cliente
(
  codcliente number(5) not null,
  nomecliente varchar2(30) not null,
  endereco varchar2(30),
  cidade varchar2(20),
  cep varchar2(10),
  uf char(2)
);


create table TB_vendedor
(
  codvendedor number(5) not null,
  nomevendedor varchar2(30) not null,
  faixa_com number(4,2),
  salario_fixo number(7,2)
);


create table TB_produto
(
  codproduto number(5) not null,
  descricao varchar(30),
  unid char(2),
  valor_unit number(6,2)
);

Create table TB_PEDIDO

(
  NUMPEDIDO number(5) NOT NULL,
  PRAZO_ENTREGA DATE,
  CODCLIENTE number(5),
  CODVENDEDOR number(5)
);

CREATE TABLE TB_ITEM_PEDIDO
(
  NUMPEDIDO number(5) NOT NULL,
  CODPRODUTO number(5) NOT NULL,
  QTDE number(5)
);


--DEFININDO AS RESTRIÇÕES de PK

ALTER TABLE TB_Cliente
 ADD CONSTRAINT PK_Cliente_codcliente PRIMARY KEY(Codcliente);

ALTER TABLE TB_Produto 
 ADD CONSTRAINT PK_PRODUTO_CODPRODUTO PRIMARY KEY(CODPRODUTO);

ALTER TABLE TB_VENDEDOR 
 ADD CONSTRAINT PK_VENDEDOR_CODVENDEDOR PRIMARY KEY(CODVENDEDOR);

ALTER TABLE TB_PEDIDO 
 ADD CONSTRAINT PK_PEDIDO_NUMPEDIDO PRIMARY KEY(NUMPEDIDO);

ALTER TABLE TB_ITEM_PEDIDO ADD CONSTRAINT  PK_ITEMPEDIDO_PEDPROD 
 PRIMARY KEY(NUMPEDIDO,CODPRODUTO);


--- Restrições de FK 

ALTER TABLE TB_PEDIDO 
 ADD CONSTRAINT FK_PEDIDO_CODCLI FOREIGN KEY(CODCLIENTE) REFERENCES TB_CLIENTE;

ALTER TABLE TB_PEDIDO 
 ADD CONSTRAINT FK_PEDIDO_CODVENDEDOR FOREIGN KEY(CODVENDEDOR) REFERENCES TB_VENDEDOR;


--- ITEM PEDIDO

ALTER TABLE TB_ITEM_PEDIDO 
    ADD CONSTRAINT FK_ITEMPEDIDO_NUMPEDIDO FOREIGN KEY(NUMPEDIDO) REFERENCES TB_PEDIDO;

ALTER TABLE TB_ITEM_PEDIDO 
    ADD CONSTRAINT FK_ITEMPEDIDO_CODPRODUTO FOREIGN KEY(CODPRODUTO) REFERENCES TB_PRODUTO;


---- Inserindo dados

insert into TB_vendedor
values
  (5, 'Antonio Pedro'   , 5.0, 400);
insert into TB_vendedor
values
  (15, 'Carlos Sola'    , 0.0, 400);
insert into TB_vendedor
values
  (25, 'Ana Carolina'   , 1.0, 200);
insert into TB_vendedor
values
  (35, 'Solange Almeida', 1.0, 300);

--
INSERT INTO TB_CLIENTE
VALUES
  ( 30, 'João da Silva', 'AV. MATT HOFFMANN, 1100', 'SÃO PAULO', '97056-001', 'SP');
INSERT INTO TB_CLIENTE
VALUES
  ( 31, 'LUCAS ANTUNES', 'RUA TRODANI, 120', 'SOROCABA', '19658-023', 'SP');
INSERT INTO TB_CLIENTE
VALUES
  ( 32, 'LAURA STRAUSS', 'RUA TULIPAS, 650', 'PRIMAVERA', '18556-025', 'SP');

--
INSERT INTO TB_PRODUTO
VALUES
  ( 11, 'Apple Watch', 'UN', 975.99);
INSERT INTO TB_PRODUTO
VALUES
  ( 12, 'IPAD', 'UN', 999.70);
INSERT INTO TB_PRODUTO
VALUES
  ( 13, 'PÓ PARA TONER', 'KG', 85.60);
INSERT INTO TB_PRODUTO
VALUES
  ( 14, 'Mouse', 'UN', 45.60);
INSERT INTO TB_PRODUTO
VALUES
  ( 15, 'Caneta digital', 'UN', 100.00);
insert into TB_Produto
values
  (40, 'Mouse sem fio', 'UN', 68.90);
insert into TB_Produto
values
  (42, 'FIO HDMI', 'UN', 18.00);
insert into TB_Produto
values
  (43, 'Pendrive Star Wars', 'UN', 48.00);
insert into TB_Produto
values
  (44, 'Mouse com fio', 'UN', 28.00);
insert into TB_Produto
values
  (45, 'Pendrive do Mickey', 'UN', 50.00);

--
INSERT INTO TB_PEDIDO
VALUES
  ( 7, '26-02-2020', 31, 15);
INSERT INTO TB_PEDIDO
VALUES
  ( 8, '23-05-2020', 32, 25);
INSERT INTO TB_PEDIDO
VALUES
  ( 9, '21-02-2020', 32, 5);
INSERT INTO TB_PEDIDO
VALUES
  ( 10, '20-02-2020', 30, 5);

--
Insert into tb_item_pedido
values
  (7, 11, 1);
Insert into tb_item_pedido
values
  (7, 40, 2);
Insert into tb_item_pedido
values
  (7, 42, 1);
Insert into tb_item_pedido
values
  (8, 43, 5);
Insert into tb_item_pedido
values
  (9, 12, 1);
Insert into tb_item_pedido
values
  (10, 11, 1);
Insert into tb_item_pedido
values
  (10, 43, 1);
Insert into tb_item_pedido
values
  (10, 13, 2);
Insert into tb_item_pedido
values
  (8, 40, 1);


-- Listar a maior quantidade que conste na tabela de item do pedido.

select max(QTDE)
from TB_ITEM_PEDIDO;

-- Listar o menor valor unitario da tabela de produtos.

select min(valor_unit)
from TB_produto;

-- Listar a somatoria dos salarios fixos pago aos vendedores.

SELECT SUM(salario_fixo)
from TB_vendedor;

-- Listar o numero de produtos cuja unidade seja igual a "CX".

select count(unid)
from TB_produto
where unid = 'CX';

-- Listar o numero de clientes agrupados por cidade.

select count(codcliente)
from TB_cliente
group by cidade;

-- Listar quantos pedidos cada vendedor realizou.

select count(NUMPEDIDO)
from TB_PEDIDO
group by CODVENDEDOR;

-- Listar o maior e o menor valor unitario para cada tipo de unidade de produto.

select max(valor_unit) as 'maior valor unitario', min(valor_unit) as 'menor valor unitario'
from TB_produto;

-- Listar o numero de clientes, agrupados por cidade para todas as cidades 
--que aparecem mais de 4 vezes na tabela de clientes.

select count(codcliente)
from TB_CLIENTE
GROUP BY cidade
HAVING (COUNT(cidade) > 4)