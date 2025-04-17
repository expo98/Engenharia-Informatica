public class programa {
    public static void main(String[] args) {
        String[] URLs = {
                "https://www.dei.uc.pt/poao/exames",
                "http://www.scs.org/index.html",
                "https://www.nato.int/events",
                "https://www.btu.com.pt/",
                "https://www.dei.uc.pt/poao/exames",
                "http://www.eth.ch/index.html",
                "http://www.osu.edu/"
        };
        String[][] paises = {
                {"pt", "Portugal",},
                {"org", "EUA",},
                {"fr", "França",},
                {"uk", "Reino Unido",},
                {"de", "Alemanha"},
                {"com", "EUA"},
                {"edu", "EUA"}
        };
        int[] Contador = new int[paises.length+1];

        boolean existe;

        for (int i = 0; i < URLs.length; i++) {
            String[] link = URLs[i].split("/");
            String[] ponto = link[2].split("\\.");

            existe =false;
            for (int j = 0; j < paises.length; j++)
            {
                if ( ponto[ponto.length-1].equalsIgnoreCase(paises[j][0]) && (existe == false) ){
                    for (int k=0; k< paises.length;k++)
                    {
                        if ( paises[j][1].equalsIgnoreCase(paises[k][1]) )
                        {
                            Contador[k] += 1;
                            existe = true;
                            break;
                        }
                    }

                }
            }

            if (existe != true)
            {
                Contador[Contador.length-1] +=1;
                existe = false;
            }
        }

        for (int i = 0; i<Contador.length;i++)
        {
            if(i != Contador.length-1)
            {
                if ((Contador[i] != 0)) {
                    System.out.println(paises[i][1] + " : " + Contador[i]);
                }
            }
            else{
                System.out.println("Outro(s): " + Contador[Contador.length-1]);
            }
        }
    }
}