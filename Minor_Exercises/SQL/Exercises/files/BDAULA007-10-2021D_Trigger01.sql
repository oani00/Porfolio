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
 
 --  Criando uma sequência automática para ser usada como PK na tabela de Log.

drop sequence seqlog

create sequence seqlog;

select seqlog.currval from dual;

select seqlog.nextval from dual;


insert into TB_produto values (60,'Caneta','CX', 5.00,30);
  
-- Criando o Trigger
   
Create or Replace trigger EliminaProduto
before delete on tb_produto
for each row
begin
  insert into logteste values(seqlog.nextval,sysdate,user,'produto','E',1);
end Eliminaproduto;

-- Testando
delete Tb_produto where codproduto = 60;

select * from logteste;

Exemplo 2: Este gatilho não permite que os usuários atualizem ou eliminem registros
da tabela de  paciente antes das 7:00 da manhã e depois das 14:00
*/

Create or Replace Trigger ChecaHora
before update or delete on paciente
begin
  if to_number(to_char(sysdate,'HH24')) not between 7 and 9 then
    raise_application_error(-20400,'Alterações não permitidas');
  end if;
end ChecaHora;
/
select * from Paciente;

update paciente
set nompaciente = 'xxx'
where codpaciente = 2;


select * from paciente;

