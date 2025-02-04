#ifndef ARRAY_H
#define ARRAY_H
#include "main.h"
static int dem=0;
// We have arrays int not sort.
class ARR{
private:
	int size;
	int *mang;
public:
	ARR(int size);
	ARR();
	~ARR();
	int getSize();
	int* getPtrMang();
	void push(int x);
	void input(string s);
	void output();
};
// Then we divide it into shot arrays.

// Until len of shot arrays is 1.

// Then we sort with each 2 elements nearest.
#endif
