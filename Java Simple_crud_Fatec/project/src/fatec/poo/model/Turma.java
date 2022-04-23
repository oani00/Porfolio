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
public class Turma {
    
    private String SiglaTurma, Descricao, DataInicio, DataTermino, Periodo;
    private int QtdVagas; 
    private String Observacoes;
    private Instrutor instrutor; //multiplicidade 1
    private Curso curso; //multiplicidade 1
    private ArrayList<Matricula> matriculas; //multiplicidade 1..* 

    public Turma(String SiglaTurma, String Descricao) {
        this.SiglaTurma = SiglaTurma;
        this.Descricao = Descricao;
        matriculas = new ArrayList<Matricula>();
    }

    public void setCurso(Curso c) {
        this.curso = c;
    }

    public void setInstrutor(Instrutor instrutor) {
        this.instrutor = instrutor;
    }

    public void addMatricula (Matricula m) {
        matriculas.add(m);
        m.setTurma(this);
    }
    
    public void setDescricao(String Descricao) {
        this.Descricao = Descricao;
    }

    public void setDataInicio(String DataInicio) {
        this.DataInicio = DataInicio;
    }

    public void setDataTermino(String DataTermino) {
        this.DataTermino = DataTermino;
    }

    public void setPeriodo(String Periodo) {
        this.Periodo = Periodo;
    }

    public void setQtdVagas(int QtdVagas) {
        this.QtdVagas = QtdVagas;
    }

    public void setObservacoes(String Observacoes) {
        this.Observacoes = Observacoes;
    }
    
    public void EmitirListaFrequencia(){
    }

    public String getSiglaTurma() {
        return SiglaTurma;
    }

    public String getDescricao() {
        return Descricao;
    }

    public int getQtdVagas() {
        return QtdVagas;
    }

    public String getDataInicio() {
        return DataInicio;
    }

    public String getDataTermino() {
        return DataTermino;
    }
    
    
    
}
