/**
 * A classe {@code Guerreiro} é uma subclasse de {@code Character} e representa
 * uma personagem guerreiro no jogo. Ela gere as habilidades e itens específicos
 * para um guerreiro.
 *
 * <p>
 * O guerreiro possui um inventário composto por armadura e uma arma de curto alcance.
 * </p>
 * @author miguempereira
 * @version 1.0
 */
class Guerreiro extends Character{

    /**
     * Indica se o guerreiro tem ou não armadura.
     */
    boolean Armor;
    /**
     * A arma de curto alcance que o guerreiro possui.
     */

    String ShortRangeWeapon;




    /**
     * Construtor default para a classe {@code Guerreiro}.
     * Inicializa, com base na experiência, as habilidades
     * do guerreiro.
     *
     * @param Armor Indica se tem armadura ou não
     * @param ShortRangeWeapon Tipo de arma de curto alcance do guerreiro
     */

    public Guerreiro(boolean Armor, String ShortRangeWeapon){

        this.Armor = Armor;
        this.ShortRangeWeapon = ShortRangeWeapon;

        /**
         * O nível inicial da força do guerreiro.
         */
        this.strength = 10;
        /**
         * O nível inicial da agilidade do guerreiro.
         */
        this.agility = 5;
        /**
         * O nível inicial da inteligência de um guerreiro.
         */
        this.inteligence =3;

        // Define os níveis das diferentes habilidades com base na experiencia

            this.strength = 10* (double) (Math.pow(1.2,experience-1));
            this.agility = 5 * (double) (Math.pow(1.1,experience-1));
            this.inteligence = 3 * (double) (Math.pow(1.05,experience-1));

    }

    /**
     * Imprime as informações do personagem, incluindo nome, experiência, força,
     * agilidade, inteligência, presença ou ausência de armadura e a arma de curto alcance.
     */
    @Override
    public void printCharacterInfo() {
        System.out.println("Nome: " + name);
        System.out.println("Experiência: " + experience);
        System.out.println("Força: " + Math.round(strength));
        System.out.println("Agilidade: " + Math.round(agility));
        System.out.println("Inteligência: " + Math.round(inteligence));
        System.out.println("Tem armadura: " + Armor);
        System.out.println("Arma de curto alcance: " + ShortRangeWeapon +"\n\n");

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

            this.strength = 10* (double) (Math.pow(1.2,experience-1));
            this.agility = 5 * (double) (Math.pow(1.1,experience-1));
            this.inteligence = 3 * (double) (Math.pow(1.05,experience-1));

            System.out.println("Informação do personagem após subir de nível:");
            printCharacterInfo();
        }
        else System.out.println("Limite máximo de experienca atingido");
    }
    /**
     * Verifica se o guerreiro possui armadura.
     *
     * @return true se o guerreiro tem armadura, false caso contrário.
     */
    @Override
    public boolean temArmadura(){
        return Armor;
    }

}
