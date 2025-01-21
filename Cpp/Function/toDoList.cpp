//PUROSE: Make a List need to do
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<fstream>
using namespace std;
const string FILENAME = "tasks.txt";//file where save task is you not complete!/
void menu(){
	cout<<"1. Make task !"<<endl;
	cout<<"2. Finish task !"<<endl;
	cout<<"3. View task !"<<endl;
	cout<<"0. End the program + Save before"<<endl;
}
int main(){
	string task;
	stack<string>tasks;
	stack<string>tm;
	int chose;
	bool flag = true;
	int num;
	vector<string>list;
	ofstream file(FILENAME);
	while(true && flag){
		menu();
		cout<<"Enter your chose relative numb : ";cin>>chose;
		switch (chose){
			case 0:
				cout<<"Turn of the program! "<<endl;
				cout<<"Have a nice day, DetK!"<<endl;
				if(file.is_open()){
					tm = tasks;
					while(!tm.empty()){
						file<<tm.top()<<endl;
						tm.pop();
					}
					file.close();
					cout<<"Tasks is save at "<<FILENAME<<endl;
					flag = false;
				}
				else{
					cout<<"Can not open file "<<endl;
				}
					 
			break;
			case 1:
				cout<<"Make a new task! : ";
				cin.ignore();
				getline(cin, task);
				list.push_back(task);
				tasks.push(task);
				cout<<"Success 2 make a new task! Good luck to day Sir"<<endl;
				cout<<endl;
				
				break;
			case 2:
				if(list.empty()){
					cout<<"No task in here! ";
				}
				else{
					cout<<"Chose your task numb that you have finish! : ";cin>>chose;
					if(chose < 0 || chose > list.size())
						cout<<"Please, try again with new number "<<endl;
					cout<<"Complete Task "<<chose<<" hheh"<<endl;
					tasks.pop();
					list.erase(list.begin() + chose-1);
					cout<<endl;
				}
			break;
			case 3:
				if(list.empty())
					cout<<"No task in here! ";
				else{
					num = 1;
					cout<<"__________________________________________";
					cout<<endl<<"Your List here!"<<endl;
					for(auto toDo : list){
						cout<<num++<<". "<<toDo<<endl;
					}
					cout<<"__________________________________________";
					cout<<endl;
				}
			break;
			default:
				return 0;
			break;
		}
		cout<<endl;
	}
}
