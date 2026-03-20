import java.util.LinkedList;
import java.util.Queue;

public class ProducerConsumerUsingQueue {

    int capacity;
    boolean produced = false;

    Queue<Integer> queue = new LinkedList<>();

    public ProducerConsumerUsingQueue(int capacity) {
        this.capacity = capacity;
    }

    public synchronized void produce(int value) {
        try {
            while (queue.size() == capacity) {
                wait();
            }
        } catch (InterruptedException e) {
            // TODO: handle exception
        }

        queue.add(value);
        System.out.println("Produced Value : " + value);
        notify();

    }

    public synchronized int consume() {
        try {
            while (queue.isEmpty()) {
                wait();
            }
        } catch (InterruptedException e) {
            // TODO: handle exception
        }

        int value = queue.poll();
        System.out.println("Consumed Value: " + value);
        notify();
        return value;

    }

    public static void main(String[] args) {

        ProducerConsumerUsingQueue sharedResource = new ProducerConsumerUsingQueue(5);

        Thread pcThread = new Thread(() -> {
            int value = 0;
            while (true) {
                sharedResource.produce(value++);

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread csThread = new Thread(() -> {
            while (true) {
                sharedResource.consume();

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        pcThread.start();
        csThread.start();
    }
}
