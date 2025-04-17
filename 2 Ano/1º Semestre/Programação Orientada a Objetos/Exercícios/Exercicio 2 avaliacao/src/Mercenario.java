import java.util.Objects;

/**
 * A classe {@code Mercenario} é uma subclasse de {@code Character} e representa
 * uma personagem mercenário no jogo. Ela gere as habilidades e itens específicos
 * para um mercenário.
 * <p>
 * O Mercenario possui um inventário composto por uma arma de longo alcance e
 * o munição.
 * </p>
 * @author miguempereira
 * @version 1.0
 */
class Mercenario extends Character{

    /**
     * Tipo de arma de longo alcance que o mercenário detém.
     */

    String LongRangeWeapon;
    /**
     * Número de munição que o mercenário tem para a sua arma de longo alcance.
     */
    int numAmmo;



    /**
     * Construtor default para a classe {@code Mercenario}.
     * Inicializa, com base na experiência, as habilidades
     * do mercenário.
     *
     * @param LongRangeWeapon Tipo de arma de longo alcance do Mercenario
     * @param numAmmo Número de munição que o Mercenário tem para a sua arma
     */
    public Mercenario(String LongRangeWeapon, int numAmmo){
        super();

        this.LongRangeWeapon = LongRangeWeapon;
        this.numAmmo = numAmmo;

        /**
         * Nível inicial de força do mercenário
         */
        this.strength=4;
        /**
         * Nível inicial de agilidade do mercenário
         */
        this.agility=10;
        /**
         * Nível inicial da inteligencia do mercenário
         */
        this.inteligence=4;

        // Define os níveis das diferentes habilidades com base na experiencia
        this.strength = 4 * (double) (Math.pow(1.08,experience-1));
        this.agility = 10 * (double) (Math.pow(1.2,experience-1));
        this.inteligence = 4 * (double) (Math.pow(1.08,experience-1));
    }

    /**
     * Imprime as informações do personagem, incluindo nome, experiência, força,
     * agilidade, inteligência, a arma de curto alcance e o número de munição.
     */
    @Override
    public void printCharacterInfo() {
        System.out.println("Nome: " + name);
        System.out.println("Experiência: " + experience);
        System.out.println("Força: " + Math.round(strength));
        System.out.println("Agilidade: " + Math.round(agility));
        System.out.println("Inteligência: " + Math.round(inteligence));
        System.out.println("Arma de Longo alcance: " + LongRangeWeapon);
        System.out.println("Número de munição: " + numAmmo + "\n\n");
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

            experience +=1;

            this.strength = 4 * (double) (Math.pow(1.08,experience-1));
            this.agility = 10 * (double) (Math.pow(1.2,experience-1));
            this.inteligence = 4 * (double) (Math.pow(1.08,experience-1));

            System.out.println("Informação do personagem após subir de nível:");
            printCharacterInfo();
        }
        else System.out.println("Limite máximo de experienca atingido");
    }
    /**
     * Verifica se o Mercenario possui Arco.
     *
     * @return true se o Mercenario tem Arco, false caso contrário.
     */
    @Override
    public boolean temArco(){
        return Objects.equals(LongRangeWeapon, "Arco");
    }

}