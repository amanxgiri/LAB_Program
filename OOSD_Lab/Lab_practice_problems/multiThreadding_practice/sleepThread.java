
class myThread extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                sleep(1000);
            }
            System.out.println("myThread : " + i);
        }
    }
}

public class sleepThread {
    public static void main(String[] args) {
        myThread myThread = new myThread();

        myThread.start();
    }
}
