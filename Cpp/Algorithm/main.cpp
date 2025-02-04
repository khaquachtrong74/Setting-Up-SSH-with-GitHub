#include "array.h"
#include "mergeSort.h"
int main(){
//	string input;
//	cout<<"Nhap so luong phan tu: ";cin>>input;
//	ARR al(stoi(input));
//	cin.ignore();
//	cout<<"Nhap cac phan tu duoc ngan boi bat ky dau: ";
//	getline(cin, input);
	ARR al(7);
	al.input("12,8,9,3,11,5,4");
	cout<<"Mang truoc khi sap xep"<<endl;
	showSubArr(al.getPtrMang(), 0, al.getSize()-1);
	mergeAndSort(al.getPtrMang(), 0, al.getSize()-1);
	cout<<"Mang sau khi sap xep "<<endl;
	showSubArr(al.getPtrMang(), 0, al.getSize()-1);
}
