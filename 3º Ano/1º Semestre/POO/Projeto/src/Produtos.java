package Projeto.src;

public abstract class Produtos {

    private int codigo;
    private String nome;
    private String descricao;
    private int quantidade;
    private double valorUnitario;

    //Construtor

    public Produtos(int codigo, String nome, String descricao, int quantidade, double valorUnitario){
        this.codigo = codigo;
        this.nome = nome;
        this.descricao = descricao;
        this.quantidade = quantidade;
        this.valorUnitario = valorUnitario;
    }


    // Getters
    public int getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    public String getDescricao() {
        return descricao;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public double getValorUnitario() {
        return valorUnitario;
    }

    public double getPrecoSemIva() {
        return valorUnitario * quantidade;
    }

    // Abstract method to calculate IVA
    public abstract double calculaIva(Cliente.Localizacao localizacao);

    public abstract void printDadosProduto();


}
