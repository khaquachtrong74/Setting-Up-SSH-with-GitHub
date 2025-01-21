package neetcode;
class DynamicArray{
	protected int [] array;
	protected int length;
	protected int capacity;
	public DynamicArray(int capacity){
		this.length = 0;
		this.capacity = capacity;
		this.array = new int [this.capacity];
	}
	// function return value at index
	public int getIndex(int index){
		return this.array[index];
	}
	// function make change value at index in array
	public void setIndex(int index, int var){
		this.array[index] = var;
	}
	// push value in array
	public void pushBack(int var){
		if(length < capacity){
			this.array[length++] = var;
		}
		else{
			System.out.println("Length is full!");
		}
	}
	public int popBack(){
		if(length == 0)
			return 0;
		return this.array[--length];
	}
	private void reLength(int length){
		this.length = length;
	}
	public int getLength(){
		return this.length;
	}
	public int getCapacity(){
		return this.capacity;
	}
	public static void main(String [] args){
		DynamicArray dynamicArray = new DynamicArray(10);
		dynamicArray.pushBack(2);
		System.out.println("The first value is : " + dynamicArray.popBack());
	}
}
