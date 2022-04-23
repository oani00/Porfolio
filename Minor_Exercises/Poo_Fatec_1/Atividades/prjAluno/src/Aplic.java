import java.util.Scanner;
import fatec.poo.model.Aluno;
/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Aluno objAluno = new Aluno();
        
        int RA, opcao;
        double NtPrv1, NtPrv2, NtTrab1, NtTrab2;
        
        System.out.print("Digite seu RA: ");
        RA = entrada.nextInt();
        System.out.print("Digite a nota da sua primeira prova: ");
        NtPrv1 =  entrada.nextDouble();
        System.out.print("Digite a nota da sua segunda prova: ");
        NtPrv2 =  entrada.nextDouble();
        System.out.print("Digite a nota do seu primeiro trabalho: ");
        NtTrab1 =  entrada.nextDouble();
        System.out.print("Digite a nota do seu primeiro trabalho: ");
        NtTrab2 =  entrada.nextDouble();
        
        // passagem de mensagens
        objAluno.setRA(RA);
        objAluno.setNtPrv1(NtPrv1);
        objAluno.setNtPrv2(NtPrv2);
        objAluno.setNtTrab1(NtTrab1);
        objAluno.setNtTrab2(NtTrab2);
        
        do {
            System.out.println("\n1 - Exibir Nota das provas/trabalhos");
            System.out.println("2 - Exibir média dos trabalhos/provas");
            System.out.println("3 - Exibir média final");
            System.out.println("4 - Sair");
            System.out.print("\n \n\tDigite sua opção: ");
        
            opcao = entrada.nextInt(); // scanf("%d", &opcao)
            
            switch(opcao){
                case 1: 
                    System.out.println("Aluno: " + objAluno.getRA());
                    System.out.println("Nota da prova 1: " + objAluno.getNtPrv1());
                    System.out.println("Nota da prova 2: " + objAluno.getNtPrv2());
                    System.out.println("Nota do trabalho 1: " + objAluno.getNtTrab1());
                    System.out.println("Nota do trabalho 2: " + objAluno.getNtTrab2());
                    break;
                case 2: 
                    System.out.println("Aluno: " + objAluno.getRA());
                    System.out.println("Média dos trabalhos: " + objAluno.calcMediaTrab());
                    System.out.println("Média das provas: " + objAluno.calcMediaProva());
                    break;
                case 3: 
                    System.out.println("Aluno: " + objAluno.getRA());
                    System.out.println("Média final: " + objAluno.calcMediaFinal());
                    break;
                case 4:
                    System.out.println("Aplicação encerrada");
                    break;
            }
        } while (opcao < 4);
        
        
    }
    
}
