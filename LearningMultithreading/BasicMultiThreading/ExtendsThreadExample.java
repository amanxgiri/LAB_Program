package LearningMultithreading.BasicMultiThreading;

class ThreadOne extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.err.println("Thread One:  " + i);
        }
    }

}

class ThreadTwo extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.err.println("Thread One:  " + i);
        }
    }

}

public class ExtendsThreadExample {

    public static void main(String[] args) {
        Thread threadOne = new Thread();
        Thread threadTwo = new Thread();

        threadOne.start();
        threadTwo.start();
    }
}