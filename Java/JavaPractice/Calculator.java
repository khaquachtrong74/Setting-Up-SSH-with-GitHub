// File: Calculator.java


// Nhập các lớp cần thiết
import java.util.Scanner;

public class Calculator {
    private int yourAge;
    private String yourName;

    public void setAge(int age){
        this.yourAge = age;
    }
    public int getAge(){
        return this.yourAge;
    }
    public void setName(String name){
        this.yourName = name;
    }
    public String getName(){
        return this.yourName;
    }
    // Phương thức chính
    public static void main(String[] args) {
        // Tạo một đối tượng Scanner để nhận dữ liệu từ người dùng
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter first number:");
        double num1 = scanner.nextDouble();

        System.out.println("Enter second number:");
        double num2 = scanner.nextDouble();

        // Gọi phương thức để tính toán
        double sum = add(num1, num2);
        System.out.println("Sum: " + sum);

        scanner.nextLine();
        String name = scanner.nextLine();
        
        yourName(name);
        scanner.close();

        Calculator a = new Calculator();
        a.setAge(255);
        a.setName("Quach Trong Kha");
        System.out.println("Your age is " +  a.getAge() + " And your Name is : " + a.getName());
    }

    // Phương thức cộng hai số
    public static double add(double a, double b) {
        return a + b;
    }
    public static void yourName(String name){
        System.out.println("Your name is " + name );
    }
    // Phuơng thức lấy tên tuổi
    
    
}
