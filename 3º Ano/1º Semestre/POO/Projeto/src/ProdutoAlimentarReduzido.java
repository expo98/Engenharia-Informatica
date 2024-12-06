package Projeto.src;

import java.util.EnumSet;

public class ProdutoAlimentarReduzido extends ProdutosAlimentares {
    public enum Certificacoes{
        ISO22000,
        FSSC22000,
        HACCP,
        GMP;
    }

    EnumSet<Certificacoes> certificacoesSet;

    public ProdutoAlimentarReduzido(int codigo, String nome, String descricao, int quantidade, double valorUnitario, boolean isBiologico, EnumSet<Certificacoes> certificacoesSet){
        super(codigo, nome, descricao, quantidade, valorUnitario, isBiologico);
        this.certificacoesSet = certificacoesSet;
    }

    @Override
    public double calculaIva(Cliente.Localizacao localizacao){
        double taxaIva = 0.06;

        if (localizacao.equals(Cliente.Localizacao.MADEIRA)){
            taxaIva = 0.05;
        } else if (localizacao.equals(Cliente.Localizacao.ACORES)) {
            taxaIva = 0.04;
        }

        if (certificacoesSet.size() == 4){
            taxaIva -= 0.01;
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
            System.out.print("Biologico: Sim");
        } else {
            System.out.print("Biologico: Não");
        }

        System.out.println("Taxa de IVA: Reduzido");
        System.out.println("Certificações: ");
        for(Certificacoes certificacao : certificacoesSet){
            System.out.print(certificacao + " ");
        }

        System.out.println("Nome do produto: " + getNome());
        System.out.println("Código do produto: " + getCodigo());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Preço por unidade: " + getValorUnitario() + "€");
        System.out.println("Preço total (s/ IVA): " + getValorUnitario() * getQuantidade() + "€");

    }

}
