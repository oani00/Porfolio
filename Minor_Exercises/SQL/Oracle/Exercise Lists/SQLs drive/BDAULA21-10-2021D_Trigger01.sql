-- Aula do dia 07-10-2021
-- TRIGGERS

-- teste de um trigger de auditoria

drop table logteste;

create table logteste
(nrlog number primary key, 
 Dttrans date not null, 
 Usuario varchar2(20) not null, 
 Tabela varchar2(30),
 Opera char(1) check (opera in('I','A','E')),
 Linhas Number(5) not Null check(linhas >=0));
 
 --  Criando uma sequ�ncia autom�tica para ser usada como PK na tabela de Log.

drop sequence seqlog

create sequence seqlog;

select seqlog.currval from dual;

select seqlog.nextval from dual;


insert into TB_produto values (60,'Caneta','CX', 5.00,30);
  
-- Criando o Trigger de auditoria para registrar a exclus�o e um produto
   
Create or Replace trigger EliminaProduto
before delete on tb_produto
for each row
begin
  insert into logteste values(seqlog.nextval,sysdate,user,'produto','E',1);
end Eliminaproduto;

-- Testando
delete Tb_produto where codproduto = 60;

select * from logteste;

Exemplo 2: Este gatilho n�o permite que os usu�rios atualizem ou eliminem registros
da tabela de  paciente antes das 7:00 da manh� e depois das 14:00
*/

Create or Replace Trigger ChecaHora
before update or delete on paciente
begin
  if to_number(to_char(sysdate,'HH24')) not between 7 and 9 then
    raise_application_error(-20400,'Altera��es n�o permitidas');
  end if;
end ChecaHora;
/
select * from Paciente;

update paciente
set nompaciente = 'xxx'
where codpaciente = 2;


select * from paciente;

-- aula do dia 21-10-2021

--Exemplo 3 - igual ao exemplo 2 por�m identificando se o usu�rio tentou fazer update ou delete.

Create or Replace Trigger ChecaHora2
before update or delete on paciente
begin
  if to_char(sysdate,'HH24') not between 7 and 9 then
    if updating then	
      raise_application_error(-20400,'Update n�o permitido');
    elsif deleting then
      raise_application_error(-20410,'Delete n�o permitido');
    end if;
  end if;
end ChecaHora2;


update paciente
set nompaciente = 'xxx'
where codpaciente = 2;

-- como identificar o codigo do produto excluido???

Create or Replace trigger EliminaProduto
before delete on tb_produto
for each row
begin
  insert into logteste values(seqlog.nextval,sysdate,user,'produto: '||:old.codproduto ,'E',1);
end Eliminaproduto;

insert into TB_produto values (60,'Caneta','CX', 5.00,30);

delete tb_produto
where codproduto = 60;

select * from logteste;


Exemplo 4 � Usando :NEW e :OLD

Ao ser inserida uma linha na tabela de Pedido, mudar o prazo de entrega para mais 15 dias


CREATE or replace TRIGGER TR_Troca_data
BEFORE INSERT ON Tb_pedido
FOR EACH ROW
BEGIN
      :NEW.prazo_entrega := SYSDATE + 15;

END;

Para testar execute: 

 insert into tb_pedido values (995,'22/10/2021',31,15, 100.00);

select * from tb_pedido;

select * from tb_item_pedido;

--Escreva um  trigger que ao ser inserido um novo Item de pedido, 
-- substitua o preco informado pelo valor unit�rio existente na tabela de produto

insert into tb_item_pedido(995,15,3,4.00);

select * from tb_produto;

solu��o:

CREATE or replace TRIGGER TR_busca_preco
BEFORE INSERT ON Tb_Item_pedido
FOR EACH ROW
BEGIN
       -- buscar o preco do produto
       -- trocar o preco informado no insert pelo pre�o que foi buscado
      :NEW. := ;

END;