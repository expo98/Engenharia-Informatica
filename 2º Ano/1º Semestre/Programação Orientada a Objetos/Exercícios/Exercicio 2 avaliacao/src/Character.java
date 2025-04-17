/**
 *
 * @author miguempereira
 * @version 1.0
 */

/**
 * A classe {@code Character} representa uma personagem genérica
 * no jogo. Ela engloba propriedades como o nome, experiencia, e
 * habilidades básicas partilhadas por todas as suas subclasses
 *
 */
class Character{
    /**
     * Nome da personagem
     */
    String name;
    /**
     * Nível de experiência da personagem
     */
    double experience;
    /**
     * Nível de força da personagem
     */
    double strength;
    /**
     * Nível de agilidade da personagem
     */
    double agility;
    /**
     * Nível da inteligencia da personagem
     */
    double inteligence;

    /**
     * Construtor default da classe {@code Character}.
     * Inicializa o nome, a experiência num valor aleatório e as
     * habilidades básicas para valores nulos.
     */
    public Character() {
        name = "";
        int max = 25;
        int min = 1;
        int range = max - min + 1;
        experience = (int) (Math.random() * range) + min;
        strength = 0;
        agility = 0;
        inteligence = 0;
    }
    public void printCharacterInfo(){
        System.out.println("Nome: " + name);
        System.out.println("Experiência: " + experience);
        System.out.println("Força: " + Math.round(strength));
        System.out.println("Agilidade: " + Math.round(agility));
        System.out.println("Inteligência: " + Math.round(inteligence));
    };
    public void levelUp(){
        System.out.println("Personagem antes de subir de nível:");
        printCharacterInfo();
        experience +=1;
        System.out.println("Personagem após subir de nível:");
        printCharacterInfo();
    };

    boolean sementesAbobora(){
        return false;
    };
    boolean temArmadura(){
        return false;
    };
    boolean   temArco(){
        return false;
    };

}

