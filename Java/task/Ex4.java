package task;
public class Ex4{
    static int sum(int a, int b){
        return a + b;
    }
    static int getFirstNumb(int a){
        int tmp = a;
        int pre = 0;
        while(tmp != 0)
        {   
            pre = tmp;
            tmp /= 10;
        }
        return pre;
    }
    //function Sum first digit and last digit of a number;
    
    static int sumFl(int numb){
        return sum(getFirstNumb(numb), numb%10);
    }
    // function count digits on number
    static int count(int numb){
        int times = 0;
        while(numb != 0){
            times++;
            numb /= 10;
        }
        return times;
    }
    // function reverse number
    static int reverseNumb(int numb){
        int ans = 0;
        while(numb != 0){
            ans = ans*10 + numb%10;
            numb /= 10;
        }
        return ans;
    }
    // function check is palindrome
    static boolean isPalindrome(int numb){
        return numb == reverseNumb(numb) ? true : false;
    }
    public static void main(String[] args){
        System.out.println("Get first number : " + getFirstNumb(923));
        System.out.println("Sum first and last digits " + sumFl(523));
        System.out.println("Quantity of digit :" + count(1232312));//7
        System.out.println("Reverse Numb: " + reverseNumb(32123));
        System.out.println("is" + 123 +" Palindrome: " + isPalindrome(123));

    }
}
