package taskthree;
import java.util.Scanner;
// fix Ex1. write some function


class Ex2{
	public static void main(String[] args){
		FunctionArray arrayInt = new FunctionArray(5);
		for(int i = 0; i < arrayInt.getSize(); i++){
			
			arrayInt.insertSpecific(i+1);
			System.out.println(i);
		}
		arrayInt.View();
	}
}	

// remove the first specific element from an array and return true
// if the element does not exist in array return false.
class FunctionArray{
	Scanner sc = new Scanner(System.in);
	private int[] staticArrayInt = new int[100];
	private int size = 0;
	public FunctionArray(int size){
		this.size = size;
	}
	public FunctionArray(){
		this.size = 0;
	}
	// copy
	public FunctionArray(final FunctionArray other){
		this.size = other.getSize();
		this.staticArrayInt = new int [this.size];
		for(int i = 0; i < this.size; i++){
			this.staticArrayInt[i] = other.getIndexAt(i);
		}
	}

	// check if specific elemnt is exit on array == true
	public boolean isExitEl(int el){
		if(size == 0){
			return false;
		}
		else{
			for(int ith = 0; ith < this.size; ith++){
				if(staticArrayInt[ith] == el){
					return true;
				}
			}
			return false;
		}
	}
	// function get index at specific 
	public int getIndexAt(int position){
		if(position < this.size){
			return this.staticArrayInt[position];
		}
		else{
			return -1;
		}
	}

	// Function to insert an element at a specific position
	// into an array.
	public void insertSpecific(int el){
		System.out.println("Enter your elements:");
		int position = sc.nextInt();
		if(position > size || position <= 0){
			System.out.println("Position out of bounds");
			return;
		}
		else{
			staticArrayInt[position-1] = el;
		}
	}
	// Function to find the duplicate values of an array of 
	// integer values
	public int[] findDuplicate(){
		int [] keys = new int[size];	
		for(int i = 0; i < size; i++){
			for(int j = i+1; j < size; j++){
				if(staticArrayInt[i] == staticArrayInt[j]){
					keys[i] = staticArrayInt[i];
					break;
				}
			}
		}
		return keys;
	}
	// Function to remove the duplicates values of an array 
	// of integer values
	public int[] removeDuplicates(){
		// make one aggregate
		int[] aggreGate = new int[size];
		int index = 0;
		for(int i = 0; i < size ;i++){
			int j = index-1;
			for(; j >=0; j--){
				// case at i is not duplicates
				if(staticArrayInt[i] == aggreGate[j]){
					i++;
					break;
				}
			}
			if(j < 0){
				aggreGate[index++] = staticArrayInt[i];	
			}
		}
		return aggreGate;	
	}
	// function to View all elements
	public void View(){
		for(int ith = 0; ith < size; ith++){
			System.out.println(staticArrayInt[ith]);
		}
	}
	// resize and copy
	public void setSize(int newSize){
		if (newSize > 0){
			int[] newArray = new int[newSize];
			for(int ith = 0; ith < Math.min(size, newSize); ith++){
				newArray[ith] = staticArrayInt[ith];
			}
			staticArrayInt = newArray;
			size = newSize;
		}
	}
	public int getSize(){
		return this.size;
	}
}
