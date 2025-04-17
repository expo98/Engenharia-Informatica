import java.util.Objects;

/**
 * A classe {@code Mago} é uma subclasse de {@code Character} e representa
 * uma personagem mago no jogo. Ela gere as habilidades e itens específicos
 * para um mago.
 * <p>
 * O mago possui um inventário composto por sementes e folhas.
 * </p>
 * @author miguempereira
 * @version 1.0
 */
class Mago extends Character{

    /**
     * O tipo de sementes que o mago possui.
     */
    String Seeds;
    /**
     * O tipo de folhas que o mago possui
     */
    String Leaves;




    /**
     * Construtor default para a classe {@code Mago}.
     * Inicializa, com base na experiência, as habilidades
     * do mago.
     *
     * @param Leaves Tipo de folhas do mago
     * @param Seeds Tipo de sementes do mago
     */
    public Mago(String Seeds, String Leaves){

        super();

        this.Seeds = Seeds;
        this.Leaves = Leaves;

        /**
         * O nível inicial de força do mago.
         */
        this.strength = 2;
        /**
         * O nível inicial de agilidade do mago.
         */
        this.agility = 4;
        /**
         * O nível inciial de inteligência do mago.
         */
        this.inteligence=9;

        // Define os níveis das diferentes habilidades com base na experiencia
        this.strength = 2 * (double) (Math.pow(1.05,experience-1));
        this.agility = 4 * (double) (Math.pow(1.1,experience-1));
        this.inteligence = 9 * (double) (Math.pow(1.2,experience-1));
    }
    /**
     * Imprime as informações do personagem, incluindo nome, experiência, força,
     * agilidade, inteligência, o tipo de sementes e de fohas.
     */
    @Override
    public void printCharacterInfo() {
        System.out.println("Nome: " + name);
        System.out.println("Experiência: " + experience);
        System.out.println("Força: " + Math.round(strength));
        System.out.println("Agilidade: " + Math.round(agility));
        System.out.println("Inteligência: " + Math.round(inteligence));
        System.out.println("Tipo de Sementes: " + Seeds);
        System.out.println("Tipo de Folhas: " + Leaves +"\n\n");
    }
    /**
     * Aumenta o nível do personagem, atualizando as habilidades com base na experiência.
     * Imprime as informações do personagem antes e depois de subir de nível.
     */
    @Override
    public void levelUp(){
        if (experience+1 <=25){
            System.out.println("Informação do personagem antes de subir de nível:");
            printCharacterInfo();
            experience+=1;
            this.strength = 2 * (double) (Math.pow(1.05,experience-1));
            this.agility = 4 * (double) (Math.pow(1.1,experience-1));
            this.inteligence = 9 * (double) (Math.pow(1.2,experience-1));
            System.out.println("Informação do personagem após subir de nível:");
            printCharacterInfo();
        }
        else System.out.println("Limite máximo de experienca atingido");
    }
    /**
     * Verifica se o Mago possui Sementes de Abóbora.
     *
     * @return true se o Mago tem Sementes de Abóbora, false caso contrário.
     */
    @Override
    public boolean sementesAbobora(){
        return Objects.equals(Seeds, "Abóbora");
    }
}