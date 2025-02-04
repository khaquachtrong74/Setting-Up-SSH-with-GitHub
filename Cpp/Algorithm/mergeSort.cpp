#include "mergeSort.h"
void incLeft(int& left){
	left++;
}
void decRight(int& right){
	right--;
}
int getMid(int left, int right){
	return (right+left)/2;
}
void divide(int* mang, int size){
	cout<<getMid(0, size-1)<<" ";
}
