import java.util.Scanner;

public class DebugPets {

    public static void main (String[] args)
    {

        boolean isMenuActive = true;  // Flag for the menu loop
        Scanner s = new Scanner(System.in);

        // Create the new pets
        Pet skippy = new Pet("poodle","9","skippy");
        Pet.petCounter++;
        Pet jack = new Pet("Shiba Inu","4","Jack");
        Pet.petCounter++;
        Pet mark = new Pet("Cairn Terrier", "7", "Mark");
        Pet.petCounter = 3;

        System.out.println("Hello! What's your name?");
        String name = s.nextLine();
        int totalPrice = 0;

        // Loop for the menu
        while (isMenuActive) {
            System.out.println("--       Menu       --");
            System.out.println("1. Adopt a pet \n2. Buy a pet toy \n3. Donate supplies \n4. " +
                    "Quit\n");
            int userChoice = s.nextInt();

            // Switch based on the user choice from the menu
            switch(userChoice) {
                case 1:
                    System.out.println("Here are the pets we have in the system: ");

                    // Print pet details
                    skippy.printDetails();
                    jack.printDetails();
                    mark.printDetails();
                    System.out.println("How many pets do you want to adopt? There is " + Pet.petCounter + " available.");
                    int numPets = s.nextInt();
                    totalPrice+= adoptPet(numPets);
                    isMenuActive = true;
                    break;
                case 2:
                    System.out.println("How many toys do you want?");
                    int numToys = s.nextInt();
                    totalPrice += buyPetToy(numToys);
                    isMenuActive = true;
                    break;
                case 3:
                    donateSupplies(name);
                    isMenuActive = true;
                    break;
                case 4:
                    isMenuActive = false;
                    break;
                default:
                    System.out.println("Enter an integer corresponding with a menu option!");
                    isMenuActive = true;
            }
        }

        System.out.println("Thank you, " + name + "! You spent $" + totalPrice + ".");

    }


    
    //Calculates the adoption fee for pets and updates the number of pets
    //after processing adoption.

    //@param numPets number of pets the user wants to adopt
    //@return returns the calculated adoption fee.
     

   public static int adoptPet(int numPets) {
        int price = 0;

        // Verify pets are available and user request is nonnegative.
        if(numPets > 0 && numPets <= Pet.petCounter) {

            System.out.println("The adoption fee is $100 per pet.");
            price = numPets * 100;
            Pet.petCounter -= numPets;
        }
        else if(numPets <= 0) {
            System.out.println("Please enter a number greater than 0");
        }
        else {
            System.out.println("We do not have that many pets available.");
        }

        return price;
    }

    
    //Calculates the total price of the pet toys the user wants to purchase.

    //@param numToys the number of toys the user wants to purchase
    //@return the total price of the number of toys the user is purchasing.
    

   public static int buyPetToy(int numToys) {
        int price = 0;

        if (numToys > 0) {
            System.out.println("The price is $5 per toy.");
            price = numToys * 5;
        }
        else {
            System.out.println("Please enter a number greater than 0");
        }

        return price;

    }

    
    //Thanks the user for donating supplies
    //@param name the user's name
     

    public static void donateSupplies(String name) {
        System.out.println(String.format("Thank you for your contribution, %s!", name));
    }
}
