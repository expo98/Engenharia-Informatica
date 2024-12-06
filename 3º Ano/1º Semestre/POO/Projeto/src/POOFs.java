package Projeto.src;

import java.util.*;

public class POOFs {

    private List<Cliente> clientes;
    private List<Fatura> faturas;
    private int proxFaturaID;

    public POOFs(){
        this.clientes = new ArrayList<>();
        this.faturas = new ArrayList<>();
        this.proxFaturaID = 1;
    }

    public void criarCliente() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Insira o nome do cliente: ");
        String nome = scanner.nextLine();

        Cliente.Localizacao localizacao = Cliente.Localizacao.CONTINENTE; // Valor precarregado para o IDE não chorar
        boolean inputValido = false;

        // Keep prompting the user until a valid location is chosen
        while (!inputValido) {
            System.out.println("Escolha a localização do cliente:");
            for (int i = 0; i < Cliente.Localizacao.values().length; i++) {
                System.out.println(i + 1 + ") " + Cliente.Localizacao.values()[i]);
            }

            System.out.print("Opção: ");
            int localizacaoIndex = scanner.nextInt();
            scanner.nextLine(); // Consume leftover newline

            if (localizacaoIndex < 1 || localizacaoIndex > Cliente.Localizacao.values().length) {
                System.out.println("Opção inválida. Tente novamente.");
            } else {
                localizacao = Cliente.Localizacao.values()[localizacaoIndex - 1];
                inputValido = true; // Exit loop if valid input is provided
            }
        }

        System.out.print("Introduza o número de contribuinte do cliente: ");
        int numContribuinte = scanner.nextInt();

        Cliente cliente = new Cliente(nome,numContribuinte, localizacao);
        clientes.add(cliente);

        System.out.println("Cliente criado com sucesso!");
    }

    public Fatura criarFatura(Cliente cliente, List<Produtos> produtos){
        double precoSemIva = 0;
        double precoIva = 0;

        for(Produtos produto : produtos){
            precoSemIva += produto.getPrecoSemIva();
            precoIva += produto.calculaIva(cliente.localizacao);
        }

        Fatura novaFatura = new Fatura(proxFaturaID, cliente, produtos, precoSemIva, precoIva);
        faturas.add(novaFatura);
        proxFaturaID++;
        return novaFatura;
    }

    public void listarFaturas(){
        if (faturas.isEmpty()){
            System.out.println("Não existem faturas ainda registadas");
            return;
        }

        System.out.println("Listagem de faturas: ");

        for( Fatura fatura : faturas){
            System.out.println("Número da fatura: " + fatura.getNumFatura());
            System.out.println("Cliente: " + fatura.getCliente().nome);
            System.out.println("Número de produtos: " + fatura.calculaNumProdutos());
            System.out.println("Preço total (s/ IVA): " + fatura.getPrecoSemIva() + "€");
            System.out.println("Preço total (c/ IVA): " + fatura.getPrecoIva() + "€");
            System.out.println("----------------------------");
        }
    }

    public void visualizarFaturaPorID(int numFatura){
        for (Fatura fatura : faturas){
            if (fatura.getNumFatura() == numFatura) {
                fatura.visualizarFatura();
                return;
            }
        }
        System.out.println("Não existe nenhuma fatura com o número: " + numFatura);
    }

    public void adicionarProdutoAFatura(int numFatura, Produtos produto){
        for (Fatura fatura : faturas){
            if( fatura.getNumFatura() == numFatura){
                fatura.adicionarProdutos(produto);
                System.out.println("Produto " + produto.getNome() + "adicionado à fatura número " + numFatura);
            }
        }

        System.out.println("Fatura com  o número " + numFatura + " não encontrada");
    }

    public Produtos criarProduto(){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Insira o nome do Produto: ");
        String nomeProduto = scanner.nextLine();

        System.out.print("Escreva uma breve descrição sobre o produto: ");
        String descricaoProduto = scanner.nextLine();

        System.out.print("Insira o código do produto: ");
        int codigoProduto = scanner.nextInt();

        System.out.print("Insira a quantidade do produto: ");
        int quantidadeProduto = scanner.nextInt();

        System.out.print("Insira o preço do produto (Ex. 12.33): ");
        double precoUnidadeProduto = scanner.nextDouble();

        while (true) {
            System.out.println("Qual o tipo do seu produto?");
            System.out.print("1) Produto Alimentar \n2) Produto Farmacêutico \n\nOpção: ");
            int escolhaTipoProduto = scanner.nextInt();

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
        Scanner scanner = new Scanner(System.in);
        boolean isBiologic; //Inicializado a falso
        int opcaoTaxa=0;

        do {
            System.out.println("O seu produto é biológico?\n1) Sim\n2) Não\n\nOpção: ");
            int opcaoBiologico = scanner.nextInt();

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
            opcaoTaxa = scanner.nextInt();
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
                opcaoCategoria = scanner.nextInt();
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
                System.out.print("Escolha uma certificação ou 0 para finalizar: ");


                for(int i = 0; i < certificacoes.length; i++){
                    System.out.println(i+1 + ") " + certificacoes[i].name());
                }

                System.out.print("Opção: ");
                int escolha = scanner.nextInt();

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
        boolean temPrescricao;
        int opcaoPrescricao;

        Scanner scanner = new Scanner(System.in);
        do {
            System.out.println("O seu produto farmacêutico tem prescrição?\n1) Sim\n2) Não\n\nOpção: ");
            opcaoPrescricao = scanner.nextInt();

            if (opcaoPrescricao == 1) {
                temPrescricao = true;
            } else if (opcaoPrescricao == 2) {
                temPrescricao = false;
            } else {
                System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcaoPrescricao != 1 && opcaoPrescricao != 2);

        if (opcaoPrescricao == 1){
            String nomeMedico;
            System.out.print("Introduza o nome do médico que realizou a prescrição: ");
            nomeMedico = scanner.nextLine();

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
                opcaoCategoria = scanner.nextInt();
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
        System.out.println("Valor Total Sem IVA: " + totalSemIva + "€");
        System.out.println("Valor Total do IVA: " + totalIva + "€");
        System.out.println("Valor Total Com IVA: " + totalComIva + "€");
    }

}
