// hand made queue
#include<iostream>
using namespace std;

template<typename T>
class Queue{
    private:
    T arr[100];
    int front;
    int re;
    int capacity;
};