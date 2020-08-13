import java.util.concurrent.atomic.AtomicInteger;

public class Counter1 implements Counter{
    private int value = 0;

    public synchronized void inc() {
        value = value + 1;
    }

    public synchronized void dec() {
        value = value - 1;
    }

    public int get() {
        return value;
    }
}
