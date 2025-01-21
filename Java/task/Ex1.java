package task;
// Program to print your name, DOB, student ID from the keyboard
import java.util.Scanner;
public class Ex1 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        String dob = scanner.nextLine();
        String studentId = scanner.nextLine();

        System.out.println("Name: " + name + ", DOB : " + dob + " ID : " + studentId);
        scanner.close();
    }
}
