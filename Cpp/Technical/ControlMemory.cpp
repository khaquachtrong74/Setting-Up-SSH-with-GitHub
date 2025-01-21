#include<iostream>
using namespace std;

// purpose : make Dynamic Array with every kind of data
template<typename T>
class DynamicArray{
	private:
	T *dynamicArray = nullptr;
	int size; // size of array;
	public:
	DynamicArray(): size(0), dynamicArray(nullptr) {}
	// explicit avoid change
	explicit DynamicArray(int s): size(s){
		if(s <= 0){
			throw std::invalid_argument("Size must be positive");// check size
		}
		try{
			dynamicArray = new T[size];
		}
		catch(std::bad_alloc& e){
		//	cout<<"Memory allocation failed"<<e.what();
			throw;//re throw exception
		}
	}

	// copy constructor
	DynamicArray(const DynamicArray other): size(other.size){
		dynamicArray = new T [other.size];
		for(int i = 0; i < other.size;i++){
			dynamicArray[i] = other.dynamicArray[i];
		}
	}
	//assign
	DynamicArray& operator=(const DynamicArray other){
		if(this != &other){
			T* tmp = new T [other.size];
			for(int i = 0; i < other.size; i++){
				tmp[i] = other.dynamicArray[i];
			}
			delete[] dynamicArray;
			dynamicArray = tmp;
			size = other.size;
		}
		return *this;
	}
	void setSize(int newSize){
		if(newSize <= 0){
			//return;
			throw std::invalid_argument("Size must be positive");
		}
		delete [] dynamicArray;
		size = newSize;
		dynamicArray = new T [size];
	}
	int getSize(){
		return size;
	}
	void inputValuesArray(){
		for(int i = 0; i < size; i++){
			cout<<"Enter value at ["<<i<<"] : ";
			cin>>this->dynamicArray[i];
		}
	}
	void viewArray(){
		int count = 0;
		for(int i = 0; i < size; i++){
			cout<<this->dynamicArray[i]<<" ";
			if(count + 10 == i){
				cout<<endl;
				count+=10;
			}
		}
	}
	void declaredDynamicArray(){
		// check if array is null
		int newSize;
		cout<<"Enter new Size of array";
		cin>>newSize;
		setSize(newSize);
		try{
		this->dynamicArray = new T[size];
		}
		catch(std::bad_alloc & e){
			cout<<"Memory allocation failed"<<e.what();
		}
	}
	T findMinMax(bool flag){
		T m = this->dynamicArray[0];
		for(int i = 1; i < size; i++){
			if(m < this->dynamicArray[i] == flag){
				m = this->dynamicArray[i];
			}
		}
		return m;
	}
	~DynamicArray(){
		delete [] this->dynamicArray;
		this->dynamicArray = nullptr;
	}
	bool isEmpty(){
		return size == 0 ? true : false;
	}
	void clear(){
		delete [] this->dynamicArray;
		dynamicArray = nullptr;
		size = 0;
	}
};
int main(){
	// for INT array
	DynamicArray <int> arrayInt(10);
	arrayInt.inputValuesArray();
	cout<<"Find max in array "<<arrayInt.findMinMax(true)<<endl;
	cout<<"Find min in array "<<arrayInt.findMinMax(false)<<endl;

	// for Double array
	DynamicArray <double> arrayDouble;
	arrayDouble.declaredDynamicArray();
	arrayDouble.inputValuesArray();
	cout<<"Find max in array "<<arrayDouble.findMinMax(true)<<endl;
	cout<<"Find min in array "<<arrayDouble.findMinMax(false)<<endl;
	return 0;
}
