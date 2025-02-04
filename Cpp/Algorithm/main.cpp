#include "array.h"
int main(){
	string input;
	cout<<"Nhap so luong phan tu: ";cin>>input;
	ARR al(stoi(input));
	cin.ignore();
	cout<<"Nhap cac phan tu duoc ngan boi bat ky dau: ";
	getline(cin, input);
	al.input(input);
	al.output();
}
