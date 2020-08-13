public class Pet {

    private String species;
    private String age;
    private String name;

    public static int petCounter;

    Pet(String species, String age, String name) {
        this.species = species;
        this.name = name;
        this.age = age;
    }

    public void printDetails () {
        System.out.println("\nName: " + this.name + "\nSpecies: " + this.species + "\nAge: " + this.age);
    }

}
