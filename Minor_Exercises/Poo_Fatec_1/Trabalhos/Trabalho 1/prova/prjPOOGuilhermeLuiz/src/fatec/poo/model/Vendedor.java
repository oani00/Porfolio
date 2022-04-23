/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Guilherme Henrique Mello e Almeida
 * @author Luiz Miguel Jarduli Leite
 */
public class Vendedor extends Pessoa{
    private double salarioBase;
    private double taxaComissao;
    private ArrayList<Pedido> pedidos; // multiplicidade 0..*
    
    public Vendedor(String cpf, String nome, double salarioBase) {
        super(cpf,nome);
        this.salarioBase = salarioBase;
        pedidos = new ArrayList<Pedido>();
    }
    
    public void addPedido(Pedido p) {
        pedidos.add(p);
        p.setVendedor(this);
    }
    public double getSalarioBase() {
        return salarioBase;
    }
    
    public double getTaxaComissao() {
        return taxaComissao;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }

    public void setTaxaComissao(double taxaComissao) {
        this.taxaComissao = taxaComissao;
    }
    
    
}
