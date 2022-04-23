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
public class Cliente extends Pessoa{ 
    
    private double limiteCred;
    private double limiteDisp;
    private ArrayList<Pedido> pedidos;

    public Cliente(double limiteCred, String cpf, String nome) {
        super(cpf, nome);
        this.limiteCred = limiteCred;
        this.limiteDisp = limiteCred;
        pedidos = new ArrayList<Pedido>();
    }
    
    public void addPedido(Pedido p) {
        pedidos.add(p);
        p.setCliente(this);
    }
    
    public double getLimiteCred() {
        return limiteCred;
    }

    public void setLimiteCred(double limiteCred) {
        this.limiteCred = limiteCred;
    }

    public double getLimiteDisp() {
        return limiteDisp;
    }    
    
}
