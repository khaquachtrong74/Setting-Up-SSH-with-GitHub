package taskthree;
// finish excersize 1;

public class Ex1 {
    // function to remove the first specific element from an array
    // and return true
    public static boolean removeFirstElm(int[] arr, int k) {
        if (arr.length == 0) {
            return false;
        } else {
            int index = 0;
            for (int ith : arr) {
                if (ith == k) {
                    for (; index < arr.length - 1; index++) {
                        arr[index] = arr[index + 1];
                    }
                    break;
                }
                index++;
            }

            return true;
        }
    }

    // function to insert an element at a specific position
    public static void insertElm(int[] arr, int k, int pos) {

        for (int i = arr.length - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = k;

    }

    // function find the duplicate values of an array integer;
    public static void checkFace(int arr[], int k) {

        for (int ith : arr) {
            System.out.println(ith);
        }
        
    }

    public static int[] findDuplicate(int[] arr) {
        int[] ans = new int[arr.length];

        int index = 0;
        while (index != arr.length) {
            int tmp = arr[index];
            int i = index + 1;
            for (; i < arr.length && tmp != arr[i]; i++) {
            }
            if (i == arr.length) {
                index++;
            } else {
                checkFace(arr, tmp);
                index++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] array = { 1, 3, 1, 3, 2, 4 };
        // System.out.println(removeFirstElm(array, 2));

        insertElm(array, 7, 2);
        for (int ith : array) {
            System.out.println(ith);
        }
        System.out.println("__________________");
        for (int ith : findDuplicate(array)) {
            System.out.println(ith);
        }
    }
}
