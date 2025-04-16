import java.util.Scanner;

public interface lerConsola {
        Scanner scanner = new Scanner(System.in);

         static int readInt() {
            int tentativa = 0;

            while (true) {
                if (tentativa>0){
                    System.out.print("Por favor tente outra vez:");
                }

                String input = scanner.nextLine(); // Read input as a string
                if (input.matches("-?\\d+")) { // Regex for an integer (with optional negative sign)
                    return Integer.parseInt(input); // Parse and return the integer
                } else {
                    System.out.println("Input inválido. Por favor insere apenas um inteiro.");
                    tentativa++;
                }
            }
        }

     static double readDouble() {
            int tentativa = 0;
        while (true) {
            if (tentativa >0){
                System.out.print("Por favor tente outra vez:");
            }
            String input = scanner.nextLine(); // Read input as a string
            if (input.matches("-?\\d*(\\.\\d+)?")) { // Regex for a double (with optional negative sign)
                return Double.parseDouble(input); // Parse and return the double
            } else {
                tentativa++;
                System.out.println("Input inválido. Por favor insere apenas um double.");
            }
        }
    }

         static String readString() {
            int tentativa = 0;
            while (true) {
                if (tentativa < 0){
                    System.out.print("Por favor tente outra vez:");
                }
                String input = scanner.nextLine().trim(); // Trim to remove leading/trailing spaces
                if (!input.isEmpty() && !input.matches("\\d+")) { // Ensure input is non-empty and not purely numeric
                    return input;
                } else {
                    tentativa++;
                    System.out.println("Input inválido. Por favor insere uma String não vazia sem números!");
                }
            }
        }
    }

