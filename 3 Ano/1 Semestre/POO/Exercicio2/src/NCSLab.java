
import java.util.ArrayList;

public class NCSLab {

    private ArrayList<Computador> computadores;

    public NCSLab(){
        computadores = new ArrayList<>(); //array list computadores
        preencheComputadores(); //cria computadores
    }

    private void preencheComputadores(){
        for( int i =1; i <=5; i++){ //loop para criar computadores 5 vezes

            //cria 1 computador de cada tipo
            Computador servidor = new Servidor("Servidor-"+i, randomRam(128, 512), randomDisk(1024, 16384), randomCpu(3.0, 4.0), "x64", "Cloud");
            Computador laptop = new Laptop("Laptop-"+i, randomRam(16, 64), randomDisk(256, 1024), randomCpu(2.0, 3.0), "x64", "Edge", Math.random() < 0.5); //random para hasGPU
            Computador raspberryPi = new RaspberryPi("RPi-"+i, randomRam(2, 8), randomDisk(16, 128), randomCpu(1.0, 2.0), "ARM", "IoT");

            //adiciona computadores ao array list
            computadores.add(servidor); 
            computadores.add(laptop);
            computadores.add(raspberryPi);
        }
    }


    //metodos para gerar numeros aleatorios potencia de 2
    private int randomRam(int min, int max) {
        return (int) Math.pow(2, (int) (Math.log(min) / Math.log(2) + Math.random() * (Math.log(max) / Math.log(2) - Math.log(min) / Math.log(2))));
    }

    private int randomDisk(int min, int max) {
        return (int) Math.pow(2, (int) (Math.log(min) / Math.log(2) + Math.random() * (Math.log(max) / Math.log(2) - Math.log(min) / Math.log(2))));
    }

    //metodo para gerar numeros aleatorios 
    private double randomCpu(double min, double max) {
        return min + Math.random() * (max - min); 
    }

    public void printConsumoEnergia(){ //print consumo de energia
        for (Computador computador : computadores) {
            System.out.println(computador.getId() + " - " + computador.calculaConsumoEnergetico() + "W");
        }
    }

    public void printComputadores(){ //print todos os computadores
        for (Computador computador : computadores) {
            System.out.println(computador.toString());
        }
    }

    public void print64Computadores(){
        for (Computador computador : computadores) {
            if (computador.getArquitetura().equals("x64")) { //se arquitetura for x64 dá print
                System.out.println(computador.toString());
            }
        }
    }

}
