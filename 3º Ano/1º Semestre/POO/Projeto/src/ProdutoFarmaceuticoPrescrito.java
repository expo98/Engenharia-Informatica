package Projeto.src;

public class ProdutoFarmaceuticoPrescrito extends ProdutoFarmaceutico{

    private String nomeMedico;

    public ProdutoFarmaceuticoPrescrito(int codigo, String nome,String descricao, int quantidade, double valorUnitario, String nomeMedico){
        super(codigo, nome,descricao, quantidade, valorUnitario);
        this.nomeMedico = nomeMedico;
    }

    @Override
    public double calculaIva(Cliente.Localizacao localizacao){
        double taxaIva = 0.06;

        if (localizacao.equals(Cliente.Localizacao.MADEIRA)){
            taxaIva -= 0.01;
        } else if (localizacao.equals(Cliente.Localizacao.ACORES)) {
            taxaIva -= 0.02;
        }

        return getQuantidade() * getValorUnitario() * taxaIva;
    }
    @Override
    public void printDadosProduto(){
        System.out.println("Dados do Produto:");
        System.out.println("Tipo: Produto Farmacêutico");
        System.out.println("Tem prescrição: Sim");
        System.out.println("Nome do médico: " + nomeMedico);
       // Se calhar esta parte por no codigo normal? É comum a todas, nao sei...
        System.out.println("Nome do produto: " + getNome());
        System.out.println("Descrição do produto: " + getDescricao());
        System.out.println("Código do produto: " + getCodigo());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Preço por unidade: " + getValorUnitario() + "€");
        System.out.println("Preço total (s/ IVA): " + getValorUnitario() * getQuantidade() + "€");
        // Para por o preco do IVA preciso de saber a localizacao do cliente, dentro desta classe nao da
    }
    public String getNomeMedico() {
        return nomeMedico;
    }

    public void setNomeMedico(String nomeMedico) {
        this.nomeMedico = nomeMedico;
    }
}
