#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a = {1, 2, 4, 5, 7};

    for_each(a.begin(), a.end(), [](int x)
             { cout << x << " "; });
    cout << endl;
    int sum = 0;
    for_each(a.begin(), a.end(), [&sum](int n)
             { sum += n; });
    for_each(a.begin(), a.end(), [](int n)
             {
        cout<< (n%2==0) ? true:false;cout<<endl; });
    int b = []()
    {
        return 5;
    }();
    [](){
        for(int i = 0; i < 10; i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }();
    int c = [a]
    {
        int sum = 0;
        for_each(a.begin(), a.end(), [&sum](int n)
                 { sum += n; });
        return sum;
    }();
    auto line = []()
    {
        string l;
        for (int i = 0; i < 20; i++)
        {
            l += "_";
        }
        cout << l << endl;
        return "";
    }();
    return 0;
}
