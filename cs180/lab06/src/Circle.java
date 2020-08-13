public class Circle {

    private double radius;

    public Circle(double radius) {
        //TODO: implement Circle constructor
        this.radius = radius;
    }

    public double getCircumference() {
        //TODO: implement method
        return 2 * Math.PI * this.radius;
    }

    public double getArea() {
        //TODO: implement method
        return Math.PI * Math.pow(this.radius, 2);
    }

}