import java.util.Scanner;

public abstract class Shop {
    abstract void serve();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("What store would you like to know the menu options of?");
        System.out.println("Type either Cafe, Restaurant, or Clothing Store");
        System.out.println("");
        String input = sc.nextLine();
        if (input.equals("Cafe")) {
            Shop cafe = new Cafe();
            cafe.serve();
        } else if(input.equals("Restaurant")) {
            Shop res = new Restaurant();
            res.serve();
        } else if (input.equals("Clothing Store")) {
            Shop clo =  new ClothingStore();
            clo.serve();
        } else {
            System.out.println("That's not a valid input!");
        }
    }

}
