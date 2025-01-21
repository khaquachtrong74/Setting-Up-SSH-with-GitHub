#include<iostream>
using namespace std;

int main(){
	for(int i = 0 ;i  < 10; i++){
		for(int j = 0; j < i; j++){
			cout<<"||";
		}
		for(int k = 0; k < i; k++){
			cout<<"__";
		}
		cout<<"~~";
		for(int t = 10 - i; t >= 0; t--){
			cout<<"(";
		}
		for(int l = 10-i; l >= 0; l--){
			cout<<"=====";
		}
		cout<<";;";
	}
}
