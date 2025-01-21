#include <iostream>
#include <thread>
#include <chrono>
using namespace std ;

void animateDot(int steps) {
    for (int i = 0; i < steps; i++) {
        system("clear"); // Dùng "cls" nếu chạy trên Windows
        for (int j = 0; j < i; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}
void printMessage(){
    cout<<"Hello from a separate thread!"<<endl;
}
int main() {
    // animateDot(20);
    // cout<<"Waiting for 3 seconds ..."<<endl;
    // this_thread::sleep_for(chrono::seconds(3));
    // cout<<"Done!";
    thread t(printMessage);
    t.join();
    chrono::milliseconds mil(1000);
    mil *= 60;
    cout<<"Duration (in periods):";
    cout<<mil.count()<<" milliseconds.\n";
    cout<<"Duration (in seconds) ";
    cout<<(mil.count() * chrono::milliseconds::period::num/
                        chrono::microseconds::period::den);
    cout<<" seconds.\n";
    return 0;
}
