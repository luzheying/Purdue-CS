public class Driver {
    public static void main(String[] args) {
        Thread ta = new A();
        ta.start();

        Runnable r = new B();
        Thread tb = new Thread(r);
        tb.start();
    }
}
