#include "array.h"
#include <regex>

ARR::ARR(int size) : size(size) {
	try{
		this->mang = new int[size];
	}
	catch(...){
		cout<<"Default Error";
	}
}
ARR::ARR() : size(0){}
ARR::~ARR(){
	delete[] this->mang;
}
void ARR::push(int x){
	if(dem < this->size){
		this->mang[dem++] = x;
	}
}
/* 
 * use regex to separate numb
 * each numb will be push into mang*/
void ARR::input(string s){
	regex pattern("\\d+");
	sregex_iterator it(s.begin(), s.end(), pattern);
	sregex_iterator end;
	while(it != end){
		this->push(stoi(it->str()));
		++it;
	}
}
void ARR::output(){
	for(int* it = this->mang; it < (this->mang + this->size); ++it) cout<<*it<<" ";
}

