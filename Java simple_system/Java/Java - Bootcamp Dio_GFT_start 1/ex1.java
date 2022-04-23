import java.util.*; //por causa do metodo de stdin
import java.io.IOException;

public class Main{
	
    public static void main(String[] args) throws IOException {
    	
    	Scanner scan = new Scanner(System.in);
    	
    	int numero = scan.nextInt();
    	
    	for (int i = 1 ; i <= numero ; i++) { if (i%2 == 0  ) System.out.println(i);}
    		//atente a esse 1, no exercicio ele nao considerava 0 par
    }
	
}


/*

///////https://www.hackerrank.com/challenges/java-stdin-and-stdout-1/problem

BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

StringTokenizer st = new StringTokenizer(br.readLine()); // Lê a linha de entrada

int a = Integer.parseInt(st.nextToken());

System.out.println(a); // Imprime o dado */