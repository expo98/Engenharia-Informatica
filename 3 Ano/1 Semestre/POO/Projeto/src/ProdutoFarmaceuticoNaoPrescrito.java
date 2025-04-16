public class ProdutoFarmaceuticoNaoPrescrito extends ProdutoFarmaceutico {

    public enum Categoria{
        ANIMAIS,
        BELEZA,
        BEMESTAR,
        BEBES,
        OUTROS
    }

    private final Categoria categoria;

    public ProdutoFarmaceuticoNaoPrescrito(int codigo, String nome, String descricao, int quantidade, double valorUnitario, Categoria categoria){
        super(codigo, nome, descricao, quantidade, valorUnitario);
        this.categoria = categoria;
    }

    @Override
    public double calculaIva(Cliente.Localizacao localizacao){
        //Nao existe verificacao da localizacao visto ser o unico caso
        // de produto que nao varia dependendo da localizacao do cliente, no entanto, é
        // preciso à mesma ter a variável
        double taxaIva = 0.23;

        if (categoria.equals(Categoria.ANIMAIS)){
            taxaIva -= 0.01;
        }

        return getQuantidade() * getValorUnitario() * taxaIva;
    }

    @Override
    public void printDadosProduto(){
        System.out.println("Dados do Produto: ");
        System.out.println("Tipo: Produto Farmacêutico");
        System.out.println("Tem prescrição: Não");
        System.out.println("Categoria: " + categoria);

        System.out.println("Nome do produto: " + getNome());
        System.out.println("Descrição do produto: " + getDescricao());
        System.out.println("Código do produto: " + getCodigo());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Preço por unidade: " + getValorUnitario() + "€");
        System.out.println("Preço total (s/ IVA): " + getValorUnitario() * getQuantidade() + "€");
    }

    @Override
    public String guardarFormato() {
        String produtoFormatado = "";
        // NomeProduto|DescricaoProduto|Quantidade|ValorUnitario|TipoDeProduto|SubtipoDeProduto|Categoria

        produtoFormatado += getNome() + "|"+ getCodigo() + "|" + getDescricao() + "|" + getQuantidade() + "|" + getValorUnitario() + "|Produto Farmaceutico|Produto Farmaceutico Nao Prescrito|" + categoria;

        return produtoFormatado;
    }
}
