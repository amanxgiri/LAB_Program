
import java.io.RandomAccessFile;
import java.io.IOException;

public class RandomAccessFileDemo {

    public static void main(String[] args) {
        try {
            RandomAccessFile raf = new RandomAccessFile("Data.dat", "rw");

            raf.writeInt(101);
            raf.writeUTF("John Doe");
            raf.writeDouble(99.5);
            raf.seek(0);

            int id = raf.readInt();
            String name = raf.readUTF();
            double marks = raf.readDouble();

            System.out.println("ID: " + id);
            System.out.println("Name: " + name);
            System.out.println("Marks: " + marks);

            raf.seek(4);

            System.out.println("Name(Random Access): " + raf.readUTF());

            raf.close();
        } catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}
