#include "array.h"
int main(){
	string input;
	cout<<"Nhap so luong phan tu: ";cin>>input;
	ARR al(stoi(input));
	cout<<"Nhap cac phan tu duoc ngan boi bat ky dau: ";
	cin>>input;
	al.input(input);
	al.output();
}
