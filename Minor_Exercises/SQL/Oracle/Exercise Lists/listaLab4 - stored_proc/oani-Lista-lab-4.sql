-------------------------------------OANI DA SILVA DA COSTA----------------------------------
----------------FATEC – ADS -   Laboratório de  Banco de Dados  - Tarefa 4 ------------------
-------------------------------Lista04 – Stored Procedures-----------------------------------
---------------------------------------------------------------------------------------------
---------------Inserts retirados do arquivo Script_Cliente_Pedido_com_inserts2021.sql--------

--- Excluindo tabelas (caso existam)
DROP TABLE tb_item_pedido;

DROP TABLE tb_pedido;

DROP TABLE tb_cliente;

DROP TABLE tb_vendedor;

DROP TABLE tb_produto;

--
CREATE TABLE tb_cliente (
    codcliente  NUMBER(5) NOT NULL,
    nomecliente VARCHAR2(30) NOT NULL,
    endereco    VARCHAR2(30),
    cidade      VARCHAR2(20),
    cep         VARCHAR2(10),
    uf          CHAR(2)
);

CREATE TABLE tb_vendedor (
    codvendedor  NUMBER(5) NOT NULL,
    nomevendedor VARCHAR2(30) NOT NULL,
    faixa_com    NUMBER(4, 2),
    salario_fixo NUMBER(7, 2)
);

CREATE TABLE tb_produto (
    codproduto NUMBER(5) NOT NULL,
    descricao  VARCHAR(30),
    unid       CHAR(2),
    valor_unit NUMBER(6, 2)
);

CREATE TABLE tb_pedido (
    numpedido     NUMBER(5) NOT NULL,
    prazo_entrega DATE,
    codcliente    NUMBER(5),
    codvendedor   NUMBER(5)
);

CREATE TABLE tb_item_pedido (
    numpedido  NUMBER(5) NOT NULL,
    codproduto NUMBER(5) NOT NULL,
    qtde       NUMBER(5)
);


--DEFININDO AS RESTRIcoES de PK

ALTER TABLE tb_cliente ADD CONSTRAINT pk_cliente_codcliente PRIMARY KEY ( codcliente );

ALTER TABLE tb_produto ADD CONSTRAINT pk_produto_codproduto PRIMARY KEY ( codproduto );

ALTER TABLE tb_vendedor ADD CONSTRAINT pk_vendedor_codvendedor PRIMARY KEY ( codvendedor );

ALTER TABLE tb_pedido ADD CONSTRAINT pk_pedido_numpedido PRIMARY KEY ( numpedido );

ALTER TABLE tb_item_pedido ADD CONSTRAINT pk_itempedido_pedprod PRIMARY KEY ( numpedido,
                                                                              codproduto );


--- Restricoes de FK 

ALTER TABLE tb_pedido ADD CONSTRAINT fk_pedido_codcli FOREIGN KEY ( codcliente )
    REFERENCES tb_cliente;

ALTER TABLE tb_pedido ADD CONSTRAINT fk_pedido_codvendedor FOREIGN KEY ( codvendedor )
    REFERENCES tb_vendedor;

--- ITEM PEDIDO


ALTER TABLE tb_item_pedido ADD CONSTRAINT fk_itempedido_numpedido FOREIGN KEY ( numpedido )
    REFERENCES tb_pedido;

ALTER TABLE tb_item_pedido ADD CONSTRAINT fk_itempedido_codproduto FOREIGN KEY ( codproduto )
    REFERENCES tb_produto;

---- Inserindo dados

INSERT INTO tb_vendedor VALUES (
    5,
    'Antonio Pedro',
    5.0,
    400
);

INSERT INTO tb_vendedor VALUES (
    15,
    'Carlos Sola',
    0.0,
    400
);

INSERT INTO tb_vendedor VALUES (
    25,
    'Ana Carolina',
    1.0,
    200
);

INSERT INTO tb_vendedor VALUES (
    35,
    'Solange Almeida',
    1.0,
    300
);

--
INSERT INTO tb_cliente VALUES (
    30,
    'Joao da Silva',
    'AV. MATT HOFFMANN, 1100',
    'SAO PAULO',
    '97056-001',
    'SP'
);

INSERT INTO tb_cliente VALUES (
    31,
    'LUCAS ANTUNES',
    'RUA TRODANI, 120',
    'SOROCABA',
    '19658-023',
    'SP'
);

INSERT INTO tb_cliente VALUES (
    32,
    'LAURA STRAUSS',
    'RUA TULIPAS, 650',
    'PRIMAVERA',
    '18556-025',
    'SP'
);

--
INSERT INTO tb_produto VALUES (
    11,
    'Apple Watch',
    'UN',
    975.99
);

INSERT INTO tb_produto VALUES (
    12,
    'IPAD',
    'UN',
    999.70
);

INSERT INTO tb_produto VALUES (
    13,
    'PO PARA TONER',
    'KG',
    85.60
);

INSERT INTO tb_produto VALUES (
    14,
    'Mouse',
    'UN',
    45.60
);

INSERT INTO tb_produto VALUES (
    15,
    'Caneta digital',
    'UN',
    100.00
);

INSERT INTO tb_produto VALUES (
    40,
    'Mouse sem fio',
    'UN',
    68.90
);

INSERT INTO tb_produto VALUES (
    42,
    'FIO HDMI',
    'UN',
    18.00
);

INSERT INTO tb_produto VALUES (
    43,
    'Pendrive Star Wars',
    'UN',
    48.00
);

INSERT INTO tb_produto VALUES (
    44,
    'Mouse com fio',
    'UN',
    28.00
);

INSERT INTO tb_produto VALUES (
    45,
    'Pendrive do Mickey',
    'UN',
    50.00
);

-- INSERT INTO TB_PEDIDO VALUES ( 7, '26/02/2020', 31, 15); --|------------------------------------------------
-- INSERT INTO TB_PEDIDO VALUES ( 8, '23/05/2020', 32, 25); --|Tive que mudar o formado da data para usar no
-- INSERT INTO TB_PEDIDO VALUES ( 9, '21/02/2020', 32, 5);  --|oracle online
-- INSERT INTO TB_PEDIDO VALUES ( 10, '20/02/2020', 30, 5); --|------------------------------------------------

INSERT INTO tb_pedido VALUES (
    7,
    DATE '2020-02-26',
    31,
    15
);

INSERT INTO tb_pedido VALUES (
    8,
    DATE '2020-05-23',
    32,
    25
);

INSERT INTO tb_pedido VALUES (
    9,
    DATE '2020-02-21',
    32,
    5
);

INSERT INTO tb_pedido VALUES (
    10,
    DATE '2020-02-20',
    30,
    5
);


--
INSERT INTO tb_item_pedido VALUES (
    7,
    11,
    1
);

INSERT INTO tb_item_pedido VALUES (
    7,
    40,
    2
);

INSERT INTO tb_item_pedido VALUES (
    7,
    42,
    1
);

INSERT INTO tb_item_pedido VALUES (
    8,
    43,
    5
);

INSERT INTO tb_item_pedido VALUES (
    9,
    12,
    1
);

INSERT INTO tb_item_pedido VALUES (
    10,
    11,
    1
);

INSERT INTO tb_item_pedido VALUES (
    10,
    43,
    1
);

INSERT INTO tb_item_pedido VALUES (
    10,
    13,
    2
);

INSERT INTO tb_item_pedido VALUES (
    8,
    40,
    1
);


--Criar as tabelas abaixo que serão usadas nos exercícios a seguir.
--- Excluindo tabelas (caso existam)
DROP TABLE tablog;

DROP TABLE tab_erro;

CREATE TABLE tablog (
    datalog DATE,
    campo1  VARCHAR2(60),
    campo2  VARCHAR2(60)
);

CREATE TABLE tab_erro (
    dataerro DATE,
    mensagem VARCHAR2(50)
);

----------------------------------------------1----------------------------------------------
----------------------------------------------1----------------------------------------------
----------------------------------------------1----------------------------------------------

--Crie um procedimento de nome SP_Atraso que receba como par�metro o  n�mero de um pedido. 


CREATE OR REPLACE PROCEDURE sp_atraso (
    pnumpedido NUMBER
) AS
    vprazo        DATE;
    vnomevendedor VARCHAR2(30);
BEGIN

    --Obter o prazo de entrega deste pedido. 
    SELECT
        prazo_entrega
    INTO vprazo
    FROM
        tb_pedido
    WHERE
        numpedido = pnumpedido;
    
    
    --Se o prazo de entrega for  anterior a data atual(SYSDATE), 
    IF vprazo < sysdate THEN
        --obter o nome do vendedor deste pedido e gravar uma linha na TabLog
        SELECT
            nomevendedor
        INTO vnomevendedor
        FROM
                 tb_vendedor
            INNER JOIN tb_pedido ON tb_vendedor.codvendedor = tb_pedido.codvendedor
        WHERE
            numpedido = pnumpedido;

        SELECT
            prazo_entrega
        INTO vprazo
        FROM
            tb_pedido
        WHERE
            numpedido = pnumpedido;
        
        --Em datalog gravar o Prazo de entrega
        --Em campo 1 gravar o Nome do vendedor
        --Em campo 2 gravar a mensagem 'Pedido em atraso. O vendedor deve avisar ao cliente'
        INSERT INTO tablog VALUES (
            vprazo,
            vnomevendedor,
            'Pedido em atraso. O vendedor deve avisar ao cliente'
        );

    END IF;

    --Utilizar exception para controlar erros associados ao select. 

EXCEPTION
    WHEN no_data_found THEN
        --Em caso de erro gravar na tabela Tab_erro o numero do pedido concatenado com a  mensagem de erro 'Numero do Pedido inexistente'.
        INSERT INTO tab_erro VALUES (
            sysdate,
            pnumpedido || 'Numero do Pedido inexistente'
        );

END;

----------------------------------------------2----------------------------------------------
----------------------------------------------2----------------------------------------------
----------------------------------------------2----------------------------------------------

--Escreva uma Stored Procedure de nome SP_ClientePremium" que receba como parametro o codigo de um cliente. 
CREATE OR REPLACE PROCEDURE SP_ClientePremium (
    codcliente NUMBER
) AS
    Vnpedido NUMBER(5,0);
    nomeCliente varchar2(30);
 
BEGIN
    SELECT COUNT (NUMPEDIDO) INTO Vnpedido
    FROM TB_PEDIDO
    WHERE CODCLIENTE = codcliente AND PRAZO_ENTREGA <= ADD_MONTHS(SYSDATE,+2);

    select NOMECLIENTE into nomeCliente from tb_cliente inner join tb_pedido on tb_pedido.codcliente = tb_cliente.codcliente where tb_cliente.codcliente = codcliente;
    
    --Se este possuir mais que 2 pedidos com prazo de entrega nos pr�ximos 2 meses. 
    IF Vnpedido > 2 

         --Gravar na tabela TABLOG:
         --    Em  datalog gravar  a data do sistema 
         --    Em campo1  gravar a mensagem  'Cliente especial - enviar brinde'
         --    Em campo2 gravar o codigo do cliente concatenado com o nome do cliente
         
        INSERT INTO Tablog VALUES (sysdate, 'Cliente especial - enviar brinde', codcliente || ' ' ||  nomeCliente);

    END IF;
    
            --Fazer o tratamento de excecoes. 
    EXCEPTION
    WHEN no_data_found THEN
    INSERT into
        tab_erro(sysdate, codcliente || 'Cliente nao encontrado');

end;