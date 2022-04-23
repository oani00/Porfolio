--Aula dia 30

--Funções de totalização
CREATE TABLE AGREGACAO
(
 NF	NUMBER(3),
 Produto	VARCHAR2(100),
 Cliente	VARCHAR2(100),
 Quantidade	 NUMBER(3), 
Valor		NUMBER(7,2),
 Dia		 NUMBER(2)
);

INSERT INTO AGREGACAO VALUES
	(1, 'P001', 'C1', 8, 160, 5);
INSERT INTO AGREGACAO VALUES	(1, 'P002', 'C1', 2, 34, 5);
INSERT INTO AGREGACAO VALUES	(1, 'P003', 'C1', 1, 58, 5);
INSERT INTO AGREGACAO VALUES	(2, 'P002', 'C3', 20, 340, 7);
INSERT INTO AGREGACAO VALUES	(3, 'P001', 'C2', 12, 240, 8);
INSERT INTO AGREGACAO VALUES	(3, 'P002', 'C2', 5, 85, 8);
INSERT INTO AGREGACAO VALUES	(4, 'P001', 'C1', 2, 40, 10);
INSERT INTO AGREGACAO VALUES	(5, 'P003', 'C3', 4, 232, 15);

select * from agregacao;

SELECT SUM(Valor) FROM AGREGACAO 
WHERE Cliente = 'C1'

SELECT SUM(Valor*0.9) FROM AGREGACAO 

-- count

select count(*) from agregacao;  9 linhas

select count(*) from agregacao
where cliente = 'C2';

select count(cliente) from agregacao; 8 linhas (tuplas)row

INSERT INTO AGREGACAO VALUES	(6, 'P003', null, 4, 232, 15);

--- média aritmética

SELECT trunc(AVG(Valor),2) FROM AGREGACAO;

-- valor mínimo

select min(valor) from agregacao;

select * from agregacao;

-- valor máximo

select max(valor) from agregacao;

--
SELECT MIN(Valor), MAX(Valor), avg(valor) FROM AGREGACAO WHERE Cliente='C1'

--- Group by

select count(*) from agregacao
where cliente = 'C1';

select count(*) from agregacao
where cliente = 'C2';

select count(*) from agregacao
where cliente = 'C3';


--
select cliente,count(*) from agregacao
group by cliente;

---
select cliente,sum(valor) from agregacao
group by cliente
order by 2;

select cliente,sum(valor) as Total_valor from agregacao
group by cliente
order by Total_valor;


SELECT cliente,MIN(Valor), MAX(Valor), avg(valor) FROM AGREGACAO 
group by cliente;

select * from agregacao;

SELECT cliente,dia, count(*), sum(valor)as total FROM AGREGACAO 
group by cliente,dia
having  sum(valor) > 300
order by cliente;

SELECT Cliente, SUM(Valor), COUNT(*) as Qtd
FROM AGREGACAO 
GROUP BY Cliente
HAVING (COUNT(*) > 2)

------------------

dicionário de dados do Oracle
user_constraints

select * from user_constraints;

-- testando a inclusão

select * from medico

insert into medico values (100, 'dr. y');
