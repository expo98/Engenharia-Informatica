public class Servidor extends Computador {

    public Servidor(String id, int ram, int disco, double cpu, String arquitetura, String nivel){

        // Chama a superclasse
        super(id, ram, disco, cpu, arquitetura, "Cloud");
    }

    @Override
    public double calculaConsumoEnergetico(){
        return 80 * getCPU();
    }
}
