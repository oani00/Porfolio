//https://www.urionlinejudge.com.br/judge/pt/problems/view/1020

import java.io.IOException;
import java.util.Scanner;

public class Main{
	
    public static void main(String[] args) throws IOException {
        Scanner leitor = new Scanner(System.in);
        int idadeDias = leitor.nextInt();
        int anos = idadeDias / 365;
        idadeDias -= anos * 365;
        int meses = idadeDias / 30;
        idadeDias -= meses * 30;
        int dias = idadeDias;
        System.out.println( anos + " ano(s)");
        System.out.println( meses + " mes(es)");
        System.out.println( dias + " dia(s)");
    }
	
}