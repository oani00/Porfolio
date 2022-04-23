/**
 *
 * @author luizj
 */
public class Exemplo7 {
    public static void main(String[] args) {
       double[] matrizRandom;
       int cont;
       double media = 0;
        
       matrizRandom = new double[10];
       
       // armazenando números aleatórios gerados na matriz
       // exibindo os valores da matriz
       for(cont = 0; cont < 10; cont++){
           matrizRandom[cont] = (double)(Math.random() * 100);
           media += matrizRandom[cont];
           System.out.println("Matriz[" + cont + "] = " + matrizRandom[cont]);
       }
       
       // calculando a média aritmética
       System.out.println("Média aritmética é = " + media/10);
       
        
    }
    
}
