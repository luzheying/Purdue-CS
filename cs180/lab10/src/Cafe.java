import java.util.ArrayList;

public class Cafe extends Shop {

    ArrayList<String> menu = new ArrayList<>();

    public Cafe() {
        menu.add("Croissants");
        menu.add("Iced Coffee");
        menu.add("Bagels and Cream Cheese");
        menu.add("Chicken and Avocado Sandwich");
        menu.add("Roast Beef Sandwich");
        menu.add("Tea");
        menu.add("Black Coffee");
        menu.add("Chicken Cobb Salad");
    }

    @Override
    void serve() {
        System.out.println("We serve a variety of food! Here is what we serve.");
        for (String s : menu) {
            System.out.println(s);
        }
    }
}
