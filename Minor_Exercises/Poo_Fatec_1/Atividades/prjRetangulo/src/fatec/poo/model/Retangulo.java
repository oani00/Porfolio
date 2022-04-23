package fatec.poo.model;
/**
 *
 * @author luizj
 */
public class Retangulo {
    
    private double altura;
    private double base;
    
    public void setAltura(double a){
        altura = a;
    }
    
    public void setBase(double b){
        base = b;
    }
    
    public double getAltura(){
        return(altura);
    }
    
    public double getBase(){
        return(base);
    }
    
    public double calcArea(){
        return(base * altura);
    }
    
    public double calcPerimetro(){
        return((base + altura) * 2);
    }
    
    public double calcDiagonal() {
        return(Math.sqrt(Math.pow(base,2) + Math.pow(altura, 2)));
    }
}
