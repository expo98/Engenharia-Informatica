import java.io.Serializable;

public class Cliente implements Serializable {

    // Definicao de enum da localizacao
    public enum Localizacao {
        CONTINENTE,
        ACORES,
        MADEIRA
    }

    private String nome;
    private int numContribuinte;
    private Localizacao localizacao;

    public Cliente(String nome, int numContribuinte, Localizacao localizacao){
        this.nome = nome;
        this.numContribuinte = numContribuinte;
        this.localizacao = localizacao;
    }

    public Cliente() {
    }
    public void setLocalizacao(Localizacao localizacao) {
        this.localizacao = localizacao;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNumContribuinte(int numContribuinte) {
        this.numContribuinte = numContribuinte;
    }

    public String getNome() {
        return nome;
    }

    public int getNumContribuinte() {
        return numContribuinte;
    }

    public Localizacao getLocalizacao() {
        return localizacao;
    }

    public Localizacao[] getLocalizacoes(){
        return Localizacao.values();
    }


    public void printDadosCliente() {
        System.out.println("\n");
        System.out.println("Dados do Cliente:");
        System.out.println("Nome: " + nome);
        System.out.println("Número de contribuinte: " + numContribuinte);
        System.out.println("Localização do cliente: " + localizacao.name());
    }
}
