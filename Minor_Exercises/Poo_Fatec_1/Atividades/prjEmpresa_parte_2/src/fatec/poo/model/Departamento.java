package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Dimas
 */
public class Departamento {
    private String sigla;
    private String nome;
    private ArrayList<Funcionario> funcionarios; //multiplicidade 1..*
      
    public Departamento(String sigla, String nome) {
        this.sigla = sigla;
        this.nome = nome;
        funcionarios = new ArrayList<Funcionario>();        
    }

    public String getSigla() {
        return sigla;
    }

    public String getNome() {
        return nome;
    }
                                                       
    public void addFuncionario(Funcionario f){
        funcionarios.add(f);     
        f.setDepartamento(this);
    }  
    
    public void listarFuncionarios(){
        System.out.println("\n\nSigla: " + sigla);
        System.out.println("Nome: " + nome);
        System.out.println("No. de Funcionários: " + funcionarios.size());
        System.out.println("\nRegistro\t\tNome\t\tCargo");
        for (int x = 0; x < funcionarios.size(); x++){
            System.out.print(funcionarios.get(x).getRegistro() + "\t\t");
            System.out.print(funcionarios.get(x).getNome()    + "\t\t");
            System.out.println(funcionarios.get(x).getCargo());
        }
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    
}
