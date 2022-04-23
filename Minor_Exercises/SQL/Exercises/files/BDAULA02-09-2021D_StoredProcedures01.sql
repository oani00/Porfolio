--Aula do dia 02-09-2021
--
-- Usando EXISTS em subconsultas

operadores:

= > < <> <= >=         => usar qdo a subconsulta compara 1 elem.

in  
not in                 => usar qdo a subconsulta devolve vários elem.			
                	      elementos (testa se pertence a um conjunto)


Exists
not exists	       =>  Testa se o select interno é verdadeiro 	
    			   ou falso


Exemplo 1: Listar todos os clientes que tem pedidos

USANDO IN

select nomecliente from tb_cliente
WHERE CODCLIENTE IN (SELECT CODCLIENTE FROM TB_PEDIDO);  --ok Correto


Exemplo 1 com EXISTS

select nomecliente from tb_cliente
WHERE  EXISTS (SELECT CODCLIENTE FROM TB_PEDIDO);  -- Não Correto

-- COrreto (incluindo a clausula where na subconsulta)

select nomecliente from tb_cliente
WHERE  EXISTS 
(SELECT 'A' FROM TB_PEDIDO where tb_pedido.codcliente= Tb_cliente.codcliente);  -- Correto

select '1' from dual;

se o resultado do select interno for verdadeiro o banco executa o Select externo.
Verdadeiro quando o select interno devolve pelo menos 1 linhas.
Falso quando o select interno devolve zero linhas.

Exemplo 2: Listar os clientes que não tem pedidos

USANDO NOT IN

select nomecliente from tb_cliente
WHERE CODCLIENTE NOT IN (SELECT CODCLIENTE FROM TB_PEDIDO);  --ok Correto

Usando not exists

select nomecliente from tb_cliente
WHERE  Not EXISTS 
(SELECT 'A' FROM TB_PEDIDO where tb_pedido.codcliente= Tb_cliente.codcliente);  -- Correto

--
Listar a frase "Não existem pedidos para o cliente 40" se isso for verdade.

select 'Não existem pedidos para o cliente 40' as Mensagem from dual
where not exists ( SELECT 1 FROM TB_PEDIDO where codcliente = 40);

--- Stored Procedures

drop table tab_erro;

 create table tab_erro
( dataerro date,
  mensagem varchar2(50));
  
Declare
V_preco number(5);
Begin
  select  valor_unit  into  V_preco
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


