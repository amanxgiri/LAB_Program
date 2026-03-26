
public class DemoWrapper {

    public static void main(String args[]) {

        // boxing
        int i = 10;
        Integer iob1_boxing = Integer.valueOf(i);
        Integer iob1_autoboxing = i; // autoboxing because the compiler will automatically put the vlaue of method

        // unboxing
        Integer integerObject = Integer.valueOf(100);

        int iPrimitive1 = integerObject.intValue(); // unboxing
        int iPrimitive2 = integerObject;

        // printing out
        System.out.println("--------- Boxing ------------");
        System.out.println("Integer Value : " + i);
        System.out.println("Boxed Value :" + iob1_boxing);
        System.out.println("Autoboxed Value : " + iob1_autoboxing);

        System.out.println("--------- Unboxing ------------");
        System.out.println("Integer Object  Value : " + integerObject);
        System.out.println("UnBoxed Value :" + iPrimitive1);
        System.out.println("AutoUnboxed Value : " + iPrimitive2);
    }
}