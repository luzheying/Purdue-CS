public class IceGiant extends Planet{
    private String spacecraftVisited;

    public IceGiant(double mass, double radius, String name, double distFromSun, String spacecraftVisited) throws PlutoNotAPlanetException{
        super(mass, radius, name, distFromSun);
        this.spacecraftVisited = spacecraftVisited;
    }

    public String getSpacecraftVisited() {
        return spacecraftVisited;
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println(String.format("This ice giant has been visited by the %s",spacecraftVisited));
    }
}
