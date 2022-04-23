-- Aula do dia 04-11-2021
-- Lista de Trigger – PL/SQL  -    Gabarito completo da lista de triggers

1.	Sobre o modelo do item-pedido, escreva um trigger que ao inserir um item do pedido 
verifique se o cliente já possui mais de 2 pedidos com entrega no mês atual. 
Se sim, aplicar um desconto de 15% ao preço do item que está sendo cadastrado.

alter table tb_item_pedido add Pco_unit number(6,2).

CREATE OR REPLACE TRIGGER TR_INSERE_ITEM
BEFORE INSERT ON TB_ITEM_PEDIDO
FOR EACH ROW
DECLARE
    Vtotal number;
    vcodcliente tb_pedido.codcliente%type;
BEGIN
  SELECT codcliente INTO vCodcliente
  FROM tb_pedido WHERE tb_pedido.numpedido = :NEW.numpedido;
  
  SELECT COUNT(*)  INTO Vtotal
  FROM tb_pedido 
  WHERE tb_pedido.codcliente = vCodcliente
    AND TO_CHAR(prazo_entrega,'MM-YYYY')= TO_CHAR(SYSDATE,'MM-YYYY');
  
    IF  Vtotal >=  2 THEN
    :NEW.pco_unit := :NEW.pco_unit * 0.85;  
  END IF;
END TR_INSERT_ITEM;

select * from tb_item_pedido;

select * from tb_pedido;

update tb_pedido
set prazo_entrega = prazo_entrega + 60
where codcliente = 32;

alter trigger tr_busca_preco disable;

insert into tb_item_pedido values (9,15,7,10.00);

-- 2. Crie um trigger que ao ser alterado o campo endereço da tabela de cliente, 
faça a inserção de uma linha na tabela de log com a mensagem:
  "Observar mudança de endereço" <codigo do cliente> <endereço velho><endereço novo>                    Tablog2 (datalog,campo1,campo2)

create table tablog2
(datalog date,
campo1 varchar2(100),
campo2 varchar2(100));

create or replace trigger Tr_alterEndereco
before update of endereco on tb_cliente
for each row 
begin
    insert into Tablog2 
    values (sysdate, 'Observar mudança de endereço - '||:new.nomecliente,'Novo: '||:new.endereco||'/ Velho: '||:old.endereco);
end;

SELECT * FROM TB_CLIENTE;

UPDATE TB_CLIENTE
SET ENDERECO = 'RUA Sete de Setembro,999'
where codcliente = 35;


select * from tablog2;

4) Escreva um trigger que ao incluir um pedido ou alterar o prazo de entrega 
de um pedido, só permita inserir prazo de entrega superior a 5 dias da data atual.
Caso isso não ocorra mudar o prazo para mais 5 dias automaticamente se for insert, 
se for update trocar para mais 10 dias.

Create or Replace trigger TR_checaPrazo
before INSERT OR UPDATE OF prazo_entrega on TB_pedido
for each row
begin
if :new.prazo_entrega < sysdate + 5 then
           if inserting then 
           :new.prazo_entrega := sysdate + 5;
           end if;
            if updating then 
           :new.prazo_entrega := sysdate + 10;
           end if;
end if;
end TR_checaPrazo;

update tb_pedido
set prazo_entrega = sysdate
where numpedido = 10;

select * from tb_pedido;