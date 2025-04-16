import java.io.*;
import java.util.ArrayList;
import java.util.EnumSet;
import java.util.Objects;

public interface GerenciadorFicheiros {

      static POOFs lerFicheiroObjetos(){
        File file = new File("ficheiroObjetos.obj");
        POOFs poofs;
        try (ObjectInputStream ois = new ObjectInputStream((new FileInputStream(file)))){
            poofs = (POOFs) ois.readObject();
        } catch (IOException | ClassNotFoundException e){
            System.out.println("Ficheiro de objetos não existe!");
            poofs = new POOFs();
        }

        return poofs;
    }

     static void guardarFicheiroObjetos(ArrayList<Cliente> clientes, ArrayList<Fatura> faturas, int proxNumFatura){
        try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("ficheiroObjetos.obj"))){
            POOFs poofs = new POOFs(clientes,faturas,proxNumFatura);
            oos.writeObject(poofs);
        } catch (IOException e){
            System.out.print("Erro ao guardar ficheiro de objetos");
        }
    }

     static void guardarFicheiroTxt(ArrayList<Fatura> faturas) {
        String fileName = "faturas.txt"; // Name of the output file

//
//          Formato de guardar as faturas
//
//          NumFatura|NumContribuinte|PrecoSemIva|PrecoDoIVA|NomeProduto|DescricaoProduto|Quantidade|ValorUnitario|TipoDeProduto|SubtipoDeProduto
//
//
//          Para produtoFarmaceuticoNaoPrescrito -> ...|SubtipoDeProduto|Categoria
//          Para produtoFarmceuticoPrescriuto    -> ...|SubtipoDeProduto|NomeDoMedico
//
//          Para produtoAlimentarNormal          -> ...|SubtipoDeProduto|isBiologic
//          Para produtoAlimentarIntermedio      -> ...|SubtipoDeProduto|isBiologic|CategoriaAlimentar
//          Para produtoAlimentarReduzido        -> ...|SubtipoDeProduto|isBiologic|Certificados(separadas por ,)
//
        int totalFaturas = faturas.size();
        int faturasAtualIndice = 0;

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (Fatura fatura : faturas) {
                writer.write( String.format("%d",fatura.getNumFatura()));
                writer.write("|");
                writer.write(String.format("%d",fatura.getCliente().getNumContribuinte()));
                writer.write("|");
                writer.write(fatura.getCliente().getNome());
                writer.write("|");
                writer.write(fatura.getCliente().getLocalizacao().name());
                writer.write("|");
                writer.write(String.format("%.2f", fatura.getPrecoSemIva()));
                writer.write("|");
                writer.write(String.format("%.2f", fatura.getPrecoIva()));
                writer.write("|");
                for (Produtos produto : fatura.getProdutos()) { // Assuming Produtos has a toString or similar
                    writer.write(produto.guardarFormato()); // Customize based on your Produto class
                    writer.write("|");
                }
                faturasAtualIndice++;
                if (faturasAtualIndice < totalFaturas) {
                    writer.write("\n");
                }
            }


            System.out.println("Faturas guardadas em" + fileName);
        } catch (IOException e) {
            System.err.println("Erro ao guardar no ficheiro: " + e.getMessage());
        }
    }

     static POOFs lerFaturasTxt(){
        String filename = "faturas.txt";
        ArrayList<Cliente> clientes = new ArrayList<>();
        ArrayList<Fatura> faturas = new ArrayList<>();

        String linhaFicheiros;

        try(BufferedReader reader = new BufferedReader(new FileReader(filename))){
            //NumFatura|NumContribuinte|Nome|Localizacao|PrecoSemIva|PrecoDoIVA|NomeProduto|DescricaoProduto|Quantidade|ValorUnitario|TipoDeProduto|SubtipoDeProduto

            int ultimoNumFatura = -1;
            while ((linhaFicheiros = reader.readLine()) != null){
            Cliente cliente = new Cliente();
            String[] linha = linhaFicheiros.split("\\|");

            int numFatura = Integer.parseInt(linha[0]);
            ultimoNumFatura = numFatura;
            int numContribuinte = Integer.parseInt(linha[1]);
            String nomeCliente = linha[2];
            String localizacao = linha[3];

            cliente.setNome(nomeCliente);
            cliente.setNumContribuinte(numContribuinte);
            if (Objects.equals(localizacao, Cliente.Localizacao.CONTINENTE.name())){
                cliente.setLocalizacao(Cliente.Localizacao.CONTINENTE);
            } else if (Objects.equals(localizacao, Cliente.Localizacao.ACORES.name())) {
                cliente.setLocalizacao(Cliente.Localizacao.ACORES);
            } else if (Objects.equals(localizacao,Cliente.Localizacao.MADEIRA.name())) {
                cliente.setLocalizacao(Cliente.Localizacao.MADEIRA);
            }

            Fatura fatura = new Fatura(numFatura);
            fatura.setCliente(cliente);
            clientes.add(cliente);

            double faturaPrecoSemIva = Double.parseDouble(linha[4]);
            double faturaPrecoDoIva = Double.parseDouble(linha[5]);
            String nomeProduto = linha[6];
            int codigoProduto = Integer.parseInt(linha[7]);
            String descricaoProduto = linha[8];
            int quantidade = Integer.parseInt(linha[9]);
            double valorUnitario = Double.parseDouble(linha[10]);

            String subTipoDeProduto = linha[12];

            if (Objects.equals(subTipoDeProduto,"Produto Farmaceutico Prescrito")){
                String nomeMedico = linha[13];
                ProdutoFarmaceuticoPrescrito produto = new ProdutoFarmaceuticoPrescrito(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,nomeMedico);
                fatura.adicionarProdutos(produto);
            } else if (Objects.equals(subTipoDeProduto,"Produto Farmaceutico Nao Prescrito")) {
                String categoria = linha[13];
                ProdutoFarmaceuticoNaoPrescrito produto = null;

                if (Objects.equals(categoria,ProdutoFarmaceuticoNaoPrescrito.Categoria.ANIMAIS.name())){
                    produto = new ProdutoFarmaceuticoNaoPrescrito(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,ProdutoFarmaceuticoNaoPrescrito.Categoria.ANIMAIS);
                } else if (Objects.equals(categoria,ProdutoFarmaceuticoNaoPrescrito.Categoria.BEMESTAR.name())) {
                    produto = new ProdutoFarmaceuticoNaoPrescrito(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,ProdutoFarmaceuticoNaoPrescrito.Categoria.ANIMAIS);
                } else if (Objects.equals(categoria,ProdutoFarmaceuticoNaoPrescrito.Categoria.BEBES.name())) {
                    produto = new ProdutoFarmaceuticoNaoPrescrito(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,ProdutoFarmaceuticoNaoPrescrito.Categoria.ANIMAIS);
                } else if (Objects.equals(categoria,ProdutoFarmaceuticoNaoPrescrito.Categoria.BELEZA.name())) {
                    produto = new ProdutoFarmaceuticoNaoPrescrito(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,ProdutoFarmaceuticoNaoPrescrito.Categoria.ANIMAIS);
                } else if (Objects.equals(categoria,ProdutoFarmaceuticoNaoPrescrito.Categoria.OUTROS.name())){
                    produto = new ProdutoFarmaceuticoNaoPrescrito(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,ProdutoFarmaceuticoNaoPrescrito.Categoria.ANIMAIS);
                }
                if (produto != null) {
                    fatura.adicionarProdutos(produto);
                }
            } else if (Objects.equals(subTipoDeProduto,"Produto Alimentar Normal")){
                String isBiologic = linha[13];
                ProdutoAlimentarNormal produto = null;

                if (Objects.equals(isBiologic, "Sim")){
                    produto = new ProdutoAlimentarNormal(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,true);
                } else if (Objects.equals(isBiologic, "Não")) {
                    produto = new ProdutoAlimentarNormal(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,false);
                }

                fatura.adicionarProdutos(produto);
            } else if (Objects.equals(subTipoDeProduto,"Produto Alimentar Intermedio")) {
                String Biologic = linha[13];
                boolean isBiologic = false;
                String categoria = linha[14];
                ProdutoAlimentarIntermedio produto = null;

                if (Objects.equals(Biologic, "Sim")){
                    isBiologic = true;
                }

                if (Objects.equals(categoria,ProdutoAlimentarIntermedio.CategoriasAlimentar.VINHO.name())){
                    produto = new ProdutoAlimentarIntermedio(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,isBiologic,ProdutoAlimentarIntermedio.CategoriasAlimentar.VINHO);
                } else if (Objects.equals(categoria,ProdutoAlimentarIntermedio.CategoriasAlimentar.CONGELADOS.name())) {
                    produto = new ProdutoAlimentarIntermedio(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,isBiologic,ProdutoAlimentarIntermedio.CategoriasAlimentar.CONGELADOS);
                } else if (Objects.equals(categoria,ProdutoAlimentarIntermedio.CategoriasAlimentar.ENLATADOS.name())) {
                    produto = new ProdutoAlimentarIntermedio(codigoProduto,nomeProduto,descricaoProduto,quantidade,valorUnitario,isBiologic,ProdutoAlimentarIntermedio.CategoriasAlimentar.ENLATADOS);
                }

                if (produto != null) {
                    fatura.adicionarProdutos(produto);
                }
            } else if (Objects.equals(subTipoDeProduto,"Produto Alimentar Reduzido")) {
                String biologic = linha[13];
                boolean isBiologic = Objects.equals(biologic, "Sim");

                String[] certificados = linha[14].split(",");
                EnumSet<ProdutoAlimentarReduzido.Certificacoes> certificacoesSet = EnumSet.noneOf(ProdutoAlimentarReduzido.Certificacoes.class);

                for (String certificado : certificados) {
                    switch (certificado.trim()) {
                        case "ISO22000":
                            certificacoesSet.add(ProdutoAlimentarReduzido.Certificacoes.ISO22000);
                            break;
                        case "FSSC22000":
                            certificacoesSet.add(ProdutoAlimentarReduzido.Certificacoes.FSSC22000);
                            break;
                        case "HACCP":
                            certificacoesSet.add(ProdutoAlimentarReduzido.Certificacoes.HACCP);
                            break;
                        case "GMP":
                            certificacoesSet.add(ProdutoAlimentarReduzido.Certificacoes.GMP);
                            break;
                    }
                }

                ProdutoAlimentarReduzido produto = new ProdutoAlimentarReduzido(
                        codigoProduto,
                        nomeProduto,
                        descricaoProduto,
                        quantidade,
                        valorUnitario,
                        isBiologic,
                        certificacoesSet
                );

                fatura.adicionarProdutos(produto);
            }
            fatura.setPrecoIva(faturaPrecoDoIva);
            fatura.setPrecoSemIva(faturaPrecoSemIva);
            faturas.add(fatura);
            }
            return new POOFs(clientes,faturas,ultimoNumFatura);
        } catch (IOException e){
            throw new RuntimeException(e);
        }
    }
}
