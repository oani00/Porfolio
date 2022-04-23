import fatec.poo.model.Aluno;
import fatec.poo.model.Professor;
import java.text.DecimalFormat;
/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        //instanciação de um objeto da classe Aluno
        Aluno ObjAluno = new Aluno(1010, "Carlos", "15/03/1978");
        
        ObjAluno.setMensalidade(1500);
        System.out.println("ALUNO\n");
        System.out.println("Registro Escolar: "+ ObjAluno.getRegEscolar());
        System.out.println("Nome: "+ ObjAluno.getNome());
        System.out.println("Data de nascimento: "+ ObjAluno.getDataNascimento());
        System.out.println("Mensalidade: "+ df.format(ObjAluno.getMensalidade()));
        
        Professor objProfessor = new Professor(1011, "Dimas", "01/01/1950");
        
        objProfessor.setSalario(20589.25);
        System.out.println("\n\nPROFESSOR\n");
        System.out.println("Registro Funcional: "+ objProfessor.getRegFuncional());
        System.out.println("Nome: "+ objProfessor.getNome());
        System.out.println("Data de nascimento: "+ objProfessor.getDataNascimento());
        System.out.println("Salário: "+ df.format(objProfessor.getSalario()));
    }   
}
