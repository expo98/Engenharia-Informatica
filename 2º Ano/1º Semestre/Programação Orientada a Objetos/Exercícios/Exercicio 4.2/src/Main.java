import javax.swing.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

//Todo: Alineas CDEF

class Character{
    String name;
    int experience;
    int strength;
    int agility;
    int inteligence;

    public Character(){
        name = "";
        int max = 25;
        int min = 1;
        int range = max - min + 1;
        experience = (int) (Math.random() * range) + min;
        strength=0;
        agility=0;
        inteligence=0;
    }
}

class Guerreiro extends Character{

    //Inventário
    boolean Armor;
    String ShortRangeWeapon;


   public Guerreiro(){

       // Nivel das habilidades-base
       strength = 10;
       agility = 5;
       inteligence =3;

       // Define os níveis das diferentes habilidades
       for(int i = 1; i <=experience;i++){
           strength += (int) ( strength * (0.2));
           agility += (int) (agility * (0.1));
           inteligence += (int) (inteligence* (0.05));
       }
   }
}

class Mago extends Character{

    // Inventário
    String Seeds;
    String Leaves;


    public Mago(){
        // Nivel das habilidades-base
        strength = 2;
        agility = 4;
        inteligence=9;

        // Define os níveis das diferentes habilidades
        for(int i = 1; i <=experience;i++){
            strength += (int) (strength * (0.05));
            agility += (int) (agility * (0.1));
            inteligence += (int) (inteligence* (0.2));
        }
    }
}
class Mercenario extends Character{

    //Inventário
    String LongRangeWeapon;
    int numAmmo;


    public Mercenario(){
        // Nivel das habilidades-base
        strength=4;
        agility=10;
        inteligence=4;
        // Define os níveis das diferentes habilidades
        for(int i = 1; i <=experience;i++){
            strength += (int) (strength * (0.08));
            agility += (int) (agility * (0.2));
            inteligence += (int) (inteligence* (0.08));
        }
    }
}
class PoW{
    ArrayList<Character> characters = new ArrayList<Character>();
    Scanner scanner = new Scanner(System.in);

    public PoW(){

    }

    public void SubirNivelPersonagem() {
        Scanner scanner = new Scanner(System.in);

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

            // Imprime toda a informação antes de subir de nível
            System.out.println("Stats antes de subir de nível");
            printCharacterInfo(selectedCharacter);

            // Sobe o nível do personagem
            if ((selectedCharacter.experience + 1) <=25) {
                selectedCharacter.experience = selectedCharacter.experience + 1;

                if( selectedCharacter instanceof Guerreiro)
                {
                    selectedCharacter.strength += (int) (selectedCharacter.strength * (0.2));
                    selectedCharacter.agility += (int) (selectedCharacter.strength * (0.1));
                    selectedCharacter.inteligence += (int) (selectedCharacter.strength* (0.05));
                } else if (selectedCharacter instanceof Mago) {
                    selectedCharacter.strength += (int) (selectedCharacter.strength * (0.05));
                    selectedCharacter.agility += (int) (selectedCharacter.strength * (0.1));
                    selectedCharacter.inteligence += (int) (selectedCharacter.strength* (0.2));
                } else if (selectedCharacter instanceof Mercenario ) {
                    selectedCharacter.strength += (int) (selectedCharacter.strength * (0.08));
                    selectedCharacter.agility += (int) (selectedCharacter.strength * (0.2));
                    selectedCharacter.inteligence += (int) (selectedCharacter.strength* (0.08));
                }

                // Imprime toda a informação após subir de nível
                System.out.println("Stats após subir de nível:");
                printCharacterInfo(selectedCharacter);
            }
            else System.out.println("Limite máximo de experienca atingido");
        } else {
            System.out.println("Seleção de índice inválido");
        }

    }


    public void printPersonagensList(){
        for (Character character : characters) {
            printCharacterInfo(character);

            // Check the type of character and print additional information based on the type
            if (character instanceof Guerreiro guerreiro) {
                if (guerreiro.Armor) System.out.println("Armadura: Tem");
                if (!guerreiro.Armor) System.out.println("Armadura: Não tem");
                System.out.println("Arma de Curto Alcance: " + guerreiro.ShortRangeWeapon);
            } else if (character instanceof Mago mago) {
                System.out.println("Folhas: " + mago.Leaves);
                System.out.println("Sementes: " + mago.Seeds);
            } else if (character instanceof Mercenario mercenario) {
                System.out.println("Arma de Longo Alcance: " + mercenario.LongRangeWeapon);
                System.out.println("Número de Munição: " + mercenario.numAmmo);
            }

            System.out.println("\n");
        }
    }

    public void printPersonagens10ExpList(){
        for (Character character : characters){
            if (character.experience >10){
                printCharacterInfo(character);

                // Check the type of character and print additional information based on the type
                if (character instanceof Guerreiro guerreiro) {
                    if (guerreiro.Armor) System.out.println("Armadura: Tem");
                    if (!guerreiro.Armor) System.out.println("Armadura: Não tem");
                    System.out.println("Arma de Curto Alcance: " + guerreiro.ShortRangeWeapon);
                } else if (character instanceof Mago mago) {
                    System.out.println("Folhas: " + mago.Leaves);
                    System.out.println("Sementes: " + mago.Seeds);
                } else if (character instanceof Mercenario mercenario) {
                    System.out.println("Arma de Longo Alcance: " + mercenario.LongRangeWeapon);
                    System.out.println("Número de Munição: " + mercenario.numAmmo);
                }

                System.out.println("\n");
            }
        }
    }

    public void printPersonagensAlineaE(){
        for (Character character : characters){
            if (character instanceof Guerreiro guerreiro){
                if (guerreiro.Armor){
                    printCharacterInfo(character);
                    System.out.println("Tem armadura");
                    System.out.println("Arma de Curto Alcance: " + guerreiro.ShortRangeWeapon);
                }
            }

            else if(character instanceof  Mercenario mercenario){
                if (mercenario.LongRangeWeapon == "Arco"){
                    printCharacterInfo(character);
                    System.out.println("Arma de Longo Alcance: " + mercenario.LongRangeWeapon);
                    System.out.println("Número de Munição: " + mercenario.numAmmo);
                }
            }
            else if(character instanceof Mago mago){
                if (mago.Seeds == "Abóbora"){
                    printCharacterInfo(character);
                    System.out.println("Folhas: " + mago.Leaves);
                    System.out.println("Sementes: " + mago.Seeds);
                }
            }
        }
    }

    private void printCharacterInfo(Character character) {
        System.out.println("Nome: " + character.name);
        System.out.println("Experiência: " + character.experience);
        System.out.println("Força: " + character.strength);
        System.out.println("Agilidade: " + character.agility);
        System.out.println("Inteligência: " + character.inteligence);
    }


    public void createGuerreiro(){

        for (int i =1; i <=5; i++){
            //Usado para converter i from int to text
            String iTxt = "" +i;

            //Cria novo guerreiro
            Guerreiro NewGuerreiro = new Guerreiro();

            //Define o nome de Guerreiro
            NewGuerreiro.name = "Guerreiro " + iTxt;
            System.out.printf("O nome do guerreiro é: %s \n\n\n",NewGuerreiro.name);


            //Pergunta ao utilizador se o NewGuerreiro tem armor ou não
            //Aceitando apenas valores 1 para Tem e 2 para não tem
            int temArmor = 0;

            while (temArmor != 1 & temArmor != 2) {
                System.out.printf("O %s tem armadura?\n", NewGuerreiro.name);
                System.out.println("1) Tem    2)Não tem\n");
                temArmor = scanner.nextInt();
            }

            if (temArmor ==1) NewGuerreiro.Armor = true;
            if (temArmor ==2) NewGuerreiro.Armor = false;

            //Pergunta ao utilizador que tipo de ShortRangeWeapon NewGuerreiro deverá ter
            //Aceitando 1 para Faca 2 para Machado e 3 para espada
            int typeShortRangeWeapon=0;

            while ((typeShortRangeWeapon != 1) & (typeShortRangeWeapon != 2) & (typeShortRangeWeapon != 3) ){
                System.out.printf("Que tipo de Arma de Curto Alcance %s terá? \n", NewGuerreiro.name);
                System.out.println("1) Faca    2) Machado    3) Espada\n");
                typeShortRangeWeapon = scanner.nextInt();
            }

            if (typeShortRangeWeapon == 1) NewGuerreiro.ShortRangeWeapon = "Faca";
            if (typeShortRangeWeapon == 2) NewGuerreiro.ShortRangeWeapon = "Machado";
            if (typeShortRangeWeapon == 3) NewGuerreiro.ShortRangeWeapon = "Espada";

            //Adiciona NewGuerreiro ao ArrayList characters
            characters.add(NewGuerreiro);
        }

    }
    public void createMago(){
        Scanner scanner = new Scanner(System.in);

        for (int i = 1; i <=5; i++){
            //Usado para converter i de int para String
            String iTxt= "" + i;

            //Cria novo Mago
            Mago NewMago = new Mago();

            //Define o nome de NewMago
            NewMago.name = "Mago " + iTxt;
            System.out.printf("O nome do mago é: %s \n\n\n",NewMago.name);

            //Define o tipo de folhas que Mago tem
            //Num leque de 4 tipo de folhas diferentes
            int typeLeaves=0;
            while((typeLeaves != 1) & (typeLeaves !=2) & (typeLeaves != 3) & (typeLeaves != 4)) {
                System.out.printf("Que tipo de folhas %s terá?\n", NewMago.name);
                System.out.println("1) Bambu    2) Carvalho\n3) Oliveira    4) Angelim-Vermelho");
                typeLeaves = scanner.nextInt();
            }

            if (typeLeaves == 1) NewMago.Leaves =" Bambu";
            if (typeLeaves == 2) NewMago.Leaves = "Magnolia";
            if (typeLeaves == 3) NewMago.Leaves = "Oliviera";
            if (typeLeaves == 4) NewMago.Leaves = "Angelim-Vermelho";

            //Define o tipo de folhas que Mago tem
            //Num leque de 4 tipo de folhas diferentes

            int typeSeeds=0;
            while((typeSeeds != 1) & (typeSeeds !=2) & (typeSeeds != 3) & (typeSeeds != 4)) {
                System.out.printf("Que tipo de sementes %s terá?\n", NewMago.name);
                System.out.println("1) Goji    2) Magnolia\n3) Dragoeiro    4) Abóbora");
                typeSeeds = scanner.nextInt();
            }

            if (typeSeeds == 1) NewMago.Seeds =" Goji";
            if (typeSeeds == 2) NewMago.Seeds = "Magnolia";
            if (typeSeeds == 3) NewMago.Seeds = "Dragoeiro";
            if (typeSeeds == 4) NewMago.Seeds = "Abóbora";

            //Adiciona NewMago ao ArrayList characters
            characters.add(NewMago);
        }

    }

    public void createMercenario(){

        for (int i =1; i <= 5; i++){
            //Usado para converter i de int para string
            String iTxt = "" + i;

            //Cria novo Mago
            Mercenario NewMercenario = new Mercenario();

            //Define o nome de NewMercenario
            NewMercenario.name = "Mercenario " + iTxt;
            System.out.printf("O nome do mercenário é: %s\n\n",NewMercenario.name);

            //Define o tipo de LongRangeWeapon que NewMercenario terá
            //Aceitando 1 para pedras, 2 para arco e 3 para pistola

            int typeLongRangeWeapon=0;

            while ((typeLongRangeWeapon != 1) & (typeLongRangeWeapon !=2) & (typeLongRangeWeapon != 3)){
                System.out.printf("Que tipo de Arma de Longo ALcande %s terá?\n",NewMercenario.name);
                System.out.println("1) Pedras    2) Arco    3) Pistola");
                typeLongRangeWeapon = scanner.nextInt();
            }
            if (typeLongRangeWeapon == 1) NewMercenario.LongRangeWeapon = "Pedras";
            if (typeLongRangeWeapon == 2) NewMercenario.LongRangeWeapon = "Arco";
            if (typeLongRangeWeapon == 3) NewMercenario.LongRangeWeapon = "Pistola";

            //Define o número de ammo que NewMercenario deverá ter
            System.out.printf("Quanta munição deverá %s ter? \n", NewMercenario.name);
            NewMercenario.numAmmo = scanner.nextInt();

            //Adiciona NewMercenario ao ArrayList characters
            characters.add(NewMercenario);
        }

    }
}


public class Main {
    public static void main(String[] args) {

        PoW etc = new PoW();
        etc.createGuerreiro();
       // etc.createMercenario();
       // etc.createMago();

        //etc.printPersonagensList();
        //etc.printPersonagens10ExpList();
        //etc.printPersonagensAlineaE();
        etc.SubirNivelPersonagem();

    }
}