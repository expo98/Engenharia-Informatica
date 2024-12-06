package Projeto.src;


import java.util.EnumSet;

public abstract class ProdutosAlimentares extends Produtos{

    //Declaracao de variaveis de produtos alimentares
    private boolean isBiologico;

    //Cosntrutor
    public ProdutosAlimentares(int codigo, String nome, String descricao, int quantidade, double valorUnitario, boolean isBiologico){
        super(codigo,nome,descricao,quantidade,valorUnitario);
        this.isBiologico = isBiologico;
    }

    // Getter and setter for isBiologico variable
    public void setBiologico(boolean biologico) {   isBiologico = biologico;    }

    public boolean getBiologico(){  return isBiologico; }
}
