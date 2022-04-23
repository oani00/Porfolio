<center> <h1> Oracle Database notes </center>

# print a message on screen

select 'text' as message from dual

# (TODO)working with time

# relational logic

. ==

. <>

. >=

# associate value

:=

# see tables and other things

select * from user_tables;

select * from user_constraints order by table_name;

select * from user_views;


# (TODO)Group by

# Order by
Select * from [table] order by [column] where [condition];


# Distinct
`select distinct (cidade) from [table]`

# Manipulation and creation of tables
<center> <h2> constraints </center>

### pk
`Alter table [TABLE] add constraint PK_nameconstraint primary key (col1, col2...);`
### fk
`Alter table [TABLE] add constraint PK_nameconstraint foreign key (col) references [ANOTHERTABLE];`
## other
### add columns
`Alter table [TABLE] add [columname] [varchar2(20)];`
### Alter column name
`Alter table [TABLE] modify [columname] [varchar2(20)];`
### add data
`Insert into [TABLE] values [all_values_separated_by_;s];`
### update data
`Update [TABLE] set [COLUMN] = [something] where [condition]`
### delete tuples
`Delete [TABLE] set [COLUMN] = [something] where [condition]`
### delete tables
`drop table [TABLE]`


# Creation
## Create user
``create user Trab identified BY trabsenha;
grant resource to Trab;
grant create session to Trab;
grant create view to Trab;
GRANT ALL PRIVILEGES to Trab;``


If needed: 
https://www.plsql.co/ora-65096-invalid-common-user-or-role-name.html#:~:text=Oracle%20SQL%20Error%3A%20ORA-65096%3A%20invalid%20common%20user%20or,specify%20a%20valid%20common%20user%20or%20role%20name.

## Create Table

``Create table Paciente
( Codpaciente      number(4,0)    not null,
   Nompaciente     varchar2(30)   not null,
   Datanasc        date,
   Sexo            char( 1 ) check (sexo in ( 'F',  'M' )),
   Endereco        varchar2(25),
   constraint pk_codpaciente Primary Key (codpaciente));``

# views

create or replace view [view_name]
as 

-----code-----

;

<center> <h1> ====PlSql==== </center>

# subqueries

in

not in <-------- use when the subquerie returns more than one 

item

else, use exists or not exists


# [Stored procedures](http://www.dbarepublic.com/2016/04/oracle-stored-procedure-with-examples.html)

CREATE [OR REPLACE] PROCEDURE procedure_name [(
  parameter [,
  parameter]) ]
IS
 [VARIABLE declaration goes here] 
BEGIN
 [Executable SQL statements goes here]
EXCEPTION
 [Error handling goes here]
END [procedure_name];



CREATE OR REPLACE PROCEDURE insert_employee(
  empno_in     IN NUMBER,
  ename_in     IN VARCHAR2,
  job_in       IN VARCHAR2,
  mgr_in       IN NUMBER,
  hiredate_in  IN DATE,
  sal_in       IN NUMBER,
  comm_in      IN NUMBER,
  deptno_in    IN NUMBER) 
-– Just the data type, don’t define the data length
IS
 ecode   NUMBER;
 emesg   VARCHAR2(200);
BEGIN
 INSERT INTO baniya.emp(
  empno,
  ename,
  job,
  mgr,
  hiredate,
  sal,
  comm,
  deptno)
 VALUES(
  empno_in,
  ename_in,
  job_in,
  mgr_in,
  hiredate_in,
  sal_in,
  comm_in,
  deptno_in);
 COMMIT;
EXCEPTION
 WHEN OTHERS THEN
  ecode := SQLCODE;
  emesg := SQLERRM;
  dbms_output.put_line(TO_CHAR(ecode) || '-' || emesg);
END insert_employee;
/


## Execution

exec procedure_name(args);


# Triggers

Create or Replace trigger [name]
before delete on [table]
for each row
begin
  -----------code-----------;
end [name];

# Functions

Create or replace Function CalcDobro (p1 in number) return number 
  as
    p2 number;
 BEGIN
    p2 := p1* 2;
    Return p2;
 END;

select codproduto, valor_unit from tb_produto;



<center> <h1> Some simple exercises </center>

#### select 2nd greatest entry
#### select 2nd greatest entry
#### select 2nd greatest entry
#### select 2nd greatest entry
#### select 2nd greatest entry
#### select 2nd greatest entry
#### select 2nd greatest entry







===============================================

create user ani IDENTIFIED BY aniani;
grant resource to ani;
grant create session to ani;

===============================================

alter user system identified by oani;

===============================================

SYS SYSTEM e PDBADMIN

oani0000

===============================================

Conexao

oani

oani0000


===============================================

tonaoracle

user: 
system

pass: 
tonaoracle


create user marcos IDENTIFIED BY senhamarcos;
grant resource to marcos;
grant create session to marcos;


===============================================

