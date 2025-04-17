import java.lang.Math;
public class Random {
    public static void main(String[] args) {
        int length = 10;
        int[] lista = new int[length];

        // define range
        int max = 100;
        int min = 0;
        int range = max - min + 1;


        int soma_total = 0;
        for(int i = 0; i< length;i++){
            lista[i] = (int) (Math.random() * range +1);
            soma_total += lista[i];
        }

        int media = soma_total / length;

        for (int i = 0; i<length; i++)
        {
            System.out.printf("Posição: %d ; Número : %d \n", i, lista[i]);
        }

        System.out.printf("A média da lista é : %d", media);
    }
}