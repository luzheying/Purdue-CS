public class Star{
    private String name;
    private double magnitude;
    private double lightyearsFromEarth;
    private boolean planetsOrbiting;

    public Star(String name, double magnitude, double lightyearsFromEarth, boolean planetsOrbiting) {
        this.name = name;
        this.magnitude = magnitude;
        this.lightyearsFromEarth = lightyearsFromEarth;
        this.planetsOrbiting = planetsOrbiting;
    }

    public String getName() {
        return name;
    }

    public double getMagnitude() {
        return magnitude;
    }


    public double getLightyearsFromEarth() {
        return lightyearsFromEarth;
    }

    public boolean getPlanetsOrbiting() {
        return this.planetsOrbiting;
    }

}
