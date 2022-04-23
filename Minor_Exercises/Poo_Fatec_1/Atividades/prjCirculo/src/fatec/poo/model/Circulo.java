package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class Circulo {
    private double raio;
    private static final double PI = 3.1416;
    
    public void  setRaio(double raio) {
        this.raio = raio;
    }
    
    public double getRaio(){
        return(raio);
    }
    
    public double calcArea(){
        return(PI * Math.pow(raio,2));
    }
    
    public double calcPerimetro(){
        return(2 * PI * raio);
    }
    
    public double calcDiametro(){
        return(2 * raio);
    }
    
}
