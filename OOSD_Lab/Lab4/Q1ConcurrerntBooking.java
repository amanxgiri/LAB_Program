package Lab4;

class Hotel {
    private int rooms = 2; // total available rooms

    // Booking method
    synchronized void bookRoom() {
        while (rooms == 0) {
            System.out.println(Thread.currentThread().getName()
                    + " -> No rooms available. Waiting...");
            try {
                wait(); // wait until a room is released
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }

        rooms--;
        System.out.println(Thread.currentThread().getName()
                + " -> Room BOOKED. Remaining rooms: " + rooms);
    }

    // Release method
    synchronized void releaseRoom() {
        rooms++;
        System.out.println(Thread.currentThread().getName()
                + " -> Room RELEASED. Available rooms: " + rooms);

        notify(); // notify one waiting booking thread
    }
}

class Customer extends Thread {
    private Hotel hotel;

    Customer(Hotel hotel, String name) {
        super(name);
        this.hotel = hotel;
    }

    @Override
    public void run() {
        hotel.bookRoom();

        try {
            Thread.sleep(1000); // simulate staying time
        } catch (InterruptedException e) {
            System.out.println("Sleep interrupted");
        }

        hotel.releaseRoom();
    }
}

public class Q1ConcurrerntBooking {
    public static void main(String[] args) {
        Hotel hotel = new Hotel();

        Customer c1 = new Customer(hotel, "Customer-1");
        Customer c2 = new Customer(hotel, "Customer-2");
        Customer c3 = new Customer(hotel, "Customer-3");
        Customer c4 = new Customer(hotel, "Customer-4");

        c1.start();
        c2.start();
        c3.start();
        c4.start();
    }
}
