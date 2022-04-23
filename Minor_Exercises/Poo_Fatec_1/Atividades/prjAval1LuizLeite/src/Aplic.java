import fatec.poo.model.Palestrante;
import fatec.poo.model.Participante;
import fatec.poo.model.Palestra;
import java.text.DecimalFormat;
/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##.00");
        Palestrante objPalestrante = new Palestrante("123.456.789-11", "Carlos Silva", 75.00);
        Participante objParticipante1 = new Participante("121.121.121-22", "Ana Beatriz", 1);
        Participante objParticipante2 = new Participante("131.131.131-33", "Fabio Souza", 2);
        Participante objParticipante3 = new Participante("141.141.141-44", "Marcos Silva", 3);
        Palestra objPalestra = new Palestra("15/06/2020", "Segurança Corporativa");
        
        objPalestrante.setAreaAtuacao("Segurança em Rede de Computadores");
        objParticipante1.setEscolaridade("Ensino Médio");
        objParticipante2.setEscolaridade("Ensino Médio");
        objParticipante3.setEscolaridade("Ensino Superior");
        objPalestra.setLocal("Auditório Carlos Penha");
        objPalestra.setValor(600.00);
        
        objPalestra.addParticipante(objParticipante1);
        objPalestra.addParticipante(objParticipante2);
        objPalestra.addParticipante(objParticipante3);
        objPalestra.addPalestrante(objPalestrante);
        objPalestrante.addPalestra(objPalestra);
        
        objPalestrante.listarPalestras();
        
        objPalestra.emitiListaParticipantes();
        
    }
}
