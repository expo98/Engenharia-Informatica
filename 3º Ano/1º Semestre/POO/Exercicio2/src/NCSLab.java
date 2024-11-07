import java.lang.reflect.Array;
import java.util.ArrayList;

public class NCSLab {

    private ArrayList<Computador> computadores;

    //construtor
    public NCSLab(){
        computadores = new ArrayList<>();
    }

    private void preencheComputadores(){
        for( int i =1; i <=5; i++){
            computadores.add(new Servidor("Server-"+i));
            computadores.add(new Laptop("Laptop-"+i));
            computadores.add(new RaspberryPi("RaspberryPi"+i));
            //gay

        }
    }



}
