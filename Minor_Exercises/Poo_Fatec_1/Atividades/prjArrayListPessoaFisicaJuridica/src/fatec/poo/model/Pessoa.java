package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Dimas
 */
public abstract class Pessoa {
    private String nome;
    private int anoInscricao;
    private double totalCompras;
    private ArrayList<PedidoCompra> pedidosCompra; //multiplicidade 1..*
    
    public Pessoa(String nome, int anoInscricao){
        this.nome = nome;
        this.anoInscricao = anoInscricao;
        pedidosCompra = new ArrayList<PedidoCompra>();        
    }
    
    public abstract double calcBonus(int anoAtual);
    
    public void addCompras(double val){
        totalCompras += val;
    }
    
    public String getNome() {
        return nome;
    }

    public int getAnoInscricao() {
        return anoInscricao;
    }

    public double getTotalCompras() {
        return totalCompras;
    }
    
    public void addPedidoCompra(PedidoCompra pc){
        pedidosCompra.add(pc);       
        pc.setPessoa(this);
    }
}
