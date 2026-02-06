package Lab5;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Q2FileReadAndCopy {
    public static void main(String[] args) {
        FileReader fr = null;
        FileWriter fw = null;

        try {
            // Open source and destination text files
            fr = new FileReader("input.txt");
            fw = new FileWriter("output.txt");

            int ch;
            // Read and write character by character
            while ((ch = fr.read()) != -1) {
                fw.write(ch);
            }

            System.out.println("Text copied successfully.");

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        } finally {
            try {
                if (fr != null) {
                    fr.close();
                }
                if (fw != null) {
                    fw.close();
                }
            } catch (IOException e) {
                System.out.println("Error closing file");
            }
        }
    }
}
