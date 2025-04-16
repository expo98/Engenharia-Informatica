import java.io.Serializable;

public abstract class Produtos implements Serializable {

    private final int codigo;
    private final String nome;
    private final String descricao;
    private final int quantidade;
    private final double valorUnitario;

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

    public abstract String guardarFormato();

}
