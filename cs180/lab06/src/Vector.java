public class Vector {
    double x,y,z;
    
    Vector (){
        this.x = this.y = this.z = 0.0;
    }
    
 	//TODO: implement constructor
    Vector(double x, double y, double z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    public Vector add(final Vector v){
     	//TODO: implement method
        Vector output = new Vector();
        output.x = this.x + v.x;
        output.y = this.y + v.y;
        output.z = this.z + v.z;
        return output;
    }
    
    public Vector sub(final Vector v){
     	//TODO: implement method
        Vector output = new Vector();
        output.x = this.x - v.x;
        output.y = this.y - v.y;
        output.z = this.z - v.z;
        return output;
    }
    
    public Vector multC(final double v){
     	//TODO: implement method
        Vector output = new Vector();
        output.x = this.x*v;
        output.y = this.y*v;
        output.z = this.z*v;
        return output;
    }
    
    public Vector mult(final Vector v){
     	//TODO: implement method
        Vector output = new Vector();
        output.x = this.x*v.x;
        output.y = this.y*v.y;
        output.z = this.z*v.z;
        return output;
    }
    
    public Vector norm(){
     	//TODO: implement method
        Vector output = new Vector();
        double length = Math.sqrt(Math.pow(this.x,2) + Math.pow(this.y,2) + Math.pow(this.z,2));
        output.x = this.x/ length;
        output.y = this.y/ length;
        output.z = this.z/ length;
        return output;
    }
    
    public double dot(final Vector v){
        //TODO: implement method
        double output = 0.0;
        output = this.x*v.x + this.y*v.y + this.z*v.z;
        return output;
    }
    
}