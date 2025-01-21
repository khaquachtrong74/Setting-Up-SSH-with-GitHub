// PURPOSE: MAKE SORT FUNCTION FOR ARRAY
#include<iostream>
using namespace std;

// int array[100];
// size_t size;
// void swap(int &a, int &b){
//     int tmp = a + b;
//     a = tmp - a;
//     b = tmp - a;
// }
// void interChangeSort(){
//     for(int i = 1; i < size-1; i++){
//         for(int j = 0; j < size; j++ ){
//             if(array[i] < array[j]){
//                 swap(array[i], array[j]);
//             }
//         }
//     }
// }
// void bubbleSort(){
//     for(int i = 0; i < size-1; i++){
//         for(int j = size-1; j > i; j--){
//             if(array[j] > array[j-1]){
//                 swap(array[j],array[j-1]);
//             }
//         }
//     }
// }
// void selectionSort(){
//     int min;
//     for(int i = 0; i < size -1; i++){
//         min = i;
//         for(int j = i+1; j < size; j++){
//             if(array[min] > array[j]){
//                 min = j;
//             }
//         }
//         if(min != i)
//             swap(array[min], array[i]);
//     }
// }
// void insertionSort(){
//     int key, val;
//     for(int i = 1; i < size;i++){
//         val = array[i];
//         key = i;
//         while(key >= 0 && val < array[key-1]){
//             array[key] = array[key-1];
//             key--;
//         }
//         array[key] = val;
//     }
// }
bool isLarger(int a, int b){
    return a > b;
}
struct binaryNode{
    private:
    binaryNode* head;
    binaryNode* tail;
    int data;
    public:
    binaryNode():head(nullptr), tail(nullptr), data(int()){}
    binaryNode(int root): head(nullptr), tail(nullptr), data(root){}  
    binaryNode(binaryNode* h = nullptr, binary* t = nullptr, int dt = 0) : head(h), tail(t), data(dt) {}
    friend binarySort;
};
class binarySort{
    private: 
    binaryNode root;
    public:
    
    void push(int el){
        if(el > root.data){
            binaryNode tmp
            root.tail = new binaryNode(root, nullptr, data);
        }
    }
};

// void heapSort(){

// }
// void mergeSort(){

// }
// void quickSort(){
    
// }
int main(){
    int arr[] = {1,5,7,2,4};
    int *newArray = binarySort(arr, 5);
    newArray = binarySort(newArray, 5);
    newArray = binarySort(newArray, 5);
    for(int i = 0; i < 5; i++){
        cout<<newArray[i]<<" ";
    }
    delete []newArray;
}

