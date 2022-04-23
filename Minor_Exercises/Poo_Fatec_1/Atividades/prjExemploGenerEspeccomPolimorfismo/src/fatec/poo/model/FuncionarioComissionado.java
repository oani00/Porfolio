package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class FuncionarioComissionado extends Funcionario{
    private double salBase;
    private final double taxaComissao;
    private double totalVendas = 0;

    public FuncionarioComissionado(int registro, String nome, String dtAdmissao, double taxaComissao) {
        super(registro, nome, dtAdmissao);
        this.taxaComissao = taxaComissao;
    }

    public void setSalBase(double salBase) {
        this.salBase = salBase;
    }

    public double getSalBase() {
        return salBase;
    }

    public double getTaxaComissao() {
        return taxaComissao;
    }

    public double getTotalVendas() {
        return totalVendas;
    }

    public void addVendas(double venda) {
        this.totalVendas += venda;
    }
    
    @Override
    public double calcSalBruto() {
        return (salBase + (taxaComissao/100) * totalVendas);
    }
    
    public double calcGratificacao() {
        int gratificacao = getSalBase() > 5000 && getSalBase() <= 10000 ?
                           3 : getSalBase() > 10000 ?
                           5 : 0;
        return (calcSalBruto() * (gratificacao/100));
    }
    
    @Override
    public double calcSalLiquido() {
        return (super.calcSalLiquido() + calcGratificacao());
    }
}
