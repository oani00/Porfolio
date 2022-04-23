import java.util.Scanner;
import fatec.poo.model.Circulo;
/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Circulo objCir = new Circulo();
        
        double raio;
        int opcao;
        
        // Inserindo o Raio
        System.out.print("Digite a medida do raio: ");
        raio = entrada.nextDouble();
        
        // Passagem de mensagens
        objCir.setRaio(raio);
        
        System.out.println("Valor do raio: " + objCir.getRaio());
        
        do {
            System.out.println("\n1 - Consultar Área");
            System.out.println("2 - Consultar Perímetro");
            System.out.println("3 - Consultar Diâmetro");
            System.out.println("4 - Sair");
            System.out.print("\n \n\tDigite sua opção: ");
        
            opcao = entrada.nextInt(); // scanf("%d", &opcao)
            
            switch(opcao){
                case 1: 
                    System.out.println("Área: " + objCir.calcArea());
                    break;
                case 2: 
                    System.out.println("Perímetro: " + objCir.calcPerimetro());
                    break;
                case 3: 
                    System.out.println("Diâmetro: " + objCir.calcDiametro());
                    break;
                case 4:
                    System.out.println("Aplicação encerrada");
                    break;
            }
        } while (opcao < 4);
        
        
    }
    
}
