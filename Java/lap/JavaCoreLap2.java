package lap;

import java.util.Arrays;

public class JavaCoreLap2 {
    /**
     * @param args
     */
    public static void main(String[] args){
        // Point A = new Point(0, 2);
        // Point B = new Point(2,0);
        // System.out.println(A.caculateDistance(B));
        // System.out.println(A.toString());
        // System.out.println("_______");
        // Line test = new Line(new Point(-1,8),new Point(-3,4));
        // System.out.println(test.toString());
        // System.out.println(test.caculateLength());
        // System.out.println(test.findMiddlePoint().toString());
        // System.out.println("______________");
        // Rectangle rectangle = new Rectangle(new Point(),new Point(2,2));
        // System.out.println(rectangle.toString());
        PhanSo[] a = {
            new PhanSo(1,2)
            ,new PhanSo(4,5)
            ,new PhanSo(-2,-7)
            ,new PhanSo(15,-9)
            ,new PhanSo(7,3)
        };
        Arrays.stream(a).forEach(x -> System.out.println(x.toString()));
        
        System.out.println("_____________");
        PhanSo tong = Arrays.stream(a).reduce(new PhanSo(), (x,y)->x.cong(y));
        tong.rutGon();
        System.out.println(tong.toString());
        PhanSo maxPhanSo = Arrays.stream(a).max(PhanSo::soSanh).orElse(null);
        System.out.println(maxPhanSo.toString());
        Arrays.sort(a, (p1,p2) -> p1.soSanh(p2));
        Arrays.stream(a).forEach(x -> System.out.println(x.toString()));
    }

// Tương tác với không gian 2 chiều
/* Point
 * chứa 2 thuộc tính
 * hoành độ: x
 * tung độ : y
 */


class Point{
    private double x;
    private double y;
    public Point(double x, double  y){
        this.x = x;
        this.y = y;
    }
    public Point(double x){
        this(x,0);
    }
    public Point(){
        this(0,0);
    }
    public void setX(double x){
        this.x = x;
    }
    public void setY(double y){
        this.y = y;
    }
    public double getX(){
        return this.x;
    }
    public double getY(){
        return this.y;
    }
    // get infomation about point
    @Override
    public String toString(){
        
        return "Point: ("+this.x+","+this.y+")";
    }
    // function to caculate distance between 2 point A, B;
    public double caculateDistance(Point A, Point B){
        return Math.sqrt(Math.pow((A.getX()-B.getX()),2) + Math.pow((A.getY()-B.getY()), 2));
    }
    // Overloading method caculate distance because
    // I want use it when caculate with itself
    public double caculateDistance(Point B){
        return Math.sqrt(Math.pow((this.getX()-B.getX()),2) + Math.pow((this.getY()-B.getY()), 2));
    }
    
}
// line with 2 attributes of Point to
class Line{
    private Point A;
    private Point B;
    // build constructor
    public Line(Point A, Point B){
        this.A = A;
        this.B = B;
    }
    public Line(Point A){
        this(A, null);
    }
    public Line(){
        this(null,null);
    }
    // build setter, getter
    public void setA(double x, double y){
        A.setX(x);
        A.setY(y);
    }
    public void setB(double x, double y){
        B.setX(x);
        B.setY(y);
    }
    public Point getA(){
        return A;
    }
    public Point getB(){
        return B;
    }
    @Override
    public String toString(){
        return "Location of two point: [("+this.A.getX()+","+this.A.getY()+"),("+this.B.getX()+","+this.B.getY()+")]";
    }
    // function to caculate length of line
    public double caculateLength(){
            return A.caculateDistance(B);
    }
    // function to find middle point of line
    public Point findMiddlePoint(){
        Point middle = new Point((A.getX()+B.getX())/2, (A.getY()+B.getY())/2);
        return middle;
    }
    // function to check if 2 Line is parallel
    public boolean isParallel(Line AB, Line CD){    
        double ab = (AB.getA().getX() - AB.getB().getX())/(AB.getA().getY()-AB.getB().getY());
        double cd = (CD.getA().getX() - CD.getB().getX())/(CD.getA().getY()-CD.getB().getY());
        return ab == cd;
    }

} 

class Rectangle{
    private Point topLeft;
    private Point downRight;
    public Rectangle(Point A, Point B){
        this.topLeft = A;
        this.downRight = B;
    }
    public Rectangle(Point A){
        this(A, null);
    }
    public Rectangle(){
        this(null, null);
    }
    public void setTopLeft(Point topLeft) {
        this.topLeft = topLeft;
    }
    public void setDownRight(Point downRight) {
        this.downRight = downRight;
    }
    public Point getTopLeft() {
        return topLeft;
    }
    public Point getDownRight() {
        return downRight;
    }
    public double caculatePerimeter(){
        // a = topLeftx -downRightx
        // b = topLefty - downRighty
        return ((topLeft.getX()-downRight.getX())+(topLeft.getY()-downRight.getY()))*2;
    }
    public double caculateArea(){
        return ((topLeft.getX()-downRight.getX())*(topLeft.getY()-downRight.getY()));
    }
    @Override
    public String toString(){
        String a = "Point Top-Left: " + topLeft.toString()+"\n";
        String b = "Point Down-Right: "+downRight.toString() + "\n";
        a += b;
        b = "Perimeter of Rectangle: " + caculatePerimeter()+"\n";
        a += b;
        b = "Area of Rectangle: " + caculateArea()+"\n";
        return a + b;
    }
}

class Circle{
    private Point center;
    private double radius;
    private final static double PI = 3.1415;
    public Circle(Point center, double radius){
        this.center = center;
        this.radius = radius;
    }
    public Circle(){
        this(null, 0);
    }
    public double caculateArea(){
        return radius*radius*PI;
    }
    public double caculatePerimeter(){
        return radius*2*PI;
    }
    // function to compare one point with center of circle
    // true: this point is out of circle
    // false: this point is in circle
    public boolean compareOnePont(Point A){
        double distance = center.caculateDistance(A);
        if(distance > radius){
            return true;
        }
        else{
            return false;
        }
    }
    // function to compare one cirlce with this circle
    public void compareOneCircle(Circle A){
        boolean check = A.compareOnePont(center);
        if(check){
            System.out.println("Circle A is not touch Circle B");
        }
        else{
            System.out.println("Circle A is touched by Circle B");
        }
    }
}
}