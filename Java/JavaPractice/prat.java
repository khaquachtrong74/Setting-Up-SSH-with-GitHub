public class prat {
    //set and get

    //Purpose: practice
    private int num1;
    private int num2;

    public void setNum(int a, int b){
        this.num1 = a;
        this.num2 = b;
    }
    //  Overloading *method
    public void setNum(int a){
        this.num1 = this.num2 = a;
    }
    public void setNum(){
        this.num1 = this.num2 = 0;
    }
    public int getNum1(){
        return num1;
    }
    public int getNum2(){
        return num2;
    }
    // 
    public static void main(String args[]){
        System.out.println("Hello World!");
        prat a = new prat();//Declared Object
        a.setNum(4, 6);
        a.setNum(123);
        System.out.println(a.getNum1()+a.getNum2());
        
    } 
}
