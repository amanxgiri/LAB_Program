
enum RoomType {
    STANDARD(2000),
    DELUXE(3000),
    SUITE(5000);

    private int baseTrafficValue;

    private RoomType(int baseTrafficValue) {
        this.baseTrafficValue = baseTrafficValue;
    }

    public int getRoomTrafficValue() {
        return baseTrafficValue;
    }
}

public class Q2HotelEnum {

    public static void main(String args[]) {
        RoomType standard = RoomType.STANDARD;

        int baseValue = standard.getRoomTrafficValue();

        int noOfStays = 10;

        System.out.println("Room Type: " + standard);
        System.out.println("Base Traffice Value: " + standard.getRoomTrafficValue());
        System.out.println("Day your Staying: " + noOfStays);
        System.out.println("Your Total Room Traffic: " + noOfStays * standard.getRoomTrafficValue());
    }
}
