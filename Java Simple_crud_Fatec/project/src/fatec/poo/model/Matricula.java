package fatec.poo.model;

/**
 *
 * @author Gustavo
 */
public class Matricula {
    private String data;
    private int QtdeFaltas;
    private double nota;
    private Aluno aluno; //multiplicidade 1
    private Turma turma; //multiplicidade 1
    private AVista avista; //multiplicidade 1 ou 0 e Avista nao aponta de volta)
    private APrazo aprazo; //multiplicidade 1 ou 0 e APrazo nao aponta de volta)

    public void setAluno(Aluno a) {
        this.aluno = a;
        a.setMatricula(this); //facilitando a associação
    }

    public void setTurma(Turma t) {
        this.turma = t;
    }
    
    public Matricula(String data) {
        this.data = data;
    }

    public void setQtdeFaltas(int QtdeFaltas) {
        this.QtdeFaltas = QtdeFaltas;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }
    
    /*public void emitirCarne(){ 
    }*/
}
