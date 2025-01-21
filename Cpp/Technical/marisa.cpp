#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    cout<<a<<c<<b;
    if (c == '+') {
        cout <<fixed<<setprecision(3)<< a + b;
    } else if (c == '-') {
        cout <<fixed<<setprecision(3)<< a - b;
    } else if (c == '*') {
        cout <<fixed<<setprecision(3)<< a * b;
    } else if (c == '/') {
        if (b != 0) {
            cout <<fixed<<setprecision(3)<< a / b;
        } else {
            cout << "ZE";
        }
    } else {
        cout << "ZE";
    }
    
    return 0;
}
