package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class FuncionarioHorista extends Funcionario{
    private final double valHorTrab;
    private int qtdHorTrab;

    public FuncionarioHorista(double valHorTrab, int registro, String nome, String dtAdmissao) {
        super(registro, nome, dtAdmissao);
        this.valHorTrab = valHorTrab;
    }

    public void setQtdHorTrab(int qtdHorTrab) {
        this.qtdHorTrab = qtdHorTrab;
    }
    
    @Override
    public double calcSalBruto() {
        return (qtdHorTrab * valHorTrab);
    }
    
    public double calcGratificacao() {
        return (calcSalBruto() * 0.075);
    }
    
    @Override
    public double calcSalLiquido() {
        return (calcSalBruto() + calcGratificacao() - calcDesconto());
    }
}
