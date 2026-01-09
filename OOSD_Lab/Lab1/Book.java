package Lab1;

import java.util.Scanner;

public class Book {

    private int bookID;
    private String title;
    private String author;
    private double price;
    private boolean status;

    // Set all values
    public void setBookID(int bookID) {
        this.bookID = bookID;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setPrice(double price) {
        if (price > 0) {
            this.price = price;
        } else {
            System.out.println("Price Can't Be Negative!");
            System.out.println("Try Again!");
        }
    }

    public void setAvailabilityStatus(boolean availabilityStatus) {
        this.status = availabilityStatus;
    }

    // all the get methods
    public int getBookID() {
        return bookID;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public double getPrice() {
        return price;
    }

    public boolean getStatus() {
        return status;
    }

    public void displayBookInfo() {
        System.out.println("Book ID: " + bookID);
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: $" + price);
        System.out.println("Available: " + (status ? "Yes" : "No"));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Book book = new Book();

        System.out.println("Enter BookId: ");
        book.setBookID(sc.nextInt());
        sc.nextLine();

        System.out.println("Enter Author: ");
        book.setAuthor(sc.nextLine());

        System.out.println("Enter title: ");
        book.setTitle(sc.nextLine());

        System.out.println("Enter Price");
        book.setPrice(sc.nextDouble());

        System.out.println("Enter Status: ");
        book.setAvailabilityStatus(sc.nextBoolean());

        book.displayBookInfo();

        sc.close();
    }
}
