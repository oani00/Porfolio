/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author oani_
 */
public class Notas {
    
}


/*  

[x]private ArrayList<Pessoa> cadAlunoInstrutor = new ArrayList<Pessoa>();
[x]private ArrayList<Curso> cadCurso = new ArrayList<Curso>();
[x]private ArrayList<Turma> cadTurma = new ArrayList<Turma>();

--------------INSTRUTOR

[X]Na operação Consultar, caso seja informado um CPF inválido exiba uma mensagem de advertência e reposicione o foco na entrada de dados para o CPF. 
[X]Caso o CPF seja válido, o cpf do instrutor deve ser pesquisado no ArrayList de Instrutor/Aluno. 
    Caso seja encontrado o instrutor no ArrayList, 
    [X]o objeto da classe Instrutor deve ser instanciado 
    [X]e o conteúdo dos seus atributos devem ser exibidos na GUI, 
    [X]o botão Consultar deve ser desabilitado 
    [X]e os botões Alterar e Excluir devem ser habilitados, 
    []a caixa de edição do CPF deve ser desabilitada 
    []e as demais caixas de edição devem ser habilitadas. 
    [X]O foco deve ser posicionado na caixa de edição nome. 
    
    []Ver o que sao os textos comentados
    

Caso não exista no ArrayList um instrutor com o cpf informado, 
    [X]o botão Consultar deve ser desabilitado 
    [X]e o botão Incluir deve ser habilitado.
    [X] A caixa de edição do CPF deve ser desabilitada 
    [X]e as demais caixas de edição devem ser habilitadas.
    [X] O foco deve ser posicionado na caixa de edição nome.
[X]Os dados das entradas formatados devem inseridos no objeto Instrutor sem a formatação.

[X]O CPF deve ser validado, para tal, na classe Pessoa defina um método de classe que tenha como entrada de dados o CPF e tem como retorno um valor boleano.



-------------Aluno
Na operação Consultar 
    
    caso seja informado um CPF inválido 
    [X]exiba uma mensagem de advertência e reposicione o foco na entrada de dados para o CPF. 

Caso o CPF seja válido, 
    []o cpf do aluno deve ser pesquisado no ArryList de Instrutor/Aluno. 
    []Caso seja encontrado o aluno no ArrayList, 
    []o objeto da classe Aluno deve ser instanciado 
    []e o conteúdo dos seus atributos devem ser exibidos na GUI, 
    []o botão Consultar deve ser desabilitado 
    []e os botões Alterar e Excluir devem ser habilitados, 
    []a caixa de edição do CPF deve ser desabilitada 
    []e as demais caixas de edição devem ser habilitadas. 
    []O foco deve ser posicionado na caixa de edição nome. 

Caso não exista no ArrayList um aluno com o cpf informado, 
    []o botão Consultar deve ser desabilitado 
    []e o botão Incluir deve ser habilitado. 
    []A caixa de edição do CPF deve ser desabilitada e as demais caixas de edição devem ser habilitadas. 
    []O foco deve ser posicionado na caixa de edição nome. 
    []Os dados das entradas formatadas devem ser inseridos no objeto aluno sem a formatação. O CPF deve ser validado.


-------------CURSO

[X]Na operação Consultar a sigla do curso deve ser pesquisada no ArrayList de Curso.

Caso seja encontrado o curso no ArrayList, 
    [X]o objeto da classe Curso deve ser instanciado 
    [X]e o conteúdo dos seus atributos devem ser exibidos na GUI, 
    [X]o botão Consultar deve ser desabilitado 
    [X]e os botões Alterar e Excluir devem ser habilitados, 
    [X]a caixa de edição de Sigla deve ser desabilitada 
    [X]e as demais caixas de edição devem ser habilitadas.
    [X]O foco deve ser posicionado na caixa de edição nome.

Caso não exista ArrayList um curso com a sigla informada, 
    [X]o botão Consultar deve ser desabilitado 
    [X]e o botão Incluir deve ser habilitado.
    [X] A caixa de edição da sigla deve ser desabilitada 
    [X]e as demais caixas de edição devem ser habilitadas.
    [X] O foco deve ser posicionado na caixa de edição nome. 

[X]Os dados das entradas formatadas devem ser inseridos no objeto Curso sem a formatação.

------------TURMA


[X]No combobox de curso deve ser inserido a sigla de cada objeto curso inserido no ArrayList de Curso. 
[X]Para tal, insira na classe Curso o método de classe listarSiglas (public static ArrayList<String> listarSiglas(ArrayList<Curso>)). Este método tem como retorno um ArrayList de String contendo as siglas de todos os objetos cursos inseridos no ArrayList de Curso. 
[X]No método construtor da GuiTurmapreencha o combox, utilizando o método addItem, com a sigla de cada curso contida no ArrayList de String. 
[X]Habilita a caixa de edição da Sigla do Turma. 

[X]Na operação Consultar a sigla da turma deve ser pesquisada no ArrayList de Turma.
Caso seja encontrado a turma no ArrayList de Turma, 
    [X]o objeto da classe Turma deve ser instanciado 
    [X]bem como o objeto da classe Curso que está associado com o objeto da classe Turma que foi pesquisado 
    [X]tendo os seus atributos exibidos na GUI, 
    [X]o botão Consultar deve ser desabilitado 
    [X]e os botões Alterar e Excluir devem ser habilitados, 
    [X]a caixa de edição de Sigla deve ser desabilitada 
    [X]e as demais caixas de edição devem ser habilitadas.
    [X]O foco deve ser posicionado na caixa de edição nome.

    Caso não exista no ArrayList de Turma uma turma com a sigla informada, o botão Consultar deve ser desabilitado e o botão Incluir deve ser habilitado.
    [X] A caixa de edição da sigla de turma deve ser desabilitada e as demais caixas de edição devem ser habilitadas.
    [X] O foco deve ser posicionado na caixa de edição nome.

[]Os dados das entradas formatadas devem inseridos no objeto Turma sem a formatação.


*/