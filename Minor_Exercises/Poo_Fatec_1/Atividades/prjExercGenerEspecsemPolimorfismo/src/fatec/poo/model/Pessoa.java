package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class Pessoa {
    private final String nome;
    private final String telefone;

    public Pessoa(String nome, String telefone) {
        this.nome = nome;
        this.telefone = telefone;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefone() {
        return telefone;
    }
}
