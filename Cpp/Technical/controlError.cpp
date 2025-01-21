#include <iostream>
#include <cassert>
using namespace std;

// stack memory
void call()
{
    cout << "Hello World!" << endl;
}
template <typename T>
void sizeVariable(T var)
{
    cout << sizeof(T) << endl;
}
int sum()
{

    return -2;
}
int divide(int a, int b)
{
    assert(b != 0 && "Division by zero!");
    return a / b;
}
int main()
{
    //
    try
    {
        int divisor = 0;
        if (divisor == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        int result = 10 / divisor;
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    // check condition and value return
    int result = sum();
    if (result == -1)
    {
        cerr << "Error occurred" << endl;
    }
    // use assert
    divide(1, 0);
    
   return 0;
}
