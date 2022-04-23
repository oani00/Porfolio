package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class GameShop {
    private final int codigo;
    private final int idade;
    private double qtdeHoras;

    public GameShop(int codigo, int idade) {
        this.codigo = codigo;
        this.idade = idade;
    }

    public int getCodigo() {
        return codigo;
    }

    public int getIdade() {
        return idade;
    }

    public double getQtdeHoras() {
        return qtdeHoras;
    }
    
    public void comprar(double qtdeHoras) {
        this.qtdeHoras += qtdeHoras;
    }
    
    public void jogar(double qtdeHoras) {
        this.qtdeHoras -= qtdeHoras;
    }
    
    public void brinde() {
        this.qtdeHoras *= 2;
    }
}
