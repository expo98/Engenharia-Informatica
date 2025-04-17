public class Main {
    public static void main(String[] args) {

      System.out.println("MeioTransporte: ");
      MeioTransporte m= new MeioTransporte();
      System.out.println("condutor" + m.condutor);
      m.movimenta();

      System.out.println("\n\nTransportePublico: ");
      TransportePublico t = new TransportePublico();
      System.out.println("condutor " + t.condutor);
      t.movimenta();
      // Mas também
        for (int i = 0; i < t.passageiros.length; i++)
            System.out.println(t.passageiros[i] + "         ");
        t.picaBilhete();


      System.out.println("\n\nComboio:");
      Comboio c = new Comboio();
      System.out.println("condutor" + c.condutor);
      c.movimenta();
      System.out.println("passageiros:");
      for (int i = 0; i<c.passageiros.length; i++)
            System.out.println(c.passageiros[i] + "         ");
      c.picaBilhete();
      //.. e ainda:
       c.apita();
       System.out.println("num carruagens " + c.numCarruagens);
       // (...)
      
    }
}

class MeioTransporte{
    protected String condutor = "Zé";
    void movimenta(){
        System.out.println("Em movimento!!");
    }
}

class TransportePublico extends  MeioTransporte {
    protected String[] passageiros ={"Xico", "Manel", "João"};
    void picaBilhete(){
        System.out.println("A picar um bilhete!!");
    }
}

class Comboio extends TransportePublico {
    protected int numCarruagens = 5;
    void apita() {
        System.out.println("tutuuu!");
    }
}

