public class Laptop extends Computador {

    //Atributo adicional para Laptop
    private boolean hasGPU;


    public Laptop(String id, int ram, int disco, double cpu, String arquitetura, String nivel, boolean hasGPU) {

        // Chama a superclasse
        super(id, ram, disco, cpu, arquitetura, "Edge");
        this.hasGPU = hasGPU;
    }

    //Getter para hasGpu
    public boolean getGPU(){
        return hasGPU;
    }

    @Override
    public double calculaConsumoEnergetico(){

        if (getGPU()) {
            return 50 * getCPU() * 1.2;
        } else {
            return 50 * getCPU();
        }

    }


}
