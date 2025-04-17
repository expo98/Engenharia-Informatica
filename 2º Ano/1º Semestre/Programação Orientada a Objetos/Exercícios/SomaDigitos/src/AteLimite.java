import java.util.Scanner;

public class AteLimite {
    public static void main(String[] args) {
        int num,num_final=0;
        int soma = 0;
        System.out.printf("Introduza o número: ");
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();


        for (int i=1; soma<num;i++)
        {
            num_final=i;
            soma = soma +i;
        }

        System.out.printf("A soma final foi %d e o digito final a ser somado foi o %d", soma,num_final);
    }
}
