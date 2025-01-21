package taskthree;

public class Ex5 {
    public static void main(String[] args) {
        JavaString newTest = new JavaString("nans");
        System.out.println(newTest.isPalindrome());
    }   
}
// String program
class JavaString{
    private String str;
    public  JavaString(String str){
        this.str = str;
    } 
    public void setString(String str){
        this.str = str;
    }
    public String getString(){
        return this.str;
    }
    public int getLength(){
        str = str.trim();
        return str.length();
    }
    public int countNumb(){
        int count = 0;
        for(int i = 0; i < getLength(); i++){
            if(str.charAt(i) >= (char)('0') && str.charAt(i) <= (char)('0'+9)){
                count++;
            }
        }
        return count;
    }
    public boolean isPalindrome(){
        for(int i = 0; i < (str.length()/2); i++){
            if(str.charAt(i) != str.charAt(str.length() - 1 - i)){
                return false;
            }
        }
        return true;
    }
}