package fatec.poo.model;
/**
 *
 * @author luizj
 */
public abstract class Funcionario {
    private final int registro;
    private final String nome;
    private final String dtAdmissao;
    private String cargo;

    public Funcionario(int registro, String nome, String dtAdmissao) {
        this.registro = registro;
        this.nome = nome;
        this.dtAdmissao = dtAdmissao;
    }
    
    public void setCargo(String cargo) {
        this.cargo = cargo;
    }
    public int getRegistro() {
        return registro;
    }

    public String getNome() {
        return nome;
    }

    public String getDtAdmissao() {
        return dtAdmissao;
    }

    public String getCargo() {
        return cargo;
    }
    
    //método abstrato, ele somente possui assinatura
    abstract public double calcSalBruto();
    
    public double calcDesconto() {
        return (0.10 * calcSalBruto());
    }
    
    public double calcSalLiquido() {
        return (calcSalBruto() - calcDesconto());
    }
}
