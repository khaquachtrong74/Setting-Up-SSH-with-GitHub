/*
PURPOSE:
    given a sequence of n intergers a1, a2,..., an
    count the number Q of pairs of 2 indices (i, j)
    such that 1 <= i < j <= n and a[i] == a[j]
*/
#include <iostream>
#include <set>
#include <vector>
#include<string>
using namespace std;
int giaiThua(int n){
    int ketqua = 1;
    while(n > 0){
        ketqua+=n;
        n--;
    }
    return ketqua;
}
int input()
{
    int n, count = 0;
    cin >> n;
    int *arr = new int[n];
    set<int> mySet;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mySet.insert(arr[i]);
    }
    vector<int> myVector(mySet.begin(), mySet.end());
    int index = 0;
    while (std::vector<int>::size_type(index) < myVector.size())
    {
        for (int i = 0; i < n; i++)
        {
            if(myVector[index] == arr[i]){
                count++;
            }
        }
        count--;
        index++;
    }
    delete[] arr;
    return count+1;
}
int main()
{
    string a = "eeesadeeeee";
    string b = "sad";
    cout<<a.find(b);
}