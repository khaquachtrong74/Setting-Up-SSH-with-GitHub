//stopWatch.cpp 
#include<iostream>
#include<unistd.h> // in linux: sleep()
// #include<windows.h> in windows: Sleep()
using namespace std;

void displayTime(int hours, int minutes, int seconds){
	system("clear");
	cout<<hours<<":"
	<<minutes<<":"
	<<seconds<<endl;
}
void runTime(int hour, int min, int sec){
	//function count seconds
	while(true){
		sleep(1);
		sec++;
		if(sec > 59){
			min++;
			sec=0;
		}
		if(min>59){
			hour++;
			min = 0;	
			sec = 0;
		}
		displayTime(hour, min, sec);
	}	
}
int main(){
	int hour = 0, min = 0, sec = 0;
	runTime(hour,min,sec);
}
