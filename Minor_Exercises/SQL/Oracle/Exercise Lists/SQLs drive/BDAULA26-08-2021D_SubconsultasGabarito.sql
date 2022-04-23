--- Aula do dia 26-08-2021 
-- Gabarito lista subconsultas
1- Listar todos os clientes que moram na mesma cidade que 'João da Silva'. 

2- Quais produtos tem valor unitário maior que a média. 

3- Quais os clientes que só compraram com o vendedor com codigo 05 e 
com mais nenhum outro vendedor (fidelidade). 

select * from tb_pedido order by codcliente;

select codcliente from tb_pedido
where codvendedor = 5;                      -- não atende ao solicitado

-- solução:
select codcliente from tb_pedido 
where codvendedor = 5 and codcliente not in (select codcliente from tb_pedido
                                             where codvendedor <> 5);
ou

select codcliente from tb_pedido
where codvendedor = 5
minus
select codcliente from tb_pedido
where codvendedor <> 5

-- Para exibir o nome do cliente
Select tb_pedido.codcliente, nomecliente from tb_pedido inner join tb_cliente
on tb_pedido.codcliente = tb_cliente.codcliente
where codvendedor = 5
minus
select tb_cliente.codcliente,nomecliente from tb_pedido inner join tb_cliente
on tb_pedido.codcliente = tb_cliente.codcliente
where codvendedor <> 5;

ou

select tb_pedido.codcliente, nomecliente from tb_pedido inner join tb_cliente
on tb_pedido.codcliente = tb_cliente.codcliente
where tb_pedido.codvendedor = 5 and tb_pedido.codcliente 
not in (select codcliente from tb_pedido where codvendedor <> 5);



4- Quais vendedores não fizeram mais de 2 pedidos. fez 1 ou 0

select codvendedor, count(*) from tb_pedido
group by codvendedor
having count(*) < 2;

select * from tb_vendedor;

select  codvendedor from tb_vendedor
where codvendedor not in (select codvendedor
from tb_pedido
group by codvendedor
having count(*) >= 2);



5-Quais os vendedores não fizeram nenhum pedido no mês de maio/2021 

select  codvendedor, nomevendedor from tb_vendedor
where codvendedor not in (select codvendedor
from tb_pedido where  to_char(prazo_entrega, 'mm/yyyy') = '05/2021');

select * from tb_pedido order by codvendedor;

6-  Listar o nome do vendedor que mais fez pedidos. 


select tb_vendedor.nomevendedor
from tb_pedido inner join tb_vendedor
on tb_vendedor.codvendedor = tb_pedido.codvendedor
group by tb_vendedor.codvendedor,nomevendedor
having count(*) = (select max(count(*)) from tb_pedido
group by codvendedor);



7-Listar o nome dos clientes e o número total de pedidos associados a cada cliente em ordem decrescente de vendas, isto é do cliente que mais tem pedidos para o que menos tem. 

-- Obs: não é necessário usar subconsultas

select tb_pedido.codcliente,nomecliente, count(*)
from tb_cliente inner join tb_pedido
on tb_cliente.codcliente = tb_pedido.codcliente
group by tb_pedido.codcliente, nomecliente
order by 3 desc;

8-Excluir todos os itens dos pedidos feitos pelo cliente de código =32; 

delete tb_item_pedido
where numpedido in (select numpedido
from tb_pedido
where codcliente = 32);

rollback;

select * from tb_pedido;
select * from tb_item_pedido;


9.Alterar o valor unitário de todos os produtos sem vendas no ano de 2021
para menos 20%. 

update tb_produto
set valor_unit = valor_unit * 0.80
where codproduto not in 
(select tb_item_pedido.codproduto
from tb_pedido inner join tb_item_pedido
on tb_item_pedido.numpedido = tb_pedido.numpedido
where prazo_entrega between '01-01-21' and '31-12-21');
