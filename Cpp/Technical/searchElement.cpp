// Search Element in One dimension array
#include<iostream>
#include<unistd.h>
#include<ctime>
using namespace std;
struct SearchFunction{
    private:
    int arr[1000];
    int size;
public:
    SearchFunction(int s):size(s){}
    SearchFunction(): size(0){}
    void setSize(int size){
        this->size = size;
    }
    int getSize(){
        return this->size;
    }
    void pushEl(int x){
        if(size+1 < 100){
            arr[size++] = x;
        }
    }
    void viewEl(){
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
    }
    // linear Search
    int linearSearch(int el){
        int result = 0;
        //for(int i = 0; i < size && arr[i] != el ;result = ++i){}
        while(arr[result++] != el) {}
        return (result >= size) ? -1 : result-1;
    } 
    void autoPush(){
        size = 1000;
        for(int i = 0; i < size; i++){
            arr[i] = i;
        }
    }
    // only use when user use autoPush()
    int binarySearch(int el){
        int start = 0;
        int end = size-1;
        int mid = 0;
        
        while(start < end){
            mid = (start + end)/2;
            if(arr[mid] > el){
                end = mid -1;
            }
            else if(arr[mid] < el){
                start = mid+1;
            }
            else{
                break;
            }
        }
        return mid+1;
    }
};

// hash table
struct HashTable{
    private:
    int arr[1000];
    int key;
    int el;
    public:
    HashTable(){
        for(int i = 0; i < 1000; i++){
            arr[i] = 0;
        }
    }
    void setEl(int el){
        this->el = el;
    }
    int getEl(){
        return this->el;
    }
    void setKey(int k){
        setEl(k);
        if(k > 0)
            this->key = k;
        else{
            this->key = -k;
        }
    }
    int getKey(){
        return this->key;
    }
    int HashFunction(){
        int n;
        // enter number to hash 
        cout<<"enter your numb";
        cin>>n;
        
        setKey(n);
        return n%1000;
    }
    
    int HashFunction(int el){
        return el%1000;
    }
    void ArrangeEl(){
        int pos = HashFunction();
        arr[pos] = getEl();
    }
    void View(){
        int index = 0;
        for(auto x : arr){
            if(index == 100)
            {
                cout<<endl;
                index = 0;
            }
            cout<<x<<" ";
            index++;
        }
    }
    // random 1000 numb different
    void autoPush(){
        srand(static_cast<unsigned int>(time(0)));//seed random number generate
        int randomNum;
        for(int i = 0; i < 1000; i++){
            randomNum = rand();
            arr[HashFunction(randomNum%1000 + 1)] = randomNum % 1000 + 1;
        }
    }
};

int main(){
//    SearchFunction test;
//    test.autoPush();
//    cout<<test.linearSearch(568501)<<endl;
//    cout<<test.binarySearch(24);
    HashTable test;
    test.autoPush();
    //test.HashFunction();
    //test.ArrangeEl();
    test.View();
    return 0;
}
