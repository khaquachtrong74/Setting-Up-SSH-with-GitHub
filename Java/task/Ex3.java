package task;

import java.math.BigDecimal;

// class with some function do math
class HailStone {
    protected int var;
    HailStone(){
        var = 0;
    }
    HailStone(int var) {
        this.var = var;
    }

   
    public boolean Odd(){
        return this.var == 0;
    }
    
    public void Action() {
        if (Odd()) {

            System.out.printf("%d is odd, so we take 3 * n + 1: ", (3 * this.var + 1));

        } else {
            System.out.printf("%d is even, so we take n/2: ", (this.var / 2));
        }
    }
}

public class Ex3{
    
    protected HailStone hailStone = new HailStone(5);
    public Ex3(){

    }
    // function to return the remainder of a division
    public double Remainder(double a, double b) {
        if (b != 0)
            return (a / b - (int) (a / b));
        return 0.0;
    }

    // function convert the temperature from F -> C, C -> F
    public BigDecimal Convert(BigDecimal temperature, boolean flag) {
        // F -> C
        if (flag) {
            return (temperature.subtract(new BigDecimal(32)).multiply(new BigDecimal(0.555))
                    .multiply(new BigDecimal(-1)));
        } else {
            return temperature.multiply(new BigDecimal(1.8)).add(new BigDecimal(32));
        }
    }

    // function to check year is a leap year or not
    static boolean isLeapYear(int year) {

        return (((int) (year % 4) == 0) && ((int) (year % 100) != 0) || (year % 100 == 0));
    }

    // function find min with variables
    public double findMin(double a, double b) {
        return a > b ? b : a;
    }

    public double findMin(double a, double b, double c) {
        return findMin(a, b) > c ? c : findMin(a, b);
    }
    // function check it is alphanumeric or not

    public boolean isAlphaNumb(char c) {
        System.out.println((char) ('0' + 9));

        return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= (char) ('0') && c <= (char) ('0' + 9)));
    }

    // write some functions to caculate
    public int RecursiveSum(int n) {
        if (n == 0) {
            return 0;
        }
        return n + RecursiveSum(n - 1);
    }

    public int RecursiveMulti(int n) {
        if (n == 1) {
            return 1;
        }
        return n * RecursiveMulti(n - 1);
    }

    public int Expontial(int a, int n) {
        final int Const = a;

        while (n - 1 != 0) {
            a *= Const;
            n--;
        }
        return a;
    }

    public int SecondNewton(int n) {
        if (n == 1) {
            return 1;
        }
        return Expontial(2, n - 1) + SecondNewton(n - 1);
    }

    @SuppressWarnings("deprecation")
    public BigDecimal RecursiveDevide(int n) {
        if (n == 1) {
            return new BigDecimal(0.5);
        }
        // làm tròn tới số gần nhất
        return (new BigDecimal(1).divide(new BigDecimal(2 * n), 10, BigDecimal.ROUND_HALF_DOWN))
                .add(RecursiveDevide(n - 1));
    }

    public int SumSquare(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += Expontial(i, 2);
        }
        return ans;
    }
    

    

    public static void main(String[] args) {
        Ex3 task = new Ex3();
        System.out.println(task.Remainder(5.0, 1.2));
        System.out.println(task.Convert(new BigDecimal(17), true));
        System.out.println(isLeapYear(2020));
        System.out.println(task.findMin(1.3, 5.2, 10.9));
        System.out.println(task.isAlphaNumb('A'));
        System.out.println(task.RecursiveSum(5));
        System.out.println(task.RecursiveMulti(5));
        System.out.println(task.SecondNewton(4));
        System.out.println(task.RecursiveDevide(3));
        System.out.println(task.SumSquare(5));
        task.hailStone.Action();
    
    }

    public HailStone getHailStone() {
        return hailStone;
    }

    public void setHailStone(HailStone hailStone) {
        this.hailStone = hailStone;
    }
}
