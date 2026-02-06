package LearningMultithreading.BasicMultiThreading;

public class JoinThreadExample {
    
    public static void main(String[] args){

        Thread one = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread One: "+ i); 
            }
        }
    );
    }
}
