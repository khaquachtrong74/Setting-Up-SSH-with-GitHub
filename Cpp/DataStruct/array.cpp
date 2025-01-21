#include "function.cpp"

struct array{
	int arr[100];
	int size;
	array(int s = 100){
		size = s;
	}
	void nhap(){
		int x;int i = 0;
		while(cin>>x && i < size){
			arr[i] = x;
			i++;
		}
		size = i; 
	}
	void xuat(){
		int count = 0;
		for(int x : arr){
			if(count < size)
				cout<<x<<" ";
			count++;
		}
		cout<<endl;
	}
	void insertionSort(){
		int key;
		for(int i = 1; i < size ;i++){
			key = arr[i];
			int j = i-1;
			while(j >=0 && arr[j] > key){
				arr[j+1] = arr[j];
			}
			arr[j] = key;
		}
	}
	void selectionSort(){
		int viTri;
		for(int i = 0; i < size -1;i++){
			viTri = i;
			for(int j = i; j < size; j++){
				if(arr[viTri] < arr[j]){
					viTri = j;
				}
			}
			if(viTri != i){
				swap(arr[viTri], arr[i]);
			}
		}
	}
	void bubbleSort(){
		for(int i = 0; i < size -1; i++){
			for(int j = 0; j < size -i - 1; j++){
				if(arr[j+1] < arr[j]){
					swap(arr[j+1] , arr[j]);
				}
			}
		}
	}
};
int main(){
	cout<<"hello world!"<<endl;
	array a;
	a.nhap();
	a.xuat();
	a.bubbleSort();
	a.xuat();
	a.selectionSort();a.xuat();
	return 0;
}
