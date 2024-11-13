public class Exercicio1 {

    public static void main(String[] args) {
        String[] medicos = {
                "Vasco Santana/radiologia/15/10",
                "Laura Alves/oftalmologia/5/7",
                "António Silva/oftalmologia/12/5"
        };

        String[] especialidade = {
                "Radiologia/2030/50",
                "Oftalmologia/2500/70",
                "Pediatria/2700/75"
        };

        String[][] resultados;
        resultados = relacionaEspecialidadeMedicos(especialidade, medicos);

        ImprimirResultados(resultados,especialidade);
    }

    public static String[][] separaFrase(String[] frase) {
        // Inicializa um duplo array do tipo string com tamanho de frase.length()
        String[][] arrayDividido = new String[frase.length][];

        // Percorre as strings em frase[] e separa-as por /
        for (int i = 0; i < frase.length; i++) {
            arrayDividido[i] = frase[i].split("/");
        }
        return arrayDividido;
    }

    public static String[][] relacionaEspecialidadeMedicos(String[] especialidade, String[] medicos) {
        int numMedicos = medicos.length;
        int numEspecialidades = especialidade.length;

        // Declara variaveis duplo array com as especialidades e medicos separados
        String[][] especialidadeDividido = separaFrase(especialidade); // [][]
        String[][] medicosDividido = separaFrase(medicos);

        // Formato : [][Nome,Especialidade,SalárioFinal]
        String[][] salarios = new String[numMedicos][3];

        double vencimento;
        int anosBonus;

        // Especialidade : especialidade/salario base/custo da hora extra
        // Medicos : nome/especialidade/anos de servico/horas extra
        for (int i = 0; i < numMedicos; i++) {
            for (int j = 0; j < numEspecialidades; j++) {
                if ((medicosDividido[i][1].equalsIgnoreCase(especialidadeDividido[j][0]))) {

                    vencimento = 0; // Define vencimento como 0, para não somar aos vencimentos dos outros médicos já parsed
                    salarios[i][0] = medicosDividido[i][0]; // Define o nome da pessoa
                    salarios[i][1] = medicosDividido[i][1]; // Define a especialidade da pessoa

                    // Salário Base
                    vencimento += Double.parseDouble(especialidadeDividido[j][1]);

                    //Salário bonus
                    anosBonus = Integer.parseInt(medicosDividido[i][2]);
                    anosBonus = (int) Math.floor((double) anosBonus /5);

                    for (int k = 0; k< anosBonus; k++){
                        vencimento *= 1.04;
                    }

                    // Horas Extra
                    vencimento += Double.parseDouble(medicosDividido[i][3]) * Double.parseDouble(especialidadeDividido[j][2]);

                    //Arredondar vencimento
                    vencimento =  (double) Math.round(vencimento * 10) / 10;

                    salarios[i][2] = vencimento + "€"; // Convert to String
                }
            }
        }
        return salarios;
    }

    public static void ImprimirResultados(String[][] salarios, String[] especialidades) {

        //Print de salários de médicos Individuais
        for (String[] salario : salarios) {
            System.out.println(salario[0] + ": " + salario[2]);
        }

        System.out.print("\n\n");

        //Print de salário total de especialidades
        double especialidadeTotal;
        String[] parseSalario = new String[2]; // Usado para dividir em [<salário>,€]

        //Percorre todas as especialidades existentes
        for (String especialidade : especialidades){

            especialidadeTotal=0; // Define o total salário para 0 sempre que há uma nova especialidade

            String[] especialidadeDividido = especialidade.split("/"); // Usado para dividir especialidade em [espcialidade, salario base, custo hora extra]

            for (String[] salario : salarios){

                // especialidadeDividido[0] -> nome da especialidade
                if (especialidadeDividido[0].equalsIgnoreCase(salario[1])){

                    //Parsing para retirar o € da string do salário e transformar em double
                    parseSalario = salario[2].split("€");
                    especialidadeTotal += Double.parseDouble(parseSalario[0]);
                }
            }
            //Print de  <Nome Especialidade>: <total>€
            if(especialidadeTotal > 0){
                System.out.println(especialidadeDividido[0] +": " +especialidadeTotal +"€");
            }
            
        }
    }
}
