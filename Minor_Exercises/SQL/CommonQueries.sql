SELECT
FROM
WHERE


    WHERE To retrieve specific information from a table excluding other irrelevant data
    AND Select rows that must satisfy all the given conditions
    OR Select rows that satisfy atleast one of the given conditions
    NOT Select rows that do not satisfy the given condition
    AS (alias) To temporarily rename a table or a column heading
    BETWEEN..AND.. To select values within a range
    EXISTS Used in combination with a subquery and is considered to be met if the subquery returns at least one row
    GROUP BY To collect data across multiple records and group the results by a column
    HAVING To filter data based on the group functions
    IN To test whether a value is in the list of values provided
    LIKE To search for a specified pattern in a column
    DISTINCT To return only distinct (different) values in a column
    ORDER BY To sort the records in the result based on a column
    IS NULL To test for a NULL value in a column
    INNER JOIN Returns all rows from both tables where there is a match
    LEFT JOIN Returns all the rows from the first table even if there are no matches in the second table
    RIGHT JOIN Returns all the rows from the second table, even if there are no matches in the first table
    FULL JOIN Returns all rows from both tables with nulls in place where the join condition is not met
    UNION Combines the result of two or more SELECT statements and selects only distinct values
    UNION ALL Combines the result of two or more SELECT statements and also select duplicate values


DROP TABLE tb_item_pedido;


CREATE TABLE tb_cliente (
    codcliente  NUMBER(5) NOT NULL,
    nomecliente VARCHAR2(30) NOT NULL,
    uf          CHAR(2)
    prazo_entrega DATE,
);

ALTER TABLE tb_cliente ADD CONSTRAINT pk_cliente_codcliente PRIMARY KEY ( codcliente );
ALTER TABLE tb_item_pedido ADD CONSTRAINT pk_itempedido_pedprod PRIMARY KEY ( numpedido,
                                                                              codproduto );

ALTER TABLE tb_pedido ADD CONSTRAINT fk_pedido_codcli FOREIGN KEY ( codcliente )    REFERENCES tb_cliente;

INSERT INTO tb_vendedor VALUES (
    5,
    'Antonio Pedro',
    5.0,
    400
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

CREATE OR REPLACE PROCEDURE SP_Atraso (Pnumpedido NUMBER) as

    --Nao precisa do Declare
    Vprazo DATE;
    Vnomevendedor varchar2(30);

begin

    --Obter o prazo de entrega deste pedido. 
    SELECT PRAZO_ENTREGA INTO Vprazo FROM TB_PEDIDO WHERE NUMPEDIDO = Pnumpedido;
    
    
    --Se o prazo de entrega for  anterior a data atual(SYSDATE), 
    IF Vprazo < SYSDATE then
        --obter o nome do vendedor deste pedido e gravar uma linha na TabLog
        SELECT nomevendedor INTO Vnomevendedor 
        FROM
            TB_vendedor
            INNER JOIN TB_PEDIDO ON TB_vendedor.CODVENDEDOR = TB_PEDIDO.CODVENDEDOR
        WHERE NUMPEDIDO = Pnumpedido;
    
        SELECT PRAZO_ENTREGA INTO Vprazo
        FROM tb_pedido
        WHERE NUMPEDIDO = Pnumpedido;

        INSERT INTO TabLog
        VALUES
            ( Vprazo, Vnomevendedor, 'Pedido em atraso. O vendedor deve avisar ao cliente' );
    END IF;

    --Utilizar exception para controlar erros associados ao select. 
    
    EXCEPTION
        WHEN no_data_found THEN
        --Em caso de erro gravar na tabela Tab_erro o n�mero do pedido concatenado com a  mensagem de erro 'N�mero do Pedido inexistente'.
        INSERT INTO Tab_erro VALUES ( SYSDATE, Pnumpedido || 'Numero do Pedido inexistente' );
END;

