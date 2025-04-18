public class ProdutoAlimentarNormal extends ProdutosAlimentares {

    public ProdutoAlimentarNormal(int codigo, String nome, String descricao, int quantidade, double valorUnitario, boolean isBiologico)
    {
        super(codigo, nome, descricao, quantidade, valorUnitario, isBiologico);
    }

    @Override
    public double calculaIva(Cliente.Localizacao localizacao){
        double taxaIva = 0.23;

        if (localizacao.equals(Cliente.Localizacao.MADEIRA)){
            taxaIva = 0.22;
        } else if (localizacao.equals(Cliente.Localizacao.ACORES)) {
            taxaIva = 0.16;
        }
        if (getBiologico()){
            taxaIva *= 0.9;
        }

        return getQuantidade()* getValorUnitario() * taxaIva;
    }

    @Override
    public void printDadosProduto(){
        System.out.println("Dados do Produto:");
        System.out.println("Tipo: Produto Alimentar");

        if (getBiologico()){
            System.out.println("Biologico: Sim");
        } else {
            System.out.println("Biologico: Não");
        }

        System.out.println("Taxa de IVA: Normal");

        System.out.println("Nome do produto: " + getNome());
        System.out.println("Código do produto: " + getCodigo());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Preço por unidade: " + getValorUnitario() + "€");
        System.out.println("Preço total (s/ IVA): " + getValorUnitario() * getQuantidade() + "€");
    }

    @Override
    public String guardarFormato() {
        String produtoFormatado = "";
        // NomeProduto|DescricaoProduto|Quantidade|ValorUnitario|TipoDeProduto|SubtipoDeProduto|isBiologic

        produtoFormatado += getNome() + "|"+ getCodigo() + "|" + getDescricao() + "|" + getQuantidade() + "|" + getValorUnitario();
        if (getBiologico()) {
            produtoFormatado += "|Produto Alimentar|Produto Alimentar Normal|Sim";
        }
        else {
            produtoFormatado += "|Produto Alimentar|Produto Alimentar Normal|Não";
        }
        return  produtoFormatado;
    }
}
