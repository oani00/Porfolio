--- Aula do dia 28-1-2021
-- exercícios Trigger ( do arquivo em word aulaPratica_triggers)

1- Escreva um  trigger que ao ser inserido um novo Item de pedido, 
-- substitua o preco informado pelo valor unitário existente na tabela de produto

insert into tb_item_pedido(995,15,3,4.00);

select * from tb_produto;

solução:

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

--testando

select * from tb_produto
insert into tb_item_pedido values(995,15,3,4.00);

select * from tb_item_pedido;

2. Escreva um trigger que ao alterar o prazo de entrega de um pedido. 
Grave na tablog o prazo antigo, prazo novo e o nome do cliente.

create sequence seqtablog;

drop table tablog;

create table tablog
( numLog number primary key,
  datalog  date,
  usuario  varchar2(15),
  tabela   varchar2(15),
  oldcampo varchar2(30),
  newcampo varchar2(30),
  campo1   varchar2(30));

create or replace trigger TR_altera_prazo
before update of prazo_entrega on tb_pedido
for each row
declare
 vnome tb_cliente.nomecliente%type;
begin
  select nomecliente into vnome
  from tb_cliente 
  where tb_cliente.codcliente = :new.codcliente;
 insert into tablog values (seqtablog.nextval,sysdate,user,"tb_pedido",:old.prazo_entrega,:new.prazo_entrega,Vnome);
end TR_altera_prazo;


update  tb_pedido
set prazo_entrega = sysdate
where numpedido = 995;
