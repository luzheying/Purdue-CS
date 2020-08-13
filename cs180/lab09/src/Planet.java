public class Planet {
    private double mass;
    private double radius;
    private String name;
    private double distFromSun;

    public Planet(double mass, double radius, String name, double distFromSun) throws PlutoNotAPlanetException {
        this.mass = mass;
        this.radius = radius;
        this.name = name;
        if (name.contains("pluto")) {
            throw new PlutoNotAPlanetException("Sorry Pluto...");
        }
        this.distFromSun = distFromSun;
    }

    public double getVolume() {
        return (4.0/3.0)*Math.PI*Math.pow(this.radius,3);
    }

    public double getDensity() {
        return this.mass / getVolume();
    }

    public String getName() {
        return this.name;
    }

    public double getDistFromSun() {
        return this.distFromSun;
    }

    public double distToPlanet(Planet otherPlanet) {
        return Math.abs(this.distFromSun - otherPlanet.distFromSun);
    }

    public void printInfo() {
        System.out.println(String.format("This is the planet %s. It is %.2f AU from the Sun. It has a density of %.2f kg/m^3",getName(),getDistFromSun(),getDensity()));
    }

    public static void main(String[] args) {

    }
}
