
package Lab1;

// Abstract class Room
abstract class Room {
    protected int roomNumber;
    protected double basePrice;

    // Constructor
    public Room(int roomNumber, double basePrice) {
        this.roomNumber = roomNumber;
        this.basePrice = basePrice;
    }

    // Abstract method - must be implemented by subclasses
    public abstract double calculateTariff();

    // Concrete method
    public void displayRoomDetails() {
        System.out.println("Room Number: " + roomNumber);
        System.out.println("Base Price: $" + basePrice);
        System.out.println("Total Tariff: $" + calculateTariff());
    }

    // Getters
    public int getRoomNumber() {
        return roomNumber;
    }

    public double getBasePrice() {
        return basePrice;
    }
}

// Interface Amenities
interface Amenities {
    void provideWifi();
    void provideBreakfast();
}

// StandardRoom class - extends abstract Room and implements Amenities
class StandardRoom extends Room implements Amenities {
    private boolean hasAC;
    private boolean wifiAvailable;
    private boolean breakfastAvailable;
    private static final double AC_CHARGE = 25.0;

    public StandardRoom(int roomNumber, double basePrice, boolean hasAC, 
                       boolean wifiAvailable, boolean breakfastAvailable) {
        super(roomNumber, basePrice);
        this.hasAC = hasAC;
        this.wifiAvailable = wifiAvailable;
        this.breakfastAvailable = breakfastAvailable;
    }

    // Implement abstract method from Room
    @Override
    public double calculateTariff() {
        double totalTariff = basePrice;
        if (hasAC) {
            totalTariff += AC_CHARGE;
        }
        return totalTariff;
    }

    // Implement interface methods
    @Override
    public void provideWifi() {
        if (wifiAvailable) {
            System.out.println("Free Wi-Fi is available in this Standard Room");
        } else {
            System.out.println("Wi-Fi is not available in this Standard Room");
        }
    }

    @Override
    public void provideBreakfast() {
        if (breakfastAvailable) {
            System.out.println("Complimentary breakfast is provided");
        } else {
            System.out.println("Breakfast is not included. Available at $15 extra");
        }
    }

    @Override
    public void displayRoomDetails() {
        System.out.println("\n=== Standard Room Details ===");
        super.displayRoomDetails();
        System.out.println("Air Conditioning: " + (hasAC ? "Yes" : "No"));
    }
}

// LuxuryRoom class - extends abstract Room and implements Amenities
class LuxuryRoom extends Room implements Amenities {
    private boolean hasAC;
    private boolean hasMiniBar;
    private boolean hasJacuzzi;
    private boolean wifiAvailable;
    private boolean breakfastAvailable;
    private static final double AC_CHARGE = 30.0;
    private static final double MINIBAR_CHARGE = 75.0;
    private static final double JACUZZI_CHARGE = 150.0;

    public LuxuryRoom(int roomNumber, double basePrice, boolean hasAC, 
                     boolean hasMiniBar, boolean hasJacuzzi,
                     boolean wifiAvailable, boolean breakfastAvailable) {
        super(roomNumber, basePrice);
        this.hasAC = hasAC;
        this.hasMiniBar = hasMiniBar;
        this.hasJacuzzi = hasJacuzzi;
        this.wifiAvailable = wifiAvailable;
        this.breakfastAvailable = breakfastAvailable;
    }

    // Implement abstract method from Room
    @Override
    public double calculateTariff() {
        double totalTariff = basePrice;
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

    // Implement interface methods
    @Override
    public void provideWifi() {
        if (wifiAvailable) {
            System.out.println("High-speed Premium Wi-Fi is available in this Luxury Room");
        } else {
            System.out.println("Wi-Fi is not available in this Luxury Room");
        }
    }

    @Override
    public void provideBreakfast() {
        if (breakfastAvailable) {
            System.out.println("Gourmet breakfast buffet is included");
        } else {
            System.out.println("Breakfast is not included. Gourmet options available at $30 extra");
        }
    }

    @Override
    public void displayRoomDetails() {
        System.out.println("\n=== Luxury Room Details ===");
        super.displayRoomDetails();
        System.out.println("Air Conditioning: " + (hasAC ? "Yes" : "No"));
        System.out.println("Mini Bar: " + (hasMiniBar ? "Yes" : "No"));
        System.out.println("Jacuzzi: " + (hasJacuzzi ? "Yes" : "No"));
    }
}

// Main class
public class RoomAbstract {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("Hotel Room Management System");
        System.out.println("Demonstrating Abstraction and Interfaces");
        System.out.println("============================================");

        // Creating objects using base class reference (abstraction)
        Room room1 = new StandardRoom(101, 100.0, true, true, false);
        Room room2 = new StandardRoom(102, 100.0, false, false, false);
        Room room3 = new LuxuryRoom(201, 250.0, true, true, true, true, true);
        Room room4 = new LuxuryRoom(202, 250.0, true, true, false, true, false);

        // Array of Room references
        Room[] rooms = {room1, room2, room3, room4};

        // Display details and invoke methods
        for (Room room : rooms) {
            room.displayRoomDetails();
            
            // Check if room implements Amenities interface
            if (room instanceof Amenities) {
                Amenities amenities = (Amenities) room;
                amenities.provideWifi();
                amenities.provideBreakfast();
            }
            System.out.println("--------------------------------------------");
        }

        // Demonstrating interface-based design
        System.out.println("\n============================================");
        System.out.println("Amenities Demonstration (Interface-based)");
        System.out.println("============================================");

        // Using interface reference
        Amenities standardAmenities = new StandardRoom(103, 120.0, true, true, true);
        System.out.println("\nStandard Room Amenities:");
        standardAmenities.provideWifi();
        standardAmenities.provideBreakfast();

        Amenities luxuryAmenities = new LuxuryRoom(203, 300.0, true, true, true, true, true);
        System.out.println("\nLuxury Room Amenities:");
        luxuryAmenities.provideWifi();
        luxuryAmenities.provideBreakfast();

        // Demonstrating that abstract class cannot be instantiated
        // Room room = new Room(999, 500.0); // This would cause compilation error
        System.out.println("\n============================================");
        System.out.println("Note: Abstract Room class cannot be instantiated directly");
        System.out.println("It must be extended by concrete classes");
        System.out.println("============================================");
    }
}