-------
--- Junção - gabarito da lista 

1.	Listar o código e o nome dos vendedores que efetuaram vendas para o cliente com código 32.

select tb_Vendedor.codvendedor,tb_vendedor.nomevendedor
from tb_pedido inner join tb_vendedor
on tb_pedido.codvendedor = tb_vendedor.codvendedor
where tb_pedido.codcliente = 32;

select * from tb_pedido;

2.	Listar  o número do pedido, prazo de entrega, a quantidade e a descrição do produto com código 11.

select Tb_pedido.numpedido,tb_pedido.prazo_entrega, tb_item_pedido.qtde, tb_produto.descricao
from tb_pedido inner join tb_item_pedido
                on tb_pedido.numpedido = tb_item_pedido.numpedido
                inner join tb_produto
                on tb_produto.codproduto = tb_item_pedido.codproduto
where tb_item_pedido.codproduto = 11;


3.	Quais os vendedores (código e nome) fizeram pedidos para o cliente 'João da Silva'.

select tb_vendedor.codvendedor, tb_vendedor.nomevendedor
from tb_vendedor inner join tb_pedido
on tb_pedido.codvendedor = tb_vendedor.codvendedor
inner join tb_cliente 
on tb_pedido.codcliente = tb_cliente.codcliente
where tb_cliente.nomecliente = 'João da Silva';

select * from tb_cliente

select * from tb_pedido


4.	Listar o número do pedido, o código do produto, a descrição do produto, o código do vendedor, o nome do vendedor , o nome do cliente, para todos os clientes que moram em Sorocaba.

select tb_pedido.numpedido , tb_produto.codproduto , tb_produto.descricao, 
tb_vendedor.codvendedor, tb_vendedor.nomevendedor, tb_cliente.nomecliente
from tb_pedido inner join tb_cliente 
on tb_pedido.codcliente = tb_cliente.codcliente
inner join tb_item_pedido 
on tb_pedido.numpedido = tb_item_pedido.numpedido
inner join tb_produto
on tb_produto.codproduto = tb_item_pedido.codproduto
inner join tb_vendedor 
on tb_pedido.codvendedor = tb_vendedor.codvendedor
where upper(tb_cliente.cidade) like 'SOROCABA';

select * from tb_cliente

select * from tb_pedido

5.	Listar o código do produto, a descrição, a quantidade pedida e o prazo de entrega para o pedido número 123.

6.	Quais os cliente ( nome e endereço) da cidade de Itu ou Sorocaba tiveram seus pedidos
tirados com o vendedor  de código igual a 15.


select tb_cliente.codcliente, tb_cliente.endereco
from tb_cliente inner join tb_pedido
on tb_cliente.codcliente = tb_pedido.codcliente
where 
(tb_cliente.cidade = 'SOROCABA' or tb_cliente.cidade= 'ITU') and tb_pedido.codvendedor = 15;

ou

select tb_cliente.codcliente, tb_cliente.endereco
from tb_cliente inner join tb_pedido
on tb_cliente.codcliente = tb_pedido.codcliente
where 
tb_cliente.cidade in ('SOROCABA','ITU') and tb_pedido.codvendedor = 15;



select * from tb_pedido
7.	Listar o código do cliente, nome do cliente e o total de pedidos que cada um realizou.


select * from tb_pedido order by codcliente;


select codcliente,count(*) from tb_pedido
group by codcliente;



select tb_pedido.codcliente,tb_cliente.nomecliente, count(*) 
from tb_pedido inner join tb_cliente
on tb_cliente.codcliente = tb_pedido.codcliente
group by tb_pedido.codcliente, tb_cliente.nomecliente;


