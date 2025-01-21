import java.util.Scanner;

class BankAccount {
    // Save customer information
    private int accountNumber;
    private double balance;

    public void setAccountNumber() {
        this.accountNumber = (int) (Math.random() * 100 + 1);
    }

    public void setBalance() {
        this.balance = Math.random() * 1000;
    }

    BankAccount() {
        setAccountNumber();
        setBalance();
    }
    // thêm tiền vào
    public void deposit(double amount) {
        this.balance += amount;
    }
    // rút số dư
    public void withDraw(double amount) {
        
        if (this.balance >= amount) {
            this.balance -= amount;
        } else {
            System.out.println("Your balance is not enough, please try again!");
        }
    }

    public void displayBalance() {
        System.out.println("Your account number is " + this.accountNumber
                + " and your balance now: " + this.balance);
    }
}

class Customer {
    // Manage customer information
    private BankAccount[] customer = new BankAccount[100];
    // biến static sẽ khiến nó được các đối tượng khác dùng chung
    private int index;

    Customer() {
        index = 0;
    }

    public boolean logIn(BankAccount newCustomer) {
        if (index < 100) {
            this.customer[index++] = newCustomer;
            return true;
        } else {
            System.out.println("System full, can't login");
            return false;
        }
    }

    public boolean program(BankAccount newCustomer) {
        if (logIn(newCustomer)) {
            System.out.println("0. End!");
            System.out.println("1. Deposit ");
            System.out.println("2. Withdraw");
            System.out.println("3. View your balance");
            Scanner scanner = new Scanner(System.in);
            int a = scanner.nextInt();
            double amount;
            switch (a) {
                case 1:
                    System.out.println("Enter your amount:");
                    amount = scanner.nextDouble();
                    newCustomer.deposit(amount);
                    break;
                case 2:
                System.out.println("Enter your amount: ");
                    amount = scanner.nextDouble();
                    newCustomer.withDraw(amount);
                    break;
                case 3:
            
                    newCustomer.displayBalance();
                    break;
                case 0:
                    scanner.close();
                    return false; // end Program
                default:
                    break;
            }
            scanner.close();
            return true;
        } else {
            System.out.println("Log in not success, please try again!");
            return false;
        }
        
    }
}

public class prat5 {
    public static void main(String[] args) {
        Customer custm = new Customer();
        BankAccount tmp = new BankAccount();
        while (true) {
            custm.program(tmp);
        }
    }
}
