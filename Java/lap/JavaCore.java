package lap;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;
//lap 4 Object and class
// Illustrate with simple example'
class Student {
    // local Variables

    /*
     * Access Modifier : public, private, protected;
     * None Access Modifier: static
     * Constructor : need to defined default constructor, copy and parameterized
     */
    private String name;
    private String gender;
    private int age;

    // default constructor
    public Student() {
        this.name = "";
        this.gender = "male";
        this.age = 0;
    }

    // copy constructor
    public Student(Student other) {
        this.name = other.name;
        this.gender = other.gender;
        this.age = other.age;
    }

    // Parameterized constructor
    public Student(String name, String gender, int age) {
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    public void studying() {
        System.out.println("Stuyding ...");
    }

    public void reading() {
        System.out.println("reading...");
    }
    // overloading method
    
    public void reading(String smth){
        System.out.println("reading "+ smth);
    }

    public String reading(String smth, String smo){
        System.out.println("Reading " + smth + " with " + smo);
        return "Reading " + smth + " With " + smo;
    }

    // Encapsulation -- Tính đóng gói
    /*
     * It is a mechanism of wrapping the data and code acting
     * on the data together as a signle unit
     * it will hidden from other classes and can be accessed only 
     * through the methods of their current class
     * -> data hiding
     */
    public void setName(String name){
        this.name = name;
    }
    public void setAge(int age){
        this.age = age;
    }
    public void setGender(String gender){
        this.gender = gender;
    }
    public String getName(){
        return this.name;
    }
    public String getGender(){
        return this.gender;
    }
    public int getAge(){
        return this.age;
    }
    
    // print the information of object
    // now we can use override to do that
    // it also call Override method
    @Override
    public String toString(){
        return "Student[" + name + ", "+ gender +" | " + age +"]";
    }
}

public class JavaCore {

    public static void main(String[] args) {

        ArraysClassTutorial();
        StringClassTutorial();
        int[] test = input(5);
        view(test);
        System.out.println(maxEven(test));
        System.out.println(minOdd(test));
        System.out.println(sumEven(test));
        System.out.println(sumEven(test));
        System.out.println(prodOdd(test));
        System.out.println(idxFirstEven(test));
        System.out.println(idxLastOdd(test));
        
    }

    public static void line() {
        for (int i = 0; i <= 20; i++) {
            System.out.print("_");
        }
        System.out.println();
    }

    public static void view(int[] tmp) {

        for (var it : tmp) {
            System.out.println(it);
        }
        line();
    }

    // Lap 3
    public static void ArraysClassTutorial() {
        /* Arrays Class */
        // way to make a array
        int[] org = new int[] { 1, 2, 3, 4, 5 };
        /* Some function() of Arrays */

        int[] copy = Arrays.copyOf(org, 3);
        // it will return [1, 2, 3]
        view(copy);
        copy = Arrays.copyOfRange(copy, 2, 4);
        // it will copy of 2 -> 4 minus 1
        view(copy);

        String copyString = Arrays.toString(org);
        System.out.println((copyString instanceof String) ? "True" : "False");
        // return true; so copyString make a copy and make it become String

        // sort function()
        int intArr[] = { 10, 20, 15, 22, 36 };
        Arrays.sort(intArr);
        view(intArr);

        /*
         * binaryScarch using binary search algorithm
         * the array need to be sort before call this function
         */
        int index = Arrays.binarySearch(intArr, 22);
        System.out.println(index);
        line();
    }

    public static void StringClassTutorial() {

        /* Class Strinng */
        String greeting = "Hello"; // create with string literal

        String greeting1 = new String("Hello"); // create with new keyword

        // so with address on heap memory, greeting and greeting1 is different address;
        // so if we want to check equal, we use equals, not use "=="

        if (greeting.equals(greeting1))
            System.out.println("True yeah");

        // we can compare 2 String with compareTo

        System.out.println("Star".compareTo("star")); // return negative it means Larger
        System.out.println("abc".compareTo("abc")); // return zero
        System.out.println("d".compareTo("abc")); // return positive it means smaller
        line();
        System.out.println("Star".compareTo("sar"));
        // we can get length with
        line();

        System.out.println("Greeting length u get " + greeting.length());
        line();

        // we can have character at index
        System.out.println(greeting.charAt(2)); // l

        line();

        // use concat or operator += to concatenate two strings
        greeting += greeting1;
        System.out.println(greeting);
        greeting1 = greeting1.concat("Kha");
        System.out.println(greeting1);
        line();
        // subString()
        String title = "J Perfect's Diary";
        System.out.println(title.substring(2, 9));// Perfect;

        // indexOf(String str, int fromIndex)
        // return index for the first substring eaul to str starting from Index

        String tmp = "Perfect";
        System.out.println(title.indexOf(tmp)); // return 2
        System.out.println(title.indexOf(tmp, 5)); // return -1

        /*
         * u can use trim() to delete Space in head and tail
         * split to make list (tokenzied)
         */
    }

    // lap 5 make function with array
    public static int maxEven(int[] a){
        return Arrays.stream(a).filter(x -> x % 2 == 0).max().orElse(-1);
    }
    public static int minOdd(int[] a){
        return Arrays.stream(a).filter(num -> num % 2!= 0).min().orElse(-1);
    }
    // caculate sum of the greatest even numb and smallest odd numb
    public static int sumMEMO(int[] a){
        return maxEven(a) + minOdd(a);
    }
    // caculate sum of even numbs;
    public static int sumEven(int[] a){
        return Arrays.stream(a).filter(num -> num % 2 == 0).sum();
    }
    // caculate the product of odd Numbers in an array
    public static int prodOdd(int[] a){
        return Arrays.stream(a).reduce(1, (x, y)-> x*y);
    }
    // return the position of the first even number in the array
    public static int idxFirstEven(int[] a){
        return Arrays.stream(a).filter(i -> a[i] % 2 == 0).findFirst().orElse(-1);
    }
    public static int idxLastOdd(int[] a){
        return IntStream.iterate(a.length-1, i -> i >=0, i -> i-1).filter(i -> a[i] % 2 != 0).findFirst().orElse(-1);
    }
    // enter n integer to push n times elemenets
    public static int[] input(int n){
       
        Scanner sc = new Scanner(System.in);
        int[] outPut = new int[n];
        for(int i = 0; i < n; i++){
            outPut[i] = sc.nextInt();
        }
        sc.close();
        line();
        return outPut;
        
    } 
}
