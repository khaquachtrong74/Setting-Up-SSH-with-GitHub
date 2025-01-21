abstract class Employee{
    protected String name, id;
    protected double salary;
    public Employee(String name, String id, double salary){
        this.name = name;
        this.id = id;
        this.salary = salary;
    }
    public abstract double caculateSalary();
    public String getName(){
        return this.name;
    }
    public String getId(){
        return this.id;
    }
    public double getSalary(){
        return this.salary;
    }
}
// Lớp con
class Manager extends Employee{
    protected double bonus;
    
    public Manager(double bonus, String name, String id, double salary){
        
        
        super(name, id, salary);
        this.bonus = bonus;
    }
    public void setBonus(double bonus){
        this.bonus = bonus;
    }
    public double getBonus(){
        return this.bonus;
    }
    @Override
    public double caculateSalary(){
        return this.salary + this.bonus;
    }
}
class Developer extends Employee{
    // công thức tính lương khi tăng ca: 1hour = 10
    protected int overTime; // Tăng ca
    public Developer(String name, String id, double salary, int overTime){
        super(name, id, salary);
        this.overTime = overTime;
    }
    public void setOverTime(int overTime){
        this.overTime = overTime;
    }
    public int getOverTime(){
        return this.overTime;
    }
    @Override
    public double caculateSalary(){
        return this.salary + this.overTime * 10;
    }
    @Override
    public String toString(){
        return "Developer {name: "+ this.name + ", id: "+ id + ", salary: " + salary + ", overTime: "+this.overTime;
    }
}
public class Prat8 {
    public static void main(String[] args){
        Employee manager = new Manager(100, "Kha", "1001", 12500);
        Employee developer = new Developer("kha", "1002", 25000, 3);
        System.out.println(manager.caculateSalary());
        System.out.println(developer.caculateSalary());
        System.out.println(manager);
        System.out.println(developer.toString());
    }
}
