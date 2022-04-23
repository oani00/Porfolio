/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Gustavo Cecato
 */
public class Instrutor extends Pessoa{
    
    private String Formacao, AreaAtuacao;
    private ArrayList<Turma> turmas; //multiplicidade 1..* 

    public void addTurma (Turma t) {
    turmas.add(t);
    t.setInstrutor(this); //simplificando a associação
    
    }

    public String getFormacao() {
        return Formacao;
    }

    public String getAreaAtuacao() {
        return AreaAtuacao;
    }
    
    public Instrutor(String cpf, String nome) {
        super(cpf, nome);
        turmas = new ArrayList<Turma>();
    }

    public void setFormacao(String Formacao) {
        this.Formacao = Formacao;
    }

    public void setAreaAtuacao(String AreaAtuacao) {
        this.AreaAtuacao = AreaAtuacao;
    }
    
}
