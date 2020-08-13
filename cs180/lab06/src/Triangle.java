public class Triangle {

    private double base;

    //TODO: implement Triangle constructor
    public Triangle(double base) {
        this.base = base;
    }

	//TODO: implement getPerimeter method
    double getPerimeter(){
        return this.base * 3;
    }

	//TODO: implement getArea method
    double getArea() {
        return Math.sqrt(3)*this.base*this.base/4;
    }

}