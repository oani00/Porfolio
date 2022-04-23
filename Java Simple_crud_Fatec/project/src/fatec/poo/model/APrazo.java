package fatec.poo.model;

/**
 *
 * @author Gustavo
 */
public class APrazo {
    private double valor;
    private String dtVencimento;
    private double taxaJuros;
    private int qtdeMensalidade;

    public void setValor(double valor) {
        this.valor = valor;
    }

    public void setDtVencimento(String dtVencimento) {
        this.dtVencimento = dtVencimento;
    }

    public void setTaxaJuros(double taxaJuros) {
        this.taxaJuros = taxaJuros;
    }

    public void setQtdeMensalidade(int qtdeMensalidade) {
        this.qtdeMensalidade = qtdeMensalidade;
    }
}
