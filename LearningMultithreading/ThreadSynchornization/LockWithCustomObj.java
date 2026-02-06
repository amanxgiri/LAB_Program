package LearningMultithreading.ThreadSynchornization;

public class LockWithCustomObj {

    private static int counter1 = 0;
    private static int counter2 = 0;

    public static void main(String[] args) {

        Thread one = new Thread(() -> {
            for (int i = 0; i < 10000; i++) {
                increment1();
            }
        });
        
        Thread two = new Thread(() -> {
            for (int i = 0; i < 10009; i++) {
                increment2();
            }
        });

        one.start();
        two.start();

        try {
            one.join();
            two.join();
        } catch (InterruptedException e) {
            System.out.println("Thread Execution were Interuppted....");
        }
    }

    private static void increment1(){
        
        synchronized(){
            counter1++;
        }
    }

    private static void increment2(){
        
        synchronized(){
            counter2++;
        }
    }
}
