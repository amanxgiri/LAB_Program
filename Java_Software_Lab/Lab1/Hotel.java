package Lab1;

// 2. Create a base class named Room to represent general room details in a hotel. The 
// class should contain data members such as room number, room type, and base 
// price. Implement multiple constructors (constructor overloading) in the Room 
// class to initialize room objects in different ways, such as: 
// i.  Initializing only the room number and type
// ii. Initializing room number, type, and base price 
// 
// iii.Create a derived class named DeluxeRoom that inherits from the Room class 
// using single inheritance. The derived class should include additional data 
// members such as free Wi-Fi availability and complimentary breakfast. 
// Implement appropriate constructors in the derived class that invoke the base 
// class constructors using the super keyword.
// 
// iv. Create a main class to instantiate objects of both Room and DeluxeRoom using 
// different constructors and display the room details. This application should 
// clearly illustrate constructor overloading and inheritance. 

class Room {

    private int roomNumber;
    private String roomType;
    private double basePrice;

    public Room(int roomNumber, String roomType) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.basePrice = 10.0;
    }

    public Room(int roomNumber, String roomType, double basePrice) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.basePrice = basePrice;
    }

    public int getRoomNumber() {
        return roomNumber;
    }

    public String getRoomType() {
        return roomType;
    }

    public double getBasePrice() {
        return basePrice;
    }

    public void displayDetails() {
        System.out.println("Room Number: " + roomNumber);
        System.out.println("Room Type: " + roomType);
        System.out.println("Base Price: " + basePrice);

    }

}

class DeluxeRoom extends Room {

    public boolean isWifiAvailable;
    public boolean complimentaryBreakfast;

    public DeluxeRoom(int roomNumber, String roomType, boolean isWifiAvailable, boolean complimentaryBreakfast) {
        super(roomNumber, roomType);
        this.isWifiAvailable = isWifiAvailable;
        this.complimentaryBreakfast = complimentaryBreakfast;
    }

    public DeluxeRoom(int roomNumber, String roomType,
            double basePrice, boolean isWifiAvailable, boolean complimentaryBreakfast) {
        super(roomNumber, roomType, basePrice);
        this.isWifiAvailable = isWifiAvailable;
        this.complimentaryBreakfast = complimentaryBreakfast;
    }

    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Free Wifi: " + (isWifiAvailable ? "Yes" : "No"));
        System.out.println("Free Breakfast: " + (complimentaryBreakfast ? "Yes" : "No"));
    }
}

public class Hotel {

    public static void main(String[] args) {

        Room standardRoom = new Room(101, "Standard");
        Room suiteRoom = new Room(201, "Suite", 2100);

        DeluxeRoom deluxStandardRoom = new DeluxeRoom(301, "Deluxe", false, false);
        DeluxeRoom deluxSuiteRoom = new DeluxeRoom(308, "Delux Suite", 690000, true, true);

        standardRoom.displayDetails();
        suiteRoom.displayDetails();

        deluxStandardRoom.displayDetails();
        deluxSuiteRoom.displayDetails();
    }
}
