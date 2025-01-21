#include<iostream>
using namespace std;

// it will pass pointer point to array
void fun(int A[ ]) // or we can use (*) instead
{
	// it will return 8 / 4 = 2; because int* is 8 bytes
	// and int is 4 bytes
	cout<<sizeof(A)/sizeof(int)<<endl;
}

void funT(int A[ ]){
	// error: begin, end no declare in this scope
	for(int a:A)
	cout<<a<<" ";
	// so to fix that we should pass size of array 
	// like parameter
}

void funtC(int *A, int n){
	A[0]=15; // it will change A[0] in to 15
}
// create an array and return address
int *funtcionCreate(int size){
	int *p;
	p=new int[size];
	for(int i = 0; i < size; i++)
		p[i]=i+1;
	return p;
}
void clearMemory(int* p){
	delete[] p;
}
int main(){
	int *ptr, sz=5;
	ptr=funtcionCreate(sz);// arr will create at heap memory

	
	for(int i=0;i<sz;i++)
		cout<<ptr[i]<<endl;
	clearMemory(ptr);
	//int A[ ]={2,4,6,8,10};
	//fun(A);

	//for(int x:A)
	//cout<<x<<" ";
	return 0;
}
