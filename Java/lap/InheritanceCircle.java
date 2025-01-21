package lap;

public class InheritanceCircle {
    
}
class Circle{
    private double radius;
    private String color;
    public Circle(){
        this.radius=1.0;
        this.color="red";
    }
    public Circle(double radius){
        this.radius=radius;
    }
    public Circle(double radius, String color){
        this.radius=radius;
        this.color=color;
    }
    public double getRadius() {
        return radius;
    }
    public void setRadius(double radius) {
        this.radius = radius;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    @Override
    public String toString(){
        return "Circle{ radius:["+this.radius+"]\n color:["+this.color+"]}\n";
    }
}
class Cylinder extends Circle{
    private double height;
    public Cylinder(){
        super(); 
        this.height=1.0;
    }
    public Cylinder(double radius, double height){
        super(radius);
        this.height=height;
    }
    public Cylinder(double radius, double height, String color){
        super(radius, color);
        this.height=height;
    }
    public double getHeight() {
        return height;
    }
    public void setHeight(double height) {
        this.height = height;
    }
    @Override
    public String toString(){
        return "Cylinder :{ "+super.toString()+" height:["+this.height+"]\n";
    }

}