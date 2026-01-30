package Lab5;


import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Q2FileReadAndCopy {
    public static void main(String[] args) {
        FileInputStream fis = null;
        FileOutputStream fos = null;

        try {
            // Open source file and destination file
            fis = new FileInputStream("source.txt");
            fos = new FileOutputStream("destination.txt");

            int data;
            // Read and write byte by byte
            while ((data = fis.read()) != -1) {
                fos.write(data);
            }

            System.out.println("File copied successfully.");

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        } finally {
            try {
                if (fis != null) {
                    fis.close();
                }
                if (fos != null) {
                    fos.close();
                }
            } catch (IOException e) {
                System.out.println("Error closing file");
            }
        }
    }
}

    
}
