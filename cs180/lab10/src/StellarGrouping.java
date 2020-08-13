public abstract class StellarGrouping {
    private String name;
    private Star[] Stars;

    public StellarGrouping(String name, Star[] stars) {
        this.name = name;
        this.Stars = stars;
    }

    String planetsOrbiting() {
        return "Unknown";
    }

    Star brightestStar() {
        double lowest= Stars[0].getMagnitude();
        Star re = Stars[0];
        for(Star s : Stars) {
            if (s.getMagnitude() < lowest) {
                lowest = s.getMagnitude();
                re = s;
            }
        }
        return re;
    }

    abstract boolean isVisible(Month month);

    double distanceFromEarth(String starName) {
        for(Star s: Stars) {
            if (s.getName().equals(starName)) {
                return s.getLightyearsFromEarth() * 5.878625;
            }
        }
        return -1;
    }

    double distanceFromEarth(Star s) {
        for(Star star: Stars) {
            if (star == s ) {
                return star.getLightyearsFromEarth() * 5.878625;
            }
        }
        return -1;
    }

    double furthestStar() {
        double furthest = distanceFromEarth(Stars[0]);
        for( Star s: Stars) {
            if ( distanceFromEarth(s) > furthest) {
                furthest = distanceFromEarth(s);
            }
        }
        return furthest;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Star[] getStars() {
        return Stars;
    }

    public void setStars(Star[] stars) {
        Stars = stars;
    }
}