/*
 * Filename: prat.cpp
 * Author: Quach Trong Kha
 * Date: October 8, 2024
 * Description: Declared Obj struct
 */
#ifndef PRAT_FIGS_H
#define PRAT_FIGS_H
#include<iostream>
#include<string>

using namespace std;
class Obj{
    private:
    string name;
    int id; // 0-127
    public:
    static void helloWorld(){
        cout<<"hello World!"<<endl;
    };
    void callObj();
    string getName();
    int getId();
    void Set(string s, int i);
    void setName(string s);
    void setId(int i);
    Obj(string name = " ", int id = 0){
        this->name = name;
        this->id = id;
    }
    
};
#endif