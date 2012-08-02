public class BoxDemo2 {

    public static void main(String[] args) {

        // ONLY place Integer objects 
        // into this box!
        Box_1 integerBox = new Box_1();

        // Imagine this is one part of 
        // a large application
        // modified by one programmer. 
        // Note how the type is now 
        // String.
        integerBox.add("10");

        // ... and this is another, 
        // perhaps written by a 
        // different programmer
        String someInteger 
            = (String)integerBox.get();
        System.out.println(someInteger);
    }
}
