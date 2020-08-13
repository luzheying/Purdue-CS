import java.util.Scanner;

public class MenuRunner {

    private static Shop shop;

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        String input;
        System.out.println("What store would you like to know the menu options of?");
        System.out.println("Type either Cafe, Restaurant, or Clothing Store");
        System.out.println();
        input = s.nextLine();
        switch (input) {
            case "Cafe":
                shop = new Cafe();
                shop.serve();
                break;
            case "Restaurant":
                shop = new Restaurant();
                shop.serve();
                break;
            case "Clothing Store":
                shop = new ClothingStore();
                shop.serve();
                break;
            default:
                System.out.println("That's not a valid input!");
                break;
        }
    }
}
