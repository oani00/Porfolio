-- Subconsultas

-- Exemplo1: Listar a descrição do produto que tem o preço unitário maior que a média.

-- sem subconsultas teríamos 2 comandos isolados

select * from tb_produto where valor_unit > 187.30;
 
select avg(valor_unit) from TB_PRODUTO;
 
 select * from tb_produto;
 
 select * from tb_produto where valor_unit > (select avg(valor_unit) from TB_PRODUTO);
 
 Exemplo2: Listar o nome dos clientes que moram na mesma cidade do 'João da Silva';

    select nomecliente from TB_cliente
    where nomecliente <> 'João da Silva'  
    and cidade = (select cidade from TB_cliente where nomecliente = 'João da Silva');	


select * from tb_cliente

insert into tb_cliente values (40,'Ana Maria Silva','Rua x, 20', 'SÃO PAULO','13200-567','SP')

select nomecliente from TB_cliente
    where nomecliente <> 'João da Silva'  
    and cidade in (select cidade from TB_cliente where nomecliente = 'João da Silva');
    
exemplo3: Listar o nome dos clientes que tem pedidos

usando junção:
================

select nomecliente from tb_cliente inner join tb_pedido
on  tb_pedido.codcliente = tb_cliente.codcliente;  

dar preferência a junção, pois é mais rápida a execução, pode usar índices.

usando subconsultas:
===================

exibir o nome dos clientes que tem pedidos:

 select nomecliente from tb_cliente
 where codcliente in ( select codcliente from tb_pedido);

	não é tão eficiente.	

Exemplo4: Listar o nome dos clientes que não tem pedidos

select codcliente, nomecliente from TB_cliente
 where codcliente not in ( select codcliente from tb_pedido);

Listar o codigo dos clientes que não tem pedidos

select codcliente from tb_cliente
minus 
select codcliente from tb_pedido;

minus, union, intersect, 


select nomecliente from cliente,pedido
where pedido.codcliente <> cliente.codcliente; 
--- não funciona

Exemplo 5: Listar o nome do vendedor que não tem pedidos com prazo de entrega
em fevereiro/2020.

select * from tb_pedido

select tb_vendedor.codvendedor,nomevendedor 
from tb_vendedor,tb_pedido
where tb_pedido.codvendedor=tb_vendedor.codvendedor and 
 to_char(prazo_entrega,'mm/yyyy') <> '05/2021'; 

select * from tb_vendedor;
select * from tb_pedido;


A consulta acima não contempla o vendedor que nunca fez pedidos


select nomevendedor from tb_vendedor
where codvendedor not in (select codvendedor from tb_pedido
                            where to_char(prazo_entrega,'mm/yyyy') = '05/2021');
                            


--Exercicio para já
/*Listar o codigo dos  vendedores que fizeram  mais pedidos 
que o vendedor de nome ´Antonio Pedro'*/


insert into tb_pedido values (11,'02-09-2021',31,25,800.00);

select * from tb_pedido order by codvendedor;    

SELECT codvendedor, count(*)
from tb_pedido
GROUP BY codvendedor
HAVING count(*) >(SELECT count(*)from tb_pedido inner join tb_vendedor
               on tb_vendedor.codvendedor = tb_pedido.codvendedor
               where tb_vendedor.nomevendedor = 'Antonio Pedro' )

