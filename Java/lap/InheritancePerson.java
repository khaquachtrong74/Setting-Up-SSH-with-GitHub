// Inheritance
package lap;

public class InheritancePerson {
    public static void main(String[] args) {

    }
}

class Person {
    private String name;
    private String address;

    public Person() {
        this("", "");
    }

    public Person(String name, String address) {
        this.name = address;
        this.address = address;
    }

    public Person(Person other) {
        this(other.getName(), other.getAddress());
    }

    @Override
    public String toString() {
        return "Person{ Name: [" + this.name + "]\n" + "Address: [" + this.address + "]}\n";
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}

class Student extends Person {
    private float scoreMath;
    private float scorePhysical;
    private float scoreChemistry;

    public Student(String name, String address, float scoreMath, float scorePhysical, float scoreChemistry) {
        super(name, address);
        this.scoreChemistry = scoreChemistry;
        this.scoreMath = scoreMath;
        this.scorePhysical = scorePhysical;
    }

    public float getScoreMath() {
        return scoreMath;
    }

    public void setScoreMath(float scoreMath) {
        this.scoreMath = scoreMath;
    }

    public float getScorePhysical() {
        return scorePhysical;
    }

    public void setScorePhysical(float scorePhysical) {
        this.scorePhysical = scorePhysical;
    }

    public float getScoreChemistry() {
        return scoreChemistry;
    }

    public void setScoreChemistry(float scoreChemistry) {
        this.scoreChemistry = scoreChemistry;
    }
}

class Teacher extends Person {
    private String subject;

    public Teacher() {
        super();
        this.subject="";
    }

    Teacher(String name, String address, String subject) {
        super(name, address);
        this.subject = subject;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }
}
class College extends Person{
    private String program;
    private int year;
    private double fee;
    public College(String name, String address, String program, int year, double fee){
        super(name, address);
        this.program = program;
        this.year = year;
        this.fee = fee;
    }
    public String getProgram() {
        return program;
    }
    public void setProgram(String program) {
        this.program = program;
    }
    public int getYear() {
        return year;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public double getFee() {
        return fee;
    }
    public void setFee(double fee) {
        this.fee = fee;
    }
    @Override
    public String toString(){
        return "College:{"+super.toString()+ "\nProgram:"+this.program+",\n Year:"+this.year+", \n Fee:"+this.fee+"}\n";
    }
}
class Staff extends Person{
    private String school;
    private double pay;
    Staff(String name, String address, String school, double pay){
        super(name, address);
        this.school = school;
        this.pay = pay;
    }
    @Override
    public String toString(){
        return "Staff:{"+super.toString()+"\nSchool:"+this.school+",\nPay:"+this.pay+"}\n";
    }
    public String getSchool() {
        return school;
    }
    public void setSchool(String school) {
        this.school = school;
    }
    public double getPay() {
        return pay;
    }
    public void setPay(double pay) {
        this.pay = pay;
    }
    
}