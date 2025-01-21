#include<iostream>
#include<vector>

using namespace std;

bool isOdd(int a){
	return a % 2 != 0;
}
bool compare(int a, int b){
	return a > b;
}
void process(vector<int>&odd, vector<int>&even, vector<int>src){
	for( auto x : src){
		if(isOdd(x)){
			odd.push_back(x);
		}
		else{
			even.push_back(x);
		}
	}
}
void printMatrix(vector<int>&odd, vector<int>&even){
	int sizeN = odd.size()+even.size();
	for(int i = 0; i < sizeN; i++){
		for(int j = 0; j < sizeN; j++){
			if(i % 2 == 0){
				cout<<even[j%even.size()]<<" ";
			}
			else{
				cout<<odd[j%odd.size()]<<" ";
			}

		}
		cout<<endl;
	}
}
/*
 * chung ta co mang cac so
 *	dong chan thi in so chan
 *	dong le thi in so le
 *	lap lai duoc
 *	
 * */
void recursiveCall(int &s, int arr[], const int size, bool flag){
	if(s == size)
		return;
	else{
		for(int i = 0; i < size; i++){
			if(isOdd(arr[i])==flag){
				cout<<arr[i]<<" ";
				s++;
			}
		}
	}
}
void call(int arr[], const int size){
	int count=0;
	int countEven=0;
	for(int i = 0; i < size; i++){
		if(i % 2 != 0){
			label:{
				if(count < size){
					recursiveCall(count, arr, size, true);
					goto label;
				}
				else{
					count=0;
				}	
			}
		}
		else{
			label1:{
				if(countEven < size){
					recursiveCall(countEven, arr, size, false);
					goto label1;
				}
				else{
					countEven=0;
				}
			}
		}
		cout<<endl;
		
	}
}
int main(){
//	vector<int>odd;
//	vector<int>even;
//	vector<int>src={1,2,3,4};
//	process(odd,even,src);
//	printMatrix(odd, even);
	int arr[]={1,2,3,4};
	int arr2[]={43,12,24,23,13,11};
//	printMatrix_2(arr, sizeof(arr)/sizeof(arr[0]));
//	printMatrix_2(arr2, sizeof(arr2)/sizeof(arr2[0]));
	call(arr, sizeof(arr)/sizeof(arr[0]));
//	cout<<true*false;
}
