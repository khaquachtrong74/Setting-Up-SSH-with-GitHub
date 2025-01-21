package lap;

public class InheritanceShape {

}

class Shape {
    private String color = "red";
    private boolean filled = true;

    public Shape() {
    }

    public Shape(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    @Override
    public String toString() {
        return "Color: " + this.color + ", Filled:" + this.filled + "\n";
    }
}

class Circle extends Shape {
    private double radius = 1.0;

    public Circle() {
        super();
        this.radius = 1.0;
    }

    public Circle(double radius, String color, boolean filled) {
        super(color, filled);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return 3.1415 * this.radius * radius;
    }

    public double getPerimeter() {
        return 3.1415 * 2 * this.radius;
    }

    @Override
    public String toString() {
        return super.toString() + "Circle:{\nRadius:" + this.radius + ",\nArea:" + this.getArea() + ",\nPerimeter:"
                + this.getPerimeter() + "\n";
    }
}

class Rectangle extends Shape {
    private double width = 1.0;
    private double length = 1.0;

    public Rectangle() {
        super();
    }

    public Rectangle(double width, double length) {
        super();
        this.width = width;
        this.length = length;
    }

    public Rectangle(double width, double length, String color, boolean filled) {

        super(color, filled);
        this.width = width;
        this.length = length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getArea() {
        return this.length * this.width;
    }

    public double getPerimeter() {
        return 2 * (this.length + this.width);
    }

    @Override
    public String toString() {
        return super.toString() + "Width:" + this.width + ",\nLength:" + this.length + ",\nArea:" + this.getArea()
                + ",\nPerimeter:" + this.getPerimeter() + "\n";
    }
}
class Square extends Rectangle{
    public Square(){super();}
    public Square(double side){
        super(side, side);
    }
    public Square(double side, String color, boolean filled){
        super(side, side, color, filled);
    }
    @Override
    public String toString() {
        return "Square ["+super.toString()+"]\n";
    }
    public void setSide(double side){
        super.setWidth(side);
        super.setLength(side);
    }
    public double getSide(){
        return super.getLength();
    }
    @Override
    public void setWidth(double width){
        super.setWidth(width);
    }
    @Override
    public void setLength(double length){
        super.setLength(length);
    }

}