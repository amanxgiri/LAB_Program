import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class Q1HotelRoomRAF {

    private static final String FILE_NAME = "rooms.dat";
    private static final int ROOM_TYPE_LEN = 20;
    private static final int RECORD_SIZE = 4 + (ROOM_TYPE_LEN * 2) + 8 + 1;
    private static final int BASE_ROOM_NO = 101;

    private static void writeFixedString(RandomAccessFile raf, String s, int len) throws IOException {
        StringBuilder sb = new StringBuilder(s == null ? "" : s.trim());
        if (sb.length() > len)
            sb.setLength(len);
        while (sb.length() < len)
            sb.append(' ');
        // Write exactly len chars
        for (int i = 0; i < len; i++) {
            raf.writeChar(sb.charAt(i));
        }
    }

    private static String readFixedString(RandomAccessFile raf, int len) throws IOException {
        StringBuilder sb = new StringBuilder(len);
        for (int i = 0; i < len; i++) {
            sb.append(raf.readChar());
        }
        return sb.toString().trim();
    }

    private static long positionOf(int roomNumber) {
        return (long) (roomNumber - BASE_ROOM_NO) * RECORD_SIZE;
    }

    private static boolean isValidRoomNo(int roomNumber) {
        return roomNumber >= BASE_ROOM_NO;
    }

    private static boolean recordExists(int roomNumber) throws IOException {
        if (!isValidRoomNo(roomNumber))
            return false;
        try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "r")) {
            long pos = positionOf(roomNumber);
            return pos >= 0 && (pos + RECORD_SIZE) <= raf.length();
        } catch (IOException e) {
            // file may not exist yet
            return false;
        }
    }


    private static void addRoom(Scanner sc) {
        System.out.print("Enter Room Number (>= " + BASE_ROOM_NO + "): ");
        int roomNo = sc.nextInt();
        sc.nextLine();

        if (!isValidRoomNo(roomNo)) {
            System.out.println("Invalid room number.");
            return;
        }

        try {
            if (recordExists(roomNo)) {
                System.out.println("Room already exists. Use update booking status instead.");
                return;
            }

            System.out.print("Enter Room Type (max 20 chars): ");
            String type = sc.nextLine();

            System.out.print("Enter Price per Night: ");
            double price = sc.nextDouble();
            sc.nextLine();

            System.out.print("Is Booked? (true/false): ");
            boolean booked = sc.nextBoolean();
            sc.nextLine();

            try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "rw")) {
                long pos = positionOf(roomNo);

                // If someone adds room 200 directly, we may need to expand the file.
                // We'll fill missing records with "empty" defaults.
                long requiredLen = pos + RECORD_SIZE;
                if (raf.length() < requiredLen) {
                    raf.setLength(requiredLen);
                }

                raf.seek(pos);

                // Write in SAME order always
                raf.writeInt(roomNo);
                writeFixedString(raf, type, ROOM_TYPE_LEN);
                raf.writeDouble(price);
                raf.writeBoolean(booked);

                System.out.println("Room added successfully.");
            }
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }

    private static void displayRoom(Scanner sc) {
        System.out.print("Enter Room Number to display: ");
        int roomNo = sc.nextInt();
        sc.nextLine();

        if (!isValidRoomNo(roomNo)) {
            System.out.println("Invalid room number.");
            return;
        }

        try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "r")) {
            long pos = positionOf(roomNo);

            if (pos < 0 || pos + RECORD_SIZE > raf.length()) {
                System.out.println("Room not found.");
                return;
            }

            raf.seek(pos);

            int rn = raf.readInt();
            String type = readFixedString(raf, ROOM_TYPE_LEN);
            double price = raf.readDouble();
            boolean booked = raf.readBoolean();

            // If this slot was never actually written, rn might be 0.
            if (rn == 0) {
                System.out.println("Room not found.");
                return;
            }

            System.out.println("\n--- Room Details ---");
            System.out.println("Room Number     : " + rn);
            System.out.println("Room Type       : " + type);
            System.out.println("Price per Night : " + price);
            System.out.println("Booked          : " + booked);
            System.out.println("--------------------\n");

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }

    private static void updateBookingStatus(Scanner sc) {
        System.out.print("Enter Room Number to update: ");
        int roomNo = sc.nextInt();
        sc.nextLine();

        if (!isValidRoomNo(roomNo)) {
            System.out.println("Invalid room number.");
            return;
        }

        System.out.print("Enter new status (true = book, false = vacate): ");
        boolean newStatus = sc.nextBoolean();
        sc.nextLine();

        try (RandomAccessFile raf = new RandomAccessFile(FILE_NAME, "rw")) {
            long pos = positionOf(roomNo);

            if (pos < 0 || pos + RECORD_SIZE > raf.length()) {
                System.out.println("Room not found.");
                return;
            }

            raf.seek(pos);

            int rn = raf.readInt();
            String type = readFixedString(raf, ROOM_TYPE_LEN);
            double price = raf.readDouble();
            boolean oldStatus = raf.readBoolean();

            if (rn == 0) {
                System.out.println("Room not found.");
                return;
            }

            long bookedPos = pos + 4 + (ROOM_TYPE_LEN * 2) + 8;
            raf.seek(bookedPos);
            raf.writeBoolean(newStatus);

            System.out.println("Booking status updated: " + oldStatus + " -> " + newStatus);

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("====== Hotel Room Booking (RandomAccessFile) ======");
            System.out.println("1. Add new room record");
            System.out.println("2. Display specific room details");
            System.out.println("3. Update booking status (book/vacate)");
            System.out.println("4. Exit");
            System.out.print("Choose option: ");

            int choice;
            try {
                choice = Integer.parseInt(sc.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("Enter a valid number.\n");
                continue;
            }

            switch (choice) {
                case 1 -> addRoom(sc);
                case 2 -> displayRoom(sc);
                case 3 -> updateBookingStatus(sc);
                case 4 -> {
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                }
                default -> System.out.println("Invalid choice.\n");
            }
        }
    }
}
