package task;
// Write a program to compute the area of triangle with a height and base
// Provided by the user

import java.math.BigDecimal;
import java.util.Scanner;
public class Ex2 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);   
        BigDecimal height = scanner.nextBigDecimal();
        BigDecimal base = scanner.nextBigDecimal();
        System.out.println("Area of triangle is " + height.multiply(base).divide(new BigDecimal(2)));
        scanner.close();
    }
}
