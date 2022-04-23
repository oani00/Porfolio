import fatec.poo.model.Pessoa;
import fatec.poo.model.Instrutor;
import fatec.poo.model.Cliente;
import java.text.DecimalFormat;
/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        //instanciação de um objeto da classe Aluno
        Instrutor ObjInstrutor = new Instrutor(123, "J.P", "14 99999-9999");
        
        ObjInstrutor.setAreaAtuacao("Vans & Caminhões");
        System.out.println("Instrutor\n");
        System.out.println("Identificação: "+ ObjInstrutor.getIdentificacao());
        System.out.println("Área de atuação: "+ ObjInstrutor.getAreaAtuacao());
        System.out.println("Nome: "+ ObjInstrutor.getNome());
        System.out.println("Telefone: "+ ObjInstrutor.getTelefone());
        
        Cliente objCliente = new Cliente("123.456.789-12", "Dimas", "15 98999-9898");
        
        objCliente.setPeso(89.5);
        objCliente.setAltura(1.52);
        System.out.println("\n\nCliente\n");
        System.out.println("CPF: "+ objCliente.getCpf());
        System.out.println("Nome: "+ objCliente.getNome());
        System.out.println("Telefone: "+ objCliente.getTelefone());
        System.out.println("Peso: "+ df.format(objCliente.getPeso()));
        System.out.println("Altura: "+ df.format(objCliente.getAltura()));
    }   
}
