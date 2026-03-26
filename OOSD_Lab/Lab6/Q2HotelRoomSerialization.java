import java.io.Serializable;

public class Room implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private int roomNumber;
    private String roomType;
    private double pricePerNight;
    private boolean bookingStatus; // true = booked, false = available
    private String guestName;
    
    public Room(int roomNumber, String roomType, double pricePerNight, 
                boolean bookingStatus, String guestName) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.pricePerNight = pricePerNight;
        this.bookingStatus = bookingStatus;
        this.guestName = guestName;
    }
    
    // Getters
    public int getRoomNumber() {
        return roomNumber;
    }
    
    public String getRoomType() {
        return roomType;
    }
    
    public double getPricePerNight() {
        return pricePerNight;
    }
    
    public boolean isBooked() {
        return bookingStatus;
    }
    
    public String getGuestName() {
        return guestName;
    }
    
    // Setters
    public void setRoomNumber(int roomNumber) {
        this.roomNumber = roomNumber;
    }
    
    public void setRoomType(String roomType) {
        this.roomType = roomType;
    }
    
    public void setPricePerNight(double pricePerNight) {
        this.pricePerNight = pricePerNight;
    }
    
    public void setBookingStatus(boolean bookingStatus) {
        this.bookingStatus = bookingStatus;
    }
    
    public void setGuestName(String guestName) {
        this.guestName = guestName;
    }
    
    @Override
    public String toString() {
        return String.format(
            "Room Number: %d\n" +
            "Room Type: %s\n" +
            "Price per Night: $%.2f\n" +
            "Booking Status: %s\n" +
            "Guest Name: %s\n" +
            "----------------------------------------",
            roomNumber,
            roomType,
            pricePerNight,
            bookingStatus ? "BOOKED" : "AVAILABLE",
            bookingStatus ? guestName : "N/A"
        );
    }
}
public class Q2HotelRoomSerialization {

}
