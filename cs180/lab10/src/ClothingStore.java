import java.util.ArrayList;

public class ClothingStore extends Shop {

    ArrayList<String> menu = new ArrayList<>();

    public ClothingStore() {
        menu.add("Nothing to eat here!");
    }

    public void serve() {
        System.out.println("We don't serve anything here. If you want to buy some clothes though, feel free to!");
        for (String s : menu) {
            System.out.println(s);
        }
    }
}
