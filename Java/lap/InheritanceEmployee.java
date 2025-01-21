package lap;

public class InheritanceEmployee {

}

class Employee {
    private String Id;
    private String fullName;
    private int yearJoined;
    private double coefficientsSalary;
    private int numDaysOff;// number of days of in the month
    private static int currentYear = 2024;
    static final private double basicSalary = 1150.0;

    public Employee() {
        yearJoined = 2020;
        coefficientsSalary = 1.0;
    }

    public Employee(String id, String fullName, double coefficientsSalary) {
        this.Id = id;
        this.fullName = fullName;
        this.yearJoined = 2020;
        this.coefficientsSalary = coefficientsSalary;
        this.numDaysOff = 0;
    }

    public Employee(String id, String fullName, int yearJoined, double coefficientsSalary, int numDaysOff) {
        Id = id;
        this.fullName = fullName;
        this.yearJoined = yearJoined;
        this.coefficientsSalary = coefficientsSalary;
        this.numDaysOff = numDaysOff;
    }

    // method
    public double getSenioritySalary() {
        // if employee works for 5 years or more
        // seniority salary = years of work * basic salary/100
        return (currentYear - yearJoined >= 5 ? (currentYear - yearJoined + 1) * basicSalary / 100 : 0);
    }

    public String getId() {
        return Id;
    }

    public void setId(String id) {
        Id = id;
    }

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public int getYearJoined() {
        return yearJoined;
    }

    public void setYearJoined(int yearJoined) {
        this.yearJoined = yearJoined;
    }

    public double getCoefficientsSalary() {
        return coefficientsSalary;
    }

    public void setCoefficientsSalary(double coefficientsSalary) {
        this.coefficientsSalary = coefficientsSalary;
    }

    public int getNumDaysOff() {
        return numDaysOff;
    }

    public void setNumDaysOff(int numDaysOff) {
        this.numDaysOff = numDaysOff;
    }

    public static int getCurrentYear() {
        return currentYear;
    }

    public static void setCurrentYear(int currentYear) {
        Employee.currentYear = currentYear;
    }

    public static double getBasicsalary() {
        return basicSalary;
    }

    public String considerEmulation() {
        return (numDaysOff <= 1 ? "A" : (numDaysOff <= 3 ? "B" : "C"));
    }

    public double getSalary() {
        return basicSalary * coefficientsSalary
                * (considerEmulation() == "A" ? 1 : (considerEmulation() == "B" ? 0.75 : 0.5)) + getSenioritySalary();
    }
    
};
