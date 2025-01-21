
#include<iostream>
#include <unistd.h>
#include<thread>
#include<chrono>
using namespace std;
int count=0;
int soLuong[3] = {45,32,89};
enum SANPHAM{
    GAO = 30000,
    SUA = 10000,
    MI = 3000
};
SANPHAM sp;
void capNhapHang(int time);
void line(){
    cout<<"___________________"<<endl;
}
void thongTinSP(){
    cout<<"Gao: "<<soLuong[0]<<" - "<< GAO << "d/kg"<<endl;
    cout<<"Sua: "<<soLuong[1]<<" - "<< SUA << "d/bich"<<endl;
    cout<<"Mi:  "<<soLuong[2]<<" - "<< MI << "d/goi"<<endl;

}
void menu(){
    //thongTinSP();
    line();
    cout<<"+++++++++++++MENU++++++++++++++++"<<endl;
    cout<<"1. Mua hang"<<endl;
    cout<<"2. Thanh toan"<<endl;
    //cout<<"3. Mua Mi"<<endl;
    cout<<"0. Khong mua"<<endl;
    line();
}
void process(){
    int sleep_time = 0;
    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        sleep_time++;
        capNhapHang(sleep_time);
    }
    
}
int muaHang(int loaiHang){
    int n;
    cout<<"Quy khach muon mua bao nhieu : ";cin>>n;
    if(n > soLuong[loaiHang] || n < 0){
        cout<<"Hay nhap lai cho hop le!"<<endl;
        return -1;
    }
    else{
        soLuong[loaiHang] -= n;
        return n;
    }
    
    // if(n > soluong || n < 0) then cook
    // else soluong -=n;
}
int thanhToan(SANPHAM A, int loaiHang, int muaSoLuong = -1){
    
    if(muaSoLuong == -1) return 0;
    return muaSoLuong * A;
    // A::__ * mua == gia
    // output();
}
void capNhapHang(int time){
    if(time%5 == 0){
        soLuong[1] += 4;
    }
    else if(time%10 == 0){
        soLuong[2] += 30;
    }
    else if(time%30 == 0){
        soLuong[0] += 10;
    }
}
void output(){
    
    int choice=0, loai = 0, tong=0, khoang = 0;
    bool flag;
    thread capNhatThread(process);
    while(true){
        capNhapHang(count);
        thongTinSP();
        menu();
        this_thread::sleep_for(chrono::seconds(1));
        
    
        cout<<"Nhap lua chon: ";cin>>choice;
        switch (choice) {

            case 0 :
                cout<<"END."<<endl;
                exit(0);
                break;
            case 1:
                cout<<"0. GAO"<<endl;
                cout<<"1. SUA\n";
                cout<<"2. MI\n";
                cout<<"Nhap loai hang ";
                cin>> loai;
                flag = (loai <= 2 && loai >= 0);
                sp = (loai == 0 ? GAO : (loai == 1 ? SUA : MI));
                if(flag)
                    khoang = muaHang(loai);
                else
                    cout<<"Khong hop le!"<<endl;
                break;
            case 2:
                if ( sp == 0)  cout<<"Chua chon sp ! ";
                else
                    tong = thanhToan(sp, loai, khoang);
                    cout<<"Thanh toan thanh cong voi so tien la" <<tong<<endl;
                    
                
                break;
            default:
                break;
            
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    capNhatThread.join();
}
int main(){
    output();
    return 0;
}
