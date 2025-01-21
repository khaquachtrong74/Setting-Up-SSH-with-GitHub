// Quy tắc đặt tên:
// class thì in hoa chữ cái đầu
// biến, phương thức hãy theo chuẩn lạc đà

abstract class Shape{
    
    public abstract double caculateArea();

}
class Circle extends Shape{
    protected double radius;
    public final double Pi = 3.1459;
    public Circle(double radius){
        this.radius = radius;
    }
    @Override
    public double caculateArea(){
        return radius * radius * Pi;
    }
}
class Rectangle extends Shape{
    protected double width, height;
    public Rectangle(double width, double height){
        this.width = width;
        this.height = height;
    }
    @Override
    public double caculateArea(){
        return width*height;
    }
}
class Triangle extends Shape{
    protected double base, height;
    public Triangle(double base, double height){
        this.base = base;
        this.height = height;
    }
    @Override
    public double caculateArea(){
        return (1.0/2.0) * base * height;
    }
}
public class prat7 {
    public static void main(String[] args){
        Shape triangle = new Triangle(5, 2);
        Shape rectangle = new Rectangle(12, 6);
        Shape circle = new Circle(3);
        System.out.println(triangle.caculateArea());
        System.out.println(rectangle.caculateArea());
        System.out.println(circle.caculateArea());
    }
}
