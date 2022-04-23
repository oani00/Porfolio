package fatec.poo.model;

/**
 *
 * @author luizj
 */
public class Participante extends Pessoa{
    private int tipo;
    private String escolaridade;

    public Participante(String cpf, String nome, int tipo) {
        super(cpf, nome);
        this.tipo = tipo;
    }
    
    public void setEscolaridade(String escolaridade) {
        this.escolaridade = escolaridade;
    }
   
    public int getTipo() {
        return tipo;
    }

    public String getEscolaridade() {
        return escolaridade;
    }
}
