package fatec.poo.model;

import java.text.DecimalFormat;

/**
 *
 * @author luizj
 */
public class Palestra {
    DecimalFormat df = new DecimalFormat("#,##0.00");
    private String data;
    private String tema;
    private String local;
    private double valor;
    private double totalArrecadado;
    private Participante[] participante;
    private int num;
    private Palestrante palestrante;

    public Palestra(String data, String tema) {
        this.data = data;
        this.tema = tema;
        participante = new Participante[10];
        num = 0;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public String getData() {
        return data;
    }

    public String getTema() {
        return tema;
    }

    public String getLocal() {
        return local;
    }

    public double getValor() {
        return valor;
    }

    public double getTotalArrecadado() {
        return totalArrecadado;
    }
    
    public void addParticipante(Participante p) {
        participante[num] = p;
        num++;
        totalArrecadado = num * getValor();
    }
    
    public void addPalestrante(Palestrante p) {
        palestrante = p;
    }

    public Palestrante getPalestrante() {
        return palestrante;
    }
    
    public void emitiListaParticipantes() {
        System.out.println("\n\n\t\tRelação de Participantes ");
        System.out.println("Tema: " + getTema());
        System.out.println("Palestrante: " + palestrante.getNome());
        System.out.println("Data: " + getData());
        System.out.println("Local: " + getLocal());
        System.out.println("Número de Participantes: " + (num));
        System.out.println("\nNome\t\t\tEsolaridade\t\tTipo");
        for (int x = 0; x < num; x++){
            System.out.print("\n" + participante[x].getNome() + "\t\t");
            System.out.print(participante[x].getEscolaridade()+ "\t\t");
            System.out.println(participante[x].getTipo());
        }
        System.out.println("\n\t\t\t\tTotal Arrecadado "+df.format(getTotalArrecadado()));
    }
}
