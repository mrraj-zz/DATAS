public class BoxDemo1 {

    public static void main(String[] args) {

        // ONLY place Integer objects 
        // into this box!
        Box_1 integerBox = new Box_1();

        integerBox.add(new Integer(10));
        Integer someInteger = (Integer)integerBox.get();
        System.out.println(someInteger);
    }
}
