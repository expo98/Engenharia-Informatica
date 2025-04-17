import java.util.Scanner;

public class Combinacoes {
    public static void main(String[] args) {
        int elementos_escolhidos;
        int elementos;
        int elementos_fatorial=1;
        int elementos_escolhidos_fatorial=1;
        int ambos_fatorial=1;

        int combinatoria;

        System.out.printf("Escreva o número de elementos: ");
        Scanner sc = new Scanner(System.in);
        elementos = sc.nextInt();

        System.out.printf("Escreva o número de conjunto de elementos: ");
        elementos_escolhidos = sc.nextInt();

        for ( int i = 1; i <= elementos; i++)
        {
            elementos_fatorial *= i;
        }

        for ( int i = 1; i <= elementos_escolhidos; i++)
        {
            elementos_escolhidos_fatorial *= i;
        }

        for (int i =1; i<= (elementos - elementos_escolhidos); i++)
        {
            ambos_fatorial *= i;
        }

        combinatoria = (elementos_fatorial) / ((elementos_escolhidos_fatorial) * ambos_fatorial );
        System.out.printf("A combinatória de %d elementos em conjuntos de %d elementos é = %d",elementos,elementos_escolhidos,combinatoria);
    }
}
