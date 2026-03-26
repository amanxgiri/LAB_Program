package Lab3;

class OrderValidation extends Thread {
    private String customerId;

    public OrderValidation(String customerId) {
        this.customerId = customerId;
    }

    @Override
    public void run() {
        try {
            System.out.println("Order Validation Started for " + customerId + "....");
            Thread.sleep(1000);
            System.out.println("Order Validation Completed for " + customerId + "...");
        } catch (InterruptedException e) {
            System.out.println("Error Occured. Validation Thread Execution Stopped..");
        }
    }
}

class PaymentProcessing extends Thread {
    private String customerId;

    public PaymentProcessing(String customerId) {
        this.customerId = customerId;
    }

    @Override
    public void run() {
        try {
            System.out.println("Payment processing Started for " + customerId + "....");
            Thread.sleep(2000);
            System.out.println("Payment Success for " + customerId + "....");
        } catch (InterruptedException e) {
            System.out.println("Payment Processing Thread had an error. Execution Stopped..");
        }
    }
}

class OrderShipment extends Thread {
    private String customerId;

    public OrderShipment(String customerId) {
        this.customerId = customerId;
    }

    @Override
    public void run() {
        try {
            System.out.println("Order Shipment packaging Started for " + customerId + "...");
            Thread.sleep(3000);
            System.out.println("Order Shipped for " + customerId + "... ");
        } catch (InterruptedException e) {
            System.out.println("Order Shipment Thread had an error... Execution Stopped..");
        }
    }
}

public class Q2OnlineOrder {

    public static void main(String[] args) throws InterruptedException {
        String customer1 = "Customer A";
        String customer2 = "Customer B";

        // Creating threads for Customer A
        Thread validation1 = new Thread(new OrderValidation(customer1));
        Thread payment1 = new Thread(new PaymentProcessing(customer1));
        Thread shipment1 = new Thread(new OrderShipment(customer1));

        // Creating threads for Customer B
        Thread validation2 = new Thread(new OrderValidation(customer2));
        Thread payment2 = new Thread(new PaymentProcessing(customer2));
        Thread shipment2 = new Thread(new OrderShipment(customer2));

        // Starting all threads simulating simultaneous order processing
        validation1.start();
        payment1.start();
        shipment1.start();

        validation2.start();
        payment2.start();
        shipment2.start();

        // Waiting for all tasks to complete
        validation1.join();
        payment1.join();
        shipment1.join();

        validation2.join();
        payment2.join();
        shipment2.join();

        System.out.println("All Online Orders Processed Successfully...");
    }
}
