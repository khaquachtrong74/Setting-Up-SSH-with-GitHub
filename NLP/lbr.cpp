//Library C++ can use on python file
#include<iostream>
#include<string>
using namespace std;

extern "C" const char* tlw(const char* a){
    static string new_text; //static để lưu trữ chuỗi | dùng static để biến thành biến toàn cục, không bị mất khi chương trình kết thúc
    new_text.clear();// đảm bảo chuỗi trống
    for(int i = 0; a[i] != '\0';i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            new_text += a[i]+32;
        }
        else{
            new_text += a[i];
        }
    }
    return new_text.c_str(); // trả về kiểu con trỏ | ép kiểu
}