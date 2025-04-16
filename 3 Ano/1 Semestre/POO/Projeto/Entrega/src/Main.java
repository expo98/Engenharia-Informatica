public class Main implements lerConsola,GerenciadorFicheiros {



    static POOFs poofs = GerenciadorFicheiros.lerFicheiroObjetos();


    public static void main(String[] args) {
        System.out.println("A inicializar o POO Financial Services...");
        // Carregar os dados caso existam (isso esta no proprio metodo)


        boolean ligado = true;

        while (ligado) {

            mostrarMenu();
            System.out.print("Escolha uma opção: ");

            int opcao = lerConsola.readInt();



            switch (opcao) {
                case 1:
                    criarEditarCliente();
                    break;
                case 2:
                    listarClientes();
                    break;
                case 3:
                    criarEditarFatura();
                    break;
                case 4:
                    listarFaturas();
                    break;
                case 5:
                    visualizarFaturas();
                    break;
                case 6:
                    poofs = GerenciadorFicheiros.lerFaturasTxt();
                    break;
                case 7:
                    GerenciadorFicheiros.guardarFicheiroTxt(poofs.getFaturas());
                    break;
                case 8:
                    mostrarEstatisticas();
                    break;
                case 0:
                    System.out.println("Adeus!");

                    GerenciadorFicheiros.guardarFicheiroObjetos(poofs.getClientes(), poofs.getFaturas(), poofs.getProxFaturaID());
                    ligado = false;
                    break;
                default:
                    System.out.print("Opção inválida, tente novamente!\n Escolha uma opção: ");
            }
        }
    }

    private static void mostrarMenu() {
        System.out.println("1) Criar ou editar cliente");
        System.out.println("2) Listar clientes");
        System.out.println("3) Criar ou editar faturas");
        System.out.println("4) Listar faturas");
        System.out.println("5) Visualizar uma fatura");
        System.out.println("6) Importar faturas");
        System.out.println("7) Exportar faturas");
        System.out.println("8) Mostrar estatísticas");
        System.out.println("0) Sair");
    }

    private static void criarEditarFatura() {


        boolean selecionando = true;
        int opcao;
        while (selecionando) {
            System.out.println("\n1) Criar fatura\n2) Editar fatura\n3) Sair");


                System.out.print("Escolhe uma opção:");
                opcao = lerConsola.readInt();



            if (opcao == 1) {
                poofs.criarFatura();
                selecionando = false;
            } else if (opcao == 2) {
                poofs.editarFatura();
                selecionando = false;
            } else if (opcao == 3) {
                selecionando = false;
            } else {
                System.out.println("Opção inválidad");
            }
        }
        System.out.println("\n\n\n");

    }

    private static void mostrarEstatisticas() {
        poofs.mostrarEstatisticas();
        System.out.println("\n\n\n");

    }

    private static void listarFaturas() {
        poofs.listarFaturas();
        System.out.println("\n\n\n");

    }

    private static void visualizarFaturas() {

        System.out.print("Introduza o ID da fatura que deseja visualizar: ");
        int idFatura = lerConsola.readInt();



        poofs.visualizarFaturaPorID(idFatura);
        System.out.println("\n\n\n");

    }

    private static void criarEditarCliente() {


        boolean selecionando = true;
        int opcao;
        while (selecionando) {
            System.out.println("Escolha uma opção: \n1) Criar cliente\n2) Editar cliente\n3) Sair");
            opcao = lerConsola.readInt();

            if (opcao == 1) {
                poofs.criarCliente();
                selecionando = false;
            } else if (opcao == 2) {
                poofs.editarCliente();
                selecionando = false;
            } else if (opcao == 3) {
                selecionando = false;
            } else {
                System.out.println("Opção inválida!");
            }
        }
        System.out.println("\n\n\n");

    }

    private static void listarClientes() {
        poofs.listarClientes();
        System.out.println("\n\n\n");
    }


}


