import fatec.poo.model.GameShop;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
   
       Scanner entrada = new Scanner(System.in);
       
       double qtdeHoras;
       int opcao, codigo, idade;
       
       System.out.println("Digite seu código: ");
       codigo = entrada.nextInt();
       
       System.out.println("Digite sua idade: ");
       idade = entrada.nextInt();
       
       //instanciação do objeto da classe
       //e chamada do método construtor
       GameShop objGame = new GameShop(codigo,idade);
       
       do{
           System.out.println("\n\n1 - Comprar Horas");
           System.out.println("2 - Jogar");
           System.out.println("3 - Brinde");
           System.out.println("4 - Consultar Saldo de Horas");
           System.out.println("5 - Sair");
           System.out.print("\n\n\t Digite a opcao: ");
           opcao = entrada.nextInt();           
           
           switch(opcao){                                        
                case 1: 
                    System.out.println("Digite a quantidade de horas que deseja comprar: ");
                    qtdeHoras = entrada.nextDouble();
                    objGame.comprar(qtdeHoras);
                    System.out.println("Compra efetuado com sucesso na conta " + objGame.getCodigo());
                    break;                           
                case 2: 
                    System.out.println("Jogará por quanto tempo ?: ");
                    qtdeHoras = entrada.nextDouble();
                    if (qtdeHoras > objGame.getQtdeHoras()) {
                        System.out.println("Você não possui horas suficientes para jogar!");
                    } else {
                        objGame.jogar(qtdeHoras);
                        System.out.println("Tempo subtraido do de saldo de horas da conta " + objGame.getCodigo());
                    }      
                    break;
                case 3:
                    objGame.brinde();
                    System.out.println("A conta " + objGame.getCodigo() + " acaba de dobrar seu saldo de horas com o brinde!");
                    break;  
                case 4:
                    System.out.println("Seu saldo de horas atual é: " + objGame.getQtdeHoras());          
                    break;
           }
       }while (opcao < 5);
    }
    
}
