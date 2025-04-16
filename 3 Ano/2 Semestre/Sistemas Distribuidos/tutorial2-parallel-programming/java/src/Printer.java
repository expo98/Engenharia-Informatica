import java.util.Arrays;
import java.util.concurrent.atomic.AtomicInteger;

public class Printer {
     static long startTime = 0;
    static long stopTime= 0;
    static boolean running = false;

    public static long getElapsedTime(){
        long elapsed;
        if(running){
            elapsed = (System.currentTimeMillis() - startTime);
        }
        else {
            elapsed = stopTime - startTime;
        }

        return elapsed;
    }

    public static void start(){
        startTime = System.currentTimeMillis();
        running = true;
    }

    public static void stop(){
        stopTime = System.currentTimeMillis();
        running = false;
    }

    public static void MonteCarlo() {
            int[] totalDarts = new int[100000000];
            //AtomicInteger inside = new AtomicInteger(0);
            start();
            long inside = Arrays.stream(totalDarts).parallel().mapToLong(v -> {
                        double x = Math.random();
                        double y = Math.random();
                        return (x * x + y * y <= 1) ? 1L : 0L;
                    })
                    .sum();
            stop();
            System.out.println("Monte Carlo Parallel Execution Time: " + getElapsedTime() + "ms");
            double pi = 4.0 * inside / totalDarts.length;
            System.out.println("Pi = " + pi);

            int serialInside = 0;
            start();
                for (int i = 0; i < totalDarts.length; i++) {
                    double x = Math.random();
                    double y = Math.random();
                    if (x * x + y * y <= 1) {
                        serialInside++;
                    }
                }
            stop();

            System.out.println("Serial Execution Time: " + getElapsedTime() +"ms");
            double piSerial = 4.0 * serialInside / totalDarts.length;
            System.out.println("Pi = " + piSerial);

            return;
        }





    public static void main(String[] args) {

        int[] array = new int[100];
        for (int i = 0; i < array.length; i++) {
            array[i] = i;
        }

        int serialSumOfSquares = 0;
        Printer.start();
        System.out.println("Serial execution");
        for (int v : array){
                    try {
                        Thread.sleep(10);  // Simulate 100ms task
                        serialSumOfSquares += v * v;
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
        Printer.stop();
        System.out.println(serialSumOfSquares);
        System.out.println("Serial Execution Time: " + Printer.getElapsedTime());

        AtomicInteger parallelTotalValue = new AtomicInteger(0);
        Printer.start();
        System.out.println();
        System.out.println("Parallel execution");
        Arrays.stream(array).parallel()
                .forEach(v -> {
                    try {
                        Thread.sleep(10);  // Simulate 100ms task
                        parallelTotalValue.addAndGet(v*v);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                });
        Printer.stop();
        System.out.println(parallelTotalValue);
        System.out.println("Parallel Execution Time: " + Printer.getElapsedTime());

        MonteCarlo();

    }




}
