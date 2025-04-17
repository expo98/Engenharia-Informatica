import javax.swing.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

/**
 * A classe {@code PoW} é responsável por gerar um novo jogo "POAO of Warcraft".
 * Ela mantém uma lista de personagens e fornece métodos para subir de nível, imprimir listas
 * de personagens com diferentes critérios e criar personagens dos tipos Guerreiro, Mago e Mercenário.
 *
 * <p>
 * Para cada tipo de personagem, como Guerreiro, Mago e Mercenário, há métodos específicos
 * para criar personagens e ajustar as habilidades e itens de inventário com base nas escolhas do usuário.
 * </p>
 *
 * @author miguempereira
 * @version 1.0
 */
class PoW{
    ArrayList<Character> characters = new ArrayList<>();
    Scanner scanner = new Scanner(System.in);

    /**
     * Construtor default para a classe {@code PoW}.
     */
    public PoW(){

    }

    /**
     * Método usado para subir de nível uma personagem já criada.
     * Permite ao utilizador selecionar uma personagem e subir 1 nível de experiência.
     * As habilidades da personagem são ajustados com base no tipo de personagem.
     */
    public void SubirNivelPersonagem() {

        // Imprime os personagens associando um indice a elas
        System.out.println("Lista das personagens");
        for (int i = 1; i <= characters.size(); i++) {
            System.out.println(i + ") " + characters.get(i-1).name);
        }

        // Pede ao utilizador para selecionar uma personagem
        System.out.println("Escolhe o numero associado à personagem para subir de nível:");
        int characterIndex = scanner.nextInt();
        characterIndex -=1;

        // Verifica se o indice é válido
        if (characterIndex >= 0 && characterIndex < characters.size()) {
            // Seleciona o personagem escolhido
            Character selectedCharacter = characters.get(characterIndex);
            selectedCharacter.levelUp();
        } else {
            System.out.println("Seleção de índice inválido");
        }

    }


    /**
     * Método usado para imprimir todas as personagens já criadas em PoW.
     * Para cada tipo de personagem, imprime informações específicas adicionais.
     */
    public void printPersonagensList(){
        for (Character character : characters) {
            character.printCharacterInfo();
            System.out.println("\n");
        }
    }

    /**
     * Método usado para imprimir todos os personagens com mais de 10 de experiência.
     * Para cada tipo de personagem, são exibidas informações específicas adicionais.
     */
    public void printPersonagens10ExpList(){
        for (Character character : characters){
            if (character.experience >10){
                character.printCharacterInfo();
                System.out.println("\n");
            }
        }
    }

    /**
     * Método usado para imprimir os mercenários com arcos,
     * os magos com sementes de abóbora
     * e os guerreiros com armaduras.
     */
    public void printPersonagensAlineaE(){
        for (Character character : characters){
            if(character.sementesAbobora()) character.printCharacterInfo();
            if(character.temArco()) character.printCharacterInfo();
            if(character.temArmadura()) character.printCharacterInfo();
            }
        }

    /**
     * Método usado para criar um Guerreiro. Permite ao utilizador definir as características
     * específicas do Guerreiro, como a presença de armadura e o tipo de arma de curto alcance.
     */
    public void createGuerreiro(){

            String nomeGuerreiro;

            System.out.print("Insira um nome para o guerreiro: ");
            nomeGuerreiro = scanner.next();
            System.out.print("\n");


            //Define o nome de Guerreiro
            System.out.printf("O nome do guerreiro é: %s \n",nomeGuerreiro);


            //Pergunta ao utilizador se o NewGuerreiro tem armor ou não
            //Aceitando apenas valores 1 para Tem e 2 para não tem
            int temArmor = 0;
            boolean Armor = false;
            while (temArmor != 1 & temArmor != 2) {
                System.out.printf("O %s tem armadura?\n", nomeGuerreiro);
                System.out.println("1) Tem    2)Não tem");
                temArmor = scanner.nextInt();
            }

            if (temArmor ==1) Armor = true;

            //Pergunta ao utilizador que tipo de ShortRangeWeapon NewGuerreiro deverá ter
            //Aceitando 1 para Faca 2 para Machado e 3 para espada
            int typeShortRangeWeapon=0;
            String ShortRangeWeapon="";

            while ((typeShortRangeWeapon != 1) & (typeShortRangeWeapon != 2) & (typeShortRangeWeapon != 3) ){
                System.out.printf("\nQue tipo de Arma de Curto Alcance %s terá? \n", nomeGuerreiro);
                System.out.println("1) Faca    2) Machado    3) Espada");
                typeShortRangeWeapon = scanner.nextInt();
            }

            if (typeShortRangeWeapon == 1) ShortRangeWeapon = "Faca";
            if (typeShortRangeWeapon == 2) ShortRangeWeapon = "Machado";
            if (typeShortRangeWeapon == 3) ShortRangeWeapon = "Espada";

            //Adiciona NewGuerreiro ao ArrayList characters

        //Cria novo guerreiro
            Guerreiro NewGuerreiro = new Guerreiro(Armor, ShortRangeWeapon);
            NewGuerreiro.name = nomeGuerreiro;
            characters.add(NewGuerreiro);
        }

    /**
     * Método usado para criar um Mago. Permite ao utilizador definir as características específicas
     * do Mago, como o tipo de folhas e sementes que o Mago possui.
     */
    public void createMago(){

        String nomeMago;

        System.out.print("Insira um nome para o mago: ");
        nomeMago = scanner.next();
        System.out.print("\n");

            //Define o tipo de folhas que Mago tem
            //Num leque de 4 tipo de folhas diferentes
            int typeLeaves=0;
            String Leaves="";
            while((typeLeaves != 1) & (typeLeaves !=2) & (typeLeaves != 3) & (typeLeaves != 4)) {
                System.out.printf("Que tipo de folhas %s terá?\n", nomeMago);
                System.out.println("1) Bambu    2) Carvalho\n3) Oliveira    4) Angelim-Vermelho");
                typeLeaves = scanner.nextInt();
            }

            if (typeLeaves == 1) Leaves =" Bambu";
            if (typeLeaves == 2) Leaves = "Magnolia";
            if (typeLeaves == 3) Leaves = "Oliviera";
            if (typeLeaves == 4) Leaves = "Angelim-Vermelho";

            //Define o tipo de folhas que Mago tem
            //Num leque de 4 tipo de folhas diferentes

            int typeSeeds=0;
            String Seeds="";
            while((typeSeeds != 1) & (typeSeeds !=2) & (typeSeeds != 3) & (typeSeeds != 4)) {
                System.out.printf("\nQue tipo de sementes %s terá?\n", nomeMago);
                System.out.println("1) Goji    2) Magnolia\n3) Dragoeiro    4) Abóbora");
                typeSeeds = scanner.nextInt();
            }

            if (typeSeeds == 1) Seeds =" Goji";
            if (typeSeeds == 2) Seeds = "Magnolia";
            if (typeSeeds == 3) Seeds = "Dragoeiro";
            if (typeSeeds == 4) Seeds = "Abóbora";

            //Adiciona NewMago ao ArrayList characters
        //Cria novo Mago
            Mago NewMago = new Mago(Seeds,Leaves);
            NewMago.name = nomeMago;
            characters.add(NewMago);
        }


    /**
     * Método usado para criar um Mercenário. Permite ao utilizador definir características
     * específicas do Mercenário, como o tipo de arma de longo alcance e o número de munições.
     */
    public void createMercenario(){


            String nomeMercenario;

            System.out.print("Insira um nome para o mercenário: ");
            nomeMercenario = scanner.next();
            System.out.print("\n");



            //Define o tipo de LongRangeWeapon que NewMercenario terá
            //Aceitando 1 para pedras, 2 para arco e 3 para pistola

            int typeLongRangeWeapon=0;
            String LongRangeWeapon = "";

            while ((typeLongRangeWeapon != 1) & (typeLongRangeWeapon !=2) & (typeLongRangeWeapon != 3)){
                System.out.printf("Que tipo de Arma de Longo Alcance %s terá?\n", nomeMercenario);
                System.out.println("1) Pedras    2) Arco    3) Pistola");
                typeLongRangeWeapon = scanner.nextInt();
            }
            if (typeLongRangeWeapon == 1) LongRangeWeapon = "Pedras";
            if (typeLongRangeWeapon == 2) LongRangeWeapon = "Arco";
            if (typeLongRangeWeapon == 3) LongRangeWeapon = "Pistola";

            //Define o número de ammo que NewMercenario deverá ter
            int numAmmo;
            System.out.printf("\nQuanta munição deverá %s ter? \n", nomeMercenario);
            numAmmo = scanner.nextInt();

            //Adiciona NewMercenario ao ArrayList characters

            //Cria novo Mago
            Mercenario NewMercenario = new Mercenario(LongRangeWeapon,numAmmo);
            NewMercenario.name = nomeMercenario;
            characters.add(NewMercenario);
        }

        public void closeScanner(){
            scanner.close();
        }

    }
