-------------------------------------OANI DA SILVA DA COSTA----------------------------------
----------------FATEC – ADS -   Laboratório de  Banco de Dados  - Tarefa 3 ------------------
---------------------------------Lista03 – Subconsultas--------------------------------------
---------------------------------------------------------------------------------------------

---------------Inserts retirados do arquivo Script_Cliente_Pedido_com_inserts2021.sql--------

--- Excluindo tabelas (caso existam)
drop table Tb_Item_pedido;
drop table Tb_Pedido;
drop table Tb_cliente;
drop table Tb_vendedor;
drop table Tb_Produto;

--
create table TB_cliente
( codcliente number(5) not null,
  nomecliente varchar2(30) not null,
  endereco varchar2(30),
  cidade varchar2(20),
  cep varchar2(10),
  uf char(2));


create table TB_vendedor
( codvendedor number(5) not null,
  nomevendedor varchar2(30) not null,
  faixa_com    number(4,2),
  salario_fixo number(7,2));


create table TB_produto
( codproduto   number(5) not null,
  descricao varchar(30),
  unid       char(2),
  valor_unit number(6,2));

Create table TB_PEDIDO

( NUMPEDIDO     number(5) NOT NULL,
  PRAZO_ENTREGA DATE,
  CODCLIENTE     number(5),
  CODVENDEDOR   number(5));

CREATE TABLE TB_ITEM_PEDIDO
(NUMPEDIDO   number(5) NOT NULL,
 CODPRODUTO  number(5) NOT NULL,
 QTDE        number(5));


--DEFININDO AS RESTRIcoES de PK

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


--- Restricoes de FK 

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

insert into TB_vendedor values (5,'Antonio Pedro',5.0,400);
insert into TB_vendedor values (15,'Carlos Sola',0.0,400);
insert into TB_vendedor values (25,'Ana Carolina',1.0,200);
insert into TB_vendedor values (35,'Solange Almeida',1.0,300);

--
INSERT INTO TB_CLIENTE 
VALUES ( 30, 'Joao da Silva', 'AV. MATT HOFFMANN, 1100', 'SAO PAULO', '97056-001', 'SP');
INSERT INTO TB_CLIENTE 
VALUES ( 31, 'LUCAS ANTUNES', 'RUA TRODANI, 120', 'SOROCABA', '19658-023', 'SP');
INSERT INTO TB_CLIENTE 
VALUES ( 32, 'LAURA STRAUSS', 'RUA TULIPAS, 650', 'PRIMAVERA', '18556-025', 'SP');

--
INSERT INTO TB_PRODUTO VALUES (11, 'Apple Watch', 'UN',     975.99);
INSERT INTO TB_PRODUTO VALUES (12, 'IPAD', 'UN',            999.70);
INSERT INTO TB_PRODUTO VALUES (13, 'PO PARA TONER', 'KG',   85.60);
INSERT INTO TB_PRODUTO VALUES (14, 'Mouse', 'UN',           45.60);
INSERT INTO TB_PRODUTO VALUES (15, 'Caneta digital', 'UN',  100.00);
insert into TB_Produto values (40,'Mouse sem fio', 'UN',    68.90);
insert into TB_Produto values (42,'FIO HDMI', 'UN',           18.00);
insert into TB_Produto values (43,'Pendrive Star Wars', 'UN', 48.00);
insert into TB_Produto values (44,'Mouse com fio', 'UN',      28.00);
insert into TB_Produto values (45,'Pendrive do Mickey', 'UN', 50.00);

--
-- INSERT INTO TB_PEDIDO VALUES ( 7, '26/02/2020', 31, 15); --|------------------------------------------------
-- INSERT INTO TB_PEDIDO VALUES ( 8, '23/05/2020', 32, 25); --|Tive que mudar o formado da data para usar no
-- INSERT INTO TB_PEDIDO VALUES ( 9, '21/02/2020', 32, 5);  --|oracle online
-- INSERT INTO TB_PEDIDO VALUES ( 10, '20/02/2020', 30, 5); --|------------------------------------------------

INSERT INTO TB_PEDIDO VALUES ( 7, DATE '2020-02-26', 31, 15);
INSERT INTO TB_PEDIDO VALUES ( 8, DATE '2020-05-23', 32, 25);
INSERT INTO TB_PEDIDO VALUES ( 9, DATE '2020-02-21', 32, 5);
INSERT INTO TB_PEDIDO VALUES ( 10,DATE '2020-02-20', 30, 5);


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



--1. Listar todos os clientes que moram na mesma cidade que 'João da Silva'.

SELECT nomecliente
FROM TB_cliente
WHERE nomecliente <> 'Joao da Silva'
AND cidade = (	
    SELECT cidade     
    FROM TB_cliente     
    WHERE nomecliente = 'Joao da Silva'
);

--2. Quais produtos tem valor unitário maior que a média.

SELECT descricao
FROM TB_produto
WHERE valor_unit > (	
    SELECT AVG(valor_unit)
    FROM TB_produto
);

-- 3. Quais os clientes que só compraram com o vendedor com codigo 05 e com mais nenhum outro vendedor (fidelidade).

select codcliente from tb_pedido
where codvendedor = 5
minus (
    select codcliente from tb_pedido
    where codvendedor <> 5;
)


--4. Quais vendedores não fizeram mais de 2 pedidos.

--Nao sei por que não esta rodando, mas é algo assim:

SELECT p.codvendedor, v.nomevendedor, COUNT(numpedido)
FROM	    TB_PEDIDO p
INNER JOIN  TB_vendedor v on p.CODVENDEDOR = v.codvendedor
GROUP BY p.CODVENDEDOR
HAVING COUNT(numpedido) < 3

-- ou

SELECT p.codvendedor, v.nomevendedor, COUNT(numpedido)
FROM	    TB_PEDIDO p
INNER JOIN  TB_vendedor v on p.CODVENDEDOR = v.codvendedor
GROUP BY p.CODVENDEDOR
WHERE (
    SELECT COUNT(numpedido)
    WHERE COUNT(numpedido) < 3
)

--5. Quais os vendedores não fizeram nenhum pedido no mês de maio/2021

--Nao sei por que não esta rodando, mas é algo assim:

select codvenedor, nomevendedor
FROM	    TB_PEDIDO p
INNER JOIN  TB_vendedor v on p.CODVENDEDOR = v.codvendedor
NOT IN (
    select codvenedor, nomevendedor
    FROM	    TB_PEDIDO p
    INNER JOIN  TB_vendedor v on p.CODVENDEDOR = v.codvendedor
    to_char(prazo_entrega,'mm/yyyy') = '05/2021'
);


--6. Listar o nome do vendedor que mais fez pedidos.

SELECT v.Nomevendedor
FROM	    TB_PEDIDO   p 
INNER JOIN  TB_vendedor v on p.CODVENDEDOR = v.codvendedor
INNER JOIN  TB_cliente  c on p.CODCLIENTE  = c.codcliente
having count(*) =  (
    SELECT max(count(*)) 
    FROM tb_pedido
    group by codvendedor)
group by nomevendedor;



--7. Listar o 
-- - nome dos clientes e 
-- - o número total de pedidos associados a cada cliente 
--    em ordem decrescente de vendas, 
--     isto é do cliente que mais tem pedidos para o que menos tem.

SELECT c.nomecliente, COUNT(numpedido)
FROM	    TB_PEDIDO   p 
INNER JOIN  TB_vendedor v on p.CODVENDEDOR = v.codvendedor
INNER JOIN  TB_cliente  c on p.CODCLIENTE  = c.codcliente
GROUP BY c.nomecliente
ORDER BY COUNT(numpedido) desc


--8. Excluir todos os itens 
    --dos pedidos 
    --feitos pelo cliente de código = 32;

DELETE tb_item_pedido
WHERE codproduto in (
                    SELECT tb_produto.codproduto 
                    FROM        tb_item_pedido i
                    INNER JOIN  tb_produto pr on pr.codproduto = i.codproduto
                    INNER JOIN  tb_pedido pe on pe.numpedido = i.numpedido
                    WHERE pe.codcliente = 32
                    );


--9. Alterar o valor unitário de todos os produtos sem vendas no ano de 2021 para menos 20%.

update tb_produto 
set valor_unit = valor_unit * 0.80 
WHERE codproduto in(
                    select ip.codproduto 
                    from        tb_pedido p
                    INNER JOIN  tb_item_pedido ip on ip.numpedido = p.numpedido
                    WHERE to_char(prazo_entrega,'yyyy') <> 2021
                    )
