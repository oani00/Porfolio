package fatec.poo.model;

import java.text.DecimalFormat;

/**
 *
 * @author luizj
 */
public class Palestrante extends Pessoa{
    DecimalFormat df = new DecimalFormat("#,##0.00");
    private String areaAtuacao;
    private double taxaCobranca;
    private Palestra[] palestras;
    private int num;
    private double total;

    public Palestrante( String cpf, String nome, double taxaCobranca) {
        super(cpf, nome);
        this.taxaCobranca = taxaCobranca;
        palestras = new Palestra[10];
        num = 0;
        total = 0;
    }

    public void setAreaAtuacao(String areaAtuacao) {
        this.areaAtuacao = areaAtuacao;
    }

    public String getAreaAtuacao() {
        return areaAtuacao;
    }

    public double getTaxaCobranca() {
        return taxaCobranca;
    }
    
    public void addPalestra(Palestra p) {
        palestras[num] = p;
        num++;
    }
    public void listarPalestras() {
        System.out.println("\n\n\t\tRelação de Palestras Dadas ");
        System.out.println("CPF: " + getCpf());
        System.out.println("Nome: " + getNome());
        System.out.println("Área de Atuação: " + getAreaAtuacao());
        System.out.println("Taxa de Cobrança (%): " + getTaxaCobranca());
        System.out.println("\nData Palestra\t\t\tTema\t\tValor Recebido");
        for (int x = 0; x < num; x++){
            System.out.print("\n" + palestras[x].getData() + "\t\t");
            System.out.print(palestras[x].getTema()+ "\t\t");
            System.out.println(df.format((palestras[x].getValor()) * (getTaxaCobranca()/100)));
        }
        System.out.println("\n\t\t\t\tTotal "+df.format((palestras[0].getTotalArrecadado()) * (getTaxaCobranca()/100)));
    }
    
    
}
