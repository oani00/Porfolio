----------- FATEC Sorocaba - Banco de Dados ---------------
---------------- Oaní da Silva da Costa -------------------

create table TB_cliente
( codcliente  number(5) not null,
  nomecliente varchar2(30) not null,
  endereco    varchar2(30),
  cidade      varchar2(20),
  cep         varchar2(10),
  uf          char(2));


create table TB_vendedor
( codvendedor   number(5) not null,
  nomevendedor  varchar2(30) not null,
  faixa_com     number(4,2),
  salario_fixo  number(7,2));


create table TB_produto
( codproduto number(5) not null,
  descricao  varchar(30),
  unid       char(2),
  valor_unit number(6,2));

Create table TB_PEDIDO

( NUMPEDIDO     number(5) NOT NULL,
  CODPRODUTO    number(5) NOT NULL, -- <----- para juntar com produto e item pedido
  PRAZO_ENTREGA DATE,
  CODCLIENTE    number(5),
  CODVENDEDOR   number(5))
  quantidade    number(5); -- <------ não tinha antes, coloquei para os exercícios.

CREATE TABLE TB_ITEM_PEDIDO
(NUMPEDIDO   number(5) NOT NULL,
 CODPRODUTO  number(5) NOT NULL,
 QTDE        number(5));


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

select * from user_constraints

---- Inserindo dados

insert into TB_vendedor values (5,'Antonio Pedro'   ,5.0,400);
insert into TB_vendedor values (15,'Carlos Sola'    ,0.0,400);
insert into TB_vendedor values (25,'Ana Carolina'   ,1.0,200);
insert into TB_vendedor values (35,'Solange Almeida',1.0,300);

--
INSERT INTO TB_CLIENTE 
VALUES ( 30, 'João da Silva', 'AV. MATT HOFFMANN, 1100', 'SÃO PAULO', '97056-001', 'SP');
INSERT INTO TB_CLIENTE 
VALUES ( 31, 'LUCAS ANTUNES', 'RUA TRODANI, 120', 'SOROCABA', '19658-023', 'SP');
INSERT INTO TB_CLIENTE 
VALUES ( 32, 'LAURA STRAUSS', 'RUA TULIPAS, 650', 'PRIMAVERA', '18556-025', 'SP');

--
INSERT INTO TB_PRODUTO VALUES ( 11, 'Apple Watch', 'UN', 975.99);
INSERT INTO TB_PRODUTO VALUES ( 12, 'IPAD', 'UN', 999.70);
INSERT INTO TB_PRODUTO VALUES ( 13, 'PÓ PARA TONER', 'KG', 85.60);
INSERT INTO TB_PRODUTO VALUES ( 14, 'Mouse', 'UN', 45.60);
INSERT INTO TB_PRODUTO VALUES ( 15, 'Caneta digital', 'UN', 100.00);
insert into TB_Produto values (40,'Mouse sem fio', 'UN', 68.90);
insert into TB_Produto values (42,'FIO HDMI', 'UN', 18.00);
insert into TB_Produto values (43,'Pendrive Star Wars', 'UN', 48.00);
insert into TB_Produto values (44,'Mouse com fio', 'UN', 28.00);
insert into TB_Produto values (45,'Pendrive do Mickey', 'UN', 50.00);

--
INSERT INTO TB_PEDIDO VALUES ( 7, '26/02/2020',  31, 15);
INSERT INTO TB_PEDIDO VALUES ( 8, '23/05/2020',  32, 25);
INSERT INTO TB_PEDIDO VALUES ( 9, '21/02/2020',  32, 5);
INSERT INTO TB_PEDIDO VALUES ( 10, '20/02/2020', 30, 5);

--
Insert into tb_item_pedido values (7,11,1);
Insert into tb_item_pedido values (7,40,2);
Insert into tb_item_pedido values (7,42,1);
Insert into tb_item_pedido values (8,43,5);
Insert into tb_item_pedido values (9,12,1);
Insert into tb_item_pedido values (10,11,1);
Insert into tb_item_pedido values (10,43,1);
Insert into tb_item_pedido values (10,13,2);
Insert into tb_item_pedido values (8,40,1);


----------------------------------------------- Exercicios -----------------------------------------------

-- 1. Listar o código e o nome dos vendedores que efetuaram vendas para o cliente com código 10.

select TB_PEDIDO.CODVENDEDOR, TB_vendedor.nomevendedor;
from TB_PEDIDO inner join TB_vendedor;
on TB_PEDIDO.CODVENDEDOR = TB_vendedor.CODVENDEDOR;
where CODCLIENTE = 10;


-- 2. Listar o número do pedido, prazo de entrega, a quantidade e a descrição do produto com código 100.

select TB_PEDIDO.NUMPEDIDO, TB_PEDIDO.PRAZO_ENTREGA, TB_PEDIDO.quantidade, TB_produto.descricao ;
from TB_PEDIDO 
inner join TB_produto;
    on TB_PEDIDO.numpedido = TB_produto.numpedido
inner join produto 
    on TB_produto.codproduto = TB_PEDIDO.codproduto
where codproduto = 100

-- 3. Quais os vendedores (código e nome) fizeram pedidos para o cliente 'José da Silva'.

select TB_VENDEDOR.codvendedor, TB_VENDEDOR.nomevendedor;
from TB_VENDEDOR 
    inner join TB_PEDIDO;
        on TB_PEDIDO.CODVENDEDOR = TB_VENDEDOR.codvendedor
from TB_PEDIDO 
    inner join TB_cliente;
        on TB_PEDIDO.CODCLIENTE = TB_cliente.codcliente
where nomecliente = 'José da Silva'

-- 4. Listar o número do pedido, o código do produto, a descrição do produto, o código do vendedor, o 
-- nome do vendedor , o nome do cliente, para todos os clientes que moram em Sorocaba.

select TB_PEDIDO.NUMPEDIDO, TB_PEDIDO.CODPRODUTO, TB_produto.descricao, TB_vendedor.codvendedor, TB_vendedor.nomevendedor, TB_cliente.nomecliente;
from TB_PEDIDO;
    inner join TB_produto;
        on TB_PEDIDO.CODPRODUTO = TB_produto.CODPRODUTO;
from TB_PEDIDO ;
    inner join TB_vendedor;
        on TB_PEDIDO.codvendedor = TB_vendedor.codvendedor;
from TB_PEDIDO ;
    inner join TB_cliente;
        on TB_PEDIDO.CODCLIENTE = TB_cliente.CODCLIENTE;
where endereco = 'Sorocaba';

-- 5. Listar o código do produto, a descrição, a quantidade pedida e o prazo de entrega para o pedido 
-- número 123.

select TB_PEDIDO.CODPRODUTO, TB_PEDIDO.quantidade, TB_PEDIDO.PRAZO_ENTREGA, TB_produto.descricao;
from TB_PEDIDO;
    inner join TB_produto;
        on TB_PEDIDO.CODPRODUTO = TB_produto.CODPRODUTO;
where NUMPEDIDO = 123;

-- 6. Quais os cliente ( nome e endereço) da cidade de Itu ou Sorocaba tiveram seus pedidos tirados com 
-- o vendedor  de código igual a 10.

select TB_cliente.nomecliente, TB_cliente.endereco
from TB_PEDIDO;
    inner join TB_vendedor;
        on TB_PEDIDO.CODVENDEDOR = TB_vendedor.CODVENDEDOR;
from TB_PEDIDO;
    inner join TB_cliente;
        on TB_PEDIDO.codcliente = TB_cliente.codcliente;
where endereco = 'Sorocaba' OR endereco = 'Itu';
where codvendedor = 10;


-- 7. Listar o código do cliente, nome do cliente e o total de pedidos que cada um realizou.

select TB_cliente.codcliente, TB_cliente.nomecliente, 
from TB_PEDIDO
    inner join TB_cliente
        on TB_cliente.codcliente = TB_PEDIDO.codcliente
count(TB_PEDIDO.codcliente) "Total de pedidos"  --aqui seria algo como count BY cliente ou algo assim, contar PEDIDOS mas referente a cada
                                                --CLIENTE unico...