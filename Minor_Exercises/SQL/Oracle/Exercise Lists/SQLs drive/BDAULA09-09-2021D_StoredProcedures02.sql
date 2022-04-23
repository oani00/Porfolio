-- Aula 09-09-2021 PL/SQL
--
create table tab_erro
( dataerro date,
  mensagem varchar2(50));

--	Criar o bloco anônimo abaixo (como não especifica um nome não será gravado no catálogo)

Declare
V_preco number(5);
Begin
  select  valor_unit into V_preco
  from Tb_produto where codproduto = 15 ;
	 if v_preco is null then 
	       update TB_produto
	           set valor_unit = 100.00 
	       where codproduto = 15;
	 end if ;
commit;
Exception
    when no_data_found then
       insert into tab_erro values (sysdate, 'produto não encontrado');
end;  
/

select * from tb_produto;

update tb_produto
set valor_unit = null
where codproduto =15;

Testar das 3 formas a seguir
1 - Testar com produto que exista mas o valor_unit seja = null
2 - testar com um produto que não exista (checar se gravou na tab_erro)
3 - Testar com um produto que não exista mas comentando o exception /* 
           para ver a mensagem na tela informando erro no select.*/
           

-- testando condição 2

Declare
V_preco number(5);
Begin
  select  valor_unit into V_preco
  from Tb_produto where codproduto = 99 ;
	 if v_preco is null then 
	       update TB_produto
	           set valor_unit = 100.00 
	       where codproduto = 99;
	 end if ;
commit;
Exception
    when no_data_found then
       insert into tab_erro values (sysdate, 'Produto não encontrado');
end;  

select * from tab_erro;

-- testando a condição 3

Declare
V_preco number(5);
Begin
  select  valor_unit into V_preco
  from Tb_produto where codproduto = 99 ;
	 if v_preco is null then 
	       update TB_produto
	           set valor_unit = 100.00 
	       where codproduto = 99;
	 end if ;
commit;
/*Exception
    when no_data_found then
       insert into tab_erro values (sysdate, 'Produto não encontrado');*/
end;  

--

accept cod_p prompt "informe o codigo do produto:"

declare
     v_preco number(5);
begin 
  select valor_unit  into v_preco
  from tb_produto
  where codproduto = &cod_p;
if v_preco is null then
  update tb_produto
  set valor_unit = 100
  where codproduto = &cod_p;
end if;
exception
  when no_data_found then
    insert into tab_erro values  (sysdate,'produto não encontrado  '|| &cod_p);
end;

select * from tab_erro;

--
Exemplo 4  - Transformando em Stored procedure

create or replace procedure Atualiza_Preco(Pcodprod number)
as 
v_preco  number(5);
Begin
  select  valor_unit into v_preco
  from tb_produto where codproduto =  Pcodprod ;
	 if v_preco is null then 
	       update TB_produto
	       set valor_unit = 100 
	       where codproduto = Pcodprod;
	      
	end if ;
  
  exception
	when no_data_found then
	insert into tab_erro values
                   (sysdate,'Produto não encontrado '||Pcodprod);
  end;  
/
show errors;

exec Atualiza_Preco(99);

select * from tab_erro;

create view VerProc as 
select object_name from user_objects 
where object_type = 'PROCEDURE';
--
Exercício

1.	Criar o campo pco_unit number(6,2) na tabela de item pedido.

Escreva uma stored procedure para inserir um item de pedido. 
Esta deve receber como parametro o numero do pedido, codproduto e a quantidade. 
O preço unitario deve ser obtido atraves da tabela produto.

select * from tb_item_pedido;

create or replace procedure SP_additem (Pnumped number, Pcodpro number, Pqtd number)
as
Vpreco number(6,2);
begin

select valor_unit into Vpreco from tb_produto
where codproduto = pcodpro;

insert into tb_item_pedido values (Pnumped,Pcodpro, Pqtd, Vpreco);

exception
when no_data_found then
   insert into tab_erro values
                   (sysdate,'Produto informado Inválido '||Pcodpro);
end;


testando

select * from tb_item_pedido order by numpedido;

exec SP_additem (8, 11, 3);

select * from tb_produto;

Para próxima aula: Lista04_SP
