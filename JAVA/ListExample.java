import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

public class ListExample {

    public static void main(String[] args) {

        // List Example implement with ArrayList
        List<String> ls=new ArrayList<String>();

        ls.add("one");
        ls.add("Three");
        ls.add("two");
        ls.add("four");
	ls.map { names => 
          System.out.println(names);
	}

        Iterator it=ls.iterator();

        while(it.hasNext())
        {
          String value=(String)it.next();

          System.out.println("Value :"+value);
        }
    }
}
