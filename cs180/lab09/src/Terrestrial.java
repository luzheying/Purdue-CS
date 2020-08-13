public class Terrestrial extends Planet {
    private String habitability;

    public Terrestrial(double mass, double radius, String name, double distFromSun, String habitability) throws PlutoNotAPlanetException{
        super(mass, radius, name, distFromSun);
        this.habitability = habitability;
    }

    public String getHabitability() {
        return this.habitability;
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println(String.format("This terrestrial planet is %s",getHabitability()));
    }
}
