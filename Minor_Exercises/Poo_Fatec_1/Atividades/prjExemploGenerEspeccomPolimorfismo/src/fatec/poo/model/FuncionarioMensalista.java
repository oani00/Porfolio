package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class FuncionarioMensalista extends Funcionario{
    private final double valSalMin;
    private double numSalMin;

    public FuncionarioMensalista(int registro, String nome, String dtAdmissao, double valSalMin) {
        super(registro, nome, dtAdmissao);
        this.valSalMin = valSalMin;
    }

    public void setNumSalMin(double numSalMin) {
        this.numSalMin = numSalMin;
    }
    
    @Override
    public double calcSalBruto() {
        return(valSalMin * numSalMin);
    }
}