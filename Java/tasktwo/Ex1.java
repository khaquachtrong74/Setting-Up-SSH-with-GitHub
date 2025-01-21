package tasktwo;
import java.math.BigDecimal;


class Ex1{
// function to find the maximum value of an array
	public static int findMax(int arr[]){
		int max = arr[0];
		for(int i = 1; i < arr.length; i++){
			if(arr[i] > max){
				max = arr[i];
			}
		}
		return max;
	}
	// function to find the minimum value of an array
	public static int findMin(int arr[]){
		int min = arr[0];
		for(int i = 1; i < arr.length; i++){
			if(arr[i] < min){
				min = arr[i];
			}
		}
		return min;
	}
	// function to sum all value of an array
	public static int sumAll(int arr[]){
		int ans = 0;
		for(int ith : arr){
			ans += ith;
		}
		return ans;
	}
	// function to count how many natural number
	public static boolean isNatural(int numb){
		if(numb < 2){
			return false;
		}
		for(int i = 2; i < Math.sqrt(numb);i++){
			if(numb % i == 0)
				return false;
		}
		return true;
	}
	public static int countNaturalNumb(int arr[]){
		int count = 0;
		for(int ith : arr){
			if(isNatural(ith))
				count++;
		}
		return count;
	}
	// function to find the index of elements k
	public static int find(int arr[], int k){
		int i = 0;
		for(int ith : arr){
			if(ith == k)
				return i;
			i++;
		}
		return -1; // if i == arr.Length => not find
	}
	// function to square all elements of an array
	public static void square(double arr[]){
		int index = 0;
		for(double ith : arr){
			arr[index++] = Math.sqrt(ith);
			
		}
	}
	// function to find maximun value of a BigDemical array
	public static BigDecimal findMax(BigDecimal [] arr){
		BigDecimal max = arr[0];
		for(BigDecimal ith : arr){
			if(ith.equals(max)){
				max = ith;
			}
		}
		return max;
	}
	// find elements can be divisible k and return a list
	public static int[] divisibleNumvers(int arr[], int k){
		int arrAns[] = new int[arr.length];
		int index = 0;
		for(int ith : arr){
			if(ith %k == 0){
				arrAns[index++] = ith;
			}
		}
		System.out.println(index);
		return arrAns;
	}
	public static void main(String [] args)
	{
		int[] arr = {1,2,3,4,5,6,7};
		for(int ith : divisibleNumvers(arr, 2)){
			if(ith != 0)
			System.out.println(ith);
		}
		System.out.println("_______________");
		System.out.println(findMax(arr));
		System.out.println(findMin(arr));
		System.out.println(sumAll(arr));
		System.out.println(countNaturalNumb(arr));
		System.out.println(find(arr, 4));
		System.out.println("__________________");
		double[] arrDouble = new double[arr.length];
		int index = 0;
		for(double ith : arr){
			arrDouble[index ++] = ith;
		}
		square(arrDouble);
		for(double ith : arrDouble){
			System.out.println(ith);
		}
		for(int ith : divisibleNumvers(arr, 2)){
			System.out.println(ith);
		}

	}

} 
