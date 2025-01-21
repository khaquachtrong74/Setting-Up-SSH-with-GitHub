// Tính kế thừa
// lớp cơ sở (super Class)
class Animal{
    String name;

    public Animal(String name){
        this.name = name;
    }
    public void makeSound(){
        System.out.print(name + " makes a sound.");
    }
}
class Dogs extends Animal{
    public Dogs(String name){
        super(name); //Gọi hàm khởi tạo từ lớp cơ sở
    }
    // Chuẩn dùng để ghi đè
    @Override
    public void makeSound(){
        System.out.println(this.name + " barks.");
    }
    //Overload
    public void makeSound(String str){
        System.out.println(this.name + " " + str);
    }
}
//Upcasting chuyển đổi một đối tượng từ một lớp con lên lớp cơ sở
//Downcasting chuyển đổi một đối tượng từ lớp cơ sở về lớp con

public class prat3{
    public static void main(String[] args){
        System.out.println("hello World!");
        Dogs dog = new Dogs("Buddy");
        dog.makeSound();
        dog.makeSound("meo meo");

        Animal animal = new Dogs("Corky"); // Upcasting
        Dogs dog_new = (Dogs) animal; //Downcasting
        dog_new.makeSound();
    }
}
