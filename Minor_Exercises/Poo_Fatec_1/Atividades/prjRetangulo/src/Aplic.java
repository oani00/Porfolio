
import fatec.poo.model.Retangulo;
import java.util.Scanner;

/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        // instanciação de objetos da classe Scanner
        // e da classe Retangulo
        Scanner entrada = new Scanner(System.in);
        Retangulo objRet = new Retangulo();
        
        double medAlt, medBase;
        int opcao;
        
        // Inserindo altura
        System.out.println("Digite a altura: ");
        medAlt = entrada.nextDouble(); // scanf("%lf", &medAlt)
        
        // inserindo base
        System.out.println("Digite a base: ");
        medBase = entrada.nextDouble(); // scanf("%lf", &medBase)
        
        // passagem de mensagens
        objRet.setAltura(medAlt);
        objRet.setBase(medBase);
        
        System.out.println("Valor da altura: " + objRet.getAltura());
        System.out.println("Valor da base: " + objRet.getBase());
            
        // calculando perímetro e area do retangulo
        do {
            
            System.out.println("\n1 - Consultar Área");
            System.out.println("2 - Consultar Perímetro");
            System.out.println("3 - Consultar Cálculo diagonal");
            System.out.println("4 - Sair");
            System.out.print("\n \n\tDigite sua opção: ");
        
            opcao = entrada.nextInt(); // scanf("%d", &opcao)
            
            switch(opcao) {
                case 1: 
                    System.out.println("Área: " + objRet.calcArea());
                    break;
                case 2: 
                    System.out.println("Perímetro: " + objRet.calcPerimetro());
                    break;
                case 3: 
                    System.out.println("Cálculo diagonal: " + objRet.calcDiagonal());
                    break;
                case 4:
                    System.out.println("Aplicação encerrada");
                    break;
            }
        } while (opcao < 3);
  
    }
    
}
