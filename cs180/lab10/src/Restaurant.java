import java.util.ArrayList;

public class Restaurant extends Shop {

    public ArrayList<String> menu = new ArrayList<>();

    public Restaurant() {
        menu.add("Burger and Fries");
        menu.add("Baked Tilapia");
        menu.add("Chicken Sandwich");
        menu.add("Carved Ham Sandwich");
        menu.add("Spaghetti and Meatballs");
        menu.add("Pasta Carbonara");
        menu.add("Breadsticks");
        menu.add("French Onion Soup");
        menu.add("Rack of Ribs");
        menu.add("Chicken Tenders");
    }

    public void serve() {
        System.out.println("Welcome to the CS180 Restaurant! We serve many large items that can be had as a family.");
        for (String s : menu) {
            System.out.println(s);
        }
    }

}
