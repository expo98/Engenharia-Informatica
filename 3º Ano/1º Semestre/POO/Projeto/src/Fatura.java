package Projeto.src;

import java.util.ArrayList;
import java.util.List;

public class Fatura {
    private Cliente cliente;
    private List<Produtos> produtos;
    private double precoSemIva;
    private double precoIva;
    private int numFatura;


    //Contrutor para inicializar a fatura
    public Fatura(int numFatura, Cliente cliente, List<Produtos> produtos, double precoSemIva, double precoIva){
        this.cliente = cliente;
        this.produtos = produtos;
        this.precoIva = precoIva;
        this.precoSemIva = precoSemIva;
        this.numFatura = numFatura;
    }

    public void adicionarProdutos(Produtos produto){
        if (produtos == null){
            produtos = new ArrayList<>();
        }
        produtos.add(produto);
    }

    public void adicionarCliente(Cliente cliente){
        this.cliente = cliente;
    }

        // Deve ser public?
    public double calcularPreco(){
        double precoSemIva = 0;
        double precoIva = 0;
        double precoTotal = 0;

        for (Produtos produto : produtos){
            precoSemIva += produto.getPrecoSemIva();
            precoIva += produto.calculaIva(cliente.localizacao);
        }

        precoTotal = precoIva + precoSemIva;

        //Set o preco do iva e o preco dos produtos sem o iva
        this.precoIva = precoIva;
        this.precoSemIva = precoSemIva;

        return precoTotal;
    }

    //Metodos publicos
    public void visualizarFatura(){

        //Dados do cliente (Substituir por toString em Cliente)

        //Dados da fatura
        System.out.println("\n");
        System.out.println("Dados da fatura:");
        for (Produtos produto : produtos){
            //Criar toString em cada um dos produtos;
            produto.printDadosProduto();
            System.out.println("Preço do IVA: " + produto.calculaIva(cliente.localizacao) +"€");
            System.out.println("Preço total (c/ IVA): " + produto.calculaIva(cliente.localizacao) + produto.getPrecoSemIva() + "€");
        }
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
        int numProdutos = 0;

        for (Produtos produto : produtos){
            numProdutos++;
        }
        return  numProdutos;
    }
}
