/* Aula do dia 16-09-2021
-- laboratório

-- Correção da Lista04A */


1. Criar as tabelas abaixo que serão usadas nos exercícios a seguir.

drop table tablog;
drop table tab_erro;

Create table TabLog
(datalog date,
 campo1 varchar2(60),
 campo2 varchar2(60));

Create table Tab_erro
( dataerro date,
  mensagem varchar2(50));

1-	Crie um procedimento de nome SP_Atraso que receba como parâmetro o  
     número de um pedido. Obter o prazo de entrega deste pedido. 
     Se o prazo de entrega for  anterior a data atual(SYSDATE), obter o nome do vendedor deste pedido e gravar uma linha na TabLog com:

Em datalog gravar o Prazo de entrega
Em campo 1 gravar o Nome do vendedor
Em campo 2 gravar a mensagem “Pedido em atraso. O vendedor deve avisar ao cliente”
Utilizar exception para controlar erros associados ao select. 
Em caso de erro gravar na tabela Tab_erro o número do pedido concatenado com a  mensagem de erro 'Número do Pedido inexistente'.


CREATE OR REPLACE PROCEDURE SP_Atraso(P_NUMPEDIDO number) 
AS
    prazoPedido date;
    varNomeVendedor varchar2(30);
BEGIN
    SELECT prazo_entrega into prazoPedido
    FROM tb_pedido WHERE numpedido = P_NUMPEDIDO;
    
    if (prazoPedido < sysdate) then
        select NOMEVENDEDOR into varNomeVendedor
        from tb_vendedor,tb_pedido
        where tb_vendedor.codvendedor = tb_pedido.codvendedor
        and numpedido = P_NUMPEDIDO;
        insert into TABLOG values (prazoPedido, varNomeVendedor, 'Pedido em atraso. O vendedor deve avisar o cliente');
    end if;
EXCEPTION
    when no_data_found then
    insert into tab_erro values (SYSDATE, 'Pedido com numero '||P_NUMPEDIDO||' nao existe na base de dados');
end;

show errors;

Testando:
-- com pedido existente e com prazo < sysdate

select * from tb_pedido;

exec SP_Atraso(10);
select * from Tab_erro;
select * from TabLog;

-- testando com um pedido inexistente

exec SP_Atraso(99);
-------------------------------------------
testando o log do próprio SGBD

select * from tb_pedido where numpedido not in ( select numpedido from tb_item_pedido)

delete tb_pedido where numpedido = 998;

update tb_cliente....

rollback;


------------------------------------------------------------------

2. Escreva uma Stored Procedure de nome SP_ClientePremium" que receba como parâmetro o código de um cliente. 
     Se este possuir mais que 2 pedidos com prazo de entrega nos próximos 2 meses. 
             Gravar na tabela TABLOG:
             Em  datalog gravar  a data do sistema 
             Em campo1  gravar a mensagem  'Cliente especial - enviar brinde'
             Em campo2 gravar o código do cliente concatenado com o nome do cliente

     	Fazer o tratamento de exceções. 

create or replace procedure SP_clientePremium (pcodcli number)
as
vtotal_compras number;
vcodcli  tb_cliente.codcliente%type;
vnomecli tb_cliente.nomecliente%type;

begin
	-- testando se cliente existe
    select codcliente, nomeCliente into vcodcli, vnomecli from tb_cliente
	where codcliente = pcodcli;

	-- verificando compras nos próximos 2 meses
	select count(*) into vtotal_compras from tb_pedido
	where codcliente = pcodcli
	and prazo_entrega between  sysdate and add_months(sysdate, 2);
	

    if  vtotal_compras >= 2 then
        insert into tablog values (sysdate, 'Cliente especial - enviar brinde', pcodcli || ' - ' || vnomecli);
    else 
        if Vtotal_compras = 0 then
            insert into tablog values (sysdate, 'Cliente existe mas não tem pedidos', pcodcli || ' - ' || vnomecli);
        end if;
    end if;
    
    commit;

    exception
        when no_data_found then
        insert into tablog values (sysdate, 'Cliente ' || pcodcli || ' não existe', null);
end;

show errors;

-- preparando a base de dados para os testes

select * from tb_pedido;

update tb_pedido
set prazo_entrega = sysdate + 40
where codcliente = 32;

select sysdate+40 from dual;

-- testando

exec SP_clientePremium(32);
exec SP_clientePremium(68);
exec SP_clientePremium(30);

select * from tablog

------------------------------------------------------------
-
Mais alguns comandos importantes em PL/SQL

select object_name from user_objects where object_type = 'PROCEDURE';
OU
Select * from user_source;

describe user_objects;

describe tb_cliente

-- SQL%rowcount

UPDATE paciente 
    SET    desconto = 'N' 
    WHERE  datanasc > '01-01-1990'; 
--

set serveroutput ON; 
DECLARE 
    i NUMBER; 
BEGIN 
    UPDATE paciente 
    SET    desconto = 'N' 
    WHERE  datanasc > '01-01-1990'; 
     
    i := SQL%rowcount; 

    --note that assignment has to precede COMMIT
    COMMIT; 
    dbms_output.Put_line(i); 
END;

----Exemplo 2

create or replace procedure excluir_cliente (pcodcli number)
as
Begin
   delete TB_cliente
   where codcliente  = pcodcli;
 commit;
 exception 
 when no_data_found then
 insert into tab_erro values (sysdate, 'mensagem que nunca vai acontecer');
 end;
/

select * from tb_cliente;

exec excluir_cliente(41);
exec excluir_cliente(55);

select * from tab_erro;

delete tb_cliente
where codcliente = 55;

create or replace procedure excluir_cliente2 (pcodcli number)
as
Begin
   insert into tab_erro values (sysdate,'1-Pedido de exclusão do cliente '|| pcodcli);

   delete TB_cliente
   where codcliente  = pcodcli;

   if sql%rowcount = 0 then
     insert into tab_erro 
     values (sysdate,'2-Cliente a ser excluído não existe' || pcodcli); 
   Else
      insert into tab_erro values (sysdate,'3- Cliente excluído com sucesso '|| pcodcli);
   end if;

commit;
end;
/

select * from Tb_pedido

exec excluir_cliente2(55);  -- testando com cliente que não existe

exec excluir_cliente2(32);  -- testando com cliente que existe e tem pedidos

select * from tab_erro

 Create or replace procedure excluir_cliente_FK (pcodcli number)
as
vtotal number;
vcod tb_cliente.codcliente%type;
Begin


 insert into tab_erro values (sysdate,'1-Pedido de exclusão do cliente '|| pcodcli);
  
  select codcliente into vcod  from tb_cliente where codcliente = pcodcli;
  
 select count(*) into vtotal  from Tb_pedido where codcliente = pcodcli;


 If vtotal > 0 then
   insert into tab_erro values (sysdate,'4- cliente tem pedido não pode ser excluido '|| pcodcli);
 
else
   delete TB_cliente
   where codcliente = pcodcli;
  
   insert into tab_erro values (sysdate,'3- Cliente excluído com sucesso '|| pcodcli);
    
end if;
commit;
Exception
   when no_data_found then
     insert into tab_erro values (sysdate,'2-Cliente a ser excluído não existe' || pcodcli); 
end;

---

select count(*) from tb_pedido
where codcliente = 32;

select count(*) from tb_pedido
where codcliente = 53;

select count(*) from tb_pedido
where codcliente = 53
group by codcliente; -- não ha necessidade de se colocar o group by

-- Lista 4B exercício 4

4. Escreva uma Stored Procedure que receba como parâmetro a unidade de venda de 
um produto (KG por exemplo) e altere em mais 10% o preço de todos os produtos 
com a unidade igual  à passada como parâmetro.
Gravar na tabela de log as informações:
Datalog: colocar sysdate
Campo 1: a mensagem ‘Produto com preço modificado= ‘
Campo2: o número de linhas que sofreram update

create or replace procedure SP_AlteraPreco (Punid char)
as

begin
