import java.util.Timer;
import java.util.TimerTask;

public class TimerClass {
    public static void main(String[] args) {

    Timer timer=  new Timer();

    int startingTime=10000; //millisecond 10 seconds=10000
    int delayTime=1000; // millisecond 1 second
     timer.schedule(new TimerTask()
       {
        public void run() {
         System.out.println("Timer repeat statement");
        }
      },startingTime,delayTime);

    }
}
