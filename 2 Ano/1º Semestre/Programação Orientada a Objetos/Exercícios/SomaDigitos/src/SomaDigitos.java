import java.util.Scanner;

public class SomaDigitos {
    public static void main(String[] args) {
        int num;
        int soma =0;
        System.out.printf("Escreva o número: ");
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        while(num>0)
        {
            soma = soma + ( num % 10);
            num  = num / 10;
        }
        System.out.printf("Soma dos digitos : %d", soma);
    }
}
