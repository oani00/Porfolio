
import fatec.poo.model.PedidoCompra;
import fatec.poo.model.Pessoa;
import fatec.poo.model.PessoaFisica;
import fatec.poo.model.PessoaJuridica;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author
 */
public class Aplic {

    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        Scanner entrada = new Scanner(System.in);

        //Definição da matriz de objetos 
        ArrayList<Pessoa> cadPesFisJur = new ArrayList<Pessoa>();
        ArrayList<PedidoCompra> cadPedidos = new ArrayList<PedidoCompra>();

        int opcao, cont = 0, cont1 = 0, anoInsc, anoAtual, pesqPes, numPed;
        double valBase, valCompra, txIncentivo, valPed;
        String nome, cpfcgc, tipoPes, dataPed;

        System.out.print("Digite o ano atual (aaaa) ===> ");
        anoAtual = entrada.nextInt();
        do {
            System.out.println("\n1 – Cadastrar Pessoa Física");
            System.out.println("2 – Cadastrar Pessoa Jurídica");
            System.out.println("3 – Emitir Pedido");
            System.out.println("4 – Listar Bonus");
            System.out.println("5 – Sair");
            System.out.print("\n\tDigite a opcao: ");
            opcao = entrada.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("\nDigite o CPF: ");
                    cpfcgc = entrada.next();
                    System.out.print("Digite o nome: ");
                    nome = entrada.next();
                    System.out.print("Digite o ano de inscrição (aaaa): ");
                    anoInsc = entrada.nextInt();

                    //Instanciação de objetos da classe PessoaFisica
                    cadPesFisJur.add(new PessoaFisica(cpfcgc, nome, anoInsc));

                    System.out.print("Digite o valor base: ");
                    valBase = entrada.nextDouble();

                    //chamada do método setBase com downcasting
                    ((PessoaFisica)cadPesFisJur.get(cont)).setBase(valBase);

                    cont++;
                    break;

                case 2:

                    System.out.print("\nDigite o CGC: ");
                    cpfcgc = entrada.next();
                    System.out.print("Digite o nome: ");
                    nome = entrada.next();
                    System.out.print("Digite o ano de inscrição (aaaa): ");
                    anoInsc = entrada.nextInt();

                    //Instanciação de objetos da classe PessoaJuridica
                    cadPesFisJur.add(new PessoaJuridica(cpfcgc, nome, anoInsc));

                    System.out.print("Digite a taxa de incentivo(%): ");
                    txIncentivo = entrada.nextDouble();

                    //chamada do método setTaxaIncentivo com downcasting
                    ((PessoaJuridica)cadPesFisJur.get(cont)).setTaxaIncentivo(txIncentivo);

                    cont++;

                    break;

                case 3:

                    System.out.println("\n\nInforme o cpf/cgc: ");
                    cpfcgc = entrada.next();

                    if (pesqPessoa(cadPesFisJur, cpfcgc) == -1) {
                        System.out.println("\n\t\t-------------------------------------");
                        System.out.println("\t\tPessoa Física/Jurídica não cadastrada");
                        System.out.println("\t\t-------------------------------------");
                    } else {
                        System.out.println("Digite o número do pedido: ");
                        numPed = entrada.nextInt();
                        System.out.println("Digite a data do pedido: ");
                        dataPed = entrada.next();
                        System.out.println("Digite o valor do Pedido: ");
                        valPed = entrada.nextDouble();

                        //Instanciação do objeto da classe PedidoCompra
                        cadPedidos.add(new PedidoCompra(numPed));
                        cadPedidos.get(cont1).setDataPedido(dataPed);
                        cadPedidos.get(cont1).setValor(valPed);

                        //estabelecendo a associação binária bidirecional 
                        //entre PessoaFisica/PessoaJuridica e PedidoCompra
                        cadPesFisJur.get(pesqPessoa(cadPesFisJur, cpfcgc)).addPedidoCompra(cadPedidos.get(cont1));
                                                
                        //adicionando o valor do pedido de compra em PessoaFisica
                        cadPesFisJur.get(pesqPessoa(cadPesFisJur, cpfcgc)).addCompras(cadPedidos.get(cont1).getValor());

                        cont1++;
                    }

                    break;

                case 4:
                    if (cadPesFisJur.size() > 0) {
                        System.out.printf("\n%-15s %-15s %-15s %-15s %10s\n", "Tipo", "CPF/CGC", "Nome", "Ano Inscrição", "Bonus");
                        for (int i = 0; i < cont; i++) {
                            if (cadPesFisJur.get(i) instanceof PessoaFisica) {
                                System.out.printf("%-15s %-15s %-15s %-15d %10s\n", "Pessoa Fisica",
                                        ((PessoaFisica) cadPesFisJur.get(i)).getCPF(),
                                        cadPesFisJur.get(i).getNome(),
                                        cadPesFisJur.get(i).getAnoInscricao(),
                                        df.format(cadPesFisJur.get(i).calcBonus(anoAtual)));

                            } else {
                                System.out.printf("%-15s %-15s %-15s %-15d %10s\n", "Pessoa Juridica",
                                        ((PessoaJuridica) cadPesFisJur.get(i)).getCGC(),
                                        cadPesFisJur.get(i).getNome(),
                                        cadPesFisJur.get(i).getAnoInscricao(),
                                        df.format(cadPesFisJur.get(i).calcBonus(anoAtual)));
                            }
                        }
                    } else {
                        System.out.println("\n\t\t----------------------------");
                        System.out.println("\t\tNão há cadastros para listar");
                        System.out.println("\t\t----------------------------");
                    }
                    break;
            }
        } while (opcao < 5);
    }

    public static int pesqPessoa(ArrayList<Pessoa> cadastro, String cpfcgc) {
        int cont, Resultado = -1;
        String valor;

        cont = 0;

        //utilizando o downcasting
        if (cadastro.get(cont) instanceof PessoaFisica) {
            valor = ((PessoaFisica) cadastro.get(cont)).getCPF();
        } else {
            valor = ((PessoaJuridica) cadastro.get(cont)).getCGC();
        }
        while (cont < cadastro.size() && !valor.equals(cpfcgc)) {
            cont++; //posiciona no próximo

            if (cont < cadastro.size() && cadastro.get(cont) instanceof PessoaFisica) {
                valor = ((PessoaFisica) cadastro.get(cont)).getCPF();
            } else if (cont < cadastro.size() && cadastro.get(cont) instanceof PessoaJuridica) {
                valor = ((PessoaJuridica) cadastro.get(cont)).getCGC();
            }
        }
        if (cont < cadastro.size()) {
            Resultado = cont;
        }

        return (Resultado);
    }
}
