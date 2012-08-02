import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class SimpleArray {

  public static void main(String[] args) {
    int array[] = {1, 2, 3, 4, 5};
    ArrayList<String> arrlist = new ArrayList<String>();
    arrlist.add("Mohanraj");
    Map<Object, String> map = new HashMap<Object, String>();
    map.put(new String("Mohanraj"), "Mohanraj");

    System.out.println(array[0]);
    System.out.println(arrlist.get(0));
  }
}
