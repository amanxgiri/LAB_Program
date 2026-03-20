
class myRunnableThread implements Runnable {

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Runnable Thread: " + i);
        }
    }
}

class myThreadClass extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Class Thread: " + i);
        }
    }
}

public class ThreadCreation {
    public static void main(String args[]) {

        // creation of thread using a runnable inteface
        myRunnableThread task = new myRunnableThread();
        Thread taskThread = new Thread(task);

        // creation of thread that was created using Thread class
        myThreadClass threadObj = new myThreadClass();

        taskThread.start();
        threadObj.start();

    }
}
