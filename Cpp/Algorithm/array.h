#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<string>
#include<regex> // for c++, regex.h for c
using namespace std;

static int dem=0;
// We have arrays int not sort.
struct ARR{
	int size;
	int *mang;
	ARR(int size);
	ARR();
	~ARR();
	void push(int x);
	void input(string s);
	void output();
};
// Then we divide it into shot arrays.

// Until len of shot arrays is 1.

// Then we sort with each 2 elements nearest.
#endif
