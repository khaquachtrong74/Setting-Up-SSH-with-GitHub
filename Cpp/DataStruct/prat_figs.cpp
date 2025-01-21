#include "prat_figs.h"

string Obj::getName(){
    return this->name;
}
int Obj::getId(){
    return this->id;
}
void Obj::setName(string s){
    this->name = s;
}
void Obj::setId(int i){
    this->id = i;
}
void Obj::callObj(){
    cout<<"Hello "<<getName()<<" with Idetify "; cout<< int(getId())<<endl;
}
void Obj::Set(string s, int i){
    this->id = i;
    this->name = s;
}
