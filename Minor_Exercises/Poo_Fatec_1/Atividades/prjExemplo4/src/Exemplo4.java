/**
 *
 * @author luizj
 */
public class Exemplo4 {
    public static void main(String[] args) {
        int cont, num;
        
        // Gerando um número aleatório para gerar um número inteiro entre 1 e 100
        num = (int)(Math.random() * 100);
        System.out.println("\t\t\tTabuada do " + num);
        
        // for
        for (cont = 1;  cont <= 10; cont++) {
            System.out.println(num + " x " + cont + " = " + cont * num);
        }
    }
    
}
