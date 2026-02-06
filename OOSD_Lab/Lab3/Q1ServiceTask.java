package Lab3;

class RoomCleaning extends Thread {

    @Override
    public void run() {
        try {
            System.out.println("Room cleaning....");
            Thread.sleep(2000);
            System.out.println("Room Cleaning Done...");
        } catch (InterruptedException e) {
            System.out.println("Error Occured. Thread Execution Stopped.. ");
        }
    }
}

class FoodDelivery extends Thread {

    @Override
    public void run() {
        try {
            System.out.println("Food delivery Started....");
            Thread.sleep(3000);
            System.out.println("Food Delivered....");
        } catch (InterruptedException e) {
            System.out.println("Food Delivery Thread had an error. Execution Stopped..");
        }
    }
}

class Maintainence extends Thread {

    @Override
    public void run() {
        try {
            System.out.println("Maintainence Work Started...");
            Thread.sleep(5000);
            System.out.println("Maintainenece Work Ended... ");
        } catch (InterruptedException e) {
            System.out.println("Maintainence Work Thread had an error... Execution Stopped..");
        }
    }
}

public class Q1ServiceTask {

    public static void main(String[] args) throws InterruptedException {
        Thread cleaning = new Thread(new RoomCleaning());
        Thread foodDelivery = new Thread(new FoodDelivery());
        Thread maintainence = new Thread(new Maintainence());
        

        
        cleaning.start();
        foodDelivery.start();
        maintainence.start();
        cleaning.join();
        foodDelivery.join();
        maintainence.join();
        


        // join runs the main thread at the end when all the join methods 
        // are called

        System.out.println("All Hotel Services Completed...");
    }
}
