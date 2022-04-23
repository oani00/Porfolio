import fatec.poo.model.ContaCorrente;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
       DecimalFormat df = new DecimalFormat("#,##0.00");
       Scanner entrada = new Scanner(System.in);
       double valDep, valSaq, valSal;
       int opcao, numero;
       
       System.out.println("Digite o numero da conta: ");
       numero = entrada.nextInt();  
       
       System.out.println("Digite seu Saldo na conta: ");
       valSal = entrada.nextDouble();  
       
       //instanciação do objeto da classe Retangulo
       //e chamada do método construtor
       ContaCorrente objConta = new ContaCorrente(numero,valSal);
       
       do{
           System.out.println("\n\n1 - Efetuar Depósito");
           System.out.println("2 - Efetuar Saque");
           System.out.println("3 - Verificar Saldo");
           System.out.println("4 - Sair");
           System.out.print("\n\n\t Digite a opcao: ");
           opcao = entrada.nextInt();           
           
           switch(opcao){                                        
                case 1: 
                    System.out.println("Digite o valor do depósito: ");
                    valDep = entrada.nextDouble();
                    objConta.depositar(valDep);
                    System.out.println("Depósito realizado com sucesso na conta " + objConta.getNumero());
                    break;                           
                case 2: 
                    System.out.println("Digite o valor do Saque: ");
                    valSaq = entrada.nextDouble();
                    if (valSaq > objConta.getSaldo()) {
                        System.out.println("Saldo Insuficiente!");
                    } else {
                        objConta.sacar(valSaq);
                        System.out.println("Saque efetuado com sucesso na conta " + objConta.getSaldo());
                    }
                    break;
                case 3: 
                    System.out.println("conta: " + objConta.getNumero());
                    System.out.println("Saldo disponível: " + objConta.getSaldo());
                    break;        
           }
       }while (opcao < 4);
    }
    
}
