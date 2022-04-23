/**
 *
 * @author luizj
 */
public class Exemplo6 {
    public static void main(String[] args) {
        // definiçao do ponteiro
        int[] tabNum; 
        int cont;
        
        // alocação da matriz na memória
        tabNum = new int[3];
        
        tabNum[0] = 34;
        tabNum[1] = 18;
        tabNum[2] = 27;
        
        for(cont = 0; cont < 3; cont++){
            System.out.println("tabnNum[" + cont + "] = "+ tabNum[cont]);
        }
    }
    
}
