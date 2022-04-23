------------------------------------------OANI DA SILVA DA COSTA---------------------------------------
---------------------FATEC – ADS -   Laboratório de  Banco de Dados  - Tarefa 3 -----------------------
----------------------------------------Lista06 – Triggers---------------------------------------------
-------------------------------------------------------------------------------------------------------
------------------------------------------Profª M.Angélica --------------------------------------------
-------------------------------------------------------------------------------------------------------
-- 1. Sobre o modelo do item-pedido, escreva um trigger que 
-- ao inserir um item do pedido 
--  verifique se o cliente já possui mais de 2 pedidos com entrega no mês atual. 
--    Se sim, aplicar um desconto de 15% ao preço do item que está sendo cadastrado.

CREATE OR REPLACE TRIGGER trig_INSERE_ITEM
  BEFORE INSERT ON TB_ITEM_PEDIDO
  FOR EACH ROW DECLARE
    vtotal NUMBER;
    vpreco NUMBER;
BEGIN
        SELECT COUNT(*) from TB_PEDIDO as vtotal 
        where PRAZO_ENTREGA == month(SYSDATE) 
        AND CODCLIENTE == new.CODCLIENTE;
    
        IF vtotal > 2 :NEW.preco := :NEW.preco*0.75; END IF;
end;

-- 2. Crie um trigger que ao ser alterado o campo endereço da tabela de cliente, 
--    faça a inserção de uma linha na tabela de log 
--    Tablog (datalog,campo1,campo2)
--    com a mensagem: "Observar mudança de endereço" <codigo do cliente> <endereço velho><endereçonovo>  

CREATE OR REPLACE TRIGGER trig_REGISTRA_ENDERECO 
BEFORE
    UPDATE ON TB_cliente
    FOR EACH ROW 
  BEGIN

    INSERT INTO tablog VALUES('Observar mudança de endereço' || '<' ||:old.codcliente||'>'||'<'||:old.endereco||'>'||'<'||:new..endereco||'>'||)

END;


-- 3. Escreva um trigger que ao incluir um novo item de pedido, 
--    verifique se a quantidade informada no item existe em estoque (comparar com o campo qtde estoque da tabela produto).
--    Se a quantidade <= quantidade em estoque 
--      atualizar a quantidade em estoque da tabela (produto) subtraindo  a quantidade pedida 
--    Se quantidade pedida > quantidade estoque 
--     diminuir  a quantidade pedida
--     zerar a quantidade em  estoque
--    se quantidade em estoque = 0 então abortar trigger.
-- OBS: Se o campo qtde_estoque não existir na tabela de Produto, crie este campo e altere-o com valores)

CREATE OR REPLACE TRIGGER trig_CHECA_ESTOQUE
  BEFORE INSERT ON TB_ITEM_PEDIDO
  FOR EACH ROW DECLARE
    vestoque NUMBER;
    vpedido  NUMBER;
BEGIN

    --coloca o numero em estoque na variavel
    SELECT qtde_estoque from TB_produto as Vestoque
    where CODPRODUTO    == :new.CODPRODUTO;
    
    --coloca o numero pedido na variavel
    SELECT QTDE from TB_ITEM_PEDIDO as Vpedido
    where CODPRODUTO    == :new.CODPRODUTO;

    --se o estoque for zero nao executa
    WHEN Vestoque != 0 THEN
    
    IF Vpedido <= Vestoque THEN

      TB_produto.qtde_estoque := (TB_produto.qtde_estoque - Vpedido);

    ELSE IF Vpedido > Vestoque THEN

    :new.QTDE := TB_produto.qtde_estoque;
    
    --atualiza o estoque do produto do codigo fornecido para 0.
    UPDATE TB_produto.qtde_estoque SET qtde_estoque = 0 WHERE CODPRODUTO == :new.CODPRODUTO;


    
    end if;
    end trig_checa_estoque;


-- 4. Escreva um trigger que 
--    ao incluir um pedido ou alterar o prazo de entrega de um pedido, 
--      só permita inserir prazo de entrega superior a 5 dias da data atual.  
--    Caso isso não ocorra mudar o prazo para mais 5 dias automaticamente.

CREATE OR REPLACE TRIGGER trig_VALIDA_PRAZO
  BEFORE INSERT OR UPDATE ON TB_PEDIDO

  FOR EACH ROW 
    DECLARE
    Vprazo date;

  BEGIN

    -- SELECT PRAZO_ENTREGA from TB_PEDIDO as Vprazo
    -- where NUMPEDIDO == :new.NUMPEDIDO;
    
    IF :new.PRAZO_ENTREGA > (SYSDATE + 5) THEN

    :new.PRAZO_ENTREGA := :new.PRAZO_ENTREGA + 5;

    END IF;

END trig_VALIDA_PRAZO;


-- ============================== Adicional em aula ==============================


CREATE or replace TRIGGER TR_busca_preco
BEFORE INSERT ON Tb_Item_pedido
FOR EACH ROW
  Declare
  valorcorreto tb_produto.valor_unit%type;

BEGIN
  select valor_unit into ValorCorreto
  from tb_produto
  where codproduto = :new.codproduto;

  -- trocando o preco informado no insert pelo preço que foi buscado
  :new.pco_unit := valorcorreto;

END TR_busca_preco;

--2. Escreva um trigger que ao alterar o prazo de entrega de um pedido.
--Grave na tablog o prazo antigo, prazo novo e o nome do cliente.

create sequence seqtablog;


create or replace trigger TR_altera_prazo
before update of prazo_entrega on tb_pedido
for each row
declare
vnome tb_cliente.nomecliente%type;
begin



select nomecliente into vnome
from tb_cliente
where codcliente = :new.codcliente;



insert into tablog values (seqtablog.nextval,sysdate,user,"tb_pedido",:old.prazo_entrega,:new.prazo_entrega,Vnome);



end;