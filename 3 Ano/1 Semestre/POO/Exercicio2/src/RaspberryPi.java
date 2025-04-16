public class RaspberryPi extends Computador {

    public RaspberryPi(String id, int ram, int disco, double cpu, String arquitetura, String nivel){

        // Chama a superclasse
        super(id, ram, disco, cpu, arquitetura, "IoT");
    }

    @Override
    public double calculaConsumoEnergetico(){
        return 20 * getCPU();
    }
}
