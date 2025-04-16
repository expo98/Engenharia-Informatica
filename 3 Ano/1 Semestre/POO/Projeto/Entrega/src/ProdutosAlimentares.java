

public abstract class ProdutosAlimentares extends Produtos{

    //Declaracao de variaveis de produtos alimentares
    private final boolean isBiologico;

    //Cosntrutor
    public ProdutosAlimentares(int codigo, String nome, String descricao, int quantidade, double valorUnitario, boolean isBiologico){
        super(codigo,nome,descricao,quantidade,valorUnitario);
        this.isBiologico = isBiologico;
    }

    public boolean getBiologico(){  return isBiologico; }
}
