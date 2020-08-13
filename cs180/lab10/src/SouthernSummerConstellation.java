public class SouthernSummerConstellation extends StellarGrouping{

    public SouthernSummerConstellation(String name, Star[] stars) {
        super(name, stars);
    }

    @Override
    boolean isVisible(Month month) {
        if(month.equals(Month.APRIL) || month.equals(Month.MAY)|| month.equals(Month.JUNE)|| month.equals(Month.JULY)|| month.equals(Month.AUGUST)
       || month.equals(Month.SEPTEMBER)|| month.equals(Month.OCTOBER)|| month.equals(Month.NOVEMBER)) {
            return true;
        }
        return false;
    }

    @Override
    String planetsOrbiting() {
        for(Star s: super.getStars()) {
            if(s.getPlanetsOrbiting()) {
                return "Yes";
            }
        }
        return "Unknown";
    }
}
