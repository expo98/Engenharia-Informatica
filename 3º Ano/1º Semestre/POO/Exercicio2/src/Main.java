
public class Main {
    public static void main(String[] args) {
        NCSLab lab = new NCSLab();
        System.out.println("Computadores:");
        lab.printComputadores();

        System.out.println("\nComputadores com arquitetura x64:");
        lab.print64Computadores();

        System.out.println("\nConsumo de energia:");
        lab.printConsumoEnergia();

    }
}