public class Rectangle {

    private double length;
    private double width;
	
 	//TODO: implement Rectangle constructor
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

	//TODO: implement getPerimeter method
    double getPerimeter() {
        return this.length*2 + this.width*2;
    }
    
	//TODO: implement getArea method
    double getArea() {
        return this.length * this.width;
    }
}