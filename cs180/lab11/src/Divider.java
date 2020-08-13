import java.util.TreeMap;

public class Divider implements Runnable {
    static int counter = 0;
    private int start = 0;
    private int end = 0;

    public Divider(int start, int end) {
//        for (int i = start; i < end+1; i++) {
//            if (i % 7 == 0) {
//                counter++;
//            }
//        }
        this.start = start;
        this.end = end;
    }

    public synchronized void run() {
        for (int i = this.start; i < this.end+1; i++) {
            if (i!= 0 && i % 7 == 0) {
                counter++;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Runnable r1 = new Divider(0,10000);
        Runnable r2 = new Divider(10001,20000);
        Runnable r3 = new Divider(20001,30000);
        Thread t1 = new Thread(r1);
        Thread.yield();
        Thread t2 = new Thread(r2);
        Thread.yield();
        Thread t3 = new Thread(r3);
        Thread.yield();
        t1.start();
        t1.join();
        t2.start();
        t2.join();
        t3.start();
       // t1.join();
       // t2.join();
        t3.join();
        System.out.println(counter);
    }
}
