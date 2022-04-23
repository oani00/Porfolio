package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Larissa e Hector
 */
public class Pessoa {
    private String cpf;
    private String nome;
    private String endereco;
    private String cidade;
    private String uf;
    private String cep;
    private String ddd;
    private String telefone;

    public Pessoa(String cpf, String nome) {
        this.cpf = cpf;
        this.nome = nome;
    }
    
    public static boolean validarCPF(String cpf){
        char[] chars = cpf.toCharArray();
        ArrayList<Integer> digits = new ArrayList<>();
        
        for(char item: chars){
            int digit = Character.getNumericValue(item);
            if(digit >=0 && digit <= 9){
                digits.add(digit);
              
              
              
            }
            
        }
        
        int firstDigit = 0, secondDigit = 0;
        for(int i = 0; i < digits.size() - 2; i++){
            firstDigit += digits.get(i)*(i+1);
        }
        
        firstDigit = (firstDigit%11 == 10) ? 0 : firstDigit%11;
        
        secondDigit = firstDigit*2;
        for(int i = 0; i < digits.size() - 2; i++){
            secondDigit += digits.get(i)*(11-i);
        }
        secondDigit = (secondDigit*10 % 11 == 10)? 0 : secondDigit*10 % 11;
        
        return firstDigit == digits.get(9) && secondDigit == digits.get(10);
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public void setUf(String uf) {
        this.uf = uf;
    }

    public String getCpf() {
        return cpf;
    }

    public String getNome() {
        return nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public String getCidade() {
        return cidade;
    }

    public String getUf() {
        return uf;
    }

    public String getCep() {
        return cep;
    }

    public String getDdd() {
        return ddd;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public void setDdd(String ddd) {
        this.ddd = ddd;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    
    
}
