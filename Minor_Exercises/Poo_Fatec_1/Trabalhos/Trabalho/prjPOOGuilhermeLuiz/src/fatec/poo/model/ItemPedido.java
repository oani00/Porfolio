/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.model;

/**
 *
 * @author Guilherme Henrique Mello e Almeida
 * @author Luiz Miguel Jarduli Leite
 */
public class ItemPedido {
    private int sequencia;
    private double qtdeVendida;
    private Produto produto; // multiplicidade 1
    private Pedido pedido;

    public ItemPedido(int sequencia, double qtdeVendida, Produto prod) {
        this.sequencia = sequencia;
        this.qtdeVendida = qtdeVendida;
        this.produto = prod;
    }

    public void setQtdeVendida(double qtdeVendida) {
        this.qtdeVendida = qtdeVendida;
        this.produto.setQtdeEstoque(this.produto.getQtdeEstoque() - qtdeVendida);
    }

    public int getSequencia() {
        return sequencia;
    }

    public double getQtdeVendida() {
        return qtdeVendida;
    }
    
    public void setPedido(Pedido p) {
       this.pedido = p;
    }
    
    public Produto getProduto() {
        return this.produto;
    }
    
    
}
