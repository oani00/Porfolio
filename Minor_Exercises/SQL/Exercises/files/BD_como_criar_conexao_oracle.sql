-- aula do dia 05-03-2021

1- Criar uma conexão para o usuário SYSTEM (usando a senha na instalação)
2- Abrir uma nova planilha conectada ao SYSTEM
2- Dentro do SYSTEM criar um novo usuário:

-- exemplo usando o usuario bruna 

create user bruna identified by senhabruna;
Grant resource to bruna;
grant create session to bruna;

3- Criar uma nova conexão para o usuário criado (bruna neste caso)
4- Usar esta nova conexão para desenvolver as atividades de aula.



