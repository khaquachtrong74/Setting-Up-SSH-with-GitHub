// Purpose: Manager library with add and show view
// 12/10/2024:
// Author: Quach Trong Kha
class Book{
    
    private String title, author;
    private int price;
    public Book(){
        this.title = "";
        this.author = "";
        this.price = 0;
    }
    public Book(String t, String a, int p){
        this.title = t;
        this.author = a;
        this.price = p;
    }
    public void setAuthor(String author){
        this.author = author;
    }
    public void setTitle(String title){
        this.title = title;
    }
    public void setPrice(int price){
        this.price = price;
    }
    public String getAuthor(){
        return this.author;
    }
    public String getTitle(){
        return this.title;
    }
    public int getPrice(){
        return this.price;
    }
}

class Library{
    private Book[] arrB = new Book [100];
    public static int size = 0;
    public void addBook(Book book){
        this.arrB[size++] = book;
    }
    public void displayInfo(){
        for(int i = 0; i < size; i++){
            System.out.println(
                this.arrB[i].getAuthor() + ","
            +   this.arrB[i].getTitle() + ","
            +   this.arrB[i].getPrice() + "vnd");
        }
    }
}
public class prat4 {
   public static void main(String [] args){
    Library Obj = new Library();
    Book tmp = new Book("Sleep","Kha",123);
    Book tmp1 = new Book("Eat","kha1",221);
    Obj.addBook(tmp);
    Obj.addBook(tmp1);
    Obj.displayInfo();
   }
}