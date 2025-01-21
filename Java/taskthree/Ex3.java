package taskthree;
import java.util.Scanner;
// Interact with 2 dimentional array
class Ex3{
	public static void main(String[] args){
		TwoDimenSionalArray arrayInt = new TwoDimenSionalArray(3);
		arrayInt.addVariable();
		arrayInt.View();		
		System.out.println("Multiply matrix");
		arrayInt.multiplyMatrix(5);
		arrayInt.View();
	
		TwoDimenSionalArray arrayInt1 = new TwoDimenSionalArray(3);
		arrayInt1.addVariable();
		System.out.println("Sum 2 matrix");
		TwoDimenSionalArray C = arrayInt.sumTwoMatrices(arrayInt, arrayInt1);
		C.View();
	}
}
class TwoDimenSionalArray{
	Scanner sc = new Scanner(System.in);
	private int[][] array = new int[10][10];
	private int fixSize = 0;
	public TwoDimenSionalArray(int size){
		fixSize = size;
	}
	public TwoDimenSionalArray(){
		fixSize = 0;
	}
	// set size and delete old data
	public void setSize(int newSize){
		if(newSize > 0){
			this.array = new int[newSize][newSize];
			this.fixSize = newSize;
		}
	}
	public int getSize(){
		return this.fixSize;
	}
	// function at elements at index
	public void insertElement(int el, int pos1, int pos2){
		this.array[pos1][pos2] = el;
	}
	// function to get element at index
	public int getElement(int pos1, int pos2){
		return this.array[pos1][pos2];
	}
	// function to add variable
	public void addVariable(){
		for(int i = 0; i < getSize(); i++){
			for(int j = 0; j < getSize(); j++){
				array[i][j] = sc.nextInt();
			}
		}
	}
	// function to add two matrices of the same size
	public TwoDimenSionalArray sumTwoMatrices(TwoDimenSionalArray A, TwoDimenSionalArray B){
		TwoDimenSionalArray C = new TwoDimenSionalArray(A.getSize());
		for(int i = 0; i < A.getSize(); i++){
			for(int j = 0; j < A.getSize(); j++){
				C.insertElement(A.getElement(i,j)+B.getElement(i,j),i,j);
			}
		}
		return C;
	}
	// function to multiply a matrix with a number
	public void multiplyMatrix(int number){
		for(int i = 0; i < getSize();i++){
			for(int j = 0; j < getSize(); j++){
				array[i][j] *= number;
			}
		}
	}
	// function to print a matrix to screen in martix format
	public void View(){
		for(int i = 0; i < getSize(); i++){
			for(int j = 0; j < getSize(); j++){
				System.out.print(array[i][j] + "   ");
			}
			System.out.println();
		}
	}
	// main Function is above

}
