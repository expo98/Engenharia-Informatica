import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Fatura implements Serializable {
    private Cliente cliente;
    private ArrayList<Produtos> produtos;
    private double precoSemIva;
    private double precoIva;
    private final int numFatura;


    //Contrutor para inicializar a fatura
    public Fatura(int numFatura, Cliente cliente, ArrayList<Produtos> produtos, double precoSemIva, double precoIva){
        this.numFatura = numFatura;
        this.cliente = cliente;
        this.produtos = produtos;
        this.precoIva = precoIva;
        this.precoSemIva = precoSemIva;

    }

    public Fatura(int numFatura){
        this.numFatura = numFatura;
    }

    public void adicionarProdutos(Produtos produto){
        if (produtos == null){
            produtos = new ArrayList<>();
        }
        produtos.add(produto);

        this.precoSemIva += produto.getPrecoSemIva();
        this.precoIva += produto.getPrecoSemIva() + produto.calculaIva(cliente.getLocalizacao());
    }



    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public void setPrecoSemIva(double precoSemIva) {
        this.precoSemIva = precoSemIva;
    }

    public void setPrecoIva(double precoIva) {
        this.precoIva = precoIva;
    }

    //Metodos publicos
    public void visualizarFatura(){



        //Dados da fatura
        System.out.println("\n");
        System.out.println("Dados da fatura:");
        for (Produtos produto : produtos){
            System.out.println("----------------------------");
            produto.printDadosProduto();
        }
        double precoDoIVA = precoIva + precoSemIva;
        System.out.println("----------------------------");
        System.out.println("Preço total (s/ IVA): " + String.format("%.2f", precoSemIva) + "€");
        System.out.println("Preço total do IVA: " + String.format("%.2f", precoIva) + "€");
        System.out.println("Preço total (c/ IVA): " + String.format("%.2f", precoDoIVA) + "€");
        System.out.println("----------------------------");
    }

    // Getters e setters


    public int getNumFatura() {
        return numFatura;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public double getPrecoIva() {
        return precoIva;
    }

    public double getPrecoSemIva() {
        return precoSemIva;
    }

    public List<Produtos> getProdutos() {
        return produtos;
    }

    public int calculaNumProdutos(){
        return  produtos.size();
    }
}
