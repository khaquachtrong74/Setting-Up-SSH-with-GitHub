// PURPOSE: STACK function

#include <iostream>
using namespace std;

template <typename T>
struct Stack
{
private:
    T arr[100];
    int top;
    int capacity;

public:
    Stack() : top(-1), capacity(0) {}
    Stack(T c) : top(-1), capacity(c) {}
    void push(T el)
    {
        if (top < capacity - 1)
            arr[++top] = el;
    }
    T pop()
    {
        int tmp = arr[top];
        if (top >= 0)
        {

            arr[top--] = -1;
        }
        return tmp;
    }
    int getTop() const
    {
        return this->top;
    }
    int getCapacity() const
    {
        return this->capacity;
    }
    void View() const
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() const{
        return top == -1;
    }
    bool isFull() const{
        return top == capacity;
    }
    T peak(){
        if(isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        else{
            return arr[top];
        }
    }
};

// Stack List
template <typename T>
struct Node
{
private:
    T data;
    Node *next;

public:
    Node(const T &el) : data(el), next(nullptr) {}
    Node() : data(T()), next(nullptr) {}
    Node(const T &el, Node *n) : data(el), next(n) {}
    template <typename U>
    // use friend class to access StackList access private data
    friend class StackList;

};
template <typename T>
class StackList
{
private:
    Node<T> *top;
    size_t size;

public:
    StackList() : top(nullptr), size(0) {}
    ~StackList()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    void push(const T &el)
    {
        top = new Node<T> (el, top);
        size++;
    }
    T pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        Node<T> *tmp = top;
        T data = tmp->data;
        top = top->next;
        delete tmp;
        size--;
        return data;
    }
    bool isEmpty() const
    {
        return top == nullptr;
    }
    // peak a top el
    T peak() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }
    size_t getSize() const
    {
        return size;
    }
    // coppy constructor
    StackList(const StackList &other) : top(nullptr), size(0)
    {
        if (other.isEmpty())
        {
            return;
        }
        Node<T> *otherCurrent = other.top;
        Node<T> *newNode = new Node<T>(otherCurrent->data);
        top = newNode;
        otherCurrent = otherCurrent->next;
        while (otherCurrent != nullptr)
        {
            newNode->next = new Node<T>(otherCurrent->data);
            newNode = newNode->next; // put last top to Current Top of newNode
            otherCurrent = otherCurrent->next;
            size++;
        }
    }
    // assingment with operator (copy)
    StackList &operator=(const StackList &other)
    {
        // compare with address
        if (this != &other)
        {
            while (!isEmpty())
            {
                pop();
            }

            // Copy other stack
            if (!other.isEmpty())
            {
                Node<T> *otherCurrent = other.top;
                Node<T> *newNode = new Node<T>(otherCurrent->data);
                top = newNode;
                otherCurrent = otherCurrent->next;

                while (otherCurrent != nullptr)
                {
                    newNode->next = new Node<T>(otherCurrent->data);
                    newNode = newNode->next;
                    otherCurrent = otherCurrent->next;
                    size++;
                }
            }
        }
        return *this;
    }
};