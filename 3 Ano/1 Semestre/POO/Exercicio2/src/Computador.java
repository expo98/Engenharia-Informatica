public abstract class Computador {

    private String id;
    private int ram;
    private int disco;
    private double cpu;
    private String arquitetura;
    private String nivel;

    // Constructor
    public Computador(String id, int ram, int disco, double cpu, String arquitetura, String nivel){
        this.id = id;
        this.ram = ram;
        this.disco = disco;
        this.cpu = cpu;
        this.arquitetura = arquitetura;
        this.nivel = nivel;
    }

    //
    

    // Getters para cada attributo
    public String getId() {
        return id;
    }

    public int getRam() {
        return ram;
    }

    public int getDisco() {
        return disco    ;
    }

    public double getCPU() {
        return cpu;
    }

    public String getArquitetura() {
        return arquitetura;
    }

    public String getNivel() {
        return nivel;
    }

    public double calculaConsumoEnergetico(){
        return 0;
    };

    public String toString() {
        return "ID: " + id + ", RAM: " + ram + ", Disco: " + disco + "GB" + ",CPU: " + cpu + "Ghz" + ", Arquitetura: " + arquitetura + ", Nível: " + nivel;
    }


}
