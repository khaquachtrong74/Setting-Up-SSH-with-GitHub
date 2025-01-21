#include<iostream>
using namespace std;

template<typename T>
void fillPrefixSum(T arr[], int n, T prefixSum[], int k){
	prefixSum[0] = arr[0] + k;
	
	 
	for(int i = 1; i < n; i++){
		prefixSum[i] = prefixSum[i-1] + arr[i];
	}
}
template<typename T>
// With array Two demension
void fillPrefixSumTwo(T arr[4][5], int n, int m, T prefixSum[4][5], T newPrefix[4][5]){
	
	for(int i = 0; i < n ;i++){
		fillPrefixSum(arr[i], m, prefixSum[i], 0);
		if(i == 0){
			fillPrefixSum(arr[i],m, newPrefix[i], 0);
			
			continue;
		}
		fillPrefixSum(arr[i], m, newPrefix[i], newPrefix[i-1][m-1]);
		
	}
}
int main(int argc, char* argv[]){
	int arr[4][5] = {
	{2, 3, 4, 2, 3},
	{4, 1, 2, 3, 4},
	{5, 4, 3, 6, 2},
	{3, 1, 2, 4, 8}
	};	
	int prefixSum[4][5];
	int newPrefix[4][5];
	fillPrefixSumTwo(arr, 4, 5, prefixSum, newPrefix);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			cout<<prefixSum[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"____________________________"<<endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			cout<<newPrefix[i][j]<<"    ";
		}
		cout<<endl;
	}
	return 0;
}
