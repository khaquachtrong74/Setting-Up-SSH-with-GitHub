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
void showSubArr(int* mang, int left, int right){
	if(left <= right){
		for(int i = left; i <= right; i++)
			cout<<mang[i]<<" ";
		cout<<endl;
	}
}
void merge(int* mang, int left, int right, int mid){
	int lenSubLeft = mid - left + 1;
	int lenSubRight = right - mid;
	int Left[lenSubLeft], Right[lenSubRight];
	for(int i = 0; i < lenSubLeft; i++) Left[i] = mang[left+i];
	for(int j = 0; j < lenSubRight; j++) Right[j] = mang[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while(i < lenSubLeft && j < lenSubRight){
		if(Left[i] <= Right[j])	mang[k++] = Left[i++];
		else	mang[k++] = Right[j++];
	}
	while(i < lenSubLeft)	mang[k++] = Left[i++];
	while(j < lenSubRight)	mang[k++] = Right[j++];
}
void mergeAndSort(int* mang, int left, int right){
	if(left >= right) return;
	int mid = getMid(left, right);
	mergeAndSort(mang, left, mid);
	mergeAndSort(mang, mid+1, right);
	merge(mang, left, right, mid);
	showSubArr(mang, left, right);
}
