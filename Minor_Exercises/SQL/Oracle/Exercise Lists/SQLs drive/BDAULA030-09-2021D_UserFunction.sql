-- Aula do dia 30-09-2021
-- User Function
--
Exemplo 1: Fun��o que calcula o dobro de um n�mero.

Create or replace Function CalcDobro (p1 in number) return number 
  as
    p2 number;
 BEGIN
    p2 := p1* 2;
    Return p2;
 END;

select codproduto, valor_unit from tb_produto;

SELECT CODPRODUTO, CalcDobro(valor_unit) from tb_produto;

-- Exemplo2: Fun��o que devolve a descri��o de um produto


Create or replace Function  Fn_devolve_descricao(pcodprod  TB_produto.codproduto%type)
return varchar2
as
Vdesc TB_produto.descricao%type;
Begin
    Select descricao into vdesc
    From TB_produto
    Where TB_produto.codproduto = pcodprod;
    Return (vdesc);
End Fn_devolve_descricao;

Para evocar uma fun��o:

1a. Forma:

Select numpedido, codproduto, Fn_devolve_descricao(codproduto) "descricao"
From Tb_item_pedido;


2a. Forma

variable resultado varchar2(30)

execute :resultado := fn_devolve_descricao (11);
print :resultado

3� forma:   formatando a sa�da:

select numpedido, codproduto, 
substr(Fn_devolve_descricao(codproduto),1,15) as Descricao,
pco_unit from Tb_item_pedido;

select sysdate from dual;

select ver_hora(sysdate) from dual;

---Lista de User Function

Exerc�cios:

1-	Escreva uma fun��o FN_verHora que receba como par�metro uma data no formato dd/mm/yyyy e devolva-a no formato dd/mm/yyyy:HH24:mi:ss.


create or replace function ver_hora (Pdata date)
return varchar2
as
dataformatada varchar2(20);
begin
    dataformatada := to_char(Pdata, 'dd/mm/yyyy:hh:mi:ss') ;
Return (dataformatada);
end ver_hora;

select ver_hora(sysdate) from dual;

select codconsulta, ver_hora(dataconsulta) from consulta;



2-	Escreva uma fun��o que receba como par�metro um c�digo de Paciente
(modelo Paciente-consulta) e devolva �IDOSO� se o paciente tiver mais de 65 anos. 
Caso contr�rio devolva �N�O IDOSO�.

create or replace function Fn_idoso(Pcodpaciente number)
return varchar2
as

begin

  .......       (sysdate - datanasc)/365.25

end;


3-	Crie uma fun��o chamada FN_ConsultaEstoque que retorna a qtde corrente em estoque de determinado produto.
a-	Passe para a fun��o o c�digo do produto
b-	Crie o campo QTDE_estoque na tabela de produto.
c-	Crie uma forma de executar a fun��o criada.




