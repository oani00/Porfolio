
Drop table Paciente;
Create table Paciente
(
    Codpaciente int Primary  Key,
    Nompaciente varchar(1000) not null,
    Datanasc date,
    Sexo varchar(10) check (sexo in ( 'F',  'M' )),
    Rua varchar(1000),
    Cidade varchar(1000),
    seila varchar(1000)
);

Drop table medico;
Create table medico
(
    codmedico int primary key,
    nomeMedico varchar(1000)
);

Drop table Consulta;
Create table Consulta
(
    Codconsulta int Primary Key ,
    Dataconsulta date,
    Tipocons char(1) check  (tipocons in ('P','C')),
    Codpaciente int Not Null References Paciente,
    Codmedico int Not Null References Medico ,
    Valconsulta int Not Null
);


insert into Paciente
values
    (1, 'Maria Antônia da Silva', '1998-3-20', 'F', 'Rua das Flores,40', 'Sorocaba', 'S');
insert into Paciente
values
    (3, 'José Roberto Pereira', '1998-3-21', 'M', 'Rua Margarida,60', 'Itu', 'N');
insert into Paciente
values
    (4, 'Ana Costa', '1999-3-20', 'F', 'Rua das Camélias,140', 'Sorocaba', 'S');
insert into Paciente
values
    (5, 'Solange Pinheiro', '1998-8-20', 'F', 'Avenida Verão, 234', 'Itapetininga', 'N');
insert into Paciente
values
    (6, 'Caio da Silva', '2022-3-20', 'M', 'Rua das Flores,40', 'Sorocaba', 'S');
insert into paciente
values
    (2, 'Jose Maria', '1910-3-20', 'M', 'Rua Inverno, 30', 'Itu', 'N');

insert into medico
values
    (100, 'Dr. Who');
insert into medico
values
    (101, 'Dr. House');
insert into medico
values
    (102, 'Dr. Smith');
insert into medico
values
    (103, 'Dr. X');
insert into medico
values
    (104, 'Dr. Estranho');


insert into consulta
values
    (300, '01-03-2021', 'P', 3, 102, 500.50);
insert into consulta
values
    (301, '05-02-2021', 'C', 5, 103, 100.50);
insert into consulta
values
    (302, '01-03-2020', 'P', 2, 102, 600.00);
insert into consulta
values
    (303, '2021-04-20', 'C', 1, 104, 99.98);