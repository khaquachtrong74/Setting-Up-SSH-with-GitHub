#include<iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void khung(int numb){
	cout<<"|  "<<board[numb][0]<<"   |  "<<board[numb][1]<<"   |  "<<board[numb][2]<<"  |"<<endl; 
}
void khung1(){
	cout<<" ____________________ "<<endl;
}
void boardGame(){
	khung1();
	khung(0);
	khung1();
	khung(1);
	khung1();
	khung(2);

}
int main(){
	boardGame();
	int player; // 1:X     2:O
	cout<<"Please chose 1 for X, 2 for O"<<endl;
	cout<<"Player 1 : X             Player 2 : O"<<endl;
	int i, count = 0; // i >= 1 && i <= 9;
	
	cout<<"Chose your player ";cin>>player;
	bool flag = true;
	switch(player){
		case 1:
		flag = true;
		break;
		case 2:
		flag = false;
		break;
		default:
		cout<<"Hay khoi dong tro choi lai"<<endl;
		return 0;
	}
	while(count <= 9){
		cout<<"Hay nhap so ma ban muon dien "<<endl;cin>>i;
		if(i < 0 || i > 9){
			cout<<"Nhap lai nhe !";
			continue;
		}
		if(flag)
		{
			if(board[i/3][i%3 - 1] != 'X' && board[i/3][i%3 - 1] != 'O'){
			board[i/3][i%3 - 1] = 'X';
			flag = false;
			count++;
			}
			else{
				cout<<"vi tri da co, hay chon cai khac"<<endl;
				
			}
			if(board[i/3][0] == 'X' && board[i/3][1] == 'X' && board[i/3][2] == 'X'){
				cout<<"You win! Player 1"<<endl;
				break;
			}
			if(board[0][i%3 - 1] == 'X' && board[1][i%3 - 1] == 'X' && board[2][i%3 - 1] == 'X'){
				cout<<"You win! Player 1"<<endl;
				break;
			}
			
		}
		else{
			if(board[i/3][i%3 - 1] != 'X' && board[i/3][i%3 - 1] != 'O'){
			board[i/3][i%3 - 1] = 'O';
			flag = true;
			count++;
			}
			else{
				cout<<"vi tri da co, hay chon cai khac"<<endl;
			}
			if(board[i/3][0] == 'O' && board[i/3][1] == 'O' && board[i/3][2] == 'O'){
				cout<<"You win! Player 2"<<endl;
				break;
			}
			if(board[0][i%3 - 1] == 'O' && board[1][i%3 - 1] == 'O' && board[2][i%3 - 1] == 'O'){
				cout<<"You win! Player 2"<<endl;
				break;
			}
			
		}
		boardGame();
	}	
	return 0;
}
