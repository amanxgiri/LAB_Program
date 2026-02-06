package LearningMultithreading.ThreadSynchornization;

public class SynchronizationDemo {

    static int counter = 0;

    public static void main(String[] args) {

        Thread one = new Thread(() -> {
            for (int i = 0; i < 10000; i++) {
                increment();
            }
        });

        Thread two = new Thread(() -> {
            for (int i = 0; i < 10000; i++) {
                increment();
            }
        });

        one.start();
        two.start();

        try {
            one.join();
            two.join();
        } catch (InterruptedException e) {
            System.out.println("Thread Interrrupted... Cleaning upp");
        }

        System.out.println("Counter Value: " + counter);

    }

    static synchronized void increment() {
        counter++;
    }
}
