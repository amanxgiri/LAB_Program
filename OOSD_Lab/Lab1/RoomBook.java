package Lab1;

// 3. Design and implement a Java application to simulate a Hotel Room Booking System 
// that demonstrates the object-oriented concepts of inheritance and runtime 
// polymorphism. 
 
// i. Create a base class named Room that represents a general hotel room. The class should 
// contain data members such as room number and base tariff, and a method 
// calculateTariff() to compute the room cost. 

// ii. Create derived classes such as StandardRoom and LuxuryRoom that inherit from the 
// Room class. Each derived class should override the calculateTariff() method to 
// compute the tariff based on room-specific features such as air conditioning, additional 
// amenities, or premium services. 


// iii. In the main class, create a base class reference of type Room and assign it to objects of 
// different derived classes (StandardRoom, LuxuryRoom). Invoke the 
// calculateTariff() method using the base class reference to demonstrate runtime 
// polymorphism, where the method call is resolved at runtime based on the actual 
// object type.


// Base class Room
class Room {
    protected int roomNumber;
    protected double baseTariff;

    // Constructor
    public Room(int roomNumber, double baseTariff) {
        this.roomNumber = roomNumber;
        this.baseTariff = baseTariff;
    }

    // Method to calculate tariff (to be overridden)
    public double calculateTariff() {
        return baseTariff;
    }

    // Display room details
    public void displayDetails() {
        System.out.println("Room Number: " + roomNumber);
        System.out.println("Base Tariff: $" + baseTariff);
        System.out.println("Total Tariff: $" + calculateTariff());
    }
}

// Derived class StandardRoom
class StandardRoom extends Room {
    private boolean hasAC;
    private static final double AC_CHARGE = 20.0;

    public StandardRoom(int roomNumber, double baseTariff, boolean hasAC) {
        super(roomNumber, baseTariff);
        this.hasAC = hasAC;
    }

    // Override calculateTariff method
    @Override
    public double calculateTariff() {
        double totalTariff = baseTariff;
        if (hasAC) {
            totalTariff += AC_CHARGE;
        }
        return totalTariff;
    }

    @Override
    public void displayDetails() {
        System.out.println("\n=== Standard Room ===");
        super.displayDetails();
        System.out.println("Air Conditioning: " + (hasAC ? "Yes" : "No"));
    }
}

// Derived class LuxuryRoom
class LuxuryRoom extends Room {
    private boolean hasAC;
    private boolean hasMiniBar;
    private boolean hasJacuzzi;
    private static final double AC_CHARGE = 20.0;
    private static final double MINIBAR_CHARGE = 50.0;
    private static final double JACUZZI_CHARGE = 100.0;

    public LuxuryRoom(int roomNumber, double baseTariff, boolean hasAC, 
                      boolean hasMiniBar, boolean hasJacuzzi) {
        super(roomNumber, baseTariff);
        this.hasAC = hasAC;
        this.hasMiniBar = hasMiniBar;
        this.hasJacuzzi = hasJacuzzi;
    }

    // Override calculateTariff method
    @Override
    public double calculateTariff() {
        double totalTariff = baseTariff;
        if (hasAC) {
            totalTariff += AC_CHARGE;
        }
        if (hasMiniBar) {
            totalTariff += MINIBAR_CHARGE;
        }
        if (hasJacuzzi) {
            totalTariff += JACUZZI_CHARGE;
        }
        return totalTariff;
    }

    @Override
    public void displayDetails() {
        System.out.println("\n=== Luxury Room ===");
        super.displayDetails();
        System.out.println("Air Conditioning: " + (hasAC ? "Yes" : "No"));
        System.out.println("Mini Bar: " + (hasMiniBar ? "Yes" : "No"));
        System.out.println("Jacuzzi: " + (hasJacuzzi ? "Yes" : "No"));
    }
}

// Main class
public class RoomBook {
    public static void main(String[] args) {
        System.out.println("========================================");
        System.out.println("Hotel Room Booking System");
        System.out.println("Demonstrating Runtime Polymorphism");
        System.out.println("========================================");

        // Creating base class references pointing to derived class objects
        // This demonstrates runtime polymorphism
        Room room1 = new StandardRoom(101, 100.0, true);
        Room room2 = new StandardRoom(102, 100.0, false);
        Room room3 = new LuxuryRoom(201, 200.0, true, true, true);
        Room room4 = new LuxuryRoom(202, 200.0, true, false, true);

        // Array of Room references (demonstrates polymorphism further)
        Room[] rooms = {room1, room2, room3, room4};

        // Invoking calculateTariff() using base class reference
        // Method call is resolved at runtime based on actual object type
        for (Room room : rooms) {
            room.displayDetails();
        }

        // Demonstrating runtime polymorphism explicitly
        System.out.println("\n========================================");
        System.out.println("Runtime Polymorphism Demonstration:");
        System.out.println("========================================");
        System.out.println("Room 101 Tariff: $" + room1.calculateTariff());
        System.out.println("Room 102 Tariff: $" + room2.calculateTariff());
        System.out.println("Room 201 Tariff: $" + room3.calculateTariff());
        System.out.println("Room 202 Tariff: $" + room4.calculateTariff());
    }
}