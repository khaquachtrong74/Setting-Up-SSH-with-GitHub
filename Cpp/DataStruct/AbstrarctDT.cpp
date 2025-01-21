// Abstract Data Type - ADT
#include <iostream>
using namespace std;
#define MAX 100
/*
    Abstract Data Type
    List -> 8, 3, 4, 4, 6, 10, 12
            0  1  2  3  4  5   6

    Data: 1- Space for storing elements
          2- Capacity
          3- Size

    We can use Array or linkedlist

    Some Operations:
                    + add(x) // add to the end of list
                    + add(index, x) insert element at index
                    + remove(index)
                    + set(index, x) replace element at index
                    + get(index)
                    + search(key) / contains(key)
                    + sort()
                    + split()
                    + merge()


    Define the data, and operations on data together
    Let it be used as data type.

    build data struct

*/

/*
    PURPOSE: BUILD LIST, SET, ARRAY, LINKEDLIST, QUEUE, DEQUEUE, STACK, HASHMAP
    DATE: 17/11/2024
*/

// LIST - Array
class List
{
private:
    int arrayStore[MAX];
    int capacity;
    int size;

public:
    List() : capacity(100), size(0) {}
    List(int cap) : capacity(cap), size(0) {}
    ~List()
    {
        for (int i = 0; i < capacity; i++)
        {
            arrayStore[i] = 0;
        }
    }
    List *append(int el);
    List *append(int index, int el);
    void *remove(int index);
    void *set(int index, int el);
    int *get(int index);
    // linear Search
    int *search(int key);
    // low -> high | it's work but not effective
    void sort();
    void split();
    void merge();
};
List *List::append(int el)
{
    if (size < capacity)
    {
        arrayStore[size++] = el;
        return this;
    }
    else
    {
        return nullptr;
    }
}
List *List::append(int index, int el)
{
    if (size < capacity - 1 && index < size && index >= 0)
    {
        for (int i = size; i > index; i--)
        {
            arrayStore[i] = arrayStore[i - 1];
        }
        arrayStore[index] = el;
        size++;
        return this;
    }
    else
    {
        return nullptr;
    }
}
void *List::remove(int index)
{
    if (index == size - 1)
    {
        arrayStore[index] = 0;
        size--;
        return this;
    }
    if (index < size && index >= 0)
    {
        for (int i = index; i < size - 1; i++)
        {
            arrayStore[i] = arrayStore[i + 1];
        }
        return this;
    }
    return nullptr;
}
void *List::set(int index, int el)
{
    if (index >= 0 && index < size)
    {
        arrayStore[index] = el;
        return this;
    }
    else
    {
        return nullptr;
    }
}
int *List::get(int index)
{
    if (index >= 0 && index < size)
    {
        return &arrayStore[index];
    }
    else
    {
        return nullptr;
    }
}
int *List::search(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arrayStore[i] == key)
            return &arrayStore[i];
    }
    return nullptr;
}
void List::sort()
{
    if (size <= 0)
        return;
    // allocation heap memory
    int *newArrayStore = new int[size];
    int newSize = 0;
    int root, pos = 0;
    // case list have each elements different
    while (pos < size)
    {
        root = arrayStore[pos];
        if(root == -1){
            pos++;
            continue;
        }
        for (int i = pos + 1; i < size; i++)
        {

            if (arrayStore[i] != -1 && arrayStore[i] <= root)
            {
                newArrayStore[newSize++] = arrayStore[i];
                arrayStore[i] = -1;
            }
        }
        newArrayStore[newSize++] = root;
        pos++;
    }
    for(int j = 0; j < size;j++){
        arrayStore[j] = newArrayStore[j];
    }
    // release memory
    delete [] newArrayStore;
    newArrayStore = nullptr;
}