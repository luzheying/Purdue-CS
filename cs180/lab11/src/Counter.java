import java.util.concurrent.atomic.AtomicInteger;

interface Counter {
    void inc();	// add one to my value
    void dec(); // subtract one from my value
    int get();  // get my value
}
