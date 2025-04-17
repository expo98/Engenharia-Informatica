import java.util.Scanner;

/**
 * A classe {@code Main} é a classe principal do programa e contém o método
 * {@code main} que inicia a execução do jogo. Neste método, é criada uma
 * instância da classe {@code PoW}, e em seguida, são criados personagens
 * do tipo Guerreiro, Mercenário e Mago usando os métodos específicos da
 * classe {@code PoW}. Após a criação dos personagens, são chamados métodos
 * para imprimir a lista de personagens, a lista daqueles com mais de 10 de
 * experiência e os personagens específicos conforme a alínea E. Por fim,
 * o método {@code SubirNivelPersonagem} é chamado para permitir a subida de nível
 * de um personagem escolhido pelo utilizador.
 *
 * @author miguempereira
 * @version 1.0
 */
public class Main {
    public static void main(String[] args) {

        PoW NewPoW = new PoW();

        System.out.println("Bem vindo ao PoW!");
        System.out.println("Irá agora criar 5 guerreiros...");
        for (int i =1; i<=5; i++)
        {
            System.out.println(i +"º Guerreiro\n");
            NewPoW.createGuerreiro();
        }
        System.out.println("Irá agora criar 5 mercenários...");
        for (int i =1; i<=5; i++)
        {
            System.out.println(i +"º Mercenário\n");
            NewPoW.createMercenario();
        }
        System.out.println("Irá agora criar 5 magos...");
        for (int i =1; i<=5; i++)
        {
            System.out.println(i +"º Mago\n");
            NewPoW.createMago();
        }


        int opcao=0;

        while (opcao != 5) {

            System.out.println("1) Imprimir a lista de todos os personagens    2) Imprimir todos os personagens ocm mais de 10 de experiência");
            System.out.println("3) Imprimir os guerreiros com armadura, os mercenários com arcos e os magos com sementes de abóbora");
            System.out.println("4) Subir de Nível uma personagem               5) Sair");
            System.out.println("Selecione a ação desejada:");
            opcao = NewPoW.scanner.nextInt();

            if (opcao==1) NewPoW.printPersonagensList();
            else if (opcao==2) NewPoW.printPersonagens10ExpList();
            else if (opcao==3) NewPoW.printPersonagensAlineaE();
            else if (opcao==4) NewPoW.SubirNivelPersonagem();
            else if (opcao ==5) {
                NewPoW.closeScanner();
                return;
            }
            else System.out.println("Opcão não válida!");
        }


        }
    }
