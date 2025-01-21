#include "prat.h"

istream & operator >> (istream &inDev, Obj &Cr){
    string name;
    int id;
    inDev>>id;
    inDev>>name;
    Cr.Set(name, id);
    return inDev;
}
ostream & operator << (ostream &outDev, Obj &Cr){
    outDev<<"Hello "<<Cr.getName()<<", your identify is "<<Cr.getId()<<endl;
    return outDev;
}