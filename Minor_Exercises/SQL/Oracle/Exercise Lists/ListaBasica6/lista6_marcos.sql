----------- FATEC Sorocaba - Banco de Dados ---------------
---------------- Oaní da Silva da Costa -------------------

Create table Paciente
( Codpaciente    number(4,0)    Primary  Key,
  Nompaciente    varchar2(30)   not null,
  Datanasc       date,
  Sexo           char( 1 ) check (sexo in ( 'F',  'M' )),	
  Endereco      varchar2(25) ) ;


Create table Consulta
(   Codconsulta   number(3,0)     Primary Key ,
    Dataconsulta  date,
    Tipocons      char(01)   check  (tipocons in ('P','C')),
    Codpaciente  number(4,0) Not Null   References Paciente,                   
    Codmedico    number(4,0) Not Null   References Medico ,
    Valconsulta  number(6,2) Not Null ) ;

Create table medico
(codmedico number(4,0) primary key,
 nomeMedico  varchar2(40));


-- ///1


create or replace view retorno
as select paciente.codpaciente,medico.codmedico,(dataconsulta + 10) as retorno
from paciente inner join consulta
on consulta.codpaciente = paciente.codpaciente
inner join medico
on consulta.codmedico = medico.codmedico;



////2.

create or replace view (nome da view)
as select paciente.nompaciente as paciente ,medico.nomemedico as medico ,dataconsulta
from paciente inner join consulta
on consulta.codpaciente = paciente.codpaciente
inner join medico
on consulta.codmedico = medico.codmedico;




///3.

create or replace view (nome da view)
as select medico.codmedico as codigo, medico.nomemedico as nome,  (sum (consulta.valconsulta) )  as valtotal
from consulta inner join medico
on consulta.codmedico = medico.codmedico
group by medico.codmedico, medico.nomemedico;



////4.

create or replace view (nome da view)
as select medico.codmedico as codigo, medico.nomemedico as nome,  ((sum (consulta.valconsulta) ) / count(*))  as valmedio
from consulta inner join medico
on consulta.codmedico = medico.codmedico
group by medico.codmedico, medico.nomemedico;



///5.
select *from user_views
where view_name like  '%PACSOR%'
