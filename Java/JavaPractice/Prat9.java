// quản lý thông tin về sản phẩm
import java.math.BigDecimal;
import java.util.Scanner;
class Product{
    protected String name;
    protected BigDecimal price;
    protected int among; // Số lượng
    public Product(String name, BigDecimal price, int among){
        this.name = name;
        this.price = price;
        this.among = among;
    }
    public void settingAmong(int among){
        this.among = among;
    }
    @Override
    public String toString(){
        return "Name : " + this.name + " , Price : "+ this.price + ", Among : " + this.among;
    }
}
class Store{
    protected Product[] store = new Product[100];
    protected int size = 0;
    public Scanner scanner = new Scanner(System.in);
    public void addProduct(){
        if(size >= 100){
            return;
        }
        else{
            System.out.println("Enter name Product");
            String name = scanner.nextLine();       
            System.out.println("Enter price of Products");
            BigDecimal price = scanner.nextBigDecimal();
            System.out.println("Enter Quantity of Products");
            int among = scanner.nextInt();
            this.store[size++] = new Product(name, price, among);
            scanner.nextLine(); // đọc dòng thừa sau khi nhập
            
        }
    }
    public void displayProduct(){    
        for(int i = 0; i < size;i++){
            if(store[i] != null)
                System.out.println(store[i].toString());
        }
    }
    public BigDecimal sumVariable(){
        BigDecimal sumAll = new BigDecimal(0);
        for(Product product : store){
            if(product != null)
                sumAll = sumAll.add(product.price);
        }
        return sumAll;
    }
    
}
public class Prat9 {
    public static void main(String[] args){
        Store store = new Store();
        store.addProduct();
        store.addProduct();
        store.addProduct();
        store.displayProduct();
        store.scanner.close();
    }    
}
