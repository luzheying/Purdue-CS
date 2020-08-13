public class A extends Thread{
    public void run() {
        while (true) {
            System.out.println("A");
        }
    }

    public static void main(String[] args) {
        Thread ta = new A();
        Thread.yield();
        ta.start();
    }
}
