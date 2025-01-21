// allocation
#include <iostream>
using namespace std;
struct allocation
{
private:
    char *arrOne;
    char **arrTwo;
    int size;

public:
    void del(bool flag);
    void aloc();
    // overloading method
    void aloc(int index);
    void del(int index);
    // destruction function
    ~allocation()
    {
        {
            if (getArrOne() != nullptr)
                del(false);
            if (getArrTwo() != nullptr)
            {
                for (int i = 0; i < size; i++)
                {
                    del(i);
                }
                del(true);
            }
        }
    }
    void setSize(int size)
    {
        this->size = size;
    }
    int getSize()
    {
        return size;
    }

    char *getArrOne()
    {
        return arrOne;
    }
    char **getArrTwo()
    {
        return arrTwo;
    }
    allocation() : arrOne(nullptr), arrTwo(nullptr), size(0)
    {
        // Cấp phát bộ nhớ ngay khi khởi tạo
        aloc();
    }
    allocation(int s) : arrOne(nullptr), arrTwo(nullptr), size(s)
    {
        aloc();
    }
};
void allocation::del(int index)
{
    if (this->arrTwo[index] != nullptr)
        delete[] this->arrTwo[index];
}
void allocation::del(bool flag)
{
    if (!flag)
    {
        delete[] this->arrOne;
        this->arrOne = nullptr;
    }
    else
    {
        delete[] this->arrTwo;
        this->arrTwo = nullptr;
    }
}
void allocation::aloc()
{
    if (getSize() < 0)
    {
        throw std::invalid_argument("Size must be Positive");
    }
    try
    {
        this->arrOne = new char[getSize()];
        this->arrTwo = new char *[getSize()];
    }
    catch (const std::bad_alloc &e)
    {
        cerr << "Memory aloca failed" << e.what() << endl;
        throw;
    }
}
void allocation::aloc(int index)
{
    if (index >= 0 && index < getSize())
        this->arrTwo[index] = new char[getSize()];
    else
        throw std::out_of_range("index out of range");
}
istream &operator>>(istream &inDev, allocation &arrChar)
{
    int s;
    cin >> s;
    if (s >= 0)
    {
        arrChar.setSize(s);
        for (int i = 0; i < arrChar.getSize(); i++)
        {
            arrChar.aloc(i);
        }
    }
    return inDev;
}

int main()
{
    allocation Obj;
    cin >> Obj;
    if (Obj.getArrOne() == nullptr && Obj.getArrTwo() == nullptr)
    {
        cout << "Success" << endl;
    }
}