package LearningMultithreading.BasicMultiThreading;

class ThreadOne implements Runnable {

    @Override
    public void run() {

        for (int i = 0; i < 5; i++) {
            System.out.println("Thread One: " + i);
        }
    }
}

class ThreadTwo implements Runnable {

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Thread Two: " + i);
        }
    }
}

public class RunnableThreadExample {

    public static void main(String[] args) {

        Thread Threadone = new Thread(new ThreadOne());
        Thread Threadtwo = new Thread(new ThreadTwo());

        // anonymous class implementation of Threads
        Thread Threadthree = new Thread(new Runnable() {

            @Override
            public void run() {
                for (int i = 0; i < 5; i++) {
                    System.out.println("Thread Three: " + i);
                }
            }
        });

        Threadone.start();
        Threadtwo.start();
        Threadthree.start();
    }

}
