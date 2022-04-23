package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class PedidoCompra {
    private int numPedido;
    private String dataPedido;
    private double valor;
    private Pessoa pessoa; //multiplicidade 1

    public PedidoCompra(int numPedido) {
        this.numPedido = numPedido;
    }

    public void setDataPedido(String dataPedido) {
        this.dataPedido = dataPedido;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public int getNumPedido() {
        return numPedido;
    }

    public String getDataPedido() {
        return dataPedido;
    }

    public double getValor() {
        return valor;
    }

    public Pessoa getPessoa() {
        return pessoa;
    }

    public void setPessoa(Pessoa pessoa) {
        this.pessoa = pessoa;
    }
}
