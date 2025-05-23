public class ProdutoAlimentarIntermedio extends ProdutosAlimentares {

    public enum CategoriasAlimentar{
        VINHO,
        CONGELADOS,
        ENLATADOS
    }

    public CategoriasAlimentar categoria;

    public ProdutoAlimentarIntermedio(int codigo, String nome, String descricao, int quantidade, double valorUnitario, boolean isBiologico, CategoriasAlimentar categoria){
        super(codigo, nome, descricao, quantidade, valorUnitario, isBiologico);
        this.categoria = categoria;
    }

    @Override
    public double calculaIva(Cliente.Localizacao localizacao){

        double taxaIva = 0.13;

        if (localizacao == Cliente.Localizacao.MADEIRA){
            taxaIva = 0.12;
        } else if (localizacao== Cliente.Localizacao.ACORES) {
            taxaIva = 0.16;
        }
        if (categoria == CategoriasAlimentar.VINHO){
            taxaIva += 0.01;
        }

        if(getBiologico()){
            taxaIva *= 0.9;
        }

        return getQuantidade()* getValorUnitario() * taxaIva;
    }

    @Override
    public void printDadosProduto(){
        System.out.println("Dados do Produto:");
        System.out.println("Tipo: Produto Alimentar");

        if (getBiologico()){
            System.out.print("Biologico: Sim");
        } else {
            System.out.print("Biologico: Não");
        }

        System.out.println("Taxa de IVA: Intermédia");
        System.out.println("Categoria: " + categoria.name());

        System.out.println("Nome do produto: " + getNome());
        System.out.println("Código do produto: " + getCodigo());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Preço por unidade: " + getValorUnitario() + "€");
        System.out.println("Preço total (s/ IVA): " + getValorUnitario() * getQuantidade() + "€");
    }

    @Override
    public String guardarFormato() {
        String produtoFormatado = "";
        // NomeProduto||DescricaoProduto|Quantidade|ValorUnitario|TipoDeProduto|SubtipoDeProduto|isBiologic|CategoriaAlimentar

        produtoFormatado += getNome() + "|"+ getDescricao() + "|" + getCodigo() + "|" + getQuantidade() + "|" + getValorUnitario();
        if (getBiologico()) {
            produtoFormatado += "|Produto Alimentar|Produto Alimentar Intermedio|Sim|" + categoria.name();
        }
        else {
            produtoFormatado += "|Produto Alimentar|Produto Alimentar Intermedio|Não|" + categoria.name();
        }
        return  produtoFormatado;
    }
}

