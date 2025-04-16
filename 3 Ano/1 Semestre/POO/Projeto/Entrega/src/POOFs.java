import java.io.Serializable;
import java.util.*;

/**
 * @author Miguel Pereira, Carlos Pereira
 * @version 1.6
 * @serial
 */

/**
 * Classe que gere a lista de faturas e de clientes.
 */
public class POOFs implements Serializable,lerConsola {

    /**
     * ArrayList de clientes, nele insere-se objetos da classe @Cliente.
     */
    private final ArrayList<Cliente> clientes;
    /**
     * ArrayList de faturas, nele insere-se objetos da classe @Fatura.
     */
    private final ArrayList<Fatura> faturas;
    /**
     * Inteiro para manter a par qual o ID atual da última fatura.
     */
    private int proxFaturaID;

    /**
     * Construtor da classe, recebe os dados para sua inicialização.
     * Neste caso, este construtor é apenas utilizado quando existe um fichiero .obj
     * carregando para o gerenciador {@link POOFs poofs} as {@link ArrayList<Fatura> faturas}, os {@link ArrayList<Cliente> clientes}e  o int proxFaturaID.
     * @param clientes
     * @param faturas
     * @param proxFaturaID
     */
    public POOFs(ArrayList<Cliente> clientes, ArrayList<Fatura> faturas, int proxFaturaID){
        this.clientes = clientes;
        this.faturas = faturas;
        this.proxFaturaID = proxFaturaID;
    }

    /**
     * Construtor da classe, apenas inicializa os valores para ArrayList vazias e o proxFaturaID a 1.
     * Utilizado sempre que não é possível carregar o ficheiro .obj .
     */
    public POOFs(){
        this.clientes = new ArrayList<>();
        this.faturas = new ArrayList<>();
        this.proxFaturaID = 1;
    }

    /**
     * Método criarCliente() utilizado para criar {@link Cliente cliente}.
     * Pede ao utilizador informação sobre o {@link Cliente cliente}(Número de contribuinte, Nome, Localização).
     * Insere automaticamente no {@link ArrayList<Cliente> clientes}.
     *
     */
    public void criarCliente() {

        int numContribuinte;

        System.out.print("Introduza o número de contribuinte do cliente: ");
        numContribuinte = lerConsola.readInt();
        while (numContribuinte>= 999999999 || numContribuinte <= 100000000) {

            System.out.println("Erro! Número de Contribuinte não tem apenas 9 algarismos!");
            System.out.println("Introduza o número de contribuinte do cliente: ");
            numContribuinte = lerConsola.readInt();

        }

        if (pesquisaCliente(numContribuinte) != null){
            System.out.println("Erro! Número de contribuinte já utilizado!");
            return;
        }


        Cliente novoCliente = new Cliente();

        novoCliente.setNumContribuinte(numContribuinte);

        System.out.print("Insira o nome do cliente: ");
        novoCliente.setNome(lerConsola.readString());





            boolean selecionando = true;
            Cliente.Localizacao[] localizacoes = novoCliente.getLocalizacoes();

            // Keep prompting the user until a valid location is chosen
            while (selecionando) {
                System.out.println("Escolha a localização do cliente:");

                for (int i = 0; i < localizacoes.length; i++) {
                    System.out.println(i + 1 + ") " + localizacoes[i]);
                }

                System.out.print("Opção: ");
                int localizacaoIndex = lerConsola.readInt();


                if (localizacaoIndex < 1 || localizacaoIndex > localizacoes.length) {
                    System.out.println("Opção inválida. Tente novamente.");
                } else {
                    novoCliente.setLocalizacao(localizacoes[localizacaoIndex - 1]);
                    selecionando = false; // Exit loop if valid input is provided
                }
            }

            clientes.add(novoCliente);
            System.out.println("Cliente criado com sucesso!");
    }


    /**
     * Método editarCliente() utilizado para editar {@link Cliente cliente} existente em {@link ArrayList<Cliente> clientes}.
     * Pede ao utilizador um número de contribuinte, verifica se ele já existe, e, existindo,
     * pergunta se quer alterar o nome, número de contribuinte ou localização do {@link Cliente cliente}.
     */
    public void editarCliente () {
        int numContribuinte;
        numContribuinte = lerConsola.readInt();

        Cliente cliente = pesquisaCliente(numContribuinte);
        if (cliente == null) {
            return;
        }

        boolean selecionando = true;
        int opcao;

        String novoNomeCliente;
        int novoNumContribuinte;

        while (selecionando) {
            System.out.println("Escolha uma opção:\n1) Editar nome\n2) Editar número de contribuinte\n3) Editar localização\n4) Sair");
            System.out.print("Opção: ");
            opcao = lerConsola.readInt();

            if (opcao == 1) {

                System.out.print("Introduza um novo nome: ");
                novoNomeCliente = lerConsola.readString();
                cliente.setNome(novoNomeCliente);
                System.out.println("Nome mudado com sucesso!");
            } else if (opcao == 2) {
                System.out.print("Introduza um novo número de contribuinte: ");
                novoNumContribuinte = lerConsola.readInt();
                cliente.setNumContribuinte(novoNumContribuinte);
                System.out.println("Número de contribuinte mudado com sucesso!");
            } else if (opcao == 3) {

                boolean inputValido = false;

                Cliente.Localizacao[] localizacoes = cliente.getLocalizacoes();

                while (!inputValido) {
                    System.out.println("Escolha a localização do cliente:");

                    for (int i = 0; i < localizacoes.length; i++) {
                        System.out.println(i + 1 + ") " + localizacoes[i]);
                    }

                    System.out.print("Opção: ");
                    int localizacaoIndex = lerConsola.readInt();

                    if (localizacaoIndex < 1 || localizacaoIndex > localizacoes.length) {
                        System.out.println("Opção inválida. Tente novamente.");
                    } else {
                        cliente.setLocalizacao(localizacoes[localizacaoIndex - 1]);
                        inputValido = true; // Exit loop if valid input is provided
                    }
                }
            } else if (opcao == 4) {
                selecionando = false;
            } else {
                System.out.println("Opção não válida!");
            }

        }

    }


    /**
     * Método listarClientes() faz a listagem de todos os clientes existentes.
     * Verifica incialmente se o{@link ArrayList<Cliente> clientes} está vazio, caso não, imprime
     * os dados acerca de cada cliente.
     */
    public void listarClientes() {
        if (clientes.isEmpty()) {
            System.out.println("Não existem clientes ainda registados");
            return;
        }

        System.out.println("Listagem de clientes: \n");

        for (Cliente cliente : clientes) {
            cliente.printDadosCliente();
        }
    }

    /**
     * Método pesquisaCliente() utilizado para pesquisar no {@link ArrayList<Cliente> clientes}
     * se existe um {@link Cliente cliente} com o numContribuinte dado como parametro.
     * Caso não exista, devolve {@link null null}, caso exista devolve o {@link Cliente cliente}.
     *
     * @param numContribuinte
     * @return cliente,null
     */
    private Cliente pesquisaCliente(int numContribuinte){
        for(Cliente cliente : clientes){
            if (cliente.getNumContribuinte() == numContribuinte){
                return cliente;
            }
        }
        System.out.println("Número de contribuinte não encontrado");
        return null;
    }

    /**
     * Método criarFatura cria uma fatura, pedindo ao utilizador por um cliente
     * para associar e pede para criar produtos para adicionar à fatura.
     * Associa um {@link Cliente cliente} e {@link ArrayList<Produtos> produtos}, preco do IVA e preco sem IVA à {@link Fatura fatura}.
     */
    public void criarFatura(){
        // Pesquisa pelo cliente
        int numContribuinte = 0;

        while (numContribuinte >= 999999999 || numContribuinte <= 100000000){
        System.out.println("Introduza o número de contribuinte do cliente: ");
        numContribuinte =lerConsola.readInt();
        if (numContribuinte >= 999999999 || numContribuinte <= 100000000){
            System.out.println("Erro! Número de Contribuinte não tem apenas 9 algarismos!");
        }

        }

        Cliente cliente = pesquisaCliente(numContribuinte);
        if (cliente == null){
            return ;
        }

        ArrayList<Produtos> produtos = new ArrayList<>();
        boolean continuar = true;
        int numProd = 0;
        int opcao;
        while (continuar){

            System.out.println("O que deseja fazer? \n1) Criar e adicionar um produto à fatura\n2) Sair");
            opcao =lerConsola.readInt();

            if (opcao == 1){
                produtos.add(criarProduto());
                numProd++;
            } else if (opcao == 2) {
                if (numProd == 0){
                    System.out.println("Nenhum produto criado, saindo da criação de faturas...");
                    return ;
                }
                continuar = false;
            } else{
                System.out.println("Opção errada!\n");
            }
        }



        double precoSemIva = 0;
        double precoIva = 0;

        for(Produtos produto : produtos){
            precoSemIva += produto.getPrecoSemIva();
            precoIva += produto.calculaIva(cliente.getLocalizacao());
        }

        Fatura novaFatura = new Fatura(proxFaturaID, cliente, produtos, precoSemIva, precoIva);
        faturas.add(novaFatura);
        proxFaturaID++;
    }

    /**
     * Método listarFaturas lista todas as faturas existentes.
     * Caso na {@link ArrayList<Fatura> faturas} existam faturas, imprime os dados de todas as faturas.
     */
    public void listarFaturas(){
        if (faturas.isEmpty()){
            System.out.println("Não existem faturas ainda registadas");
            return;
        }

        System.out.println("Listagem de faturas:\n ");

        for( Fatura fatura : faturas){
            double precoTotal = fatura.getPrecoIva() + fatura.getPrecoSemIva();
            System.out.println("Número da fatura: " + fatura.getNumFatura());
            System.out.println("Data da fatura: ");
            System.out.println("Cliente: " + fatura.getCliente().getNome());
            System.out.println("Número de produtos: " + fatura.calculaNumProdutos());
            System.out.println("----------------------------");
            System.out.println("Preço total (s/ IVA): " + String.format("%.2f", fatura.getPrecoSemIva()) + "€");
            System.out.println("Preço total do IVA: " + String.format("%.2f", fatura.getPrecoIva()) + "€");
            System.out.println("Preço total (c/ IVA): " + String.format("%.2f", precoTotal) + "€");
            System.out.println("----------------------------");
        }

    }

    /**
     * Método editarFatura() edita uma fatura.
     * É pedido ao utilizador pelo ID de uma {@link Fatura fatura} e, caso exista, pergunta ao
     * utilizador o que deseja editar, se trocar de cliente, se adicionar ou remover produtos.
     *
     */
    public void editarFatura(){
        if (faturas.isEmpty()){
            System.out.println("Não existem faturas ainda registadas");
            return;
        }

        System.out.print("Introduza o número da fatura que pretende editar: ");
        int numFatura =lerConsola.readInt();

        for (Fatura fatura : faturas){
            if (fatura.getNumFatura() != numFatura){
                System.out.println("Número de fatura não encontrado!");
                return;
            }
        }

        boolean selecionando = true;
        int opcao;
        while (selecionando) {
            System.out.println("Escolha as opções seguintes de edição de fatura:");
            System.out.println("1) Adicionar Produto\n2) Remover Produto \n3) Trocar cliente associado\n4) Sair");
            opcao =lerConsola.readInt();

            if (opcao == 1) {
                adicionarProdutoAFatura(numFatura, criarProduto());
            } else if (opcao == 2) {
                removerProdutoAFatura(numFatura);
            } else if (opcao == 3) {
                trocarClienteAFatura(numFatura);
                selecionando = false;
            } else if (opcao == 4){
                selecionando = false;
            }else {
                System.out.println("Opção inválida!");
            }
        }
    }

    /**
     * Método adicionarProdutoAFatura() adiciona um {@link Produtos produto} a uma {@link Fatura fatura}.
     *
     *
     * @param numFatura o número de fatura
     * @param produto o produto a associar à fatura
     */
    public void adicionarProdutoAFatura(int numFatura, Produtos produto){
        boolean faturaExiste = false;
        for (Fatura fatura : faturas){
            if (fatura.getNumFatura() == numFatura){
                if (fatura.getProdutos() == null) {
                    fatura.adicionarProdutos(produto);
                } else {
                    fatura.adicionarProdutos(produto);
                }
                System.out.println("Produto " + produto.getNome() + " adicionado à fatura número " + numFatura);
                faturaExiste = true;
                break;
            }
        }

        if (!faturaExiste) {
            System.out.println("Fatura com o número " + numFatura + " não encontrada");
        }
    }

    /**
     * Método removerProdutoAFatura() remove um produto da fatura.
     * Método auxiliar ao método {@link editarFatura()}.
     * Por parametro é fornecido o numFatura, depois lista ao utilizador os produtos da fatura e
     * para o utilizador escolher um e remove-o da fatura.
     * @param numFatura
     */
    public void removerProdutoAFatura(int numFatura){
        for (Fatura fatura : faturas){
            if (fatura.getNumFatura() == numFatura){
                visualizarFaturaPorID(numFatura);

                System.out.print("Escolha um produto para remover (introduza o código): ");
                int codigoProduto =lerConsola.readInt();
                for (Produtos produto : fatura.getProdutos()){
                    if (produto.getCodigo() == codigoProduto){
                        fatura.getProdutos().remove(produto);
                        System.out.println("Produto com o código " + codigoProduto + " removido com sucesso!");
                    }
                    break;
                }
                System.out.println("Código de produto não encontrado na fatura!");
            }
            else{
                System.out.println("Fatura não encontrada!");
            }
        }
    }


    /**
     * Método trocarClienteAFatura() troca de cliente numa fatura.
     * Método auxiliar ao método {@link editarFatura()}.
     * Por parametro é dado o numFatura. Após, é pedido ao utilizador por um numContribuinte, caso exista, esse
     * passa a ser o cliente associado à fatura.
     * @param numFatura
     */
    public void trocarClienteAFatura(int numFatura){
        int numContribuinte;

        System.out.print("Introduza o número de contribuinte ao qual quer associar a esta fatura: ");
        numContribuinte =lerConsola.readInt();

        Cliente novoClienteFatura = pesquisaCliente(numContribuinte);
        if (novoClienteFatura == null){
            return;
        }

        for (Fatura fatura : faturas){
            if (fatura.getNumFatura() == numFatura){

                System.out.println("Cliente " + fatura.getCliente().getNome() +" trocado por cliente " + novoClienteFatura.getNome());
                fatura.setCliente(novoClienteFatura);
                return;
            }
        }


    }

    /**
     * Método visualizarFaturaPorID detalha a fatura cujo ID foi fornecido por parametro.
     * @param numFatura
     */
    public void visualizarFaturaPorID(int numFatura){
        for (Fatura fatura : faturas){
            if (fatura.getNumFatura() == numFatura) {
                fatura.visualizarFatura();
                return;
            }
        }
        System.out.println("Não existe nenhuma fatura com o número: " + numFatura);
    }





    public Produtos criarProduto(){

        System.out.print("Insira o nome do Produto: ");
        String nomeProduto = lerConsola.readString();

        System.out.print("Escreva uma breve descrição sobre o produto: ");
        String descricaoProduto = lerConsola.readString();

        System.out.print("Insira o código do produto: ");
        int codigoProduto =lerConsola.readInt();

        System.out.print("Insira a quantidade do produto: ");
        int quantidadeProduto =lerConsola.readInt();

        System.out.print("Insira o preço do produto (Ex. 12.33): ");
        double precoUnidadeProduto = lerConsola.readDouble();

        while (true) {
            System.out.println("Qual o tipo do seu produto?");
            System.out.print("1) Produto Alimentar \n2) Produto Farmacêutico \n\nOpção: ");
            int escolhaTipoProduto =lerConsola.readInt();

            if (escolhaTipoProduto == 1) {
                return criarProdutosAlimentares(codigoProduto, nomeProduto, descricaoProduto, quantidadeProduto, precoUnidadeProduto);
            } else if (escolhaTipoProduto == 2) {
                return criarProdutoFarmaceutico(codigoProduto, nomeProduto, descricaoProduto, quantidadeProduto, precoUnidadeProduto);
            } else {
                System.out.println("Escolha não válida! Tente novamente.");
            }
        }

    }

    public ProdutosAlimentares criarProdutosAlimentares(int codigo, String nome, String descricao, int quantidade, double preco){
        boolean isBiologic; //Inicializado a falso
        int opcaoTaxa=0;

        do {
            System.out.println("O seu produto é biológico?\n1) Sim\n2) Não\n\nOpção: ");
            int opcaoBiologico =lerConsola.readInt();

            if (opcaoBiologico == 1) {
                isBiologic = true;
                break;
            } else if (opcaoBiologico == 2) {
                isBiologic = false;
                break;
            } else {
                System.out.println("Opção inválida. Tente novamente.");
            }
        } while (true);

        while(opcaoTaxa>3 || opcaoTaxa<1) {
            System.out.print("Qual a taxa do seu produto? \n1) Taxa Normal \n2) Taxa Intermédia \n3) Taxa Reduzida\n\nOpção: ");
            opcaoTaxa =lerConsola.readInt();
        }

        if (opcaoTaxa == 1){
            return new ProdutoAlimentarNormal(codigo,nome,descricao,quantidade,preco,isBiologic);
        } else if (opcaoTaxa == 2) {


            ProdutoAlimentarIntermedio.CategoriasAlimentar categoriaSelecionada = null;
            ProdutoAlimentarIntermedio.CategoriasAlimentar[] categorias = ProdutoAlimentarIntermedio.CategoriasAlimentar.values();

            System.out.println("Qual a categoria do seu produto?");
            for (int i = 0; i < categorias.length; i++) {
                System.out.println((i + 1) + ") " + categorias[i].name());
            }

            int opcaoCategoria = 0;
            while (opcaoCategoria < 1 || opcaoCategoria > categorias.length) {
                System.out.print("Opção: ");
                opcaoCategoria =lerConsola.readInt();
                if (opcaoCategoria >= 1 && opcaoCategoria <= categorias.length) {
                    categoriaSelecionada = categorias[opcaoCategoria - 1];
                } else {
                    System.out.println("Opção inválida. Tente novamente.");
                }
            }

            return new ProdutoAlimentarIntermedio(codigo, nome, descricao, quantidade, preco, isBiologic, categoriaSelecionada);
        } else {
            ProdutoAlimentarReduzido.Certificacoes[] certificacoes = ProdutoAlimentarReduzido.Certificacoes.values();
            EnumSet<ProdutoAlimentarReduzido.Certificacoes> certificacoesSet = EnumSet.noneOf(ProdutoAlimentarReduzido.Certificacoes.class);

            boolean escolhendo = true;

            while (escolhendo){
                System.out.println("Escolha uma certificação ou 0 para finalizar: ");


                for(int i = 0; i < certificacoes.length; i++){
                    System.out.println(i+1 + ") " + certificacoes[i].name());
                }
                System.out.println("0) Terminar");

                System.out.print("Opção: ");
                int escolha =lerConsola.readInt();

                if (escolha == 0){
                    if(certificacoesSet.isEmpty()){
                       System.out.println("Tens de selecionar pelo menos uma certificação!");
                    } else {
                        escolhendo = false;
                    }
                } else if (escolha >= 1 && escolha <= certificacoes.length) {
                    ProdutoAlimentarReduzido.Certificacoes certificacaoSelecionada = certificacoes[escolha-1];

                    if (certificacoesSet.contains(certificacaoSelecionada)){
                        System.out.println("Certificação já selecionada. Escolha outra.");
                    }
                    else {
                        certificacoesSet.add(certificacaoSelecionada);
                        System.out.println("Certificação " + certificacaoSelecionada.name() + " selecionada!");
                    }

                } else {
                    System.out.println("Opção inválida. Tenta outra vez!");
                }

            }
            return new ProdutoAlimentarReduzido(codigo,nome,descricao,quantidade,preco,isBiologic,certificacoesSet);
        }

    }

    public ProdutoFarmaceutico criarProdutoFarmaceutico(int codigo, String nome, String descricao, int quantidade, double preco){
        boolean selecionando=true;
        int opcaoPrescricao;

        do {
            System.out.println("O seu produto farmacêutico tem prescrição?\n1) Sim\n2) Não\n\nOpção: ");
            opcaoPrescricao = lerConsola.readInt();

            if (opcaoPrescricao == 1) {
                selecionando = false;
            } else if (opcaoPrescricao == 2) {
                selecionando = false;
            } else {
                System.out.println("Opção inválida. Tente novamente.");
            }
        } while (selecionando);

        if (opcaoPrescricao == 1){
            String nomeMedico;
            System.out.print("Introduza o nome do médico que realizou a prescrição: ");
            nomeMedico = lerConsola.readString();

            return new ProdutoFarmaceuticoPrescrito(codigo, nome, descricao, quantidade, preco, nomeMedico);
        }
        else {
            ProdutoFarmaceuticoNaoPrescrito.Categoria categoriaSelecionada = null;
            ProdutoFarmaceuticoNaoPrescrito.Categoria[] categorias = ProdutoFarmaceuticoNaoPrescrito.Categoria.values();

            System.out.println("Qual a categoria do seu produto?");
            for (int i = 0; i< categorias.length; i++){
                System.out.println(i+1 + ") " + categorias[i].name());
            }

            int opcaoCategoria = 0;
            while (opcaoCategoria < 1 || opcaoCategoria > categorias.length) {
                System.out.print("Opção: ");
                opcaoCategoria = lerConsola.readInt();
                if (opcaoCategoria >= 1 && opcaoCategoria <= categorias.length) {
                    categoriaSelecionada = categorias[opcaoCategoria - 1];
                } else {
                    System.out.println("Opção inválida. Tente novamente.");
                }
            }
            return new ProdutoFarmaceuticoNaoPrescrito(codigo, nome, descricao, quantidade, preco, categoriaSelecionada);
        }
    }


    public void mostrarEstatisticas() {
        int totalFaturas = faturas.size();
        int totalProdutos = 0;
        double totalSemIva = 0;
        double totalIva = 0;

        for (Fatura fatura : faturas) {
            totalProdutos += fatura.getProdutos().size();
            totalSemIva += fatura.getPrecoSemIva();
            totalIva += fatura.getPrecoIva();
        }

        double totalComIva = totalSemIva + totalIva;

        System.out.println("Estatísticas:");
        System.out.println("Número de Faturas: " + totalFaturas);
        System.out.println("Número de Produtos: " + totalProdutos);
        System.out.println("Valor Total Sem IVA: " + String.format("%.2f",totalSemIva) + "€");
        System.out.println("Valor Total do IVA: " + String.format("%.2f",totalIva) + "€");
        System.out.println("Valor Total Com IVA: " + String.format("%.2f",totalComIva) + "€");

    }

    public int getProxFaturaID() {
        return proxFaturaID;
    }

    public ArrayList<Cliente> getClientes() {
        return clientes;
    }

    public ArrayList<Fatura> getFaturas() {
        return faturas;
    }


}
