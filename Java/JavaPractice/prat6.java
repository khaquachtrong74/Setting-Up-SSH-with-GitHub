// Kế thừa và đa hình : động vật
// lớp cơ bản

//class trừu tượng | dạng định danh
abstract class Animal{
    protected String name;
    public Animal(String name){
        this.name = name;
    }
    public void setName(String name){
        this.name = name;
    }   
    public String getName(){
        return this.name;
    }
    // âm thanh động vật này phát ra
    // định danh
    public abstract void makeSound();
}
class Dog extends Animal{
    public Dog(String name){
        super(name);
    }
    @Override
    public void makeSound(){
        System.out.println(name + "bark bark");
    }
}
class Cat extends Animal{
    public Cat(String name){
        // kế thừa hàm khởi tạo của animal
        super(name);
    }
    @Override
    public void makeSound(){
        System.out.println(name + "meo meo");
    }
}

// extends là đại diện cho việc kế thừa
class Bird extends Animal{
    public Bird(String name){
        super(name);
    }
    @Override
    public void makeSound(){
        System.out.println("e e");
    }
}
public class prat6 {
    public static void main(String[] args)
    {
        // Vì class animal là một khái niệm chung, không đại diện cụ thể
        // Animal animal = new Animal(); // lỗi: không thể tạo một lớp trừu tượng
        
        //tính đa hình
        Animal dogs = new Dog("warrior");
        dogs.makeSound(); // warrior bark bark

        Animal cat = new Cat("reom");
        cat.makeSound(); // reom meo meo
    }
}
