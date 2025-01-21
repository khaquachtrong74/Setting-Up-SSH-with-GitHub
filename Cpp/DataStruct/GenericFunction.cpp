#include<iostream>
using namespace std;

template<class T>
class Arithmetic{
    private:
    T a;
    T b;
    public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};// finish template
template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->a = a;
    this->b = b;
}
template<class T>
T Arithmetic<T>::sub(){
    T C;
    C = a - b;
    return C;
}

template<class T>
T Arithmetic<T>::add(){
    T C;
    C = a+b;
    return C;
}
int main(){
    Arithmetic<int> ar(10,5);
    cout<<ar.add()<<endl;
    Arithmetic<float>ar1(5.2,4.9);
    cout<<ar1.sub();
    return 0;
}