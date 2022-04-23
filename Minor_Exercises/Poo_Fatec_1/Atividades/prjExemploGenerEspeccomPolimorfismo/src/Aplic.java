import fatec.poo.model.FuncionarioComissionado;
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;
import java.text.DecimalFormat;
/**
 *
 * @author luizj
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        FuncionarioHorista funcHor = new FuncionarioHorista(5.25, 1010, "Joãozinho", "01/01/1970");
        FuncionarioMensalista funcMen = new FuncionarioMensalista(1011, "Pedro Malandro", "01/01/1980", 1018.25);
        FuncionarioComissionado funcCom = new FuncionarioComissionado(1012, "Zika Baleiro", "01/01/1990", 15);
        
        // Funcionário Horista
        funcHor.setQtdHorTrab(200);
        funcHor.setCargo("Dev júnior");
        System.out.println("Funcionário Horista\n");
        System.out.println("Registro: "+ funcHor.getRegistro());
        System.out.println("Nome: "+ funcHor.getNome());
        System.out.println("Data de Admissão: "+ funcHor.getDtAdmissao());
        System.out.println("Cargo: "+ funcHor.getCargo());
        System.out.println("Salário Bruto: R$ "+ df.format(funcHor.calcSalBruto()));
        System.out.println("Gratificação: R$ "+ df.format(funcHor.calcGratificacao()));
        System.out.println("Desconto: R$ "+ df.format(funcHor.calcDesconto()));
        System.out.println("Salário Líquido: R$ "+ df.format(funcHor.calcSalLiquido()));
        
        // Funcionário Mensalista
        funcMen.setNumSalMin(5.5);
        funcMen.setCargo("Dev sênior");
        System.out.println("\nFuncionário Mensalista\n");
        System.out.println("Registro: "+ funcMen.getRegistro());
        System.out.println("Nome: "+ funcMen.getNome());
        System.out.println("Data de Admissão: "+ funcMen.getDtAdmissao());
        System.out.println("Cargo: "+ funcMen.getCargo());
        System.out.println("Salário Bruto: R$ "+ df.format(funcMen.calcSalBruto()));
        System.out.println("Desconto: R$ "+ df.format(funcMen.calcDesconto()));
        System.out.println("Salário Líquido: R$ "+ df.format(funcMen.calcSalLiquido()));
        
        // Funcionário Comissionado
        funcCom.setSalBase(4623.25);
        funcCom.setCargo("Vendedor Chefe de escrivaninhas");
        funcCom.addVendas(152.50);
        funcCom.addVendas(652);
        System.out.println("\nFuncionário Comissionado\n");
        System.out.println("Registro: "+ funcCom.getRegistro());
        System.out.println("Nome: "+ funcCom.getNome());
        System.out.println("Data de Admissão: "+ funcCom.getDtAdmissao());
        System.out.println("Cargo: "+ funcCom.getCargo());
        System.out.println("Salário Bruto: R$ "+ df.format(funcCom.calcSalBruto()));
        System.out.println("Total vendas: R$ "+ df.format(funcCom.getTotalVendas()));
        System.out.println("Comissão: R$ "+ df.format(funcCom.getTotalVendas() * (funcCom.getTaxaComissao()/100)));
        System.out.println("Desconto: R$ "+ df.format(funcCom.calcDesconto()));
        System.out.println("Gratificação: R$ "+ df.format(funcCom.calcGratificacao()));
        System.out.println("Salário Líquido: R$ "+ df.format(funcCom.calcSalLiquido()));
        
    }
    
}
