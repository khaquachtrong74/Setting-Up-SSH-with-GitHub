#include <iostream>
#include <stdio.h>
using namespace std;
struct Rectangle;
// Modulor style
int area(struct Rectangle r){
    return r.length*r.breadth;
}
int peri(struct Rectangle r){
    return 2*(r.length+r.breadth);
}

//struct style
struct Rectangle{
    int length;
    int breadth;
};

int main()
{
    // Monolothic style

    /*
    int length = 0, breadth = 0;
    printf("Enter Length and Breadth");
    cin >> length >> breadth;
    int area = length * breadth;
    int peri = 2 * (length + breadth);
    printf("Area=%d\nPerimeter=%d", area, peri);
    */


    // Modulor style
    Rectangle r={1,2};
    int a=area(r);
    int pr=peri(r);
    return 0;
}