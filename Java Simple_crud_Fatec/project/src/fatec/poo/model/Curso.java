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
public class Curso {
    
    private String Sigla, Nome;
    private int CargaHoraria;
    private double Valor;
    private String DataVigencia;
    private double ValorHoraInstrutor;
    private String Programa;
    private ArrayList<Turma> turmas; //multiplicidade 1..* 

    public Curso(String Sigla, String Nome) {
        this.Sigla = Sigla;
        this.Nome = Nome;
        turmas = new ArrayList<Turma>();
    }

    public void addTurmas(Turma t) {
        turmas.add(t);
        t.setCurso(this); //facilitando a associação
    }
    
    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public void setCargaHoraria(int CargaHoraria) {
        this.CargaHoraria = CargaHoraria;
    }

    public void setValor(double Valor) {
        this.Valor = Valor;
    }

    public void setDataVigencia(String DataVigencia) {
        this.DataVigencia = DataVigencia;
    }

    public void setValorHoraInstrutor(double ValorHoraInstrutor) {
        this.ValorHoraInstrutor = ValorHoraInstrutor;
    }

    public void setPrograma(String Programa) {
        this.Programa = Programa;
    }

    public String getSigla() {
        return Sigla;
    }

    public String getNome() {
        return Nome;
    }

    public int getCargaHoraria() {
        return CargaHoraria;
    }

    public double getValor() {
        return Valor;
    } 

    public String getPrograma() {
        return Programa;
    }

    public String getDataVigencia() {
        return DataVigencia;
    }

    public double getValorHoraInstrutor() {
        return ValorHoraInstrutor;
    }
    
    public static ArrayList<String> listarCursos(ArrayList<Curso> c){
        ArrayList <String> listaNomeCursos = new ArrayList<String>();
        
        for (int x=0; x < c.size(); x++){
            listaNomeCursos.add(c.get(x).getNome());
        }
        return listaNomeCursos;
    }
}
