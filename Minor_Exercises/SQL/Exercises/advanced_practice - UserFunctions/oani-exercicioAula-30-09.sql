-------------------------------------OANI DA SILVA DA COSTA----------------------------------
----------------------FATEC – ADS -   Laboratório de  Banco de Dados ------------------------
---------------------------------------------------------------------------------------------

---------------------------------------------INSERTS------------------------------------------

-- Scripts das tabelas do Modelo Paciente - Consulta - medico
---
---

alter session set nls_Date_format = 'dd-mm-yyyy'; --|
                                                  --|https://stackoverflow.com/questions/63098668/how-do-i-fix-ora-01843-not-a-valid-month
select sysdate from dual;                         --|

Create table Paciente
( Codpaciente      number(4,0)    not null,
   Nompaciente     varchar2(30)   not null,
   Datanasc        date,
   Sexo            char( 1 ) check (sexo in ( 'F',  'M' )),
   Endereco        varchar2(25),
   constraint pk_codpaciente Primary Key (codpaciente));

Create table Medico
(  Codmedico           number(4,0)     not null,
   nommedico           varchar2(30)    not null,
   constraint pk_codmedico Primary Key (codmedico));

Create table Consulta
(   Codconsulta          number(3,0)    not null,
    Dataconsulta         date,
    Codpaciente          number(4,0)    Not Null,                   
    Codmedico            number(4,0)    Not Null,
    Valconsulta          number(5,0)    Not Null,
    constraint pk_codconsulta Primary Key (codconsulta));

Alter table Consulta
ADD (constraint fk_codpaciente Foreign Key (codpaciente)
     references Paciente (codpaciente) on delete cascade);

Alter table Consulta
ADD (constraint fk_codmedico Foreign Key (codmedico)
     references Medico (codmedico) on delete cascade);
 
ALTER TABLE  Paciente  ADD (cidpaciente varchar2( 15 )   Not   Null ) ;

ALTER TABLE  Paciente  MODIFY (cidpaciente varchar2( 20 )) ;

ALTER TABLE  Paciente  ADD (desconto varchar2( 01 ) check 
                                          (desconto in ('S','N' ) ) );

ALTER TABLE  Consulta  ADD (Tipoconsulta char (1) check 
					  (tipoconsulta in ('C', 'P')));

ALTER TABLE  Consulta  MODIFY (Valconsulta number(7,2));




insert into Paciente
values (001, 'Joao da Silva','01-09-1957','M','Rua das Flores, 301',
	'Sorocaba','S');

insert into Paciente
values (002, 'Henrique Matias','25-01-1960','M','Av. das Margaridas, 112',
	'Sorocaba','S');

insert into Paciente
values (003, 'Clara das Neves','20-01-1978','F','Rua Manoel Bandeira, 1100',
	'Itu','S');

insert into Paciente
values (004, 'Joao Pessoa','15-10-1945','M','Rua Maria Machado, 800',
	'Salto','N');

insert into Paciente
values (005, 'Karla da Cruz','29-12-1939','F','Av. Brasil, 701',
	'Avare','S');

insert into Paciente
values (006, 'Jandira Gomes','18-02-1940','F','Rua Jardim Florido, 1152',
	'Sorocaba','N');

insert into Paciente
values (007, 'Ana Maria Faracco','13-08-1980','F','Rua Jose Vieira, 65',
	'Sorocaba','S');

insert into Paciente
values (008, 'Roberto Faracco','01-01-1978','M','Rua Jose Vieira, 65',
	'Sorocaba','S');

insert into Paciente
values (009, 'Barbara Moreira','30-09-1969','F','Rua das Pedras, 127',
	'Sao Paulo','N');

insert into Paciente
values (010, 'Norberto Almeida','27-11-1937','M','Rua Capitao Pereira, 170',
	'Itapetininga','S');



insert into Medico
values (001, 'Roanldo Bueno');

insert into Medico
values (002, 'Helena Ziglio');

insert into Medico
values (003, 'Paulo Cesar Oliveira');

insert into Medico
values (004, 'Roberto Sinatura');




insert into Consulta
values (001, '20-01-2020',001,003,80.00,'C');

insert into Consulta
values (002, '22-02-2020',001,003,80.00,'C');

insert into Consulta
values (003, '15-10-2020',002,001,75.50,'P');

insert into Consulta
values (004, '07-12-2020',003,002,60.75,'P');

insert into Consulta
values (005, '18-11-2020',004,004,57.80,'C');

insert into Consulta
values (006, '27-06-2020',005,001,60.00,'C');

insert into Consulta
values (007, '30-07-2020',005,001,60.00,'C');

insert into Consulta
values (008, '15-08-2020',006,003,75.20,'P');

insert into Consulta
values (009, '17-08-2020',007,003,80.00,'P');

insert into Consulta
values (010, '20-08-98',008,002,70.00,'C');

insert into Consulta
values (011, '21-08-2020',008,004,81.00,'C');

insert into Consulta
values (012, '30-08-2020',009,004,85.00,'P');

insert into Consulta
values (013, '30-08-98',001,004,35.60,'C');

insert into Consulta
values (014, '01-01-2020',007,002,80.00,'P');

insert into Consulta
values (015, '10-02-2020',008,001,74.35,'P');

insert into Consulta
values (016, '11-02-2020',010,003,71.21,'C');

insert into Consulta
values (017,'12-04-2020',002,002,84.00,'C');






---------------------------------------------INSERTS------------------------------------------









Funções definidas pelo usuário no Oracle

Uma função é semelhante a um procedimento. Também aceita argumentos. 
É uma forma diferente de bloco PL/SQL. A diferença é que uma função é chamada como parte de uma execução e retorna um valor.


Criando uma Função:

CREATE OR  REPLACE  FUNCTION  nome-da-função (nome-parametro IN tipoparametro)
RETURN tipo_de_retorno
AS
[declaração de variaveis]
BEGIN
...
..
Exception
...

END;

Exemplo 1: Função que calcula o dobro de um número.

Create or replace Function CalcDobro (p1 in number) 
return number 
  as
    p2 number;
 BEGIN
    p2 := p1* 2;
    Return p2;
 END;

Como ativar a função:

Insert into medico values (888,’dr. João Marcos’,CalcDobro(50));

Ou

SELECT CODPRODUTO, CalcDobro(valor_unit) from tb_produto;

SELECT nommedico, CalcDobro(VrHonor) from medico;


Exemplo2: Função que devolve a descrição de um produto


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


Para evocar uma função:

1a. Forma:

Select numpedido, codproduto, Fn_devolve_descricao(codproduto)
From Tb_item_pedido;


2a. Forma

variable resultado varchar2(20)

execute :resultado := fn_devolve_descricao (11);
print :resultado

3ª forma:   formatando a saída:

select numpedido, codproduto,  substr(Fn_devolve_descricao(codproduto),1,15)) as Descricao, pco_unit from Tb_item_pedido;












-- Exercícios:

--     1- Escreva uma função FN_verHora que receba como parâmetro uma data no formato dd/mm/yyyy e devolva-a no formato dd/mm/yyyy:HH24:mi:ss.


CREATE OR  REPLACE  FUNCTION  FN_verHora (Pdata IN date)
RETURN varchar2
  as
    dataformatada varchar2(25);
 BEGIN
    dataformatada := to_char(Pdata, 'dd/mm/yyyy:HH24:mi:ss');
    
    Return dataformatada;

 END FN_verHora;

-- Como ativar a função:

SELECT FN_verHora(sysdate) from dual;

--  2- Escreva uma função que receba como parâmetro um código de Paciente (modelo Paciente-consulta) 
--  e devolva “IDOSO” se o paciente tiver mais de 65 anos. 
--  Caso contrário devolva “NÃO IDOSO”.


CREATE OR REPLACE FUNCTION fn_paciente (
    pcodpaciente IN NUMBER
) RETURN VARCHAR2 AS
    nascimento NUMBER;
    status     VARCHAR2(10);
BEGIN
    SELECT
        ( sysdate - datanasc ) / 365.25
    INTO nascimento
    FROM
        paciente
    WHERE
        paciente.codpaciente = pcodpaciente;

    IF nascimento >= 60 THEN
        status := 'IDOSO';
    ELSE
        status := 'NAO IDOSO';
    END IF;

    RETURN status;
END fn_paciente;

SELECT
    fn_paciente(codigopaciente)
FROM
    dual;


----------------------------------------------------------------------------------------------------------------+
--  3- Crie uma função chamada FN_ConsultaEstoque que retorna a qtde corrente em estoque de determinado produto.|
--      a- Passe para a função o código do produto                                                              |
--      b- Crie o campo QTDE_estoque na tabela de produto.                                                      |
--      c- Crie uma forma de executar a função criada.                                                          |
----------------------------------------------------------------------------------------------------------------+

--      b- Crie o campo QTDE_estoque na tabela de produto.
alter table produto ADD QTDE_estoque number(5);

--   Crie uma função chamada FN_ConsultaEstoque que retorna a qtde corrente em estoque de determinado produto.
--      a- Passe para a função o código do produto
CREATE OR REPLACE FUNCTION fn_consultaestoque (
    codigo IN NUMBER
) RETURN NUMBER AS
    estoque NUMBER(5);
BEGIN
    SELECT
        qtde_estoque
    INTO estoque
    FROM
        produto
    WHERE
        codproduto = codigo;

    RETURN estoque;
END fn_consultaestoque;


--      c- Crie uma forma de executar a função criada.
SELECT     FN_ConsultaEstoque(codigo) from produto;

-- 4-	Escreva uma função que receba como parâmetro um número de telefone não formatado( só números) e exiba este número no formato:
-- (xx)xxxx-xxxx

CREATE OR REPLACE FUNCTION fn_formatotell (
    numero IN NUMBER
) RETURN VARCHAR2 AS
    pformatado    VARCHAR2(15);
    pnaoformatado VARCHAR2(15);
BEGIN
    pnaoformatado := to_char(numero, '9999999999'); --casting para uma string

    pformatado := '('
                  || substr(pnaoformatado, 2, 1)
                  || substr(pnaoformatado, 3, 1)
                  || ')'
                  || substr(pnaoformatado, 4, 1)
                  || substr(pnaoformatado, 5, 1)
                  || substr(pnaoformatado, 6, 1)
                  || substr(pnaoformatado, 7, 1)
                  || '-'
                  || substr(pnaoformatado, 8, 1)
                  || substr(pnaoformatado, 9, 1)
                  || substr(pnaoformatado, 10, 1)
                  || substr(pnaoformatado, 11, 1);

    RETURN pformatado;
END fn_formatotell;

------------------------------------------------------------------------------------------------------------------------|
-- 5- Escreva uma função que receba como parâmetro o código do cliente e conte quantos pedidos ele tem.                 |
-- Se ele tiver mais de 3 pedidos devolver mensagem: 'Cliente preferencial' concatenado com o código e nome do cliente. |
-- Se tiver entre 1 e 3 devolver mensagem 'Cliente Normal' concatenado com o código e nome do cliente                   |
-- Se não tiver pedidos 'Cliente Inativo' concatenado com o código e nome do cliente;                                   |
-- Testar se o cliente existe, caso contrário emitir mensagem de erro.                                                  |
------------------------------------------------------------------------------------------------------------------------|



-- 5- Escreva uma função que receba como parâmetro o código do cliente e conte quantos pedidos ele tem.

CREATE OR REPLACE FUNCTION fn_contapedidos (
    codigo IN NUMBER
) RETURN VARCHAR2 AS

    nclientes NUMBER(1);
    pedidos   NUMBER(5);
    cliente   VARCHAR2(40);
    v_line    VARCHAR2(40); --http://www.dba-oracle.com/concepts/displaying_pl_sql_output.htm
BEGIN

-- Testar se o cliente existe, caso contrário emitir mensagem de erro.

    SELECT
        COUNT(nomecliente)
    INTO nclientes
    FROM
        tb_cliente
    WHERE
        codcliente = codigo;

    IF nclientes = 0 THEN
        v_line := 'CLIENTE NAO EXISTE';
        dbms_output.put_line(v_line);
    END IF;

    SELECT         
      COUNT(*)
    INTO pedidos
    FROM
        tb_pedido
    WHERE
        codcliente = codigo;

    SELECT
        nomecliente
    INTO cliente
    FROM
        tb_cliente
    WHERE
        codcliente = codigo;

-- Se ele tiver mais de 3 pedidos devolver mensagem: 'Cliente preferencial' concatenado com o código e nome do cliente.
    IF pedidos > 3 THEN
        v_line := 'Cliente preferencial'
                  || codigo
                  || cliente;
        dbms_output.put_line(v_line);

-- Se tiver entre 1 e 3 devolver mensagem 'Cliente Normal' concatenado com o código e nome do cliente
    ELSIF
        pedidos > 0
        AND pedidos < 4
    THEN
        v_line := 'Cliente Normal'
                  || codigo
                  || cliente;
        dbms_output.put_line(v_line);


-- Se não tiver pedidos 'Cliente Inativo' concatenado com o código e nome do cliente;
    ELSE
        v_line := 'Cliente Inativo'
                  || codigo
                  || cliente;
        dbms_output.put_line(v_line);
    END IF;

    RETURN pedidos;
END fn_contapedidos;