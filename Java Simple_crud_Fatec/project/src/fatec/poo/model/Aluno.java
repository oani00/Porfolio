/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.model;

/**
 *
 * @author Gustavo Cecato
 */
public class Aluno extends Pessoa {
    
    private String escolaridade;
    private Matricula matricula; //multiplicidade 1
    

    public Aluno(String cpf, String nome) {
        super(cpf, nome);
    }

    public void setMatricula(Matricula m) {
        this.matricula = m;
        m.setAluno(this); //facilitando a associação
    }
    
    public void setEscolaridade(String escolaridade) {
        this.escolaridade = escolaridade;
    }
    
}
