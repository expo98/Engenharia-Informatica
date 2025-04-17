public class Main {
    public static void main(String[] args) {

       Aluno Aluno1 = new Aluno();
       Aluno1.nome = "Miguel Pereira";
       Aluno1.numID = 2022232552;
       Aluno1.comunica();
       System.out.println(Aluno1.toString());


       Professor Professor1 = new Professor();
       Professor1.nome = "Karima Velasquez";
       Professor1.numID = 8008135;
       Professor1.comunica();
       System.out.println(Professor1.toString());

        
    }


}

class Pessoa{
    String nome;
     void comunica(){
        System.out.println( nome + " está a comunicar!");
    }
}

class Aluno extends Pessoa{
    int numID;
    static String missao(){
        return "aprender";
    }

    public String toString() {
        return "O/A aluno " + nome + " tem o número de estudante " + numID + "e tem como missao " + missao();
    }
}


class Professor extends Pessoa {
    int numID;
    static String missao() {
            return "ensinar";
    }

    public String toString(){
        return "O/A docente " + nome +" tem o número mecanográfico " + numID + "e tem como missao " + missao();
    }
}