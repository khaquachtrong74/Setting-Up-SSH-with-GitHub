#include <iostream>
using namespace std;

struct SinhVien;
ostream &operator<<(ostream &ouDev, SinhVien &sinhVien);
istream &operator>>(istream &isDev, SinhVien &sinhVien);


struct SinhVien
{
private:
    int id;
    string name;
    float point;

public:
    SinhVien(int id = 0, string name = "", float point = 0.0)
    {
        this->id = id;
        this->name = name;
        this->point = point;
    }
    void setId(int id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
    void setPoint(float point){
        this->point = point;
    }
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    float getPoint()
    {
        return this->point;
    }
    
};

// Quản lý sinh viên tầm 100 người
struct ManageSinhVien
{
private:
    SinhVien *manage;
    int index;

public:
    ManageSinhVien()
    {
        this->manage = new SinhVien[100];
        this->index = -1;
    }
    ~ManageSinhVien()
    {
        delete[] this->manage;
        this->manage = nullptr;
    }

    void addSinhVien()
    {
        if (index < 99)
        {
            index++;
            cin>>manage[index];
        }
    }
    void viewSinhVien()
    {
        if(index == -1){
            return;
        }
        int size = index+1;
        for (int i = 0; i < size; i++)
        {
            SinhVien tmp = manage[i];
            cout<<tmp;
        }
    }
};
ostream &operator<<(ostream &ouDev, SinhVien &sinhVien) {
    ouDev << "ID: " << sinhVien.getId() << ", Name: " << sinhVien.getName() << ", Point: " << sinhVien.getPoint() << endl;
    return ouDev;
}

istream &operator>>(istream &isDev, SinhVien &sinhVien) {
    string name;
    int id;
    float point;

    cout << "Enter Id: ";
    isDev >> id;
    isDev.ignore(); // Đảm bảo bỏ qua kí tự '\n'
    cout << "Enter Name: ";
    getline(isDev, name);
    cout << "Enter Point: ";
    isDev >> point;

    sinhVien.setId(id);
    sinhVien.setName(name);
    sinhVien.setPoint(point);

    return isDev;
}


int main(){
    ManageSinhVien quanly;
    quanly.addSinhVien();
    quanly.addSinhVien();
    quanly.viewSinhVien();
    return 0;   
}